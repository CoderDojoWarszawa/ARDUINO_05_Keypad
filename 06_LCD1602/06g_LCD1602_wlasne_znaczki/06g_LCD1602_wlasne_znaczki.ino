#include <LiquidCrystal.h>

/*
 Wyświetlacz podłączenie:
 VSS - masa - GND
 VDD - zasilanie +5V
 V0 - kontrast - potencjometr do +5V i GND 
 RS - pin 2 - wybór rejestrów (komenda, dane)
 RW - masa - GND
 E - pin 3 - zezwolenie na zapis do rejestrów
 D4 - pin 4 - dane
 D5 - pin 5 - dane
 D6 - pin 6 - dane
 D7 - pin 7 - dane
 A - zasilanie +5V - zasilanie podświetlenia
 K - masa GND - masa podświetlenia  
 */

// Inicjalizacja biblioteki - stworzenie obiektu lcd który będzie naszym wyświetlaczem
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

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
  // Zapisz znaki w pamięci wyświetlacza.
  // W metodzie lcd.crateChar() mamy do dyspozycji 8 pozycji na zapisanie znaku (0-7)
  lcd.createChar(0, usmiech);
  lcd.createChar(1, mojZnak);
  lcd.createChar(2, ludek);
  lcd.createChar(3, fotel);
  lcd.createChar(4, zegar);
  // Inicjalizacja wyświetlacza
  lcd.begin(16, 2);
  // Umieść kursor w pozycji 0,0 - to samo co lcd.setCursor(0,0)  
  lcd.home();
  // Wyświetl znak 0 - odwołanie do znaku na pozycji byte(0)
  lcd.write(byte(0));
  // Umieść kursor w pozycji 1,0  
  lcd.setCursor(2,0);
  // Wyświetl znak 1 
  lcd.write(byte(1));
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


