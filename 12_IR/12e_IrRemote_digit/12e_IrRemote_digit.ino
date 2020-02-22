#include <IRremote.h>
#include <Servo.h>
#include <TM1637Display.h>

#define pin_IR 11
#define pin_Servo 9
#define CLK 6
#define DIO 7

// Tworzenie instancji klasy IRrecv o nazwie irrecv
IRrecv irrecv(pin_IR);
// Tworzenie instancji klasy decode_results o nazwie odczyt
// Tak naprawdę jest to zbiór zmiennych
decode_results odczyt;
// Tworzenie instancji klasy Servo o nazwie serwo
Servo serwo;
// Tworzenie instancji klasy TM1637Display o nazwie display
TM1637Display display(CLK, DIO); 

int pozycja = 90;
char znak;
char kanal[4];  // Ostatni element tablicy typu czar to null - dlatego deklaracja 4
int z = 0;
int liczba;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn(); // Aktywacja odczytu
  irrecv.blink13(true); // Po odebraniu kodu migaj diodą LED 13
  display.setBrightness(0x0A); // Ustawienie jasności wyświetlacza
  serwo.attach(pin_Servo);
  serwo.write(pozycja); // Ustawienie serwo na 90 stopni
  delay(1000);
}

void loop() {
  if (irrecv.decode(&odczyt) == true) {
    Serial.println(odczyt.value, HEX);
    // Porównywanie wartości w HEX. Przed liczbą HEX dajemy 0x
    switch (odczyt.value) {
      case 0xFF9867: znak = '0'; kanal[z] = znak; z++; break; // cyfra 0
      case 0xFFA25D: znak = '1'; kanal[z] = znak; z++; break; // cyfra 1
      case 0xFF629D: znak = '2'; kanal[z] = znak; z++; break; // cyfra 2
      case 0xFFE21D: znak = '3'; kanal[z] = znak; z++; break; // cyfra 3
      case 0xFF22DD: znak = '4'; kanal[z] = znak; z++; break; // cyfra 4
      case 0xFF02FD: znak = '5'; kanal[z] = znak; z++; break; // cyfra 5
      case 0xFFC23D: znak = '6'; kanal[z] = znak; z++; break; // cyfra 6
      case 0xFFE01F: znak = '7'; kanal[z] = znak; z++; break; // cyfra 7
      case 0xFFA857: znak = '8'; kanal[z] = znak; z++; break; // cyfra 8
      case 0xFF906F: znak = '9'; kanal[z] = znak; z++; break; // cyfra 9
      case 0xFF38C7:                                          // klawisz OK
        // Ustawienie na chwilę maksymalnej jasności celem potwierdzenia
        display.setBrightness(0x0F);
        display.showNumberDec(liczba, false, 4, 0);
        delay(500);
        display.setBrightness(0x0A);
        // Konwersja tablicy znakowej (same cyfry) na liczbę
        pozycja = atoi(kanal);
        serwo.write(pozycja);
        for (int i = 0; i < sizeof(kanal); i++) {
          kanal[i] = (char)0;
        }
        z = 0;
        break;
    }
    // Sprawdzanie czy są już 3 cyfry w tablicy.
    // Jeśli są 3 to zerujemy tablicę i wpisujemy tylko ostatni znak
    if (z >= 4) {
      for (int i = 0; i < sizeof(kanal); i++) {
        kanal[i] = (char)0;
      }
      z = 0;     
      kanal[z] = znak;
      z++;
    }
    // Przygotowanie do pobrania nowego kodu
    irrecv.resume();
  }
  // Konwersja tablicy znakowej (same cyfry) na liczbę
  liczba = atoi(kanal);
  // Wyświetlenie liczby na wyświetlaczu
  display.showNumberDec(liczba, false, 4, 0);
  delay(100);
}
