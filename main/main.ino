#include <LiquidCrystal.h>
#include "parameters.h"
#include "Display.h"
#include "Relay.h"

Display display;
Relay relay;

void setup() {
  display.begin();
  delay(500);
  display.reset();
  relay.begin();
  display.reset();
  display.runScreen();
  
  delay(600);
  display.updateStatuses(true,false,false,false);

}

void loop() {

}

