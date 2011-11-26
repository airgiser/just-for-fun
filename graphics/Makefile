all:
	swig -python cucb_gl.i
	gcc -c cucb_point.c cucb_bezier_spline.c cucb_gl_wrap.c -fpic -I/usr/include/python2.7
	gcc -shared cucb_point.c cucb_bezier_spline.o cucb_gl_wrap.o -o _cucb_gl.so
clean:
	rm -f *.o *.so test
