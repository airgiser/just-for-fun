/*
 * File: cucb_bezier_spline.h
 * Author: airfox <airgis@163.com>
 *
 * Brief: bezier spline algorithm
 */

#ifndef CUCB_BEZIER_SPLINE_H_
#define CUCB_BEZIER_SPLINE_H_

#include "cucb_point.h"
#include <stdlib.h>

/*
 * \brief bezier样条插值
 *
 * \param degree 控制点个数 
 * \param points 控制点数组
 * \param spline_size 生成折线的点集大小
 * \param spline 生成折线的点集
 * 
 * \return 
 */
int bezier_spline(DPoint *points, size_t degree, 
		DPoint *spline, size_t spline_size);

#endif/*CUCB_BEZIER_SPLINE_H_*/
