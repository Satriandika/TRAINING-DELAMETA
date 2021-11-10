// INISIALISASI
int Button1 = PB7;
int Button2 = PB6;
int Button3 = PB5;
int led1 = PA11;
int led2 = PA0;
int led3 = PA1;

void setup(){
  Serial.begin(9600);
  pinMode(Button1, INPUT);
  pinMode(Button2, INPUT);
  pinMode(Button3, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop(){
  // READ SENSOR
  int readButton1 = digitalRead(Button1);
  int readButton2 = digitalRead(Button2);
  int readButton3 = digitalRead(Button3);

  // PRINT TO SERIAL
  Serial.print("Button 1 : " + String(readButton1) + " | ");
  Serial.print("Button 2 : " + String(readButton2) + " | ");
  Serial.print("Button 3 : " + String(readButton3));
  Serial.println();
  
  // LOGIKA PROGRAM
  if(readButton1 == 1){
    digitalWrite(led1, HIGH);
  } else{
    digitalWrite(led1, LOW);
  }

  if(readButton2 == 1){
    digitalWrite(led2, HIGH);
  } else{
    digitalWrite(led2, LOW);
  }

  if(readButton3 == 1){
    digitalWrite(led3, HIGH);
  } else{
    digitalWrite(led3, LOW);
  }
}
