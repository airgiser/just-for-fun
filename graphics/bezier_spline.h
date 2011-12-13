/*!
 * Copyright (c) airfox 2011
 *
 * \file bezier_spline.h
 * \brief bezier spline interpolateing algorithm
 *
 * \author airfox <airgis@163.com>
 */

#ifndef UCB_BEZIER_SPLINE_H_
#define UCB_BEZIER_SPLINE_H_

#include "point.h"

UCB_BEGIN

/*!
 * \brief bezier spline interpolating
 *
 * \param[in] points -- control points
 * \param[in] degree -- count of control points 
 * \param[in][out] spline -- vertices of the created spline
 * \param[in][out] spline_size -- points count of the created spline
 * 
 * \return 0 if succeed, -1 if failed 
 */
int bezier_spline(DPoint *points, size_t degree, 
		DPoint *spline, size_t spline_size);

UCB_END

#endif/*UCB_BEZIER_SPLINE_H_*/
