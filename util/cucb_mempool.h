/*
 * Copyright (c) airfox
 *
 * \brief Interface definition of a memory pool.
 * \author airfox <airgis@163.com>
 */
#ifndef CUCB_MEM_POOL_H_
#define CUCB_MEM_POOL_H_

#include "cucb_typedef.h"

CUCB_BEGIN

struct _MemPool;
typedef struct _MemPool MemPool;

MemPool *mempool_create(size_t unit_size, size_t init_size, size_t grow_size);

void *mempool_alloc(MemPool *thiz);
void mempool_free(void *p);

void mempool_destroy(MemPool *thiz);


CUCB_END

#endif/*CUCB_MEM_POOL_H_*/
