/*
HC-06-Serial-LED-Fade
by 太极创客（2017-07-08）
www.taici-maker.com
此程序旨在演示如何利用HC-06蓝牙模块通过手机或平板电脑的
蓝牙功能来设置arduino开发板上11引脚上连接LED的亮度。

如需获得更多关于本程序的使用说明，请参见太极创客制作的《零基础入门学用Arduino》教程。

---- 电路连接 ---- 
HC-06     Arduino Uno R3 引脚
TX                0 (RX)  
RX                1 (TX)
VCC              +5v
GND              GND

LED       Arduino Uno R3 引脚
 +                11 (RX) 
 -                GND (通过220欧姆限流电阻)

注意：
1. 须使用分压电路，确保HC-06 RX信号电压为3.3伏特。
2. 须先将此程序上传至ARDUINO后，再将HC-06连接在ARDUINO开发板的串口引脚上。
   否则程序将无法正常上传。

*/
int brightness;  //LED亮度变量
int serialData;  //串口数据变量

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(11, OUTPUT);
}
 
void loop(){
  if( Serial.available()>0 ){             //如果串口缓存有数据
    delay(2);
    serialData =  Serial.parseInt(); 
    delay(1);//将串口缓存数值存储到serialData变量
    Serial.print("serialData = "); Serial.println(serialData);  
    if (serialData >=0 && serialData <= 255) {  
      if (serialData >= brightness){       //逐渐调节LED亮度
        for (brightness; brightness <= serialData; brightness++){
          analogWrite(11, brightness); 
          Serial.print("brightness = "); Serial.println(brightness);  
          delay(20);
        }      
      } else {
        for (brightness; brightness >= serialData; brightness--){
          analogWrite(11, brightness); 
          Serial.print("brightness = "); Serial.println(brightness);          
          delay(20);          
        }
        delay(1);        
      }       
      delay(1);
    }
    delay(1);     
  } 
  if(Serial.available()>0){
    while (Serial.available()>0){
      Serial.read();
    }  
    delay(2);  
  }
}
