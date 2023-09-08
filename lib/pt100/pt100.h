#if !defined(PT100_H)
#define PT100_H
    #include <Adafruit_MAX31865.h>
    class PT100{
    private:
        Adafruit_MAX31865 thermo;
        void clearFault();
        uint16_t readRTDValue();
    public:
        PT100(int csPin,int sdiPin,int sdoPin,int clkPin);
        ~PT100();
        void begin();
        float readTemperature();
        bool detectFault(); 
    };
#endif // PT100_H
