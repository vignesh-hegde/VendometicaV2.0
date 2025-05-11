#include <WaterHeater.hpp>

cWaterHeater *cWaterHeater::smpInstance = NullPtr;

cWaterHeater::cWaterHeater() : mMaxHeatingTemperature(0), mIdleTemperature(0), mpHeaterTimer(NullPtr), mIsHeaterEnabled(true)
{
    mpOneWire = new cOneWire(TEMPERATURE_SENSOR);
    mpTemperatureSensors = new cDallasTemperature(mpOneWire);
    pinMode(HEATER_COIL, OUTPUT);
    StopHeater();
}

cWaterHeater::~cWaterHeater()
{
    delete mpOneWire;
    delete mpTemperatureSensors;
    mpOneWire = NullPtr;
    mpTemperatureSensors = NullPtr;
}

void IRAM_ATTR cWaterHeater::SetAlarmCallback()
{
    if(cWaterHeater::smpInstance != NULL)
    {
        cWaterHeater::smpInstance->SetAlarm();
    }
}

void IRAM_ATTR cWaterHeater::SetAlarm()
{
    // Stop power supply to heating Coil
    DisableHeater();
    // IEC104 Send ERROR TO SERVER
}

UInt32 cWaterHeater::GetWaterTemperatureC(void)
{
    return (UInt32)(mpTemperatureSensors->getTempCByIndex(0));
}

void cWaterHeater::StartHeater()
{
    StopHeater();
    if (mIsHeaterEnabled)
    {
        smpInstance = this;
        
        mpHeaterTimer = timerBegin(0, 80, true);
        timerAttachInterrupt(mpHeaterTimer, &(cWaterHeater::SetAlarmCallback), true);
        timerAlarmWrite(mpHeaterTimer, MAX_ALLOWED_HEATING_PERIOD, true);
        timerAlarmEnable(mpHeaterTimer);
        
        digitalWrite(HEATER_COIL, HIGH);
        while (mMaxHeatingTemperature > GetWaterTemperatureC());
        StopHeater();
    }
}

void cWaterHeater::StopHeater()
{
    digitalWrite(HEATER_COIL, LOW);
}