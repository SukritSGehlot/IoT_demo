#if !defined(CONFIG_H)
#define CONFIG_H
    #include <include.h>
    #ifdef ESP32_ENABLED
        #define ssid "your SSID"   
        #define password "Your Password" 
        #define MQTT_SERVER "Your MQTT broker ip" 
        #define MQTT_PORT 1883 
        #define MQTT_TOPIC "your MQTT topic" 
        WiFiClient espClient;
        PubSubClient client(espClient);
    #endif

    #ifdef ARDUINO_MEGA_ENABLED
        #define CLK 13
        #define SDO  12
        #define SDI  11
        #define CS  10
        #define trig 5
        #define echo 6

        PT100 pt100(CS, SDI,SDO, CLK);
        HCSR04 ultra_sonic(trig,echo);
    #endif
#endif // CONFIG_H

