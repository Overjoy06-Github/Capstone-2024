#include <OneWire.h>
#include <DallasTemperature.h>
#include <runningAvg.h>

#define ONE_WIRE_BUS 2

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

const int pH_pin = A0;
runningAvg smoother(10); 

void setup() {
  Serial.begin(9600);
  sensors.begin();
}

void loop() {
  sensors.requestTemperatures();
  float tempC = sensors.getTempCByIndex(0);

  float pH = analogToPH(analogRead(pH_pin));
  float ave_pH = smoother.addData(pH);

  Serial.print(ave_pH);
  Serial.print(" ");

  Serial.println(tempC);
  delay(1000);
}

float analogToPH(int raw) {
  float voltage = raw * (5.0 / 1023.0 );
  float pH = voltage * (14.0 / 5.0);
  return pH;
}
