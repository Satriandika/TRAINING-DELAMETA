int Flame = A0;
int Buzzer = 4;

void setup(){
  Serial.begin(9600);
  pinMode(Buzzer, OUTPUT);
}

void loop(){
  int readFlame = analogRead(Flame);
  readFlame = map(readFlame, 5, 1015, 100, 0);
  //Serial.println("Flame : " + String(readFlame));

  if(readFlame > 50){
    Serial.println("Warning, harap mengungsi gan!");
    digitalWrite(Buzzer, HIGH);
    delay(200);
    digitalWrite(Buzzer, LOW);
    delay(200);
  } else if(readFlame < 50 && readFlame > 15){
    Serial.println("Warning, silakan periksa coy!");
    digitalWrite(Buzzer, HIGH);
    delay(1000);
    digitalWrite(Buzzer, LOW);
    delay(1000); 
  } else if(readFlame == 0){
    digitalWrite(Buzzer, LOW);
    Serial.println("Aman ngab!");
  }
}
