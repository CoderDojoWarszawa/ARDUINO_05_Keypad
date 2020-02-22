#include <TM1637Display.h>
#define CLK 2
#define DIO 3
TM1637Display display(CLK, DIO);

void setup() {
  //Ustawienie jasności wyświetlacza
  display.setBrightness(0x0A);
  //Wyczyszczenie wyświetlacza
  display.clear();
}

void loop() {
  //Wyświetlenie liczby
  //display.showNumberDec(25,false,4,0);
  //display.showNumberDec(2,true, 4, 0);
  display.showNumberDec(5,true,2,1);
  //display.showNumberDec(35,true,2,1);
  //display.showNumberDec(10,false,2,2);
  //display.showNumberDec(123,true,4,0);
  //display.showNumberDec(7893,false,4,0);
  //display.showNumberDec(-5,false,4,0); 
  
}
