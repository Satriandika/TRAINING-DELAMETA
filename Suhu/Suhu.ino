#include <OneWire.h>
#include <DallasTemperature.h>

int pinSuhu = 2;

OneWire oneWire(pinSuhu);

DallasTemperature sensors(&oneWire);

void setup(){
  Serial.begin(115200);
  sensors.begin();
}

void loop(){
  sensors.requestTemperatures();
  float bacaSuhu = sensors.getTempCByIndex(0);

  if(bacaSuhu != DEVICE_DISCONNECTED_C){
    Serial.print("Temperature : ");
    Serial.println(bacaSuhu + String(" °C"));
  } else{
    Serial.println("Error : Sensor pada index 0 tidak ditemukan!");
  }
}
