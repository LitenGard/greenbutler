/*
 * Relay.h - library for GreenButler specific relay control
 * Copyright Marlon van der Linde <marlon250f@gmail.com> 2018
 */
#ifndef Relay_h
#define Relay_h

#define PIN_RELAY1  8                        
#define PIN_RELAY2  9                        
#define PIN_RELAY3  10                        
#define PIN_RELAY4  11

class Relay
{
  public:
    Relay();
    void begin();

    // Functions pertaining to starting and activating relay controlled devices
    void startPumpA();
    void startPumpB();
    void startFanA();
    void openSolenoid();

    // Functions for stopping and deactivating relay controlled devices
    void stopPumpA();
    void stopPumpB();
    void stopFanA();
    void closeSolenoid();

    // Functions for checking the current status of relay controlled devices
    int statusPumpA();
    int statusPumpB();
    int statusFanA();
    int statusSolenoid();

  private:
  
};

#endif
