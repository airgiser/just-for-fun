/*
 * File: cucb_sort.h
 * Author: airfox <airgis@163.com>
 *
 * Brief: sort algorithms
 */

#ifndef CUCB_SORT_H_
#define CUCB_SORT_H_

#include "cucb_typedef.h"

CUCB_BEGIN

void quick_sort(void **array, size_t size, DataCompareFunc cmp);

CUCB_END

#endif /*CUCB_SORT_H_*/
