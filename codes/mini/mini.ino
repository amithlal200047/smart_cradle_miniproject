#include <Servo_ESP32.h>

static const int servoPin = 14;

Servo_ESP32 servo1;
int angleStep = 5;
int angleMin =55;
int angleMax = 125;

void setup() {
    servo1.attach(servoPin);
    pinMode(39,INPUT);
}

void loop() {

  int mic=digitalRead(39);
  if(mic==HIGH){
    for(int angle = 90; angle >= 55; angle -=angleStep) {
        servo1.write(angle);
        Serial.println(angle);
        delay(50);
    }
    repeat();
    repeat();
    repeat();
    repeat();
    repeat();
    for(int angle = 55; angle <=90; angle +=angleStep) {
        servo1.write(angle);
        Serial.println(angle);
        delay(50);
  }
   }   
}
void repeat()
{
  
    
   for(int angle = 55; angle <= angleMax; angle +=angleStep) {
        servo1.write(angle);
        Serial.println(angle);
        delay(50);
    }

    for(int angle = 125; angle >= angleMin; angle -=angleStep) {
        servo1.write(angle);
        Serial.println(angle);
        delay(50);
    }
    
}
