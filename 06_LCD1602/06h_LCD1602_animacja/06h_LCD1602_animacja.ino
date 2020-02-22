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
  // Inicjalizacja wyświetlacza
  lcd.begin(16, 2);
}

void loop() {
  lcd.clear();
  // Umieść kursor w pozycji 0,0 - to samo co lcd.setCursor(0,0)  
  lcd.setCursor(0,0);
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


