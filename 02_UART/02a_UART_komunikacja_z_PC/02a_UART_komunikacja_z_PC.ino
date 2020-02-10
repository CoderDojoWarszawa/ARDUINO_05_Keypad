void setup() {
  // Inicjacja komunikacji serial 
  Serial.begin(9600);
  Serial.println("Inicjacja komunikacji");
}

void loop() {
  delay(1000);
  Serial.println("Mineła 1 sekunda"); 
}


