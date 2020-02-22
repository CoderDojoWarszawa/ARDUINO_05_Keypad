#include <TM1637Display.h>
#define CLK 2
#define DIO 3
TM1637Display display(CLK, DIO);

void setup() {
  display.setBrightness(0x0A); //Ustawienie jasności
  display.clear(); //Wyczyszczenie wyświetlacza
}

//Tablica 4 elementowa - zapalone segmenty
byte segmenty[]={ 
  SEG_A,
  SEG_B|SEG_C,
  0,
  SEG_A|SEG_D|SEG_G
  }; 

uint8_t stopMe[]={
  SEG_A|SEG_F|SEG_G|SEG_C|SEG_D,
  SEG_F|SEG_G|SEG_E|SEG_D,
  SEG_G|SEG_E|SEG_C|SEG_D,
  SEG_A|SEG_F|SEG_B|SEG_G|SEG_E,
};

uint8_t err[]={
  SEG_A|SEG_D|SEG_E|SEG_F|SEG_G,
  SEG_E|SEG_G,
  SEG_E|SEG_G,
  0
};

uint8_t SEG_DONE[] = {
  SEG_B | SEG_C | SEG_D | SEG_E | SEG_G,  // d
  SEG_C | SEG_D | SEG_E | SEG_G,          // o
  SEG_C | SEG_E | SEG_G,                  // n
  SEG_A | SEG_D | SEG_E | SEG_F | SEG_G   // E
  };

uint8_t cyfry[]={
  SEG_B|SEG_C,
  SEG_A|SEG_B|SEG_D|SEG_E|SEG_G,
  SEG_A|SEG_B|SEG_C|SEG_D|SEG_G,
  SEG_F|SEG_B|SEG_G|SEG_C
};

void loop() {  
  display.setSegments(cyfry,4,0); //Zapalenie segmentów 
}
