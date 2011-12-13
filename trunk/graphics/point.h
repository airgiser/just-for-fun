/*!
 * Copyright (c) airfox 2011
 *
 * \file point.h
 * \brief 2d point
 *
 * \author airfox <airgis@163.com>
 */

#ifndef UCB_POINT_H_
#define UCB_POINT_H_

#include "typedef.h"

UCB_BEGIN

typedef struct _DPoint
{
	double x;
	double y;
}DPoint;

DPoint *points_create(size_t size);
void points_get_by_index(DPoint *pts, size_t size, size_t index, DPoint *pt);
void points_set_by_index(DPoint *pts, size_t size, size_t index, DPoint *pt);
void points_destroy(DPoint *pts);

UCB_END

#endif/*UCB_POINT_H_*/
