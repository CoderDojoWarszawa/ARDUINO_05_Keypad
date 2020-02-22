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

// Stworzenie obiektu lcd który będzie naszym wyświetlaczem
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

// Definicja własnych znaków o rozmiarach 5x8 pixeli
byte ludek1[8] = {
  B01110,
  B01110,
  B00100,
  B01110,
  B00100,
  B00100,
  B01010,
  B10001
};
byte ludek2[8] = {
  B01110,
  B01110,
  B00100,
  B01110,
  B00100,
  B00100,
  B01010,
  B10010
};
byte ludek3[8] = {
  B01110,
  B01110,
  B00100,
  B01110,
  B00100,
  B00100,
  B01010,
  B01001
};
byte pilka[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B01100,
  B01100
};
// Pusty znak
byte pusty[8] = {
};
// Ustawienie czasu opoznienia
int czas=500;

void setup() {
  // Zapisz znaki w pamięci wyświetlacza.
  // W metodzie lcd.crateChar() mamy do dyspozycji 8 pozycji na zapisanie znaku (0-7)
  lcd.createChar(0, ludek1);
  lcd.createChar(1, ludek2);
  lcd.createChar(2, ludek3);
  lcd.createChar(5, pilka);
  lcd.createChar(7, pusty);
  // Inicjalizacja wyświetlacza
  lcd.begin(16, 2);
}

void loop() {
  // Napis w dolnej linijce
  lcd.setCursor(3,1);
  lcd.print("CoderDojo");
  // Umieść kursor w pozycji 0,0 - to samo co lcd.setCursor(0,0)  
  lcd.home();
  // Wyswietl znak 1 - co odpowiada mapie bitowej: ludek2
  lcd.write(1);
  lcd.write(5);
  lcd.setCursor(15,0);
  // Poprawny zapis lcd.write. Uzywac byte(0) zamiast 0
  lcd.write(byte(0));
  delay(czas);
  lcd.home();
  lcd.write(byte(0));
  lcd.write(5);
  delay(czas);
  // Pilka - ruch w prawo
  for (int i=1; i<14; i++){
    lcd.setCursor(i,0);
    lcd.write(7);
    //lcd.print(".");
    lcd.write(5);
    delay(czas);
  }
  lcd.setCursor(15,0);
  lcd.write(2);
  delay(czas);
  lcd.setCursor(15,0);
  lcd.write(byte(0));
  delay(czas);
  // Pilka ruch w lewo
  for (int i=13; i>0; i--){
    lcd.setCursor(i,0);
    lcd.write(5);
    lcd.write(7);
    delay(czas);
  }
}

