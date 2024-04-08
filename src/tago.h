#ifndef TAGO_H
#define TAGO_H

#include<Arduino.h>
#include<WiFi.h>
#include <HTTPClient.h>



class tago {
    public:
        tago(char* ssid, char* pass, char* api_token);
        bool connectWifi();
        bool sendData(const char *variables, String values);
        ~tago();
    private:

        char* _ssid;
        char* _pass;
        String token;
        int keyindex = 0;
        char* tagoServer = "api.tago.io";

};

#endif