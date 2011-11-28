/*
 * File: cucb_bspline.h
 * Author: arifox <airgis@163.com>
 *
 * Brief: quadratic b-spline and cubic b-spline
 */

#ifndef CUCB_BSPLINE_H_
#define CUCB_BSPLINE_H_

#include "cucb_point.h"

CUCB_BEGIN

/*
 * \brief uniform quadratic b-spline interpolating
 *
 * \param p1,p2,p3 -- control points
 * \param spline -- vertices of the spline to be created
 * \param spline_size -- points count of the spline to be created
 *
 * \return 0 if succeed, -1 if failed
 */
int quadratic_b_spline_interp(DPoint p1, DPoint p2, DPoint p3,
		DPoint *spline, size_t spline_size);

/*
 * \brief uniform cubic b-spline interpolating
 *
 * \param p1,p2,p3,p4 -- control points
 * \param spline -- vertices of the spline to be created
 * \param spline_size -- points count of the spline to be created
 *
 * \return 0 if succeed, -1 if failed
 */
int cubic_b_spline_interp(DPoint p1, DPoint p2, DPoint p3, DPoint p4,
		DPoint *spline, size_t spline_size);

CUCB_END

#endif
