// INISIALISASI
int dika_button1 = PB13;
int dika_button2 = PB14;
int dika_button3 = PB15;
int dika_led1 = PB0;
int dika_led2 = PB1;
int dika_led3 = PB10;
int flag = 0;

void setup(){
  Serial.begin(9600);
  pinMode(dika_button1, INPUT);
  pinMode(dika_button2, INPUT);
  pinMode(dika_button3, INPUT);
  pinMode(dika_led1, OUTPUT);
  pinMode(dika_led2, OUTPUT);
  pinMode(dika_led3, OUTPUT);
}

void loop(){
  // READ SENSOR
  int dika_readButton1 = digitalRead(dika_button1);
  int dika_readButton2 = digitalRead(dika_button2);
  int dika_readButton3 = digitalRead(dika_button3);

  // PRINT TO SERIAL
  Serial.print("Button 1 :" + String(dika_readButton1) + " | ");
  Serial.print("Button 2 :" + String(dika_readButton2) + " | ");
  Serial.print("Button 3 :" + String(dika_readButton3) + " | ");
  Serial.println();
  
  // LOGIKA PROGRAM
  // LED 1
  if(dika_readButton1 == 1 && flag == 0){
    flag = 1;
    digitalWrite(dika_led1, HIGH);
    delay(500);
  } else if(dika_readButton1 == 1 && flag == 1){
    flag = 0;
    digitalWrite(dika_led1, LOW);
    delay(500);
  }

  if(dika_readButton2 == 1 && flag == 0){
    flag = 1;
    digitalWrite(dika_led2, HIGH);
    delay(500);
  } else if(dika_readButton2 == 1 && flag == 1){
    flag = 0;
    digitalWrite(dika_led2, LOW);
    delay(500);
  }

  if(dika_readButton3 == 1 && flag == 0){
    flag = 1;
    digitalWrite(dika_led3, HIGH);
    delay(500);
  } else if(dika_readButton3 == 1 && flag == 1){
    flag = 0;
    digitalWrite(dika_led3, LOW);
    delay(500);
  }
}
