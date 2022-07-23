#include <Servo_ESP32.h>
#include "SoundData.h"
#include "XT_DAC_Audio.h"
#include<BluetoothSerial.h>
BluetoothSerial SerialBT;

static const int servoPin = 14;
Servo_ESP32 servo1;
int angleStep = 5;
int angleMin =55;
int angleMax = 125;

XT_Wav_Class Sound(sample);                                           
XT_DAC_Audio_Class DacAudio(25,0);    
uint32_t DemoCounter=0;

char btdata;
void setup() {
    Serial.begin(115200);
    servo1.attach(servoPin);
    pinMode(39,INPUT);
    SerialBT.begin("Smart cradle");
}

void loop() {
  
  btcheck();
  int mic=digitalRead(39);
  if(mic==HIGH){
    song();
    swing();
   }
   if(btdata=='N'){
    while(btdata!='F'){
      song();
      swing1();
      btcheck();
      }
    }
}

/*******************************************************/

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

void song()
{
   for(int i=0;i<=14400;i++){
  DacAudio.FillBuffer();               
  if(Sound.Playing==false)       
    DacAudio.Play(&Sound);       
  Serial.println(DemoCounter++); 
  } 
  }

  void swing()
  {
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

   void swing1()
  {
    for(int angle = 90; angle >= 55; angle -=angleStep) {
        servo1.write(angle);
        Serial.println(angle);
        delay(50);
    }
    repeat();
    for(int angle = 55; angle <=90; angle +=angleStep) {
        servo1.write(angle);
        Serial.println(angle);
        delay(50);
  }
   } 

void btcheck(){
    if(SerialBT.available()){
   btdata=SerialBT.read();
  }
  }
