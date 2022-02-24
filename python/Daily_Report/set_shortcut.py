import os
import pythoncom
from win32com.shell import shell
from win32com.shell import shellcon


def set_shortcut():  # 如无需特别设置图标，则可去掉iconname参数
    try:
        filename = r"C:\\Users\\24798\\Desktop\\Daily_Report\\Daily_Report_3.0.exe"  # 要创建快捷方式的文件的完整路径
        iconname = ""
        lnkname = r"C:\\Users\\24798\\Desktop" + r"\\Daily_Report_3.0.lnk"  # 将要在此路径创建快捷方式

        shortcut = pythoncom.CoCreateInstance(
            shell.CLSID_ShellLink, None,
            pythoncom.CLSCTX_INPROC_SERVER, shell.IID_IShellLink)
        shortcut.SetPath(filename)

        # 设置快捷方式的起始位置, 不然会出现找不到辅助文件的情况
        # shortcut.SetWorkingDirectory(r"D:\\AppServ\\timer\\win_cron_zq")
        # shortcut.SetIconLocation(iconname, 0)  # 可有可无，没有就默认使用文件本身的图标
        if os.path.splitext(lnkname)[-1] != '.lnk':
            lnkname += ".lnk"
        shortcut.QueryInterface(pythoncom.IID_IPersistFile).Save(lnkname, 0)

        return True
    except Exception as e:
        print(e.args)
        return False

set_shortcut()