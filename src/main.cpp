#include <config.h>

    #ifdef ESP32_ENABLED
        void setup() {

        }

        void loop() {
; 
        }
    #endif
    #ifdef ARDUINO_MEGA_ENABLED
        void setup() {
            Serial1.begin(9600);
            Serial2.begin(11500);
            pt100.begin();
        }

        void loop() {
            DynamicJsonDocument data(1024);
            data["temprature"] =pt100.readTemperature();
            data["distance"] =ultra_sonic.dist();
            serializeJson(data,Serial2);
            delay(200); 
        }
    #endif
