#include <OneWire.h>
#include <DallasTemperature.h>

int pinSuhu = 2;
int Buzzer = 3;

OneWire oneWire(pinSuhu);

DallasTemperature sensors(&oneWire);

void setup(){
  Serial.begin(9600);
  pinMode(Buzzer, OUTPUT);
  sensors.begin();
}

void loop(){
  sensors.requestTemperatures();
  float bacaSuhu = sensors.getTempCByIndex(0);
  Serial.println("Temperature : " + String(bacaSuhu) + " °C");

  if(bacaSuhu > 31){
    digitalWrite(Buzzer, HIGH);
    delay(50);
    digitalWrite(Buzzer, LOW);
    delay(50);
  } else{
    digitalWrite(Buzzer, LOW);
  }
}
