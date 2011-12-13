#include <stdio.h>
#ifdef WIN32
	#include "Python.h"
#else
	#include <python2.4/Python.h>
#endif

int main()
{
	Py_Initialize();

	PyRun_SimpleString("print 'hello world'");
	return 0;
}
