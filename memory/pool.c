/*
 * Copyright (c) airfox 2012
 *
 * \brief TODO
 * \author airfox<airgis@163.com>
 */

#include "pool.h"
#include <assert.h>
#include <stdlib.h>


typedef struct _MemBlock {
    unsigned short size;
    unsigned short free_unit_count;
    unsigned short first_free_unit;

    struct _MemBlock *next;

    char data_units[0];
}MemBlock;

MemBlock *memblock_create(unsigned short unit_size, unsigned short unit_count) {
    unsigned short size = unit_size * unit_count;
    MemBlock *block = (MemBlock *)malloc(sizeof(MemBlock) + size);
    if(block == NULL) {
        assert(0);
        return NULL;
    }
    block->size = size;
    block->first_free_unit = 0;
    block->free_unit_count = unit_count;
    
    char *p = block->data_units;
    for (unsigned short i = 1; i < unit_count; i++) {
        *(unsigned short *)p = i; // next free unit index
        p += unit_size;
    }
    return block;
}

struct _MemPool {
    unsigned short unit_size;
    unsigned short init_size;
    unsigned short grow_size;

    MemBlock *head;
};

MemPool *mempool_create(unsigned short unit_size, 
        unsigned short init_size, unsigned short grow_size) {
    MemPool *thiz = (MemPool *)malloc(sizeof(MemPool));
    if(thiz == NULL) {
        assert(0);
        return NULL;
    }

    thiz->head = NULL;
    thiz->init_size = init_size;
    thiz->grow_size = grow_size;

    if(unit_size > 4) {
        thiz->unit_size = ((unit_size + 3)>>2)<<2;
    }
    else if(unit_size <=2) {
        thiz->unit_size = 2;
    }
    else {
        thiz->unit_size = 4;
    }

    return thiz;
}

void *mempool_alloc(MemPool *thiz)
{
    if (thiz == NULL) {
        assert(0);
        return NULL;
    }

    if(thiz->head == NULL) {
        MemBlock *block = memblock_create(thiz->unit_size, thiz->init_size);
        thiz->head = block;
    }

    // find block that have free units
    MemBlock *free_block = thiz->head;
    while(free_block != NULL && free_block->free_unit_count <= 0) {
        free_block = free_block->next;
    }

    if(free_block != NULL) {
        // get the first free unit
        char *free_unit = free_block->data_units + 
            (free_block->first_free_unit * thiz->unit_size);
        free_block->first_free_unit = *((unsigned short *)free_unit); // next free unit
        free_block->free_unit_count--;

        return (void *)free_unit;
    }
    else {
        // create new memory block
        if(thiz->grow_size <= 0) {
            return NULL;
        }

        free_block = memblock_create(thiz->unit_size, thiz->grow_size);
        if(free_block == NULL) {
            assert(0);
            return NULL;
        }

        // return the first unit
        free_block->first_free_unit++;
        free_block->free_unit_count--;

        free_block->next = thiz->head;
        thiz->head = free_block;
        return (void *)(free_block->data_units);
    }
}

void mempool_free(MemPool *thiz, void *ptr) {
    if(thiz->head == NULL) {
        assert(0);
        return;
    }

    // find the block
    MemBlock *prev_block = NULL;
    MemBlock *block = thiz->head;
    while (((unsigned long)block->data_units > (unsigned long)ptr) || 
            ((unsigned long)ptr >= ((unsigned long)block->data_units + block->size))) {
        prev_block = block;
        block = block->next;
    }
    block->free_unit_count++;

    // free ptr
    *((unsigned short *)ptr) = block->first_free_unit; // next free unit
    unsigned long offset = (unsigned long)ptr - (unsigned long)(block->data_units);
    block->first_free_unit = (unsigned short)(offset / thiz->unit_size);

    // move memory block
    if (prev_block != NULL) {
        prev_block->next = block->next;
        block->next = thiz->head;
        thiz->head = block;
    }

    // free memory block
    if (block->free_unit_count * thiz->unit_size == block->size) {
        thiz->head = block->next;
        free(block);
    }
}

void mempool_destroy(MemPool *thiz) {
    if (thiz == NULL) {
        return;
    }

    MemBlock *block = thiz->head;
    while(block) {
        MemBlock *next = block->next;
        free(block);
        block = next;
    }
    free(thiz);
}
