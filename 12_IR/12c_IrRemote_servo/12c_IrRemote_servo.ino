#include <IRremote.h>
#include <Servo.h>
#define pin_IR 11
#define Red 2
#define Yellow 3
#define Green 4
#define pin_Servo 9

// Tworzenie instancji klasy IRrecv o nazwie irrecv
IRrecv irrecv(pin_IR);
// Tworzenie instancji klasy decode_results o nazwie odczyt
// Tak naprawdę jest to zbiór zmiennych
decode_results odczyt;
// Tworzenie instancji klasy Servo o nazwie serwo
Servo serwo;

int pozycja = 90;
int zmiana = 0;

void setup() {
  Serial.begin(9600);
  serwo.attach(pin_Servo);
  irrecv.enableIRIn(); // Aktywacja odczytu
  irrecv.blink13(true); // Po odebraniu kodu migaj diodą LED 13
  serwo.write(pozycja); // Ustawienie serwo na 90 stopni
  delay(1000);
  // Inicjacja LED
  pinMode(Red, OUTPUT);
  pinMode(Yellow, OUTPUT);
  pinMode(Green, OUTPUT);
  digitalWrite(Red, LOW);
  digitalWrite(Yellow, LOW);
  digitalWrite(Green, LOW);
}

// Funkcja realizująca miganie diodą
void miganieLED (int dioda) {
  for (int i = 0; i < 3; i++) {
    digitalWrite(dioda, HIGH);
    delay(100);
    digitalWrite(dioda, LOW);
    delay(100);
  }
}

void loop() {
  // Jeśli są jakieś dane odebrane to zwracane jest TRUE
  // Odczytane dane są podstawiane do odczyt
  if (irrecv.decode(&odczyt)) {
    // Wysłanie na serial odczytanego kodu w postaci HEX
    Serial.println(odczyt.value, HEX);
    // Sprawdzanie który klawisz został naciśnięty
    // Porównywanie wartości w HEX. Przed liczbą HEX dajemy 0x
    switch (odczyt.value) {
      // UWAGA. Kody przycisków zmienić dla posiadanego pilota
      case 0xFFA25D: digitalWrite(Red, HIGH); break;    // cyfra 1
      case 0xFF629D: digitalWrite(Yellow, HIGH); break; // cyfra 2
      case 0xFFE21D: digitalWrite(Green, HIGH); break;  // cyfra 3
      case 0xFF22DD: digitalWrite(Red, LOW); break;     // cyfra 4
      case 0xFF02FD: digitalWrite(Yellow, LOW); break;  // cyfra 5
      case 0xFFC23D: digitalWrite(Green, LOW); break;   // cyfra 6
      case 0xFFE01F: miganieLED(Red); break;            // cyfra 7
      case 0xFFA857: miganieLED(Yellow); break;         // cyfra 8
      case 0xFF906F: miganieLED(Green); break;          // cyfra 9
      case 0xFF5AA5: zmiana = 1; break;                 // lewo
      case 0xFF10EF: zmiana = -1; break;                // prawo
      case 0xFF4AB5: zmiana = 0; break;                 // do dołu
      case 0xFF18E7: zmiana = 0; pozycja = 90; break;   // do góry
    }
    // Przygotowanie do pobrania nowego kodu
    irrecv.resume();
  }
  // Obliczenie nowej pozycji
  pozycja = pozycja + zmiana;
  // Zabezpieczenie przed za dużym lub za małym kątem
  if (pozycja > 179) {
    pozycja = 179;
  }
  if (pozycja < 0) {
    pozycja = 0;
  }
  // Sterowanie silnikiem
  serwo.write(pozycja);
  delay(10);
}

