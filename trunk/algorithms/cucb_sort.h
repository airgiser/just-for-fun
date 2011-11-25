/*
 * File: cucb_sort.h
 * Author: airfox <airgis@163.com>
 *
 * Brief: sort algorithms
 */

#ifndef CUCB_SORT_H_
#define CUCB_SORT_H_

#include <stdlib.h>

typedef int (*DataCompareFunc)(void *first, void *second);

void quick_sort(void **array, size_t size, DataCompareFunc cmp);

#endif /*CUCB_SORT_H_*/
