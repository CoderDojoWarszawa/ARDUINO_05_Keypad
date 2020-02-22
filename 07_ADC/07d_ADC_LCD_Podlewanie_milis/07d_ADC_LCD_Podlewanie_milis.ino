#include <LiquidCrystal.h>
#define pompka 10

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

 Czujnik wilgotności:
 +: +5V
 -: GND
 S: A1 
 */

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
// Deklaracja zmiennych pomocniczych
int progDzialania = 0;
int wilgotnoscGleby = 0;
int skalaDzialania = 0;
int skalaGleby = 0;
unsigned long aktualnyCzas = 0;
unsigned long zapamietanyCzas = 0;
unsigned long roznicaCzasu = 0;

void setup() {
  lcd.begin(16, 2);
  pinMode(pompka, OUTPUT);
}

void loop() { 
  // Wyłączenie pompki
  digitalWrite(pompka,HIGH);   
  // Odczyt wartości z potencjometru
  progDzialania = analogRead(A0);
  // Przemapowanie wartości z potencjometru
  skalaDzialania = map(progDzialania, 0, 1023, 0, 100);
  // Odczyt wartości z czujnika wilgotności
  wilgotnoscGleby = analogRead(A5);
  // Przemapowanie wartości z czujnika wilgotności
  skalaGleby = map(wilgotnoscGleby, 0, 800, 0, 100);
  // Wyświetlenie wilgotności i progu zadziałania na LCD
  lcd.home();
  lcd.print("Wilgotnosc:     ");
  lcd.setCursor(12, 0);
  lcd.print(skalaGleby);
  lcd.print(" %");
  lcd.setCursor(0, 1);
  lcd.print("Prog:           ");
  lcd.setCursor(6, 1);
  lcd.print(skalaDzialania);
  lcd.print(" %");
  // Aktualny czas z użyciem funkcji millis()
  aktualnyCzas = millis();
  roznicaCzasu = aktualnyCzas - zapamietanyCzas;
  // Uruchamianie pompki nie częściej niż co 5 sekund
  if (roznicaCzasu >= 5000UL) {
    zapamietanyCzas = aktualnyCzas;
    // Jeśli wilgotność gleby jest poniżej progu to włącz pompkę
    if (skalaGleby < skalaDzialania){
      lcd.setCursor(0, 1);
      lcd.print("Pompka wlaczona");
      digitalWrite(pompka,LOW);
      delay(1000);
    } 
  }
  // Krótka przerwa między pomiarami
  delay(200);
}


