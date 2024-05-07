#include <OneWire.h>
#include <DallasTemperature.h>
#include <runningAvg.h>

#define ONE_WIRE_BUS 2
#define calibrationOffset 0.00

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

  Serial.print("pH: ");
  Serial.println(pH);
  Serial.print(" Average pH: ");
  Serial.println(ave_pH);

  //Serial.print("Temperature: ");
  //Serial.println(tempC);

  delay(1000);
}

float analogToPH(int raw) {
  float voltage = raw * (5.0 / 1023.0);
  voltage = voltage - calibrationOffset;
  float pH = voltage * (14.0 / 5.0);

  return pH;
}
