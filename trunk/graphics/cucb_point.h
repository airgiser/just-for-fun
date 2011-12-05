/*!
 * \file cucb_point.h
 * \brief 2d point
 *
 * \author airfox <airgis@163.com>
 */

#ifndef CUCB_POINT_H_
#define CUCB_POINT_H_

#include "cucb_typedef.h"

CUCB_BEGIN

typedef struct _DPoint
{
	double x;
	double y;
}DPoint;

DPoint *points_create(size_t size);
void points_get_by_index(DPoint *pts, size_t size, size_t index, DPoint *pt);
void points_set_by_index(DPoint *pts, size_t size, size_t index, DPoint *pt);
void points_destroy(DPoint *pts);

CUCB_END

#endif/*CUCB_POINT_H_*/
