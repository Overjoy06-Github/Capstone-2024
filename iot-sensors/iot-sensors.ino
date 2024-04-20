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

  Serial.print(analogToPH(analogRead(pH_pin)));
  Serial.print(" ");
  Serial.println(tempC);
  delay(1000);
}

float analogToPH(int raw) {
  float voltage = raw * (5.0 / 1024.0);
  
  float pH = 7 - (voltage - 2.5) * (3.0 / 2.5);
  
  return pH;
}
