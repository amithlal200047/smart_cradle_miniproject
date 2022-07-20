#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>


char auth[] = "X382h1L_9NQBfvXgOUVdVhEBDXk4T0nm";

char ssid[] = "galaxy";
char pass[] = "galaxy123";

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
}
void loop()
{
  Blynk.run();
}
