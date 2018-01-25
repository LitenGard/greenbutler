/*
 * Sensors.h - library for GreenButler specific sensor control
 * Copyright Marlon van der Linde <marlon250f@gmail.com> 2018
 */
#ifndef Sensors_h
#define Sensors_h

// @todo pin numbers
#define PIN_SENSOR_TEMP 0
#define PIN_SENSOR_HUMID 0
#define PIN_SENSOR_SOIL 0


class Sensors
{
  public:
    Sensors();
    void begin();

    float getTemperature();
    float getHumidity();
    float getSoilMoisture();
    
  private:
    int lastTemperature;
    int lastHumidity;
    int lastSoilMoisture;
};

#endif

