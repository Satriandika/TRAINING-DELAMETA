#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

String uidString;

#define SS_PIN 10
#define RST_PIN 9
#define B1 7
#define B2 8

MFRC522 mfrc522(SS_PIN, RST_PIN);
LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo gate;

int Buzzer = 4;
int flag = 0;
int R = 2;
int G = 3;
int IR = 5;
int servo = 6;

void setup(){
  Serial.begin(9600);
  pinMode(Buzzer, OUTPUT);
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(IR, INPUT);
  pinMode(B1, OUTPUT);
  pinMode(B2, OUTPUT);
  digitalWrite(B1, LOW);
  digitalWrite(B2, LOW);
  SPI.begin();
  mfrc522.PCD_Init();
  digitalWrite(R, HIGH);
  lcd.begin();
  gate.attach(servo);
  welcome();
  gate.write(180);
}

void loop(){
  int readIR = digitalRead(IR);
  if(mfrc522.PICC_IsNewCardPresent() && flag == 0){
    readRFID();
    if(uidString == "199-9D-136"){
      flag = 1;
      succeed();
      forward();
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
    backward();
    gate.write(180);
    lcd.clear();
    lcd.setCursor(1,0); lcd.print("SILAHKAN MASUK");
    delay(2000);
    lcd.clear();
    welcome();
  }
}

void welcome(){
  lcd.clear();
  lcd.setCursor(1,0); lcd.print("SELAMAT DATANG");
  lcd.setCursor(4,1); lcd.print("DELAMETA");
  delay(2000);
  lcd.clear();
  lcd.setCursor(2,0); lcd.print("TEMPEL KARTU");
  delay(2000);
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

void succeed(){
  lcd.clear();
  lcd.setCursor(1, 0); lcd.print("PALANG TERBUKA");
  digitalWrite(Buzzer, HIGH);
  delay(50);
  digitalWrite(Buzzer, LOW);
  delay(50);
  digitalWrite(Buzzer, HIGH);
  delay(50);
  digitalWrite(Buzzer, LOW);
  digitalWrite(R, LOW);
  digitalWrite(G, HIGH);
  gate.write(90);
}

void fail(){
  digitalWrite(R, HIGH);
  digitalWrite(G, LOW);
  digitalWrite(Buzzer, HIGH);
  delay(1000);
  digitalWrite(Buzzer, LOW);
  lcd.clear();
  lcd.setCursor(2,0); lcd.print("KARTU TIDAK");
  lcd.setCursor(3,1); lcd.print("TERDAFTAR");
  delay(2000);
  lcd.clear();
  welcome();
  gate.write(180);
}

void forward(){
  digitalWrite(B1, HIGH);
  delay(80);
  digitalWrite(B1, LOW);
  digitalWrite(B2, LOW);
}

void backward(){
  digitalWrite(B2, HIGH);
  delay(80);
  digitalWrite(B2, LOW);
  digitalWrite(B1, LOW);
}
