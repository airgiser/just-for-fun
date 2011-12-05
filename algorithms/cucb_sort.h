/*!
 * \file cucb_sort.h
 * \brief sort algorithms
 *
 * \author airfox <airgis@163.com>
 */

#ifndef CUCB_SORT_H_
#define CUCB_SORT_H_

#include "cucb_typedef.h"

CUCB_BEGIN

void quick_sort(void **array, size_t size, DataCompareFunc cmp);

CUCB_END

#endif /*CUCB_SORT_H_*/
