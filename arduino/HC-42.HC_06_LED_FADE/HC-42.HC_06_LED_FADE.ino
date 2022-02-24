int brightness;  //LED亮度变量
int serialData;  //串口数据变量
int a;

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(11, OUTPUT);
  analogWrite(11,0); 
}
 
void loop(){
  if( Serial.available()>0 ){             //如果串口缓存有数据
    delay(2);
    serialData =  Serial.parseInt(); //将串口缓存数值存储到serialData变量
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
  while(Serial.available()>0){
    Serial.read();
  }  
  delay(2);  
}
