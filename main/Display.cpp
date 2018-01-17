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
Display::Display() : lcd(2, 3, 4, 5, 6, 7) {
  lcd.begin(LCD_CHARS, LCD_LINES);
}

void Display::begin() {
  delay(500);
  lcd.home();
  lcd.print(SYS_GREETING);
  delay(500);
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print(SYS_NAME_VERSION);
  delay(500);
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

void Display::runScreen() {
  lcd.setCursor(0,0);
  lcd.print(NAME_PUMP_A);
  
  lcd.setCursor(0,1);
  lcd.print(NAME_PUMP_B);

  lcd.setCursor(7,0);
  lcd.print(NAME_FAN);

  lcd.setCursor(7,1);
  lcd.print(NAME_SOLENOID);  
}

void Display::updateStatuses(bool pumpA, bool pumpB, bool fan, bool solenoid) {

  String pumpAVal = (pumpA == true) ? "on" : "off";
  String pumpBVal = (pumpB == true) ? "on" : "off";
  String fanVal = (fan == true) ? "on" : "off";
  String solenoidVal = (solenoid == true) ? "open" : "clsd";
  
  lcd.setCursor(3, 0);
  lcd.print(pumpAVal);
  lcd.setCursor(3, 1);
  lcd.print(pumpBVal);

  lcd.setCursor(12, 0);
  lcd.print(fanVal);

  lcd.setCursor(12, 1);
  lcd.print(solenoidVal);
}

void Display::announce(String message, int seconds) {
  // todo - announce on same location/line everytime
  lcd.blink();
  lcd.print(message);
  delay(seconds * 1000);
  lcd.noBlink();
}

