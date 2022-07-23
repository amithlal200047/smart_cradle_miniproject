#include<BluetoothSerial.h>
BluetoothSerial SerialBT;
char btdata;
void setup() {
  
Serial.begin(9600);
SerialBT.begin("BabyCry");

}

void loop() {
if(SerialBT.available()){
  //Serial.print(SerialBT.readString());
   btdata=SerialBT.read();
  Serial.println(btdata);
  delay(1000);
}

}
