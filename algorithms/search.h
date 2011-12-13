/*!
 * Copyright (c) airfox 2011
 *
 * \file search.h
 * \brief binary search algorithm
 *
 * \author airfox <airgis@163.com>
 */

#ifndef UCB_SEARCH_H_
#define UCB_SEARCH_H_

#include "typedef.h"

UCB_BEGIN

int binary_search(void **array, size_t size, void *data, DataCompareFunc cmp);

UCB_END

#endif/*UCB_SEARCH_H_*/
