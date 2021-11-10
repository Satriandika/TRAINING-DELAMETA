int Flame = A0;
int LDR = A1;
int PIR = 4;
int R = 3;
int Y = 6;
int G = 7;
int Buzzer = 5;

void setup(){
  Serial.begin(9600);
  pinMode(PIR, INPUT);
  pinMode(R, OUTPUT);
  pinMode(Y, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(Buzzer, OUTPUT);
}

void loop(){
  int readFlame = analogRead(Flame);
  int readPIR = digitalRead(PIR);
  int readLDR = analogRead(LDR);
  
  readLDR = map(readLDR, 3, 1015, 0, 100);
  readFlame = map(readFlame, 3, 1015, 100, 0);

  analogWrite(R, readLDR);

  if(readFlame == 0){
      Serial.println("Aman Banget");
      digitalWrite(Buzzer, LOW);
      digitalWrite(G, HIGH);
      digitalWrite(Y, LOW);
  } else if(readFlame <= 75 || readFlame >= 25){
      Serial.println("Warning Silahkan periksa");
      digitalWrite(G, LOW);
      digitalWrite(Y, HIGH);
      digitalWrite(Buzzer, HIGH);
      delay(1000);
      digitalWrite(Buzzer, LOW);
      delay(1000);
  } else if(readFlame > 75){
      Serial.println("Waspada harap mengungsi");
      digitalWrite(G, HIGH);
      digitalWrite(Y, HIGH);
      digitalWrite(Buzzer, HIGH);
      delay(200);
      digitalWrite(Buzzer, LOW);
      delay(200);
  }
}
