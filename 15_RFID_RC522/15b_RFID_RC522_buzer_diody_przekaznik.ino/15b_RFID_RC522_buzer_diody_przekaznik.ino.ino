#include <SPI.h>
#include <MFRC522.h>
#define SS_PIN 10
#define RST_PIN 9
#define LED_Zielona 6
#define LED_Czerwona 7
#define Przekaznik 8

MFRC522 rfid(SS_PIN, RST_PIN);

const byte poprawna_karta[] = {0x9E, 0xF9, 0xCE, 0x83};

void setup() {
  Serial.begin(9600);
  SPI.begin(); // Inicjalizacja szyny SPI
  rfid.PCD_Init(); // Inicjalizacja RC522
  pinMode(LED_Zielona, OUTPUT);
  pinMode(LED_Czerwona, OUTPUT);
  pinMode(Przekaznik, OUTPUT);
  digitalWrite(Przekaznik, HIGH);
  pinMode(A0, OUTPUT);
}

void loop() {
  // Szukanie nowej karty RFID
  if ( ! rfid.PICC_IsNewCardPresent())
    return;

  // Pobranie UID z karty
  if ( ! rfid.PICC_ReadCardSerial())
    return;

  // Wysłanie UID karty na serial
  Serial.print("UID: ");
  for (int i = 0; i < rfid.uid.size; i++) {
    Serial.print(rfid.uid.uidByte[i], HEX);
    Serial.print(" ");
  }
  Serial.println("");

  // Porównanie UID karty z zapisanym w pamięci
  if (rfid.uid.uidByte[0] == poprawna_karta[0] &&
      rfid.uid.uidByte[1] == poprawna_karta[1] &&
      rfid.uid.uidByte[2] == poprawna_karta[2] &&
      rfid.uid.uidByte[3] == poprawna_karta[3] )
  {
    // Poprawna karta
    Serial.println("Poprawna karta");
    digitalWrite(LED_Zielona, HIGH);
    digitalWrite(Przekaznik, LOW);
    tone(A0, 2800);
    delay(100);
    noTone(A0);
    delay(1000);
    delay(1500);
    digitalWrite(LED_Zielona, LOW);
    digitalWrite(Przekaznik, HIGH);
  }
  else
  {
    // Niepoprawna karta
    Serial.println("Niepoprawna karta!!!");
    digitalWrite(LED_Czerwona, HIGH);
    for (int i = 0; i <= 4; i++) {
      tone(A0, 4300);
      delay(150);
      tone(A0, 3500);
      delay(150);
    }
    noTone(A0);
    digitalWrite(LED_Czerwona, LOW);
  }

  // Zatrzymanie odczytu karty RFID
  rfid.PICC_HaltA();
}
