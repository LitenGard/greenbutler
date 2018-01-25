/*
   display.cpp - library for GreenButler specific display control
   Copyright Marlon van der Linde <marlon250f@gmail.com> 2018
*/
#include <LiquidCrystal.h>
#include "Arduino.h"
#include "Display.h"
#include "parameters.h"

/**
   lcd parameters:
   rs, enable, d4, d5, d6, d7
*/
Display::Display() : lcd(PIN_LCD_RS, PIN_LCD_ENABLE, PIN_LCD_D4, PIN_LCD_D5, PIN_LCD_D6, PIN_LCD_D7) {
  lcd.begin(LCD_CHARS, LCD_LINES);
}

void Display::begin() {
  delay(500);
  lcd.home();
  lcd.print(SYS_GREETING);
  delay(800);
  lcd.setCursor(0, 1);
  lcd.print(SYS_NAME_VERSION);
  delay(600);
}

void Display::reset() {
  lcd.clear();
  lcd.home();
}

void Display::mute() {
  if (muted)
    lcd.display();
  else
    lcd.noDisplay();
  muted = !muted;
}

void Display::updateStatuses(bool pumpA, bool pumpB, bool fan, bool solenoid) {
  String pumpAVal = (pumpA == true) ? "on" : "off";
  String pumpBVal = (pumpB == true) ? "on" : "off";
  String fanVal = (fan == true) ? "on" : "off";
  String solenoidVal = (solenoid == true) ? "open" : "clsd";

  // Set label positions, print labels.
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(NAME_PUMP_A);
  
  lcd.setCursor(0,1);
  lcd.print(NAME_PUMP_B);

  lcd.setCursor(7,0);
  lcd.print(NAME_FAN);

  lcd.setCursor(7,1);
  lcd.print(NAME_SOLENOID);  

  // set value positions and print values
  lcd.setCursor(3, 0);
  lcd.print(pumpAVal);
  lcd.setCursor(3, 1);
  lcd.print(pumpBVal);

  lcd.setCursor(12, 0);
  lcd.print(fanVal);

  lcd.setCursor(12, 1);
  lcd.print(solenoidVal);
}

void Display::updateSensorReadings(float temp, float humid, float soilMost, String realdate, String realtime) {
}

void Display::announce(String message, int seconds) {
  // todo - announce on same location/line everytime
  lcd.blink();
  lcd.print(message);
  delay(seconds * 1000);
  lcd.noBlink();
}

