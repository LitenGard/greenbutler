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

float Sensors::getTemperature() {
  return 666;
}

float Sensors::getHumidity() {
  return 777;
}

float Sensors::getSoilMoisture() {
    return 888;
}

