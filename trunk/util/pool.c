/*
 * Copyright (c) airfox 2012
 *
 * \brief TODO
 * \author airfox<airgis@163.com>
 */
#include "mempool.h"

typedef struct _MemBlock
{
    size_t free_size;
    size_t free_first;

    struct _MemBlock *next;

    char dataUnits[0];
}MemBlock;

typedef struct _MemPool
{
    size_t unit_size;
    size_t init_size;
    size_t grow_size;

    MemBlock *head;
}

MemPool *mempool_create(size_t unit_size, size_t init_size, size_t grow_size)
{
    MemPool *thiz = malloc(sizeof(MemPool));
    if(thiz == NULL)
    {
        assert(0);
        return NULL;
    }

    if(unit_size > 4)
    {
        thiz->unit_size = ((unit_size + 3)>>2)<<2;
    }
    else if(unit_size <=2)
    {
        thiz->unit_size = 2;
    }
    else
    {
        thiz->unit_size = 4;
    }

    return thiz;
}

void *mempool_alloc(MemPool *thiz)
{
    if(thiz->head == NULL)
    {
        assert(0);
        return NULL;
    }

    MemBlock *free_block = thiz->head;
    while(free_block != NULL && free_block->free_size <= 0)
    {
        free_block = free_block->next;
    }

    if(free_block != NULL)
    {
        char *free_unit = pBlock->data_units + 
            (free_block->free_first * thiz->unit_size);
        free_block->free_first++;
        free_block->free_size++;

        return (void *)free_unit;
    }
    else
    {
        if(thiz->grow_size <= 0)
        {
            return NULL;
        }

        free_block = (MemBlock *)malloc(sizeof(MemBlock) + 
                   thiz->unit_size * thiz->grow_size); 
        if(free_block == NULL)
        {
            assert(0);
            return NULL;
        }

        free_block->next = thiz->head;
        thiz->head = free_block;

        return (void *)(free_block->data_units);
    }
}
