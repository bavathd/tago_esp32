#include<tago.h>

tago tag("xyz-wifi", "tha-pass", "YOUR_API_KEY"); //enter your ssid, password and your tago apikey

void setup() {
  Serial.begin(9600);
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
  float co2 = random(0,9) * 10;
  float rh =  random(0,10) * 0.01;
  int temp = random(0,100) * 100;
 
  tag.sendData("Co2", String(co2));   // To send to tago cloud
  tag.sendData("rh", String(rh));
  tag.sendData("temp", String(temp));
  delay(10000);

}
