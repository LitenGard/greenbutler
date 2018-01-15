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
  display.announce("relays init ", 1);
  relay.begin();
  display.reset();
}

void loop() {

}

