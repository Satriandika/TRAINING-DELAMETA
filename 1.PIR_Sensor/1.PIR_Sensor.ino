int PIR = 2;
int Buzzer = 5;

void setup(){
  Serial.begin(9600);
  pinMode(PIR, INPUT);
  pinMode(Buzzer, OUTPUT);
}

void loop(){
  int readPIR = digitalRead(PIR);
  if(readPIR == 1){
    Serial.println("Caution! There's a thief near here!");
    digitalWrite(Buzzer, HIGH);
  } else{
    Serial.println("There's no one here");
    digitalWrite(Buzzer, LOW);
  }
}
