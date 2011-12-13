/*!
 * Copyright (c) airfox 2011
 *
 * \file sort.h
 * \brief sort algorithms
 *
 * \author airfox <airgis@163.com>
 */

#ifndef UCB_SORT_H_
#define UCB_SORT_H_

#include "typedef.h"

UCB_BEGIN

void quick_sort(void **array, size_t size, DataCompareFunc cmp);

UCB_END

#endif /*UCB_SORT_H_*/
