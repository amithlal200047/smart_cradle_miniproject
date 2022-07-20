#include<BluetoothSerial.h>
BluetoothSerial SerialBT;
void setup() {
  
Serial.begin(9600);
SerialBT.begin("BabyCry");

}

void loop() {
if(SerialBT.available()){
  Serial.print(SerialBT.readString());
  delay(1000);
}

}
