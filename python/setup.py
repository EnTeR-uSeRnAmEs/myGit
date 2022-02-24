import os, shutil, sys
from win32com.shell import shell, shellcon

def GetDesktopPath():
    ilist =shell.SHGetSpecialFolderLocation(0, shellcon.CSIDL_DESKTOP)
    return str(shell.SHGetPathFromIDList(ilist))

def mymovefile(srcfile,dstfile):
    if not os.path.isfile(srcfile):
        print ("%s not exist!"%(srcfile))
    else:
        fpath,fname=os.path.split(dstfile)    #分离文件名和路径
        if not os.path.exists(fpath):
            os.makedirs(fpath)                #创建路径
        shutil.move(srcfile,dstfile)          #移动文件
        print ("move %s -> %s"%( srcfile,dstfile))

def mycopyfile(srcfile,dstfile):
    if not os.path.isfile(srcfile):
        print ("%s not exist!"%(srcfile))
    else:
        fpath,fname=os.path.split(dstfile)    #分离文件名和路径
        if not os.path.exists(fpath):
            os.makedirs(fpath)               #创建路径
        shutil.copyfile(srcfile,dstfile)      #复制文件
        # print ("copy %s -> %s"%( srcfile,dstfile))

filename = "Daily_Report"

Desktop = GetDesktopPath()[2 : -1]
installerfile = Desktop + "\\" + filename
srcfile = Desktop + '\\Daily_Report'
dstfile = 'C:\\Daily_Report'
# print(Desktop)
# mycopyfile(srcfile,dstfile)
# print (os.getcwd())

# if os.path.exists(installerfile):  # 如果文件存在
#     # 删除文件，可使用以下两种方法。
#     os.remove(installerfile)  

mymovefile(srcfile + '\\Daily_Report_3.0.exe',dstfile + '\\Daily_Report_3.0.exe')