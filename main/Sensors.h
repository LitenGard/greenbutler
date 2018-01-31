/*
 * Sensors.h - library for GreenButler specific sensor control
 * Copyright Marlon van der Linde <marlon250f@gmail.com> 2018
 */
#ifndef Sensors_h
#define Sensors_h

class Sensors
{
  public:
    Sensors();
    void begin();

    void getActualReadings();

    float getLastTemperature();
    float getLastHumidity();
    float getLastSoilMoisture();
    
  private:
    float lastTemperature;
    float lastHumidity;
    float lastSoilMoisture;
};

#endif

