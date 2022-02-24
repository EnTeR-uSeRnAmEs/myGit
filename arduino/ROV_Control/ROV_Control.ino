//引脚定义
#define pin_Motor1_pwm 3
#define pin_Motor1_in1 2
#define pin_Motor1_in2 4

#define pin_Motor2_pwm 5
#define pin_Motor2_in1 6
#define pin_Motor2_in2 7

#define pin_Motor3_pwm 9
#define pin_Motor3_in1 8
#define pin_Motor3_in2 10

#define pin_Motor4_pwm 11
#define pin_Motor4_in1 12
#define pin_Motor4_in2 13

#define pin_Axis_X A0
#define pin_Axis_Y A1
#define pin_Axis_Z A4
#define pin_Axis_W A5

//函数申明
void ReadAxis();
void ComputeMotorSpeed();
void MotorControl(float speedMotor,int pin_Motor_PWM,int pin_Motor_in1,int pin_Motor_in2);

//全局变量定义
float axisValueX=0;
float axisValueY=0;
float axisValueZ=0;
float axisValueW=0;


float speedMotor1=0;
float speedMotor2=0;
float speedMotor3=0;
float speedMotor4=0;

void setup() 
{
  //初始化
  Serial.begin(9600);

  pinMode(pin_Motor1_pwm,OUTPUT);
  pinMode(pin_Motor1_in1,OUTPUT);
  pinMode(pin_Motor1_in2,OUTPUT);

  pinMode(pin_Motor2_pwm,OUTPUT);
  pinMode(pin_Motor2_in1,OUTPUT);
  pinMode(pin_Motor2_in2,OUTPUT);

  pinMode(pin_Motor3_pwm,OUTPUT);
  pinMode(pin_Motor3_in1,OUTPUT);
  pinMode(pin_Motor3_in2,OUTPUT);

  pinMode(pin_Motor4_pwm,OUTPUT);
  pinMode(pin_Motor4_in1,OUTPUT);
  pinMode(pin_Motor4_in2,OUTPUT);

  MotorControl(speedMotor1,pin_Motor1_pwm,pin_Motor1_in1,pin_Motor1_in2);
  MotorControl(speedMotor2,pin_Motor2_pwm,pin_Motor2_in1,pin_Motor2_in2);
  MotorControl(speedMotor3,pin_Motor3_pwm,pin_Motor3_in1,pin_Motor3_in2);
  MotorControl(speedMotor4,pin_Motor4_pwm,pin_Motor4_in1,pin_Motor4_in2);
}

void loop() 
{

  //读取摇杆键值
  ReadAxis();

  //计算电机油门值
  ComputeMotorSpeed();

  //电机油门控制
  MotorControl(speedMotor1,pin_Motor1_pwm,pin_Motor1_in1,pin_Motor1_in2);
  MotorControl(speedMotor2,pin_Motor2_pwm,pin_Motor2_in1,pin_Motor2_in2);
  MotorControl(speedMotor3,pin_Motor3_pwm,pin_Motor3_in1,pin_Motor3_in2);
  MotorControl(speedMotor4,pin_Motor4_pwm,pin_Motor4_in1,pin_Motor4_in2);
  
  delay(20);

  Serial.print(axisValueZ);Serial.print(" , ");Serial.println(speedMotor3);
}


void ReadAxis()
{
  float axisValueX_temp=0;
  float axisValueY_temp=0;
  float axisValueZ_temp=0;
  float axisValueW_temp=0;
  
  axisValueX_temp=analogRead(pin_Axis_X);
  axisValueY_temp=analogRead(pin_Axis_Y);
  axisValueZ_temp=analogRead(pin_Axis_Z);
  axisValueW_temp=analogRead(pin_Axis_W);

  axisValueX=(axisValueX_temp-512)/512.0;
  axisValueY=(axisValueY_temp-512)/512.0;
  axisValueZ=(axisValueZ_temp-512)/512.0;
  axisValueW=(axisValueW_temp-512)/512.0;

  if(axisValueX>-0.1 && axisValueX<0.1) axisValueX=0;
  if(axisValueY>-0.1 && axisValueY<0.1) axisValueY=0;
  if(axisValueZ>-0.1 && axisValueZ<0.1) axisValueZ=0;
}

void ComputeMotorSpeed()
{
  speedMotor1=axisValueY+axisValueX;
  speedMotor2=axisValueY-axisValueX;

  speedMotor3=axisValueZ;
  speedMotor4=axisValueZ;

  speedMotor1=constrain(speedMotor1,-1,1);
  speedMotor2=constrain(speedMotor2,-1,1);
  speedMotor3=constrain(speedMotor3,-1,1);
  speedMotor4=constrain(speedMotor4,-1,1);
}

void MotorControl(float speedMotor,int pin_Motor_PWM,int pin_Motor_in1,int pin_Motor_in2)
{
  float PWMValue=0;

  if(speedMotor>0)
  {
    //正转
    PWMValue=speedMotor*255;
    digitalWrite(pin_Motor_in1,LOW);
    digitalWrite(pin_Motor_in2,HIGH);
    analogWrite(pin_Motor_PWM,int(PWMValue));
  }
  else
  {
    //反转
    PWMValue=-speedMotor*255;
    digitalWrite(pin_Motor_in1,HIGH);
    digitalWrite(pin_Motor_in2,LOW);
    analogWrite(pin_Motor_PWM,int(PWMValue));
  }
}
