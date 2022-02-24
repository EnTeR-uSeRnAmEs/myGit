/*
HC-06-Serial-LED-demo
by 太极创客（2017-07-08）
www.taici-maker.com
此程序旨在演示如何利用HC-06蓝牙模块通过手机或平板电脑的
蓝牙功能来打开和关闭arduino开发板引脚11上连接的LED。
 
如需获得更多关于本程序的使用说明，请参见太极创客制作的《零基础入门学用Arduino》教程。
 
---- 电路连接 ---- 
HC-06     Arduino Uno R3 引脚
TX                0 (RX)  
RX                1 (TX)
VCC              +5v
GND              GND
 
注意：
1. 须使用分压电路，确保HC-06 RX信号电压为3.3伏特。
2. 须先将此程序上传至ARDUINO后，再将HC-06连接在ARDUINO开发板的串口引脚上。
   否则程序将无法正常上传。
 
*/
char serialData;
 
void setup() {
  Serial.begin(9600);
  pinMode(11, OUTPUT); //11引脚连接演示用LED
 
}
 
void loop(){
  if( Serial.available()>0 ){ 
    
    serialData =  Serial.read();   
    
    if (serialData == '1' ) {  //接收到点亮LED指令
      Serial.print("Got command: ");  Serial.println(serialData); 
      Serial.println("LED-ON");
      
      digitalWrite(11, HIGH);  //点亮LED指令
    } else {    //接收到熄灭LED指令
      Serial.print("Got command: ");  
      Serial.println(serialData); 
      Serial.println("LED-OFF");
 
      digitalWrite(11, LOW);      //熄灭LED指令  
    }      
  }
}
