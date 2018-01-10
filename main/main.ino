
#include <LiquidCrystal.h>

LiquidCrystal lcd(0, 1, 2, 3, 4, 5);


void setup() {
  lcd.begin(16, 2);
  delay(500);
  lcd.setCursor(0, 0);
  lcd.print("Hello Karoo!");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("GreenButler v0.1");
}

void loop() {

}

