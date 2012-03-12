#!/usr/bin/python

listone = [123, 'xyz']
listtwo = [234, 'abc']
listthree = listtwo + [789]

print(cmp(listone, listtwo))
print(cmp(listtwo, listthree))
print(len(listthree))
print(min(listthree))
print(max(listthree))
print

for i in reversed(listthree):
    print(i),
print

for i, item in enumerate(listthree):
    print(i), 
    print(item)

print(sorted(listthree))
print

listone = ['this', 'a']
listtwo = ['is', 'string.']
for i, j in zip(listone, listtwo):
    print('%s %s' % (i, j))
print

alist = [3.0, 2.0, 9.0]
print(sum(alist))
print(sum(alist, 5))
print

alist = ["str", 23, 23.3]
atuple = tuple(alist)
print(alist)
print(atuple)
anotherlist = list(atuple)
print(alist == anotherlist)
print(alist is anotherlist)
print

print(dir(list))
print

alist = [23]
alist.insert(0, "this")
alist.append("string")
alist.insert(2, 32)
print(alist)
print("This" in alist)
if 32 in alist:
    print(alist.index(32))
alist.sort()
print(alist)
alist.reverse()
print(alist)
alist.extend(["new", "item", 99])
print(alist)
alist.append("none")
print(alist)
