/*a swig interface file*/
%module cucb_gl
%{
#include "typedef.h"
#include "point.h"
#include "bezier_spline.h"
#include "bspline.h"
%}

%include "typedef.h"
%include "point.h"
%include "bezier_spline.h"
%include "bspline.h"
/*extern int bezier_spline(size_t degree, DPoint *points, size_t spline_size, DPoint *spline);*/
