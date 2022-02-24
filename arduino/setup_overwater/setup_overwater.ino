//+ tx rx gnd rst
#include "I2Cdev.h"
#include "MPU6050_6Axis_MotionApps20.h"
MPU6050 mpu;
#define INTERRUPT_PIN 2

const int pagenumber = 2;
int page=0;

//定义引脚
  const int buttonpins[6] = {12,4,7,8,A7,A6};
  const int joystickpins[4] = {A3,A2,A1,A0};
  const int LEDpins[2][3] = {{9,10,11},{3,5,6}};

//定义LED变量
  int LEDvalues[2][3]={{2,5,5},{5,5,5}};
  int LEDmax=3;

//定义操纵杆变量
  int j[4][4];
  //0:standard 1:temp 2:displacement_origin 3:displacement  4:virtual
  const int numReadings = 50;
  int readings[4][numReadings];  // the readings from the analog input
  int readIndex[4];              // the index of the current reading
  long total[4];                  // the running total
  int average[4];                // the average

//定义去抖变量
  bool buttonread[6];
  bool lastbuttonstate[6];
  bool buttonstate[6];
  bool buttonlongpress[6];
  bool button[12];
  int longpressdelay = 1000;
  unsigned long lastdebouncetime[6];
  unsigned long lastpresstime[6];
  int debouncedelay = 50;

//定义参数
  int v_Zmiddle = 0;//【-255,255】
  int v_XYmax = 510;//【0,512)
  int v_change = 30;
  int j_precision = 2;
  int a_precision = 2;

//定义平移分量
  double trans[3];
  //trans_X = trans[0]; trans_Y = trans[1]; trans_Z = trans[2];

//角度变量
//右转 +　后仰 +　左倾 +　
  bool flag_ypr[3];
  bool ypr_refresh;
  double ypr[3][5];
  float ypr_above[3];
  /*
    {{0,0,0,0,0},   //yaw
     {0,0,0,0,0},   //pitch
     {0,0,0,0,0}}   //roll
    yaw_under = ypr[0][0];
    yaw_above = ypr[0][1];
    yaw_difference = ypr[0][2];
    yaw_analog = ypr[0][3];
    yaw_deviation = ypr[0][4]
    pitch_under = ypr[1][0];
    pitch_above = ypr[1][1];
    pitch_difference = ypr[1][2];
    pitch_analog = ypr[1][3];
    pitch_deviation = ypr[1][4]
    roll_under = ypr[2][0];
    roll_above = ypr[2][1];
    roll_difference = ypr[2][2];
    roll_analog = ypr[2][3];
    roll_deviation = ypr[2][4]

  */ 

//各推进器功率和舵机位置
  double motor[8];
  double motor_deviation[8];
  double pos[4];
  bool pos_reset[4];

//串口字符串截取
  char inchar;
  String instring;
  int innumber;

//陀螺仪相关变量
  bool gyro_control = false;
  bool dmpReady = false;
  uint8_t mpuIntStatus;
  uint8_t devStatus;
  uint16_t packetSize;
  uint16_t fifoCount;
  uint8_t fifoBuffer[64]; 
  Quaternion q;
  VectorFloat gravity;
  volatile bool mpuInterrupt = false;
  void dmpDataReady() {mpuInterrupt = true;}
  
  void button_function(int n){
      switch(n){
          //第一页
          case 0: 
            if(v_Zmiddle<1023-v_change)
            {v_Zmiddle += v_change;}
            break;
          case 1: 
            if(v_Zmiddle>-1023+v_change)
            {v_Zmiddle -= v_change;}
            break;
          case 2: 
            if(v_XYmax<512-v_change)
            {v_XYmax += v_change;}
            break;
          case 3:  
            if(v_XYmax>v_change)
            {v_XYmax -= v_change;}
            break;
          case 4: 
            gyro_control=!gyro_control; 
//            Serial.println();
            break;
          case 5: page++; break;
          //第二页
          case 6:
            if(v_Zmiddle<1023-v_change)
            {v_Zmiddle += v_change;}
            break;
          case 7:
            if(v_Zmiddle>-1023+v_change)
            {v_Zmiddle -= v_change;}
            break;
          case 8:
            if(v_XYmax<512-v_change)
            {v_XYmax += v_change;}
            break;
          case 9:
            if(v_XYmax>v_change)
            {v_XYmax -= v_change;}
            break;
          case 10: 
            gyro_control=!gyro_control; 
            break;
          case 11: page--; break;
      }
  }

  void button_long_function(int n){
      switch(n){
          //第一页
          case 0: 
            pos_reset[2]=1;
            pos[2]=round(pos[2]);
            break;
          case 1: 
            pos_reset[3]=1;
            pos[3]=round(pos[3]);
            break;
          case 2: 
            pos_reset[0]=1;
            pos[0]=round(pos[0]);
            break;
          case 3:  
            pos_reset[1]=1;
            pos[1]=round(pos[1]);
            break;
          case 4: 
            break;
          case 5: 
            break;
          //第二页
          case 6:
            pos_reset[2]=1;
            pos[2]=round(pos[2]);
            break;
          case 7:
            pos_reset[3]=1;
            pos[3]=round(pos[3]);
            break;
          case 8:
            pos_reset[0]=1;
            pos[0]=round(pos[0]);
            break;
          case 9:
            pos_reset[1]=1;
            pos[1]=round(pos[1]);
            break;
          case 10: 
            break;
          case 11: 
            break;
      }
  }
  
  void(* resetFunc) (void) = 0; 

