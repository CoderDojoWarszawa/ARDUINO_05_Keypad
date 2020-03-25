#include <TM1637Display.h>
#define CLK 2
#define DIO 3
TM1637Display display(CLK, DIO);

//Deklaracja zmiennej
byte licznik = 0; 

void setup() {
  // Inicjacja komunikacji serial 
  Serial.begin(9600);
  Serial.println("Inicjacja komunikacji");
  display.setBrightness(0x09);
}

void loop() {
  //Wysłanie wartości zmiennej licznik na serial
  Serial.println(licznik); 
  display.showNumberDec(licznik,false,4,0);
  licznik = licznik + 1; //Zwiększenie licznika o 1
  delay(10);
}

