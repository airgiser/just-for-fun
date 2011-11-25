#ifndef CUCB_BEZIER_H_
#define CUCB_BEZIER_H_

#include "cucb_point.h"
#include <stdlib.h>

/*
 * \brief bezier样条插值
 *
 * \param degree 控制点个数 
 * \param points 控制点数组
 * \param spline_size 生成折线的点集大小
 * \param spline 生成折线的点集
 */
int bezier_spline(size_t degree, DPoint *points, 
		size_t spline_size, DPoint *spline);

#endif/*CUCB_BEZIER_H_*/
