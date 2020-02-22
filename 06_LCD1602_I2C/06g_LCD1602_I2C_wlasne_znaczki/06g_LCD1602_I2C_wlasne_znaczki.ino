#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
// Definicja własnych znaków o rozmiarach 5x8 pixeli
byte mojZnak[] = {
  B00100,
  B00100,
  B00100,
  B01110,
  B01010,
  B01010,
  B11011,
  B11011
};
byte usmiech[8] = {
  B00000,
  B10001,
  B00000,
  B00000,
  B10001,
  B01110,
  B00000,
};

byte ludek[] = {
  B00100,
  B01010,
  B00100,
  B00100,
  B11111,
  B00100,
  B01010,
  B10001
};
byte fotel[] = {
  B01110,
  B01110,
  B01110,
  B10101,
  B11011,
  B00100,
  B01110,
  B10101
};
byte zegar[] = {
  B11111,
  B10001,
  B01010,
  B00100,
  B01010,
  B10101,
  B10001,
  B01110
};


void setup() {
  lcd.init();
  lcd.backlight();
  // Zapisz znaki w pamięci wyświetlacza.
  // W metodzie lcd.crateChar() mamy do dyspozycji 8 pozycji na zapisanie znaku (0-7)
  lcd.createChar(0, usmiech);
  lcd.createChar(1, mojZnak);
  lcd.home();
  // Wyświetl znak 0 - odwołanie do znaku na pozycji byte(0)
  lcd.write(0);
  // Umieść kursor w pozycji 1,0  
  lcd.setCursor(2,0);
  // Wyświetl znak 1 
  lcd.write(1);
  // Wyświetl kolejne znaki   
  lcd.setCursor(4,0);
  lcd.write(2);
  lcd.setCursor(6,0);
  lcd.write(3);
  lcd.setCursor(8,0);
  lcd.write(4);
}

void loop() {
}
