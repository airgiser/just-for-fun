/*!
 * Copyright (c) airfox 2012.
 *
 * \brief The implementation of slist.
 */

#include <assert.h>
#include "slist.h"

typedef struct _SListNode
{
    struct _SListNode *next;
    void *data;
}SListNode;

typedef struct _SList
{
    SListNode *head;

    DataDestroyFunc destroy;
    void *context;
}SList;

static SListNode *slist_create_node(void *data)
{
    SListNode *node = (SListNode *)malloc(sizeof(SListNode));
    if(node != NULL)
    {
        node->data = data;
        node->next = NULL;
    }

    return node;
}

static void slist_destroy_node(SList *thiz, SListNode *node)
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

SList *slist_create(DataDestroyFunc destroy, void *context)
{
    SList *thiz = (SList *)malloc(sizeof(SList));
    assert(thiz != NULL);

    if(thiz != NULL)
    {
        thiz->head = NULL;
        thiz->destroy = destroy;
        thiz->context = context;
    }

    return thiz;
}

static SListNode *slist_get_node(SList *thiz, size_t index, 
        int fail_return_last)
{
    SListNode *cursor = NULL;
    assert(thiz != NULL && thiz->head != NULL);

    if(thiz != NULL && thiz->head != NULL)
    {
        cursor = thiz->head;
        while(cursor != NULL && cursor->next != NULL && index > 0)
        {
            cursor = cursor->next;
            index--;
        }

        if(!fail_return_last)
        {
            cursor = index > 0 ? NULL : cursor; 
        }
    }

    return cursor;
}

Ret slist_append(SList *thiz, void *data)
{
    return slist_insert_after(thiz, (size_t)-1, data);
}

Ret slist_insert_after(SList *thiz, size_t index, void *data)
{
    SListNode *node = NULL;
    SListNode *cursor = NULL;
    assert(thiz != NULL);

    node = slist_create_node(data);
    assert(node != NULL);

    if(thiz->head == NULL)
    {
        thiz->head = node;
        return RET_OK;
    }

    cursor = slist_get_node(thiz, index, 1);
    if(cursor != NULL)
    {
        if(cursor->next != NULL)
        {
            node->next = cursor->next;
        }
        cursor->next = node;
    }

    return RET_OK;
}

Ret slist_get_by_index(SList *thiz, size_t index, void **data)
{
    SListNode *cursor = slist_get_node(thiz, index, 0);
    if(cursor != NULL)
    {
        *data = cursor->data;
        return RET_OK;
    }
    return RET_INVALID_PARAM;
}

Ret slist_set_by_index(SList *thiz, size_t index, void *data)
{
    SListNode *cursor = slist_get_node(thiz, index, 0);
    if(cursor != NULL)
    {
        /* Fix: if data is a ptr to dynamic memory, 
         * may be memory leak here.
         */
        if(thiz->destroy != NULL)
        {
            thiz->destroy(thiz->context, cursor->data);
        }
        cursor->data = data;

        return RET_OK;
    }

    return RET_INVALID_PARAM;
}

Ret slist_delete(SList *thiz, size_t index)
{
    SListNode *prev = NULL;
    SListNode *cursor = NULL;
    assert(thiz != NULL && thiz->head != NULL);

    if(index == 0 && thiz->head != NULL)
    {
        if(thiz->head != NULL)
        {
            cursor = thiz->head;
            thiz->head = thiz->head->next;
            slist_destroy_node(thiz, cursor);
        }
    }
    else
    {
        prev = slist_get_node(thiz, index - 1, 0);
        if(prev != NULL && prev->next != NULL)
        {
            cursor = prev->next;
            prev->next = cursor->next;
            slist_destroy_node(thiz, cursor);
        }
        else
        {
            return RET_INVALID_PARAM;
        }
    }

    return RET_OK;
}

size_t slist_get_length(SList *thiz)
{
    SListNode *cursor = NULL;
    size_t len = 0;

    assert(thiz != NULL);
    cursor = thiz->head;
    while(cursor != NULL)
    {
        ++len;
        cursor = cursor->next;
    }

    return len;
}

int slist_find(SList *thiz, DataCompareFunc cmp, void *data)
{
    int index = 0;
    SListNode *cursor = NULL;
    assert(thiz != NULL && cmp != NULL);

    if(thiz != NULL && cmp != NULL)
    {
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

        return index;
    }

    return -1;
}

Ret slist_foreach(SList *thiz, DataVisitFunc visit, void *context)
{
    SListNode *cursor = NULL;
    assert(thiz != NULL && visit != NULL);

    if(thiz != NULL && visit != NULL)
    {
        cursor = thiz->head;
        while(cursor != NULL)
        {
            visit(context, cursor->data);
            cursor = cursor->next;
        }
        
        return RET_OK;
    }

    return RET_INVALID_PARAM;
}

void slist_destroy(SList *thiz)
{
    SListNode *cursor = NULL;
    if(thiz != NULL)
    {
        cursor = thiz->head;
        while(cursor != NULL)
        {
            thiz->head = cursor->next;
            slist_destroy_node(thiz, cursor);
            cursor = thiz->head;
        }
    }

    free(thiz);
    return;
}
