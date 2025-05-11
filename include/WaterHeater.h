#ifndef WaterHeater_H
#define WaterHeater_H
#define MAX_ALLOWED_HEATING_PERIOD (1000000 * MAX_ALLOWED_HEATING_PERIOD_SEC)
#include <VendometicaConfig.h>
#include <OneWire.h>
#include <DallasTemperature.h>

typedef OneWire cOneWire;
typedef DallasTemperature cDallasTemperature;

class cWaterHeater
{
private:

    hw_timer_t *mpHeaterTimer; 
    Float32 mIdleTemperature;
    Float32 mMaxHeatingTemperature;
    bool mIsHeaterEnabled;
    cOneWire *mpOneWire;
    cDallasTemperature *mpTemperatureSensors;
    void DisableHeater(){mIsHeaterEnabled = false;}
    UInt32 GetWaterTemperatureC(void);
    void SetAlarm();
    static void IRAM_ATTR SetAlarmCallback(); 
    static cWaterHeater *smpInstance;

public:
    cWaterHeater();
    ~cWaterHeater();
    
    inline void SetIdleTemperatureC(Float32 Temperature){ mIdleTemperature = Temperature;}
    void SetHeatingTemperatureC(Float32 Temperature){ mMaxHeatingTemperature = Temperature;}
    void StartHeater();
    void StopHeater();
};

#endif
