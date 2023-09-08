#include <functions.h>
    #ifdef ESP32_ENABLED
        void setup() {
            Serial2.begin(115200);
            ConnectWiFi();
            client.setServer(MQTT_SERVER, MQTT_PORT);
        }

        void loop() {
            if (WiFi.status() != WL_CONNECTED)
                ConnectWiFi();
            if (!client.connected())
                reconnect();
            if(Serial2.available()){
                String payload = Serial2.readString();
                client.publish(MQTT_TOPIC, payload.c_str());
            }
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
