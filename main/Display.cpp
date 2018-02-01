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
  char *pumpAVal = (pumpA == true) ? "on" : "off";
  char *pumpBVal = (pumpB == true) ? "on" : "off";
  char *fanVal = (fan == true) ? "on" : "off";
  char *solenoidVal = (solenoid == true) ? "open" : "clsd";

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

void Display::updateSensorReadings(float temp, float humid, float soilMoist, char* realdate, char* realtime) {
  soilMoist = (soilMoist > 99) ? 99 : soilMoist;
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print('t');
  lcd.setCursor(2,0);
  lcd.print((int)temp);
  lcd.setCursor(4,0);
  lcd.print((char)223); // degrees symbol
  
  lcd.setCursor(6,0);
  lcd.print((char)64);  // @ symbol
  lcd.setCursor(8,0);
  lcd.print((int)humid);

  lcd.setCursor(11,0);
  lcd.print('m');
  lcd.setCursor(13,0);
  lcd.print((int)soilMoist);
  lcd.setCursor(15,0);
  lcd.print('%');

  lcd.setCursor(0,1);
  lcd.print(realdate);

  lcd.setCursor(10,1);
  lcd.print(realtime);  
}

void Display::showReadingIndicator() {
  lcd.setCursor(15,1);
  lcd.print("*");  
}

void Display::clearReadingIndicator() {
  lcd.setCursor(16,1);
  lcd.print(" ");  
}

