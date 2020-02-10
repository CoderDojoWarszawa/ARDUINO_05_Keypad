/*
  Czujnik odległości podłączenie:
  Vcc - zasilanie +5V
  echoPin - pin 11
  trigPin - pin 12
  GND - masa 
*/
#define trigPin 12
#define echoPin 11
#define ledRed 10
#define ledYellow 9
#define ledGreen 8

void setup() {
  // Inicjacja komunikacji serial do komputera
  Serial.begin(9600);
  Serial.println("Inicjacja komunikacji");
  // Inicjacja wejść i wyjść Arduino
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledGreen, OUTPUT);  
  pinMode(A5, OUTPUT);
  // Ustawienie stanu początkowego LED
  digitalWrite(ledRed, LOW);
  digitalWrite(ledYellow, LOW);
  digitalWrite(ledGreen, LOW); 
}

// Funkcja mierzaca i zwracająca odleglość w cm
// Do funkcji nie trzeba dostarczać niczego. Funkcja zwraca zmierzoną odległość jako INT.
int zmierzOdleglosc(){
  int dystans = 0;
  // Wyzwolenie pomiaru przez podanie sygnału HIGH (+5V) na złącze trigPin czujnika odległości
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Odczyt wyniku pomiaru z pinu echoPin czujnika
  // Czujnik na pin echoPin zwraca impuls (stan HIGH +5V) proporcjonalny do zmierzonej odległości.
  // My mierzymy długość trwania tego impulsu w mikrosekundach.
  // Wyliczanie odległości - wzór z dokumentacji czujnika: cm = długość_impulsu / 58
  dystans = pulseIn(echoPin, HIGH) / 58;
  return dystans;
}

// Funkcja odtwarzająca dźwięk na buzzerze podłączonym do A5
// Do funkcji trzeba dostarczyć długość jako INT. Funkcja nic nie zwraca.
void sygnal(int czas){
  // Odtwarzaj dźwięk o częstotliwości 3500Hz na pinie A5 
  tone(A5, 3500);
  delay(czas*3);
  noTone(A5);
  delay(czas);
}

void loop() {
  // Wywołanie funkcji która mierzy odległość, wynik zapisywany jest do zmiennej odległość
  int odleglosc = zmierzOdleglosc();
  if (odleglosc > 400) {
    odleglosc = 400;
  }
  Serial.print(odleglosc);
  Serial.print(" cm - ");
  // Zapalanie LED w zależnosci od odleglości
  // Green > 50
  // Yellow 50-20
  // Red < 20
  if (odleglosc > 50) {
    digitalWrite(ledRed, LOW);
    digitalWrite(ledYellow, LOW);
    digitalWrite(ledGreen, HIGH); 
    Serial.println("Green"); 
  } else if (odleglosc < 20){
    digitalWrite(ledRed, HIGH);
    digitalWrite(ledYellow, LOW);
    digitalWrite(ledGreen, LOW);      
    Serial.println("Red"); 
  } else {
    digitalWrite(ledRed, LOW);
    digitalWrite(ledYellow, HIGH);
    digitalWrite(ledGreen, LOW);
    Serial.println("Yellow");       
  }  
  sygnal(odleglosc);
  // Następny pomiar za 200ms.
  delay(100);
}
