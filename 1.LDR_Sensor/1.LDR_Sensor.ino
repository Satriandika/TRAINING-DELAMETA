// INISIALIZATION
int LDR = A0;
int LED = 3;

void setup(){
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop(){
  // READ SENSOR
  int readLDR = analogRead(LDR);
  readLDR = map(readLDR, 3, 970, 0, 255);

  // PRINT TO SERIAL
  Serial.println("LDR : " + String(readLDR));

  // LOGICAL PROGRAM
  analogWrite(LED, readLDR);
}
