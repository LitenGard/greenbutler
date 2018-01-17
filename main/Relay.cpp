/*
   Relay.cpp - library for GreenButler specific relay control
   Copyright Marlon van der Linde <marlon250f@gmail.com> 2018
*/
#include "Relay.h"
#include "Arduino.h"
#include "parameters.h"

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

void Relay::startPumpA()
{
  digitalWrite(PIN_RELAY3_PUMP_A, HIGH);
  this->statePumpA = true;
}

void Relay::startPumpB()
{
  digitalWrite(PIN_RELAY4_PUMP_B, HIGH);
  this->statePumpB = true;
}

void Relay::startFan()
{
  digitalWrite(PIN_RELAY2_FAN, HIGH);
  this->stateFan = true;
}

void Relay::openSolenoid()
{
  digitalWrite(PIN_RELAY1_SOLENOID, HIGH);
  this->stateSolenoid = true;
}

void Relay::stopPumpA()
{
  digitalWrite(PIN_RELAY3_PUMP_A, LOW);
  this->statePumpA = false;
}

void Relay::stopPumpB()
{
  digitalWrite(PIN_RELAY4_PUMP_B, LOW);
  this->statePumpB = false;
}

void Relay::stopFan()
{
  digitalWrite(PIN_RELAY2_FAN, LOW);
  this->stateFan = false;
}

void Relay::closeSolenoid()
{
  digitalWrite(PIN_RELAY1_SOLENOID, LOW);
  this->stateSolenoid = false;
}

bool Relay::statusPumpA()
{
  this->statePumpA = digitalRead(PIN_RELAY3_PUMP_A);
  return this->statePumpA;
}

bool Relay::statusPumpB()
{
  this->statePumpB = digitalRead(PIN_RELAY4_PUMP_B);
  return this->statePumpB;
}

bool Relay::statusFan()
{
  this->stateFan = digitalRead(PIN_RELAY2_FAN);
  return this->stateFan;
}

bool Relay::statusSolenoid()
{
  this->stateSolenoid = digitalRead(PIN_RELAY1_SOLENOID);
  return this->stateSolenoid;
}

