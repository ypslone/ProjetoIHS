#include <Arduino.h>

const int buzzerPin = 8;

void setup() {
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(buzzerPin, LOW);
}

void loop() {
  if (Serial.available() > 0) {
    char c = Serial.read();
    Serial.print("Recebido: "); Serial.println(c);

    // Liga o buzzer por 200ms para qualquer caractere
    digitalWrite(buzzerPin, HIGH);
    delay(200);
    digitalWrite(buzzerPin, LOW);
  }
}
