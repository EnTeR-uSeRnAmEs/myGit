Sub Sleep(MSecs)
    Dim objOutputFile
    Dim fso
    Set fso=CreateObject("Scripting.FileSystemObject")
    If fso.FileExists("sleeper.vbs")=False  Then
       Set objOutputFile=fso.CreateTextFile("sleeper.vbs",True)
       objOutputFile.Write "WScript.Sleep WScript.Arguments(0)"
       objOutputFile.Close
    End If

    CreateObject("WScript.Shell").Run "sleeper.vbs "& MSecs,1,True
End Sub

createobject("wscript.shell").run "Bongo_Cat_Mver.exe",vbhide
Sleep 100
createobject("wscript.shell").run "winPos.exe",vbhide