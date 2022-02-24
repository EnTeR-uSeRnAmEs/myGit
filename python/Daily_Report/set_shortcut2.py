import os
import win32com.client as client
from win32com.shell import shell, shellcon

shell = client.Dispatch("WScript.Shell")

def GetDesktopPath():
    ilist =shell.SHGetSpecialFolderLocation(0, shellcon.CSIDL_DESKTOP)
    return shell.SHGetPathFromIDList(ilist)
    
def GetShortCut(shortcut):
    return shell.CreateShortCut(shortcut).Targetpath

def createShortCut(filename, lnkname):
    """filename should be abspath, or there will be some strange errors"""
    shortcut = shell.CreateShortCut(lnkname)
    shortcut.TargetPath = filename
    shortcut.save()

def CreateShortCut(filename, lnkname):
    createShortCut(os.path.abspath(filename), lnkname)

# CreateShortCut("C:\\Users\\24798\\Desktop\\Daily_Report\\Daily_Report_3.0.exe", "C:\\Users\\24798\\Desktop" + r"\\Daily_Report_3.0.lnk")





print(GetDesktopPath())