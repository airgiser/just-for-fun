/*
 * File: cucb_search.h
 * Author: airfox <airgis@163.com>
 *
 * Brief: binary search algorithm
 */

#ifndef CUCB_SEARCH_H_
#define CUCB_SEARCH_H_

#include "cucb_typedef.h"

CUCB_BEGIN

int binary_search(void **array, size_t size, void *data, DataCompareFunc cmp);

CUCB_END

#endif
