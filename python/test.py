#!/usr/bin/python
# -*- coding: GBK -*-
n = eval(input())
count1 = count2 = count3 = count4 = 0
AABB = AABC = ABAC = ABCA = []
for a in n:
    if a[0] == a[1] and a[3] == a[2] and a[2] != a[1]:
        count1 += 1
        AABB.append(a)
    if a[0] == a[1] and a[3] != a[2] and a[2] != a[1]:
        count2 += 1
        AABC.append(a)
    if a[0] == a[2] and a[3] != a[1] and a[2] != a[1]:
        count3 += 1
        ABAC.append(a)
    if a[0] == a[3] and a[3] != a[2] and a[3] != a[1]:
        count4 += 1
        ABCA.append(a)
re = {'AABB':tuple(AABB), 'AABC':tuple(AABC), 'ABAC':tuple(ABAC), 'ABCA':tuple(ABCA)}
print(re)