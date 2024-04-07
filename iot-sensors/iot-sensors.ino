const int pH_pin = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int rawValue = analogRead(pH_pin);
  
  float pH_value = analogToPH(rawValue);
  
  //Serial.print("pH value: ");
  Serial.println(pH_value);

  delay(1000); 
}

float analogToPH(int raw) {
  float voltage = raw * (5.0 / 1024.0);
  
  float pH = 7 - (voltage - 2.5) * (3.0 / 2.5);
  
  return pH;
}