//陀螺仪初始化
  void gyro_initialize(int x, int y, int z){
    #if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
        Wire.begin();
        Wire.setClock(400000); 
    #elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
        Fastwire::setup(400, true);
    #endif
    mpu.initialize();
    pinMode(INTERRUPT_PIN, INPUT);
    devStatus = mpu.dmpInitialize();
    mpu.setXGyroOffset(x);
    mpu.setYGyroOffset(y);
    mpu.setZGyroOffset(z);
    if (devStatus == 0) {
        mpu.CalibrateGyro(6);
        mpu.PrintActiveOffsets();
//        Serial.println(F("Enabling DMP..."));
        mpu.setDMPEnabled(true);
//        Serial.print(F("Enabling interrupt detection (Arduino external interrupt "));
//        Serial.print(digitalPinToInterrupt(INTERRUPT_PIN));
//        Serial.println(F(")..."));
        attachInterrupt(digitalPinToInterrupt(INTERRUPT_PIN), dmpDataReady, RISING);
        mpuIntStatus = mpu.getIntStatus();
//        Serial.println(F("DMP ready! Waiting for first interrupt..."));
        dmpReady = true;
        packetSize = mpu.dmpGetFIFOPacketSize();
    } else { resetFunc(); }
  }

//输出
  void output(){
    //  for(int n=0; n<6; n++){ Serial.print( !buttonstate[n] ); } Serial.write(9);
    //  for(int n=0; n<6; n++){ Serial.print( buttonlongpress[n] ); } Serial.write(9);
      for(int n=0; n<8; n++){ 
    //    motor[n] += motor_deviation[n];
        Serial.print( motor[n],0 ); Serial.write(9);
      } 
      for(int n=0; n<4; n++){ Serial.print( pos[n],0 ); Serial.write(9); } 
      for(int n=0; n<3; n++){ Serial.print( ypr[n][1]); Serial.write(9); }
      Serial.print(gyro_control);Serial.write(9);
      Serial.print(gyro_control&&((abs(j[2][2]-512)<j_precision&&page==0)||page==1));
      Serial.write(9);
      Serial.write(10);
  }

//指示灯
  void lignt_function(){
    if(page){LEDvalues[0][0]=1;LEDvalues[0][1]=0;}
    else{LEDvalues[0][0]=0;LEDvalues[0][1]=1;}
    if(gyro_control){LEDvalues[1][0]=1;LEDvalues[1][1]=0;}
    else{LEDvalues[1][0]=0;LEDvalues[1][1]=1;}
    if(abs(v_Zmiddle)>125){LEDvalues[0][2]=2;}else{LEDvalues[0][2]=0;}
    if(abs(v_Zmiddle)>250){LEDvalues[0][0]=0;LEDvalues[0][1]=0;}
    if(v_XYmax>450){LEDvalues[1][2]=2;}else{LEDvalues[1][2]=0;}
    if(v_XYmax>500){LEDvalues[1][1]=0;}
    if(!buttonstate[0]&&!buttonstate[1])
    {v_Zmiddle=0;LEDvalues[0][0]=3;LEDvalues[0][1]=5;LEDvalues[0][2]=0;}
    if(!buttonstate[2]&&!buttonstate[3])
    {v_XYmax=510;LEDvalues[1][0]=3;LEDvalues[1][1]=4;LEDvalues[1][2]=0;}
    if((!buttonstate[0]&&!buttonlongpress[0])
      ||(!buttonstate[1]&&!buttonlongpress[1])
      ||(!buttonstate[5]&&!buttonlongpress[5])
      ){LEDvalues[0][0]=0;LEDvalues[0][1]=0;LEDvalues[0][2]=0;}
    if((!buttonstate[2]&&!buttonlongpress[2])
      ||(!buttonstate[3]&&!buttonlongpress[3])
      ||(!buttonstate[4]&&!buttonlongpress[4])
      ){LEDvalues[1][0]=0;LEDvalues[1][1]=0;LEDvalues[1][2]=0;}
  }
  


