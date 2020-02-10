int dane_odebrane;

void setup() {
  // Inicjacja komunikacji serial 
  Serial.begin(9600);
  Serial.println("Inicjacja komunikacji");
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
}

void loop() {
//Jeśli są dostepne dane serial to sprawdź jakie
  if (Serial.available() > 0) {
    // Przeczytaj ostatnie dane z bufora
    dane_odebrane = Serial.read();
    //Jeśli to jest duże "H", to zapal diodę LED
    if (dane_odebrane == 'H') {
      digitalWrite(LED_BUILTIN, HIGH);
    }
    //Jeśli to jest duże "L", to zgaś diodę LED
    if (dane_odebrane == 'L') {
      digitalWrite(LED_BUILTIN, LOW);
    }
  }
}


