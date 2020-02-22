#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  //Inicjacja wyświetlacza
  lcd.init();
  //Włączenie podświetlenia
  lcd.backlight();
  //Ustawienie kursora na pozycji 0, 0
  lcd.home();
  // Wyświetlenie napisu
  lcd.print("Zajecia");
  //Ustawienie kursora na pozycji 0, 1
  lcd.setCursor(0, 1);
  lcd.print("CoderDojo");
}
void loop() {
}


