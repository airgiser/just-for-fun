/*!
 * Copyright (c) airfox 2012
 *
 * \brief Interface definition of a memory pool.
 * \author airfox <airgis@163.com>
 */
#ifndef UCB_POOL_H
#define UCB_POOL_H

#include "typedef.h"

UCB_BEGIN

struct _MemPool;
typedef struct _MemPool MemPool;

MemPool *mempool_create(size_t unit_size, size_t init_size, size_t grow_size);

void *mempool_alloc(MemPool *thiz);
void mempool_free(void *p);

void mempool_destroy(MemPool *thiz);

UCB_END

#endif/*UCB_POOL_H*/
