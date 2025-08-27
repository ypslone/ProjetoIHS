#include <Arduino.h>

const int buzzerPin = 8;

void setup() {
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(buzzerPin, LOW);
  
  Serial.println("Arduino pronto! Aguardando dados do kernel...");
  Serial.flush();
}

void loop() {
  if (Serial.available() > 0) {
    char c = Serial.read();
    
    // Debug: mostra TUDO que chega
    Serial.print("RX: ");
    if (c >= 32 && c <= 126) { // caracteres imprimíveis
      Serial.print("'");
      Serial.print(c);
      Serial.print("'");
    } else {
      Serial.print("CTRL");
    }
    Serial.print(" ASCII:");
    Serial.print((int)c);
    Serial.print(" HEX:0x");
    Serial.println(c, HEX);
    
    // Testa se é letra ou número válido
    if ((c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
      Serial.print("-> BUZZER ON para: ");
      Serial.println(c);
      
      // Ativa buzzer
      digitalWrite(buzzerPin, HIGH);
      delay(200);
      digitalWrite(buzzerPin, LOW);
      
      Serial.println("-> Buzzer finalizado");
    } else if (c == '\n' || c == '\r' || c == 0) {
      // Só ignora silenciosamente
    } else {
      Serial.print("-> Ignorado (não é A-Z ou 0-9): ");
      Serial.println((int)c);
    }
    
    Serial.flush();
  }
}