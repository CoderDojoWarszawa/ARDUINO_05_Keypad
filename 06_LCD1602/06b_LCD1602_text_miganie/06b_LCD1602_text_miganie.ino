#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Zajecia");
  lcd.setCursor(0, 1);
  lcd.print("CoderDojo");
}
void loop() {
  lcd.noDisplay(); //Wyłącz wyświetlacz
  delay(500);
  lcd.display(); //Włącz wyświetlacz
  delay(500);
}



