/*
   display.h - library for GreenButler specific display control
   Copyright Marlon van der Linde <marlon250f@gmail.com> 2018
*/
#include <LiquidCrystal.h>

#ifndef Display_h
#define Display_h

class Display
{
  public:
    LiquidCrystal lcd;

    Display();

    /**
       Construction and initialisation
    */
    void begin();

    /**
       Clear screen, cursor reset, and other specific preps for the LCD
    */
    void reset();

    /**
       Standard announcement
    */
    void announce(String message, int seconds);

    /**
       Toggles blank/Mute of the greenbutler display.
    */
    void mute();

    /**
     * Run screen template
     */
    void runScreen();

  private:
    int muted = 0;

};

#endif

