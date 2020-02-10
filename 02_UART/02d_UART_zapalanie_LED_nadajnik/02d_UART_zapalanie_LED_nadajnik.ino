void setup() {
  // Inicjacja komunikacji serial 
  Serial.begin(9600);
}

void loop() {
  // Wysyłanie naprzemienie H i L przez serial
  Serial.print('H');
  delay(1000);
  Serial.print('L');
  delay(1000);
}

