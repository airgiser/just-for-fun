#!/usr/bin/python

from random import Random

onelist = [1, 2, 3, 4, 5, 6, 7]

rd = Random()
for i in range(5):
    print(rd.randint(0, 100))
    print(rd.uniform(0, 100))
    print(rd.random())
    print(rd.choice(onelist))
    print('-' * 30)
