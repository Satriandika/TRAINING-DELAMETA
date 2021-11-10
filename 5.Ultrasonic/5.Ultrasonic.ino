#include <NewPing.h>

int trigger = 4;
int echo = 5;
int limit = 300;
int Buzzer = 3;
int R = 6;
int Y = 7;
int G = 8;

NewPing cm(trigger, echo, limit);

void setup(){
  Serial.begin(115200);
  pinMode(Buzzer, OUTPUT);
  pinMode(R, OUTPUT);
  pinMode(Y, OUTPUT);
  pinMode(G, OUTPUT);
}

void loop(){
  int readDistance = cm.ping_cm();
  delay(100);

  if(readDistance <= 20 && readDistance != 0){
    Serial.println(String(readDistance) + " cm | " + "Berhenti!");
    digitalWrite(R, HIGH);
    digitalWrite(Y, LOW);
    digitalWrite(G, LOW);
    digitalWrite(Buzzer, HIGH);
    delay(50);
    digitalWrite(Buzzer, LOW);
    delay(50);
  } else if(readDistance >= 21 && readDistance <= 70){
    Serial.println(String(readDistance) + " cm | " + "Bahaya");
    digitalWrite(R, LOW);
    digitalWrite(Y, HIGH);
    digitalWrite(G, LOW);
    digitalWrite(Buzzer, HIGH);
    delay(500);
    digitalWrite(Buzzer, LOW);
    delay(500);
  } else if(readDistance >= 71){
    Serial.println(String(readDistance) + " cm | " + "Aman");
    digitalWrite(R, LOW);
    digitalWrite(Y, LOW);
    digitalWrite(G, HIGH);
    digitalWrite(Buzzer, LOW);
  }
}
