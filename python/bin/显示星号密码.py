# -*- coding=utf-8 -*-
import msvcrt,sys
def pwd_input():    
    chars = []   
    while True:  
        try:  
            newChar = msvcrt.getch().decode(encoding="utf-8")  
        except:  
            return input("��ܿ��ܲ�����cmd�����������У��������뽫��������:")  
        if newChar in '\r\n': # ����ǻ��У����������               
             break   
        elif newChar == '\b': # ������˸���ɾ������ĩβһλ����ɾ��һ���Ǻ�   
             if chars:    
                 del chars[-1]   
                 msvcrt.putch('\b'.encode(encoding='utf-8')) # ������һ��  
                 msvcrt.putch( ' '.encode(encoding='utf-8')) # ���һ���ո񸲸�ԭ�����Ǻ�  
                 msvcrt.putch('\b'.encode(encoding='utf-8')) # ������һ��׼�������µ�����                   
        else:  
            chars.append(newChar)  
            msvcrt.putch('*'.encode(encoding='utf-8')) # ��ʾΪ�Ǻ�  
    return (''.join(chars) )  
  
print("Please input your password:")
pwd = pwd_input()  
print("\nyour password is:{0}".format(pwd))
sys.exit()