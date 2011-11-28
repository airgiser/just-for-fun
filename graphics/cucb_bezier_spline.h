/*
 * File: cucb_bezier_spline.h
 * Author: airfox <airgis@163.com>
 *
 * Brief: bezier spline interpolateing algorithm
 */

#ifndef CUCB_BEZIER_SPLINE_H_
#define CUCB_BEZIER_SPLINE_H_

#include "cucb_point.h"

CUCB_BEGIN

/*
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

CUCB_END

#endif/*CUCB_BEZIER_SPLINE_H_*/
