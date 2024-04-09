#include<tago.h>

WiFiClient client;
tago::tago (char* ssid, char* pass, char* api_token) {

    _ssid = ssid;
    _pass = pass;
    token = api_token;
}
bool tago::connectWifi() {
    WiFi.begin(_ssid, _pass);
    Serial.println("\nConnecting");
    int timeout_counter = 0;

    while(WiFi.status() != WL_CONNECTED){
            Serial.print(".");
            delay(200);
            timeout_counter++;
            if(timeout_counter >= 10000*5){
            Serial.println("\nConnection Timeout");
            return false;
        }
     
}
       return true;

}

bool tago::sendData(const char* variables, String values) {
    Serial.println("\nSending Data");

        String PostData = String("{\"variable\":") + String("\"") + String(variables) + String("\"") + String(",\"value\":") + String(values) + String("}");
        String Dev_token = String("Device-Token: ")+ token;
        Serial.println(variables);
        Serial.println( values);
        if (client.connect(tagoServer,80)) 
        {                     
        Serial.println("connected to server");
        // Make a HTTP request:
        client.println("POST /data? HTTP/1.1");
        client.println("Host: api.tago.io");
        client.println("_ssl: false");       // for non-secured connection, use this option "_ssl: false"
        client.println(Dev_token);
        client.println("Content-Type: application/json");
        client.print("Content-Length: ");
        client.println(PostData.length());
        client.println();
        client.println(PostData);
        return true;
        }
        else 
        {
        // if you couldn't make a connection:
        Serial.println("connection failed");
        return false;
        }
        delay(1000);
        


   
}

tago::~tago() {
    client.stop();
    Serial.println("\nDisconnecting API");
    WiFi.disconnect();
    Serial.println("\nDisconnected Wifi");
    Serial.flush();
}
