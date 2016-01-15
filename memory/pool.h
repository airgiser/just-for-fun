/*!
 * Copyright (c) airfox 2012
 *
 * \brief Interface definition of a memory pool.
 * \author airfox <airgis@163.com>
 */
#ifndef UCB_POOL_H
#define UCB_POOL_H

#include <stddef.h>
#include "typedef.h"

UCB_BEGIN

struct _MemPool;
typedef struct _MemPool MemPool;

MemPool *mempool_create(unsigned short unit_size, unsigned short init_size, unsigned short grow_size);

void *mempool_alloc(MemPool *thiz);
void mempool_free(MemPool *thiz, void *ptr);

void mempool_destroy(MemPool *thiz);

UCB_END

#endif/*UCB_POOL_H*/
