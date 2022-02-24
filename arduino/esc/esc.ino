#include <Servo.h>

Servo esc;
String inputString = ""; 
bool stringComplete = false;


void setup() {

  esc.attach(9);

  esc.writeMicroseconds(1000);

  Serial.begin(9600);


}

void loop() {
  while (Serial.available()) {
    char inChar = Serial.read();
    inputString += inChar;
    if (inChar == '\n') {
       int output = inputString.toInt();
       esc.write(output);
       Serial.println(output);
       inputString="";
    }
  }
  delay(10);
}
