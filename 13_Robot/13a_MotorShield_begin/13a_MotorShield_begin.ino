#define DIR_L 12
#define DIR_R 13
#define PWM_L 3
#define PWM_R 11
#define STOP_L 9
#define STOP_R 8

void setup() {  
  //Inicjacja wejść do sterowania silnikami 
  pinMode(DIR_L, OUTPUT);
  pinMode(DIR_R, OUTPUT);
  pinMode(PWM_L, OUTPUT);
  pinMode(PWM_R, OUTPUT);
  pinMode(STOP_L, OUTPUT);
  pinMode(STOP_R, OUTPUT);
}

void loop() {
  //Prawy silnik 1/3 prękdości do przodu
  digitalWrite(DIR_R, LOW); 
  analogWrite(PWM_L, 150);
}
