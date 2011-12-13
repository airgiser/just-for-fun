all:
	swig -python cucb_gl.i
	gcc -c point.c bezier_spline.c bspline.c cucb_gl_wrap.c -fpic -I/usr/include/python2.7
	gcc -shared point.c bezier_spline.o bspline.c cucb_gl_wrap.o -o _cucb_gl.so
clean:
	rm -f *.o *.so test
	rm -f *~
