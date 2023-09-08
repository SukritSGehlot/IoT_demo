#if !defined(FUNCTIONS_H)
#define FUNCTIONS_H
    #include <config.h>
    #ifdef ESP32_ENABLED
    
        void ConnectWiFi() {
            WiFi.begin(ssid, password);
            Serial.print("Connecting to SSID: ");
            Serial.println(ssid);
            while (WiFi.status() != WL_CONNECTED) {
                delay(1000);
                Serial.println("Connecting to WiFi...");
            }
            Serial.println("Connected to WiFi");
            }
        
        void reconnect() {
            while (!client.connected()) {
                Serial.println("Connecting to MQTT...");
                if (client.connect("ESP32Client")) {
                Serial.println("Connected to MQTT");
                } else {
                Serial.print("Failed to connect to MQTT, rc=");
                Serial.print(client.state());
                Serial.println(" Retrying in 5 seconds...");
                delay(5000);
                }
            }
            }
    #endif



#endif // FUNCTIONS_H
