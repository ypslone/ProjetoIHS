#include <Arduino.h>

// ==== Configuração do pino ====
const int buzzerPin = 8;  // Pino onde o buzzer está conectado

void setup() {
  Serial.begin(9600);      // Inicializa comunicação Serial
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(buzzerPin, LOW);  // Garante que o buzzer comece desligado
}

void loop() {
  if (Serial.available() > 0) {
    char c = Serial.read();
    Serial.print("Recebido: ");
    Serial.println(c);
    digitalWrite(buzzerPin, HIGH);
    delay(200);
    digitalWrite(buzzerPin, LOW);
  }
}