#!/usr/bin/python
# Filename: exception_try_except.py

import sys

try:
	s = raw_input('Entering something --> ')
except EOFError:
	print 'EOF Error!'
	sys.exit()
except:
	print '\nSome error/exception occurred.'

print 'Done!'
