/*a swig interface file*/
%module cucb_gl
%{
#include "cucb_point.h"
#include "cucb_bezier_spline.h"
%}

%include "cucb_point.h"
%include "cucb_bezier_spline.h"
/*extern int bezier_spline(size_t degree, DPoint *points, size_t spline_size, DPoint *spline);*/
