/*
   Relay.cpp - library for GreenButler specific relay control
   Copyright Marlon van der Linde <marlon250f@gmail.com> 2018
*/
#include "Relay.h"
#include "Arduino.h"

Relay::Relay()
{
  begin();
}

void Relay::begin()
{
  // Initialise the relay pins for output.
  pinMode(PIN_RELAY1_SOLENOID, OUTPUT);
  pinMode(PIN_RELAY2_FAN, OUTPUT);
  pinMode(PIN_RELAY3_PUMP_A, OUTPUT);
  pinMode(PIN_RELAY4_PUMP_B, OUTPUT);
}

int Relay::startPumpA()
{

}

int Relay::startPumpB()
{

}

int Relay::startFan()
{

}

int Relay::openSolenoid() {

}

int Relay::stopPumpA()
{
  int state = 0;

  if (this->statePumpA || (digitalRead(PIN_RELAY3_PUMP_A) == HIGH)) {
    state = 1;
  } else {
    state = -1;
  }

  this->statePumpA = false;
  digitalWrite(PIN_RELAY3_PUMP_A, LOW);
  return state;
}

int Relay::stopPumpB()
{
  int state = 0;

  if (this->statePumpB || (digitalRead(PIN_RELAY4_PUMP_B) == HIGH)) {
    state = 1;
  } else {
    state = -1;
  }

  this->statePumpB = false;
  digitalWrite(PIN_RELAY4_PUMP_B, LOW);
  return state;
}

int Relay::stopFan()
{
  int state = 0;

  if (this->stateFan || (digitalRead(PIN_RELAY2_FAN) == HIGH)) {
    state = 1;
  } else {
    state = -1;
  }

  this->stateFan = false;
  digitalWrite(PIN_RELAY2_FAN, LOW);
  return state;
}

/**
   Close(deactivate) the solenoid.
   If the state claims it is already closed, -1 is returned, and an attempt to close it is made anyway and the state updated.
   Normally, in good cases, 1 is returned.
   @returns int
*/
int Relay::closeSolenoid()
{
  int state = 0;

  if (this->stateSolenoid || (digitalRead(PIN_RELAY1_SOLENOID) == HIGH)) {
    state = 1;
  } else {
    state = -1;
  }

  this->stateSolenoid = false;
  digitalWrite(PIN_RELAY1_SOLENOID, LOW);
  return state;
}

bool Relay::statusPumpA()
{
  this->statePumpA = false;
  if (digitalRead(PIN_RELAY3_PUMP_A) == HIGH) {
    this->statePumpA = true;
  }
  return this->statePumpA;
}

bool Relay::statusPumpB()
{
  this->statePumpB = false;
  if (digitalRead(PIN_RELAY4_PUMP_B) == HIGH) {
    this->statePumpB = true;
  }
  return this->statePumpB;
}

bool Relay::statusFan()
{
  this->stateFan = false;
  if (digitalRead(PIN_RELAY2_FAN) == HIGH) {
    this->stateFan = true;
  }
  return this->stateFan;
}

bool Relay::statusSolenoid()
{
  this->stateSolenoid = false;
  if (digitalRead(PIN_RELAY1_SOLENOID) == HIGH) {
    this->stateSolenoid = true;
  }
  return this->stateSolenoid;
}

