import win32gui
import win32con
import os
import socket
import sys
from time import sleep
flag = 1


def handle_window(hwnd, extra):
    if win32gui.IsWindowVisible(hwnd):
        if 'C:\windows\py.exe' in win32gui.GetWindowText(hwnd):
            win32gui.ShowWindow(hwnd, win32con.SW_HIDE)
            global flag
            flag = 0


def cd2curdir():
    os.system("cd " + os.path.realpath(os.path.dirname(sys.argv[0])))
    return os.path.realpath(os.path.dirname(sys.argv[0]))


def isNetOK(testserver=('www.baidu.com', 443)):
    s = socket.socket()
    s.settimeout(3)
    try:
        status = s.connect_ex(testserver)
        if status == 0:
            s.close()
            return 0
        else:
            return 1
    except Exception as e:
        return 1


# cd2curdir()
# print(os.getcwd())
# os.system(
#     "python D:/Programs/Appilcations/反闪照/anti_shining_active.py")
# sleep(2)
# win32gui.EnumWindows(handle_window, None)
print(isNetOK())
# while flag:
#     if not isNetOK():
#         os.system(
#             "python D:/Programs/Appilcations/反闪照/anti_shining_active.py")
#         win32gui.EnumWindows(handle_window, None)
#     else:
#         sleep(3)
