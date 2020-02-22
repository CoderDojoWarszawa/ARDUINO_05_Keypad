#include <SimpleDHT.h>
#define pinCzujnik 7
SimpleDHT11 dht11;

void setup() {
  Serial.begin(9600);
}
void loop() {  
  byte temperatura = 0;
  byte wilgotnosc = 0;
  int err = 0;
  //Pobranie zmierzonych wartości temperatury i wilgotności
  err = dht11.read(pinCzujnik, &temperatura, &wilgotnosc, NULL);
  if (err == 0){
  Serial.print("DHT11  ");
  Serial.print(temperatura); Serial.print(" *C  ");
  Serial.print(wilgotnosc); Serial.println(" %RH");
  }else{
    Serial.println("Błąd odczytu");
  }
  delay(2000);
}


