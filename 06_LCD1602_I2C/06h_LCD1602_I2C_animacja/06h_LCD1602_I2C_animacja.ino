#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

// Definicja własnych znaków o rozmiarach 5x8 pixeli
byte obraz0[8] = {
  B01110,
  B00100
};
byte obraz1[8] = {
  B00100,
  B11111,
  B01110,
  B00100
};
byte obraz2[8] = {
  B00100,
  B00100,
  B00100,
  B11111,
  B01110,
  B00100
};
byte obraz3[] = {
  B00100,
  B00100,
  B00100,
  B00100,
  B00100,
  B11111,
  B01110,
  B00100
};
byte obraz4[] = {
  B00000,
  B00000,
  B00100,
  B00100,
  B00100,
  B00100,
  B00100,
  B11111
};
byte obraz5[] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00100,
  B00100,
  B00100,
  B00100
};
byte obraz6[] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00100,
  B00100
};
byte obraz7[8] = {
};
// Ustawienie czasu opoznienia
int czas=500;

void setup() {
  lcd.init();
  lcd.backlight();
  // Zapisz znaki w pamięci wyświetlacza.
  // W metodzie lcd.crateChar() mamy do dyspozycji 8 pozycji na zapisanie znaku (0-7)
  lcd.createChar(0, obraz0);
  lcd.createChar(1, obraz1);
  lcd.createChar(2, obraz2);
  lcd.createChar(3, obraz3);
  lcd.createChar(4, obraz4);
  lcd.createChar(5, obraz5);
  lcd.createChar(6, obraz6);
  lcd.createChar(7, obraz7); 

}

void loop() {
  lcd.home();
  // Wyświetl klatke 0 - odwołanie do znaku na pozycji byte(0)
  lcd.write(byte(0));
  delay(czas);
  // Wyświetl klatke 1
  lcd.setCursor(0,0);
  lcd.write(byte(1));
  delay(czas);
  // Wyświetl klatke 2
  lcd.setCursor(0,0);
  lcd.write(byte(2));
  delay(czas);
  // Wyświetl klatke 3
  lcd.setCursor(0,0);
  lcd.write(byte(3));
  delay(czas);
  // Wyświetl klatke 4
  lcd.setCursor(0,0);
  lcd.write(byte(4));
  lcd.setCursor(0,1);
  lcd.write(byte(1));
  delay(czas);
  // Wyświetl klatke 5
  lcd.setCursor(0,0);
  lcd.write(byte(5));
  lcd.setCursor(0,1);
  lcd.write(byte(2));
  delay(czas);
  // Wyświetl klatke 6
  lcd.setCursor(0,0);
  lcd.write(byte(6));
  lcd.setCursor(0,1);
  lcd.write(byte(3));
  delay(czas);
  // Wyświetl klatke 7
  lcd.setCursor(0,0);
  lcd.write(byte(7));
  lcd.setCursor(0,1);
  lcd.write(byte(4));
  delay(czas);
  // Wyświetl klatke 8
  lcd.setCursor(0,1);
  lcd.write(byte(5));
  delay(czas);
  // Wyświetl klatke 9
  lcd.setCursor(0,1);
  lcd.write(byte(6));
  delay(czas);
  // Wyświetl klatke 10
  lcd.setCursor(0,1);
  lcd.write(byte(7));
  delay(czas);
}
