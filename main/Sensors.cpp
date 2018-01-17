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

int Sensors::getTemperature() {
  return 666;
}

int Sensors::getHumidity() {
  return 777;
}

int Sensors::getSoilMoisture() {
    return 888;
}

