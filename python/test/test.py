#!/usr/bin/python
# -*- coding: GBK -*-

def cd2curdir():
    import os
    os.chdir(os.path.split(os.path.abspath(__file__))[0])

cd2curdir()
with open("SHU_Daily_Report", 'r', encoding='utf-16') as f:
    file = f.readlines()
    for a in file:
        print (a)