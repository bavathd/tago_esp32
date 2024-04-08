#include<tago.h>
#include "DHT.h"

#define DHTPIN D0
#define DHTTYPE DHT11


DHT dht(DHTPIN, DHTTYPE);

tago tag("xyz-wifi", "the-pass", "YOUR_API_KEY"); 

void setup() {
  Serial.begin(9600);
  dht.begin();
  if(!tag.connectWifi()) //To initialize and connect with the WiFi
    {
      Serial.println("not connected");
      while(1);
    }
  Serial.println("Wifi connected");
  delay(1000);

}

void loop() {

  delay(2000);

  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));

  tag.sendData("t", String(t));   // To send to tago cloud
  tag.sendData("h", String(h));
  tag.sendData("f", String(f));
  tag.sendData("hif", String(hif));
  tag.sendData("hic", String(hic));

  delay(10000);

}
