/*
 * Relay.cpp - library for GreenButler specific relay control
 * Copyright Marlon van der Linde <marlon250f@gmail.com> 2018
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
  pinMode(PIN_RELAY1, OUTPUT);       
  pinMode(PIN_RELAY2, OUTPUT);
  pinMode(PIN_RELAY3, OUTPUT);
  pinMode(PIN_RELAY4, OUTPUT);
}

void Relay::startPumpA()
{
  
}

void Relay::startPumpB()
{
  
}

void Relay::startFanA()
{
  
}

void Relay::openSolenoid() {
  
}

void Relay::stopPumpA()
{
  
}

void Relay::stopPumpB()
{
  
}

void Relay::stopFanA()
{
  
}

void Relay::closeSolenoid()
{
  
}

int Relay::statusPumpA()
{
  
}

int Relay::statusPumpB()
{
  
}

int Relay::statusFanA()
{
  
}

int Relay::statusSolenoid()
{
  
}

