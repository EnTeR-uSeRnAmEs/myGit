import win32gui
import win32con
from time import sleep

handle = win32gui.FindWindow("TXGuiFoundation", u'qq')
print(handle)
left, top, right, bottom = win32gui.GetWindowRect(handle)
print(left, top, right, bottom)
title = win32gui.GetWindowText(handle)
clsname = win32gui.GetClassName(handle)
print(title, clsname)
win32gui.ShowWindow(handle, win32con.SW_HIDE)
sleep(2)
win32gui.ShowWindow(handle, win32con.SW_SHOW)