// ================================================================
// ===                        MAIN PROGRAM                      ===
// ================================================================

void setup(){
  for(int n=0; n<6; n++){ pinMode(buttonpins[n], INPUT_PULLUP); }
  for(int n=0; n<4; n++){ pinMode(joystickpins[n], INPUT); }
  for(int n=0; n<2; n++){ for(int m=0; m<3; m++){ 
    pinMode(LEDpins[n][m], OUTPUT);
    analogWrite(LEDpins[n][m],255); }}
  pinMode(13,OUTPUT);
  digitalWrite(13,HIGH);
  gyro_initialize(43,4,14);

//电位器校准（设置初始值）
  Serial.print("操控杆初始值：");
  for(int n=0; n<4; n++){ 
    j[0][n] = analogRead(joystickpins[n]);
    Serial.write(9);
    Serial.print(j[0][n]);
    j[2][n] = 512;
    for (int thisReading = 0; thisReading < numReadings; thisReading++) {
      total[n] = total[n] - readings[n][readIndex[n]];
      readings[n][readIndex[n]] = analogRead(joystickpins[n]);
      total[n] = total[n] + readings[n][readIndex[n]];
      readIndex[n] += 1;
      if (readIndex[n] >= numReadings) {readIndex[n] = 0;}
      average[n] = total[n] / numReadings;
      j[1][n]=average[n];
    }
  }

  Serial.begin(115200);//最后放在最后

}

