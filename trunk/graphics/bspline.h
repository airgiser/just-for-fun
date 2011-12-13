/*!
 * Copyright (c) airfox 2011
 *
 * \file bspline.h
 * \brief quadratic b-spline and cubic b-spline
 *
 * \author arifox <airgis@163.com>
 */

#ifndef UCB_BSPLINE_H_
#define UCB_BSPLINE_H_

#include "point.h"

UCB_BEGIN

/*!
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

/*!
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

UCB_END

#endif/*UCB_BSPLINE_H_*/
