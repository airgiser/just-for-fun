/*!
 * \file cucb_point.c
 * \brief 2d point
 *
 * \author airfox <airgis@163.com>
 */

#include "cucb_point.h"
#include <assert.h>

DPoint *points_create(size_t size)
{
	DPoint *pts = NULL;
	if(size > 0)
	{
		pts = (DPoint *)malloc(sizeof(DPoint) * size);
		assert(pts != NULL);
	}
	return pts;
}

void points_get_by_index(DPoint *pts, size_t size, size_t index, DPoint *pt)
{
	if(pts != NULL && index < size)
	{
		*pt = *(pts + index);
	}

	return;
}

void points_set_by_index(DPoint *pts, size_t size, size_t index, DPoint *pt)
{
	if(pts != NULL && index < size && pt != NULL)
	{
		*(pts + index) = *pt;
	}

	return;
}

void points_destroy(DPoint *pts)
{
	free(pts);
}
