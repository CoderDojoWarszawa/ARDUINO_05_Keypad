#include <SPI.h>
#include <MFRC522.h>
#define SS_PIN 10
#define RST_PIN 9

MFRC522 rfid(SS_PIN, RST_PIN);

const byte poprawna_karta[] = {0x9E, 0xF9, 0xCE, 0x83};

void setup() {
  Serial.begin(9600);
  SPI.begin(); // Inicjalizacja szyny SPI
  rfid.PCD_Init(); // Inicjalizacja RC522
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
  if (rfid.uid.uidByte[0] == poprawna_karta[0] ||
      rfid.uid.uidByte[1] == poprawna_karta[1] ||
      rfid.uid.uidByte[2] == poprawna_karta[2] ||
      rfid.uid.uidByte[3] == poprawna_karta[3] )
  {
    // Poprawna karta
    Serial.println("Poprawna karta");
  }
  else
  {
    // Niepoprawna karta
    Serial.println("Niepoprawna karta!!!");
  }

  // Zatrzymanie odczytu karty RFID
  rfid.PICC_HaltA();
}
