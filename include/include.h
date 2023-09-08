#if !defined(INCLUDE_H)
#define INCLUDE_H
    #include <ArduinoJson.h>
    #include <Arduino.h>
    #ifdef ESP32_ENABLED

    #endif
    #ifdef ARDUINO_MEGA_ENABLED
        #include <Wire.h> 
        #include <pt100.h>
        #include <HCSR04.h>
    #endif
#endif // INCLUDE_H

