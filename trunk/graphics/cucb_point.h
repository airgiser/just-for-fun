/*
 * File: cucb_point.h
 * Author: airfox <airgis@163.com>
 *
 * Brief: 2d point
 */

#ifndef CUCB_POINT_H_
#define CUCB_POINT_H_

#include <stdlib.h>

struct _DPoint;
typedef struct _DPoint DPoint;

typedef struct _DPoint
{
	double x;
	double y;
}DPoint;

DPoint *points_create(size_t size);
void points_get_by_index(DPoint *pts, size_t size, size_t index, DPoint *pt);
void points_set_by_index(DPoint *pts, size_t size, size_t index, DPoint *pt);
void points_destroy(DPoint *pts);

#endif/*CUCB_POINT_H_*/
