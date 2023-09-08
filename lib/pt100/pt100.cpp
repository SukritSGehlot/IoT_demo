#include <PT100.h>
#define RREF      430.0
#define RNOMINAL  100.0
PT100::PT100(int csPin,int sdiPin,int sdoPin,int clkPin) : thermo(csPin, sdiPin, sdoPin, clkPin) {
}

PT100::~PT100(){
}

void PT100::begin() {
    thermo.begin(MAX31865_2WIRE); 
}
float PT100::readTemperature() {
    uint16_t rtd = readRTDValue();
    float ratio = rtd;
    ratio /= 32768;
    float resistance = RREF * ratio;
    float temperature = thermo.temperature(RNOMINAL, resistance);
    return temperature;
}

uint16_t PT100::readRTDValue() {
    return thermo.readRTD(); // Read and return the RTD value
}
void PT100::clearFault() {
    thermo.clearFault();
}


bool PT100::detectFault() {
    uint8_t fault = thermo.readFault();
    if (fault) {
        Serial1.print("Fault 0x"); Serial1.println(fault, HEX);
        if (fault & MAX31865_FAULT_HIGHTHRESH) {
            Serial1.println("RTD High Threshold");
        }
        if (fault & MAX31865_FAULT_LOWTHRESH) {
            Serial1.println("RTD Low Threshold");
        }
        if (fault & MAX31865_FAULT_REFINLOW) {
            Serial1.println("REFIN- > 0.85 x Bias");
        }
        if (fault & MAX31865_FAULT_REFINHIGH) {
            Serial1.println("REFIN- < 0.85 x Bias - FORCE- open");
        }
        if (fault & MAX31865_FAULT_RTDINLOW) {
            Serial1.println("RTDIN- < 0.85 x Bias - FORCE- open");
        }
        if (fault & MAX31865_FAULT_OVUV) {
            Serial1.println("Under/Over voltage");
        }
        clearFault();
        return true; // Fault exists, return true
    }

    return false; // No fault, return false
}


