/*
 * Relay.h - library for GreenButler specific relay control
 * Copyright Marlon van der Linde <marlon250f@gmail.com> 2018
 */
#ifndef Relay_h
#define Relay_h

#define PIN_RELAY1_SOLENOID  8                        
#define PIN_RELAY2_FAN  9                        
#define PIN_RELAY3_PUMP_A  10                        
#define PIN_RELAY4_PUMP_B  11

class Relay
{
  public:
    Relay();
    void begin();

    // Functions pertaining to starting and activating relay controlled devices
    int startPumpA();
    int startPumpB();
    int startFan();
    int openSolenoid();

    // Functions for stopping and deactivating relay controlled devices
    int stopPumpA();
    int stopPumpB();
    int stopFan();
    int closeSolenoid();

    // Functions for checking the current status of relay controlled devices
    bool statusPumpA();
    bool statusPumpB();
    bool statusFan();
    bool statusSolenoid();

  private:
    bool statePumpA = 0;
    bool statePumpB = 0;
    bool stateFan = 0;
    bool stateSolenoid = 0;
  
};

#endif
