#!/usr/bin/python

astr = "string."
slen = len(astr)
for i in range(0, slen):
    print astr[:slen - i]
print

alist = [5, 3, 6, 9, 2, 7, 11]
print("len:%s" % len(alist))
print("max:%s" % max(alist))
print("min:%s" % min(alist))
print("sorted:%s" % sorted(alist))
print("sum:%s" % sum(alist))

print("str:%s" % str(alist))
