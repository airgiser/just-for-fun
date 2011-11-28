#include "cucb_bspline.h"
#include <assert.h>

int quadratic_b_spline_interp(DPoint p1, DPoint p2, DPoint p3,
		DPoint *spline, size_t spline_size)
{
	assert(spline != NULL);

	if(spline == NULL || spline_size < 3)
	{
		return -1;
	}

	double t = 0.0;
	int i = 0;
	for(i = 0; i < spline_size; i++)
	{
		t = (double)(i) / (double)(spline_size - 1);

		spline[i].x = ((p1.x - 2 * p2.x + p3.x) * t * t +
				(-2 * p1.x + 2 * p2.x) * t +
				(p1.x + p2.x)) / 2.0f;
		spline[i].y = ((p1.y - 2 * p2.y + p3.y) * t * t +
				(-2 * p1.y + 2 * p2.y) *t +
				(p1.y + p2.y)) / 2.0f;
	}

	return 0;
}

int cubic_b_spline_interp(DPoint p1, DPoint p2, DPoint p3, DPoint p4,
		DPoint *spline, size_t spline_size)
{
	assert(spline != NULL);

	if(spline == NULL || spline_size < 3)
	{
		return -1;
	}

	double t = 0.0;
	int i = 0;
	for(i = 0; i < spline_size; i++)
	{
		t = (double)(i) / (double)(spline_size - 1);

		spline[i].x = ((-p1.x + 3 * p2.x - 3 * p3.x + p4.x) * t * t * t
				+ (3 * p1.x - 6 * p2.x + 3 * p3.x) * t * t
				+ (-3 * p1.x + 3 * p3.x) * t
				+ (p1.x + 4 * p2.x + p3.x)) / 6.0f;
		spline[i].y = ((-p1.y + 3 * p2.y - 3 * p3.y + p4.y) * t * t * t
				+ (3 * p1.y - 6 * p2.y + 3 * p3.y) * t * t
				+ (-3 * p1.y + 3 * p3.y) * t
				+ (p1.y + 4 * p2.y + p3.y)) / 6.0f;
	}

	return 0;
}
