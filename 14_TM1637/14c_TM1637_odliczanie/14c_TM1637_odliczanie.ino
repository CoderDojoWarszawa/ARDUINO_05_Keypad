#include <TM1637Display.h>
#define CLK 2
#define DIO 3
TM1637Display display(CLK, DIO);

int licznik = 9500; 

void setup() {
  display.setBrightness(0x09);
}

void loop() {
  display.showNumberDec(licznik,false,4,0);
  licznik = licznik + 1; 
  if (licznik >= 10000){
    licznik = 0;
  }
  delay(10);
}
