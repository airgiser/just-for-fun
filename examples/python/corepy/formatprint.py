#!/usr/bin//python

x = 108
print("%x" % x)
print("%X" % x)
print("%#x" % x)
print("%#X" % x)
print

fx = 1234.56789
print("%f" % fx)
print("%.2f" % fx)
print("%E" % fx)
print("%e" % fx)
print("%g" % fx)
print("%G" % fx)
print("%e" % 222222222222222222222222L)
print

print("%+d" % 4)
print("%+d" % -4)
print("%d%%" % 90)
print("my name is %s, i'm %d years old." % ("airfox", 25))
print

num = 123
print("dec: %d, oct: %#o, hex:%#X" % (num, num, num))

print("MM/DD/YY = %02d/%02d/%d" % (2, 23, 12))

adict = {'name':'airfox', 'age':25}
print("my name is %(name)s, i'm %(age)d years old." % adict)

from string import Template
astr = Template("my name is ${name}, i'm ${age} years old.")
print astr.substitute(name = "airfox", age = 25)

