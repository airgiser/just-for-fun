/**
 * Copyright (c) airfox 2012.
 *
 * \brief dlist.
 */

#include <assert.h>
#include "dlist.h"

typedef struct _DListNode
{
    struct _DListNode *prev;
    struct _DListNode *next;

    void *data;
}DListNode;

typedef struct _DList
{
    DListNode *head;

    DataDestroyFunc destroy;
    void *context;

    Locker *locker;
}DList;

static DListNode *dlist_create_node(void *data)
{
    DListNode *node = (DListNode *)malloc(sizeof(DListNode));
    if(node != NULL)
    {
        node->prev = NULL;
        node->next = NULL;
        node->data = data;
    }

    return node;
}

static void dlist_destroy_node(DList *thiz, DListNode *node)
{
    if(node != NULL)
    {
        if(thiz != NULL && thiz->destroy != NULL)
        {
            thiz->destroy(thiz->context, node->data);
        }
        free(node);
    }

    return;
}

static void dlist_lock(DList *thiz)
{
    if(thiz->locker != NULL)
    {
        locker_lock(thiz->locker);
    }
}

static void dlist_unlock(DList *thiz)
{
    if(thiz->locker != NULL)
    {
        locker_unlock(thiz->locker);
    }
}

static void dlist_destroy_locker(DList *thiz)
{
    if(thiz->locker != NULL)
    {
        locker_unlock(thiz->locker);
        locker_destroy(thiz->locker);
    }
}

DList *dlist_create(DataDestroyFunc destroy, void *context, Locker *locker)
{
    DList *thiz = (DList *)malloc(sizeof(DList));

    if(thiz != NULL)
    {
        thiz->head = NULL;
        thiz->destroy = destroy;
        thiz->context = context;
        thiz->locker = locker;
    }

    return thiz;
}

Ret dlist_append(DList *thiz, void *data)
{
    return dlist_insert(thiz, (size_t)-1, data);
}

Ret dlist_preappend(DList *thiz, void *data)
{
    return dlist_insert(thiz, (size_t)0, data);
}

static DListNode *dlist_get_node(DList *thiz, size_t index, 
        int fail_return_last)
{
    DListNode *cursor = thiz->head;
    while(cursor != NULL  && cursor->next != NULL && index > 0)
    {
        --index;
        cursor = cursor->next;
    }

    if(index > 0 && !fail_return_last)
    {
        cursor = NULL;
    }

    return cursor;
}

static size_t dlist_get_length_nonelock(DList *thiz)
{
    size_t len = 0;
    DListNode *cursor = NULL;
    if(thiz != NULL)
    {
        cursor = thiz->head;
        while(cursor != NULL)
        {
            ++len;
            cursor = cursor->next;
        }
    }

    return len;
}

Ret dlist_insert(DList *thiz, size_t index, void *data)
{
    DListNode *cursor = NULL;
    DListNode *node = dlist_create_node(data);
    assert(thiz != NULL && node != NULL);

    dlist_lock(thiz);
    if(thiz->head == NULL)
    {
        thiz->head = node;
        return RET_OK;
    }

    cursor = dlist_get_node(thiz, index, 1);
    /*
     * if we invoke the dlist_get_length function here,
     * dead lock may occured when the other thread 
     * used the dlist_get_length interface.
     *
     * we can invoke dlist_get_length_nonlock to protect this,
     * or use nest locker.
     */
    if(index < dlist_get_length_nonelock(thiz))
    {
        if(cursor == thiz->head)
        {
            thiz->head = node;
        }
        else
        {
            cursor->prev->next = node;
            node->prev = cursor->prev;
        }
        cursor->prev = node;
        node->next = cursor;
    }
    else
    {
        cursor->next = node;
        node->prev = cursor;
    }
    dlist_unlock(thiz);

    return RET_OK;
}

Ret dlist_get_by_index(DList *thiz, size_t index, void **data)
{
    DListNode *cursor = NULL;
    assert(thiz != NULL);

    dlist_lock(thiz);
    cursor = dlist_get_node(thiz, index, 0);
    if(cursor != NULL)
    {
        *data = cursor->data;
        return RET_OK;
    }
    dlist_unlock(thiz);

    return RET_INVALID_PARAM;
}

Ret dlist_set_by_index(DList *thiz, size_t index, void *data)
{
    DListNode *cursor = NULL;
    assert(thiz != NULL);

    dlist_lock(thiz);
    cursor = dlist_get_node(thiz, index, 0);
    if(cursor != NULL)
    {
        if(thiz->destroy != NULL)
        {
            thiz->destroy(thiz->context, cursor->data);
        }
        cursor->data = data;
        return RET_OK;
    }
    dlist_unlock(thiz);

    return RET_INVALID_PARAM;
}

Ret dlist_delete(DList *thiz, size_t index)
{
    DListNode *cursor = NULL;
    assert(thiz != NULL);

    dlist_lock(thiz);
    cursor = dlist_get_node(thiz, index, 0);
    if(cursor != NULL)
    {
        if(cursor == thiz->head)
        {
            thiz->head = cursor->next;
        }
        if(cursor->next != NULL)
        {
            cursor->next->prev = cursor->prev;
        }
        if(cursor->prev != NULL)
        {
            cursor->prev->next = cursor->next;
        }

        dlist_destroy_node(thiz, cursor);
        cursor = NULL;

        return RET_OK;
    }

    dlist_unlock(thiz);

    return RET_INVALID_PARAM;
}

size_t dlist_get_length(DList *thiz)
{
    size_t len = 0;
    dlist_lock(thiz);
    len = dlist_get_length_nonelock(thiz);
    dlist_unlock(thiz);

    return len;
}

int dlist_find(DList *thiz, DataCompareFunc cmp, void *data)
{
    DListNode *cursor = NULL;
    int index = 0;

    if(thiz != NULL && cmp != NULL)
    {
        dlist_lock(thiz);
        cursor = thiz->head;
        while(cursor != NULL)
        {
            if(cmp(data, cursor->data) == 0)
            {
                break;
            }
            ++index;
            cursor = cursor->next;
        }

        dlist_unlock(thiz);
        return index;
    }

    return -1;
}

Ret dlist_foreach(DList *thiz, DataVisitFunc visit, void *context)
{
    DListNode *cursor = NULL;
    if(thiz != NULL && visit != NULL)
    {
        dlist_lock(thiz);
        cursor = thiz->head;
        while(cursor != NULL)
        {
            visit(context, cursor->data);
            cursor = cursor->next;
        }
        dlist_unlock(thiz);

        return RET_OK;
    }

    return RET_INVALID_PARAM;
}

void dlist_destroy(DList *thiz)
{
    DListNode *cursor = NULL;
    assert(thiz != NULL);

    if(thiz != NULL)
    {
        dlist_lock(thiz);
        cursor = thiz->head;
        while(cursor != NULL)
        {
            thiz->head = cursor->next;
            dlist_destroy_node(thiz, cursor);
            cursor = thiz->head;
        }

        dlist_destroy_locker(thiz);
        free(thiz);
    }
    
    return;
}
