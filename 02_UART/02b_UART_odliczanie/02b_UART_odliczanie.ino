//Deklaracja zmiennej
int licznik = 0; 

void setup() {
  // Inicjacja komunikacji serial 
  Serial.begin(9600);
  Serial.println("Inicjacja komunikacji");
}

void loop() {
  //Wysłanie wartości zmiennej licznik na serial
  Serial.println(licznik); 
  licznik = licznik + 1; //Zwiększenie licznika o 1
  delay(100);
}


