#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 2
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

const int pH_pin = A0;

void setup() {
  Serial.begin(9600);
  sensors.begin();
}

void loop() {
  sensors.requestTemperatures();
  float tempC = sensors.getTempCByIndex(0);

  int rawValue = analogRead(pH_pin);
  
  float pH_value = analogToPH(rawValue);
  
  //Serial.print("pH value: ");
  if(tempC != DEVICE_DISCONNECTED_C) 
  {
    //Serial.print("Temperature: ");
    Serial.print(pH_value);
    Serial.print(" ");
    Serial.print(tempC);
  } 
  else
  {
    Serial.println("Undefined");
  }
  delay(1000); 
}

float analogToPH(int raw) {
  float voltage = raw * (5.0 / 1024.0);
  
  float pH = 7 - (voltage - 2.5) * (3.0 / 2.5);
  
  return pH;
}
