#include <LiquidCrystal.h>

#ifndef display_h
#define display_h

class Display
{
  public:
    LiquidCrystal lcd;
    
    Display();

    /**
     * Construction and initialisation
     */
    void begin();

    /**
     * Clear screen, cursor reset, and other specific preps for the LCD
     */
    void reset();

  private:
    
};

#endif