void loop(){
  while (!mpuInterrupt && fifoCount < packetSize) {
    if (mpuInterrupt && fifoCount < packetSize) {
    fifoCount = mpu.getFIFOCount();}}
  mpuInterrupt = false;
  mpuIntStatus = mpu.getIntStatus();
  fifoCount = mpu.getFIFOCount();
  if(fifoCount < packetSize){}
  else if ((mpuIntStatus & _BV(MPU6050_INTERRUPT_FIFO_OFLOW_BIT)) 
          or fifoCount >= 1024) { mpu.resetFIFO(); } 
  else if (mpuIntStatus & _BV(MPU6050_INTERRUPT_DMP_INT_BIT)) {
    while(fifoCount >= packetSize){ 
      mpu.getFIFOBytes(fifoBuffer, packetSize);
      fifoCount -= packetSize;
    }
    mpu.dmpGetQuaternion(&q, fifoBuffer);
    mpu.dmpGetGravity(&gravity, &q);
    mpu.dmpGetYawPitchRoll(ypr_above, &q, &gravity);
    ypr[0][1]=ypr_above[0]*180/PI;
    ypr[1][1]=ypr_above[2]*180/PI;
    ypr[2][1]=ypr_above[1]*180/PI;

  //电位器平滑
    for(int n=0; n<4; n++){
      total[n] = total[n] - readings[n][readIndex[n]];
      readings[n][readIndex[n]] = analogRead(joystickpins[n]);
      total[n] = total[n] + readings[n][readIndex[n]];
      readIndex[n] += 1;
      if (readIndex[n] >= numReadings) {readIndex[n] = 0;}
      average[n] = total[n] / numReadings;
      j[1][n]=average[n];
      if(j[1][n]>j[0][n]){j[2][n]= 1023-map(j[1][n], j[0][n], 1023, 512, 1023);}
      else if(j[1][n]<j[0][n]){j[2][n]= 1023-map(j[1][n], 0, j[0][n], 0, 512);}
      else if(j[1][n]=j[0][n]){j[2][n]= 512;}
  //    Serial.print(average[n]);
  //    Serial.print(j[2][n]);
  //    Serial.write(9);
    }

  
  //按键（含去抖）
    for(int n=0 ; n<6 ; n++){
      if (n<4){buttonread[n] = digitalRead(buttonpins[n]);}
      else{buttonread[n] = analogRead(buttonpins[n]);}
      if(buttonread[n] != lastbuttonstate[n]){
      lastdebouncetime[n]=millis();}
      if(millis()-lastdebouncetime[n]>debouncedelay){
        button[n+page*6] = !buttonstate[n];
        if(!buttonstate[n])
            {buttonlongpress[n]=millis()-lastpresstime[n]>longpressdelay;}
        else{buttonlongpress[n]=0;}
        if(buttonread[n] != buttonstate[n]){//按键抬起或按下时
          buttonstate[n] = buttonread[n];
          if(buttonstate[n]){//抬起瞬间
            if(buttonlongpress[n]){button_long_function(n+6*page);}
            else{button_function(n+6*page);}
          }
          else{//按下瞬间
            lastpresstime[n]=millis();
            if(!buttonstate[4]&&!buttonstate[5]){
//              Serial.write('r');
              resetFunc();
            }
          }
        }
      }
      lastbuttonstate[n]=buttonread[n];
    }

  //计算ypr_difference(ypr[ ][2])
      for(int n=0; n<3; n++){
        ypr[n][2] = ypr[n][1] - ypr[n][0]; 
        ypr[n][3] = ypr[n][2] - ypr[n][4];
      }
  
    switch(page){
      case 0:
        //平移
        trans[0] = - map(j[2][0],0,1023,- v_XYmax,v_XYmax);
        trans[1] = map(j[2][1],0,1023,- v_XYmax,v_XYmax);
        if(trans[0]){
          motor[0] = (trans[1] + trans[0]) / 4.0 * (0.5*cos(4*atan(trans[1]/trans[0]))+1.5);
          motor[1] = (trans[1] - trans[0]) / 4.0 * (0.5*cos(4*atan(trans[1]/trans[0]))+1.5);
        }
        else{
          motor[0] = trans[1] / 2;
          motor[1] = trans[1] / 2;
        }
        motor[2] = -motor[0];
        motor[3] = -motor[1];
        //升降
        if(j[2][3]<512){trans[2] = map(j[2][3],0,512,-255,v_Zmiddle);}
        else{trans[2] = map(j[2][3],512,1024,v_Zmiddle,256);}
        for(int n=4; n<8; n++){ motor[n] = trans[2]; }
  
        //旋转
        j[3][2]=1023-j[2][2];

      break;
      
      case 1:
        //清空!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        for(int n=0; n<4; n++){ motor[n]=0; }
        for(int n=4; n<8; n++){ motor[n] = v_Zmiddle; }
        //机械臂
        for(int n=0; n<4; n++){
          if(pos_reset[n]){
            if(pos[n]==0){pos_reset[n]=0;}
            else if(pos[n]>0){pos[n]-=0.5;}
            else if(pos[n]<0){pos[n]+=0.5;}
          }else{
            if(j[2][n]<5 and pos[n]<135){pos[n]+=0.5;}
            else if(j[2][n]>1020 and pos[n]>-135){pos[n]-=0.5;}
            if(j[2][n]<512-j_precision and pos[n]<135){pos[n]+=0.1;}
            else if(j[2][n]>512+j_precision and pos[n]>-135){pos[n]-=0.1;}
          }
        }
      break;
    }

      for(int n=0; n<4; n++){
        if(j[3][2]<512){motor[n]=map(j[3][2],0,511,-255*pow(-1,n%2),motor[n]);}
        else{motor[n]=map(j[3][2],512,1023,motor[n],255*pow(-1,n%2));}
      }
      /*
      if(j[3][2]<512){
        motor[0] = map(j[3][2],0,511,-255,motor[0]);
        motor[1] = map(j[3][2],0,511,255,motor[1]);
        motor[2] = map(j[3][2],0,511,-255,motor[2]);
        motor[3] = map(j[3][2],0,511,255,motor[3]);
      }else{
        motor[0] = map(j[3][2],512,1023,motor[0],255);
        motor[1] = map(j[3][2],512,1023,motor[1],-255);
        motor[2] = map(j[3][2],512,1023,motor[2],255);
        motor[3] = map(j[3][2],512,1023,motor[3],-255);
      }
      */

  //指示灯
    lignt_function();

  //指示灯显示
    for(int n=0; n<2; n++){for(int m=0; m<3; m++){
      analogWrite(LEDpins[n][m],255-LEDvalues[n][m]);
      digitalWrite(13,HIGH);
    //  Serial.print(LEDvalues[n][m]);
    //  Serial.write(9);
    }}
  
  //输出:
    output();

  }
  
}

/*
void serialEvent(){
  while(Serial.available()>0){
    inchar = Serial.read();
//    Serial.write( inchar );

    if(inchar == 10){ innumber = 0; instring = ""; }
    else if(inchar == 9 or inchar == 44){
      innumber++; 
      ypr[innumber-1][0] = instring.toDouble();
      instring = ""; }
    else{ instring += inchar; }
    
  }
}
*/
