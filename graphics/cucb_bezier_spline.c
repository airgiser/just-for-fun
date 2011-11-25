/*
 * File: cucb_bezier_spline.c
 * Author: airfox <airgis@163.com>
 *
 * Brief: bezier spline algorithm
 */

#include "cucb_bezier_spline.h"

/*
 * de Casteljau algorithm
 */
static int decas(size_t degree, DPoint *points, double t, DPoint *out_point)
{
	int i = 0;
	int j = 0;
	DPoint *temp_points = (DPoint *)malloc(sizeof(DPoint) * degree);
	if(temp_points == NULL)
	{
		return -1;
	}
	for(i = 0; i < degree; i++)
	{
		temp_points[i] = points[i];
	}

	for(j = 1; j <= degree; j++)
	{
		for(i = 0; i < degree - j; i++)
		{
			double dx = temp_points[i+1].x - temp_points[i].x;
			double dy = temp_points[i+1].y - temp_points[i].y;
			temp_points[i].x = (double)(temp_points[i].x + t * dx);
			temp_points[i].y = (double)(temp_points[i].y + t * dy);
		}
	}

	*out_point = temp_points[0];
	free(temp_points);

	return 0;
}

int bezier_spline(size_t degree, DPoint *points,
		size_t spline_size, DPoint *spline)
{
	/*Exception*/
	if(spline == NULL || spline_size < degree)
	{
		return -1;
	}

	/*range[0,1]*/
	double t = 0.;
	double delta = 1.0 / (double)(spline_size - 1);

	int i = 0;
	for(i = 0; i < spline_size; i++)
	{
		/* Set spline[i] */
		if(decas(degree, points, t, spline + i) < 0)
		{
			return -1;
		}
		t += delta;
	}

	return 0;
}
