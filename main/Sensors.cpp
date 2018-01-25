/*
   Sensors.cpp - library for GreenButler specific sensor control
   Copyright Marlon van der Linde <marlon250f@gmail.com> 2018
*/

#include "Sensors.h"
#include "Arduino.h"

Sensors::Sensors() {
  begin();
}

void Sensors::begin() {
    // Initialise the sensor pins for input.
    // todo
}

/** 
 * Read actual sensor values and store them in the instance variables for later retrieval. 
 * This is intended to be read on a periodic basis, remember that some sensors take longer than others
 * to get output.
 */
void getActualReadings() {
  // read the temp

  // read the humidity

  // read the soil moisture
}

/**
 * Simply return the last reading from the temperature sensor
 */
float Sensors::getLastTemperature() {
  return this->lastTemperature;
}

/**
 * Simply return the last reading from the humidity sensor
 */
float Sensors::getLastHumidity() {
  return this->lastHumidity;
}

/**
 * Simply return the last reading from the soil moisture sensor
 */
float Sensors::getLastSoilMoisture() {
    return this->lastSoilMoisture;
}

