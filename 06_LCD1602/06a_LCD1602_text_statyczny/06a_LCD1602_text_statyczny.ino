#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

void setup() {
  //Deklaracja typu wyświetlacza
  lcd.begin(16, 2);
  //Ustawienie kursora na pozycji 0, 0
  lcd.setCursor(0, 0);
  // Wyświetlenie napisu
  lcd.print("Zajecia");
  //Ustawienie kursora na pozycji 0, 1
    lcd.setCursor(0, 1);
  lcd.print("CoderDojo");
}

void loop() {
}


