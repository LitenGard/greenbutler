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
     * Run screen template.
     * This is the layout of the run screen. Also see updateStatuses() which adds values to this screen.
     */
    void runScreen();

    /**
     * Updates the runScreen() layout with the given values.
     * @param bool pumpA Boolean indicator whether pump A is running or not
     * @param bool pumpB Boolean indicator whether pump B is running or not
     * @param bool fan Boolean indicator whether the fan is running or not
     * @param bool solenoid Boolean indicator whether the solenoid is open or not
     */
    void updateStatuses(bool pumpA, bool pumpB, bool fan, bool solenoid);

  private:
    int muted = 0;

};

#endif

