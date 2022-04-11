import win32gui
import win32con
import win32api
import win32print
from time import sleep

# handle_name = input("请输入边框标题名称（默认为Bongo Cat Mver v0.1.6），按回车以确认：")

handle = win32gui.FindWindow(None, u'Bongo Cat Mver v0.1.6')
# print(handle)
# left, top, right, bottom = win32gui.GetWindowRect(handle)
# print(left, top, right, bottom)
# title = win32gui.GetWindowText(handle)
# clsname = win32gui.GetClassName(handle)
# print(title, clsname)
# win32gui.ShowWindow(handle, win32con.SW_HIDE)
# sleep(2)
# win32gui.ShowWindow(handle, win32con.SW_SHOW)
# win32gui.SetWindowLong(handle, win32con.GWL_EXSTYLE, win32gui.GetWindowLong(
# handle, win32con.GWL_EXSTYLE) | win32con.WS_EX_LAYERED)
# win32gui.SetWindowPos(handle, win32con.HWND_TOPMOST, 0,
#                       0, 150, 100, win32con.SWP_SHOWWINDOW | win32con.SWP_NOSIZE)


def callback(hwnd):
    rect = win32gui.GetWindowRect(hwnd)
    x = rect[0]
    y = rect[1]
    w = rect[2] - x
    h = rect[3] - y
    # print("Window %s:" % win32gui.GetWindowText(hwnd))
    # print("\tLocation: (%d, %d)" % (x, y))
    # print("\t    Size: (%d, %d)" % (w, h))

# callback(handle, None)


sX = win32api.GetSystemMetrics(0)  # 获得屏幕分辨率X轴
sY = win32api.GetSystemMetrics(1)  # 获得屏幕分辨率Y轴
print(sX)
print(sY)

hDC = win32gui.GetDC(0)
w = win32print.GetDeviceCaps(hDC, win32con.DESKTOPHORZRES)  # 横向分辨率
h = win32print.GetDeviceCaps(hDC, win32con.DESKTOPVERTRES)  # 纵向分辨率
print(w)
print(h)
# test = (handle, 0)
# win32gui._TrackMouseEvent(test)
win32gui.SetForegroundWindow(handle)
win32gui.SetLayeredWindowAttributes(handle, 0, 127, 0x2)
while(True):
    if input() == 'q':
        win32gui.SetLayeredWindowAttributes(handle, 0, 255, win32con.LWA_ALPHA)
        break
