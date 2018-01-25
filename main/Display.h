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
     * Updates the runScreen() layout with the given values for relay statuses.
     * @param bool pumpA Boolean indicator whether pump A is running or not
     * @param bool pumpB Boolean indicator whether pump B is running or not
     * @param bool fan Boolean indicator whether the fan is running or not
     * @param bool solenoid Boolean indicator whether the solenoid is open or not
     */
    void updateStatuses(bool pumpA, bool pumpB, bool fan, bool solenoid);

    /**
     * Updates the runScreen() layour with the given readings from the sensors with date and time.
     * @param float temp The current temperature reading
     * @param float humid The current humidity readings
     * @param float soilMost The current soil moisture reading
     * @param String The string representation of the RTC time
     * @param String The string representation of the RTC date
     */
    void updateSensorReadings(float temp, float humid, float soilMost, String realdate, String realtime);

  private:
    int muted = 0;

};

#endif

