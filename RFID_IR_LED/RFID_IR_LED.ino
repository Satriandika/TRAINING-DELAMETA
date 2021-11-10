#include <SPI.h>
#include <MFRC522.h>

String uidString;

#define SS_PIN 10
#define RST_PIN 9

MFRC522 mfrc522(SS_PIN, RST_PIN);

int Buzzer = 4;
int flag = 0;
int R = 2;
int G = 3;
int IR = 5;

void setup(){
  Serial.begin(9600);
  pinMode(Buzzer, OUTPUT);
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(IR, INPUT);
  SPI.begin();
  mfrc522.PCD_Init();
  digitalWrite(R, HIGH);
  welcome();
}

void loop(){
  int readIR = digitalRead(IR);
  if(mfrc522.PICC_IsNewCardPresent() && flag == 0){
    readRFID();
    if(uidString == "199-9D-136"){
      flag = 1;
      succeed();
      Serial.println("Gate Opened!");
    } else{
      flag = 0;
      Serial.println("Fail!");
      fail();
    }
  } 
  if(readIR == 0 && flag == 1){
    Serial.print("Please go!");
    flag = 0;
    digitalWrite(R, HIGH);
    digitalWrite(G, LOW);
    welcome();
  }
}

void readRFID(){
  mfrc522.PICC_ReadCardSerial();
  Serial.println("Tag UID : " + String(uidString));
  uidString = String(mfrc522.uid.uidByte[0]) + "-" +
  String(mfrc522.uid.uidByte[1], HEX) + "-" +
  String(mfrc522.uid.uidByte[2]), HEX + "-" +
  String(mfrc522.uid.uidByte[3]), HEX;
  uidString.toUpperCase();
}

void welcome(){
  Serial.println("SELAMAT DATANG");
}

void succeed(){
  Serial.println("SILAKAN MASUK");
  digitalWrite(Buzzer, HIGH);
  delay(50);
  digitalWrite(Buzzer, LOW);
  delay(50);
  digitalWrite(Buzzer, HIGH);
  delay(50);
  digitalWrite(Buzzer, LOW);
  digitalWrite(R, LOW);
  digitalWrite(G, HIGH);
}

void fail(){
  Serial.println("KARTU TIDAK TERDAFTAR");
  digitalWrite(R, HIGH);
  digitalWrite(G, LOW);
  digitalWrite(Buzzer, HIGH);
  delay(1000);
  digitalWrite(Buzzer, LOW);
  welcome();
}
