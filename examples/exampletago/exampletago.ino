#include<tago.h>

tago tag("***ssid_here***", "***password_here***", "YOUR_API_KEY"); //enter your ssid, password and your tago apikey

void setup() {
  Serial.begin(115200);
  if(!tag.connectWifi()) //To initialize and connect with the WiFi
    {

      Serial.println("not connected");
      while(1);
    }
  Serial.println("Wifi connected");
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  float value1 = random(0,9) * 10;
  float value2 =  random(0,9) * 0.01;
  int value3 = random(0,9) * 100;
 
  tag.sendData("value1", String(value1));   // To send to tago cloud
  tag.sendData("value2", String(value2));
  tag.sendData("value3", String(value3));
  delay(10000);

}
