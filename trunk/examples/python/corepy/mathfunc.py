#!/usr/bin/python

import math

print(abs(-2))
print(abs(10.))
print

print(coerce(1.3, 234))
print

print(divmod(10, 3))
print(divmod(3, 10))
print(divmod(11, 2.5))
print

print(pow(2, 3))
print(pow(3, 4))
print

print(round(3))
print(round(3.56))
print(round(3.499))
print(round(3.499, 1))
print(round(-3.5))
print

for i in range(10):
    print(round(math.pi, i))
print

for i in (.2, .7, 1.2, 1.7, -.2, -.7, -1.2, -1.7):
    print("int(%.1f)\t%+.1f" % (i, float(int(i))))
    print("floor(%.1f)\t%+.1f" % (i, math.floor(i)))
    print("round(%.1f)\t%+.1f" % (i, round(i)))
    print('-' * 30)
