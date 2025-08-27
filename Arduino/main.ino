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
    
    if (c >= 'a' && c <= 'z') {
      c = c - 32; // Converte para maiúscula (a=97, A=65, diferença=32)
      Serial.print("-> Convertido para maiúscula: ");
      Serial.println(c);
    }

    if (c == ' ') {
      Serial.print("-> BUZZER ON para: ");
      Serial.println(c);
      delay(280);

    }

    if (c == 'A') {
      Serial.print("-> BUZZER ON para: ");
      Serial.println(c);

      digitalWrite(buzzerPin, HIGH);
      delay(70);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(210);
      digitalWrite(buzzerPin, LOW);
      delay(210);

      Serial.println("-> Buzzer finalizado");
    } else if (c == 'B') {
      Serial.print("-> BUZZER ON para: ");
      Serial.println(c);
      
      digitalWrite(buzzerPin, HIGH);
      delay(210);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(70);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(70);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(70);
      digitalWrite(buzzerPin, LOW);
      delay(210);

      Serial.println("-> Buzzer finalizado");
    } else if (c == 'C') {
      Serial.print("-> BUZZER ON para: ");
      Serial.println(c);

      digitalWrite(buzzerPin, HIGH);
      delay(210);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(70);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(210);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(70);
      digitalWrite(buzzerPin, LOW);
      delay(210);

      Serial.println("-> Buzzer finalizado");
    } else if (c == 'D') {
      Serial.print("-> BUZZER ON para: ");
      Serial.println(c);
      
      // Ativa buzzer
      digitalWrite(buzzerPin, HIGH);
      delay(210);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(70);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(70);
      digitalWrite(buzzerPin, LOW);
      delay(210);

      Serial.println("-> Buzzer finalizado");
    } else if (c == 'E') {
      Serial.print("-> BUZZER ON para: ");
      Serial.println(c);
      
      digitalWrite(buzzerPin, HIGH);
      delay(70);
      digitalWrite(buzzerPin, LOW);
      delay(210);

      Serial.println("-> Buzzer finalizado");
    } else if (c == 'F') {
      Serial.print("-> BUZZER ON para: ");
      Serial.println(c);
      
      digitalWrite(buzzerPin, HIGH);
      delay(70);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(70);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(210);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(70);
      digitalWrite(buzzerPin, LOW);
      delay(210);

      Serial.println("-> Buzzer finalizado");
    } else if (c == 'G') {
      Serial.print("-> BUZZER ON para: ");
      Serial.println(c);
      
      // Ativa buzzer
      digitalWrite(buzzerPin, HIGH);
      delay(210);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(210);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(70);
      digitalWrite(buzzerPin, LOW);
      delay(210);

      Serial.println("-> Buzzer finalizado");
    } else if (c == 'H') {
      Serial.print("-> BUZZER ON para: ");
      Serial.println(c);
      
      digitalWrite(buzzerPin, HIGH);
      delay(70);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(70);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(70);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(70);
      digitalWrite(buzzerPin, LOW);
      delay(210);

      Serial.println("-> Buzzer finalizado");
    } else if (c == 'I') {
      Serial.print("-> BUZZER ON para: ");
      Serial.println(c);
      
      digitalWrite(buzzerPin, HIGH);
      delay(70);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(70);
      digitalWrite(buzzerPin, LOW);
      delay(210);

      Serial.println("-> Buzzer finalizado");
    } else if (c == 'J') {
      Serial.print("-> BUZZER ON para: ");
      Serial.println(c);
      
      digitalWrite(buzzerPin, HIGH);
      delay(70);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(210);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(210);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(210);
      digitalWrite(buzzerPin, LOW);
      delay(210);

      Serial.println("-> Buzzer finalizado");
    } else if (c == 'K') {
      Serial.print("-> BUZZER ON para: ");
      Serial.println(c);
      digitalWrite(buzzerPin, HIGH);
      delay(210);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(70);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(210);
      digitalWrite(buzzerPin, LOW);
      delay(210);

      Serial.println("-> Buzzer finalizado");
    } else if (c == 'L') {
      Serial.print("-> BUZZER ON para: ");
      Serial.println(c);
      
      digitalWrite(buzzerPin, HIGH);
      delay(70);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(210);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(70);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(70);
      digitalWrite(buzzerPin, LOW);
      delay(210);

      Serial.println("-> Buzzer finalizado");
    } else if (c == 'M') {
      Serial.print("-> BUZZER ON para: ");
      Serial.println(c);
      
      digitalWrite(buzzerPin, HIGH);
      delay(210);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(210);
      digitalWrite(buzzerPin, LOW);
      delay(210);

      Serial.println("-> Buzzer finalizado");
    } else if (c == 'N') {
      Serial.print("-> BUZZER ON para: ");
      Serial.println(c);
      
      digitalWrite(buzzerPin, HIGH);
      delay(210);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(70);
      digitalWrite(buzzerPin, LOW);
      delay(210);

      Serial.println("-> Buzzer finalizado");
    } else if (c == 'O') {
      Serial.print("-> BUZZER ON para: ");
      Serial.println(c);
      
      digitalWrite(buzzerPin, HIGH);
      delay(210);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(210);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(210);
      digitalWrite(buzzerPin, LOW);
      delay(210);

      Serial.println("-> Buzzer finalizado");
    } else if (c == 'P') {
      Serial.print("-> BUZZER ON para: ");
      Serial.println(c);
      
      digitalWrite(buzzerPin, HIGH);
      delay(70);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(210);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(210);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(70);
      digitalWrite(buzzerPin, LOW);
      delay(210);

      Serial.println("-> Buzzer finalizado");
    } else if (c == 'Q') {
      Serial.print("-> BUZZER ON para: ");
      Serial.println(c);
      
      digitalWrite(buzzerPin, HIGH);
      delay(210);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(210);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(70);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(210);
      digitalWrite(buzzerPin, LOW);
      delay(210);

      Serial.println("-> Buzzer finalizado");
    } else if (c == 'R') {
      Serial.print("-> BUZZER ON para: ");
      Serial.println(c);
      
      digitalWrite(buzzerPin, HIGH);
      delay(70);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(210);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(70);
      digitalWrite(buzzerPin, LOW);
      delay(210);

      Serial.println("-> Buzzer finalizado");
    } else if (c == 'S') {
      Serial.print("-> BUZZER ON para: ");
      Serial.println(c);
      
      digitalWrite(buzzerPin, HIGH);
      delay(70);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(70);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(70);
      digitalWrite(buzzerPin, LOW);
      delay(210);

      Serial.println("-> Buzzer finalizado");
    } else if (c == 'T') {
      Serial.print("-> BUZZER ON para: ");
      Serial.println(c);
      
      digitalWrite(buzzerPin, HIGH);
      delay(210);
      digitalWrite(buzzerPin, LOW);
      delay(210);

      Serial.println("-> Buzzer finalizado");
    } else if (c == 'U') {
      Serial.print("-> BUZZER ON para: ");
      Serial.println(c);
      
      digitalWrite(buzzerPin, HIGH);
      delay(70);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(70);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(210);
      digitalWrite(buzzerPin, LOW);
      delay(210);

      Serial.println("-> Buzzer finalizado");
    } else if (c == 'V') {
      Serial.print("-> BUZZER ON para: ");
      Serial.println(c);
      
      digitalWrite(buzzerPin, HIGH);
      delay(70);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(70);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(70);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(210);
      digitalWrite(buzzerPin, LOW);
      delay(210);

      Serial.println("-> Buzzer finalizado");
    } else if (c == 'W') {
      Serial.print("-> BUZZER ON para: ");
      Serial.println(c);
      
      digitalWrite(buzzerPin, HIGH);
      delay(70);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(210);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(210);
      digitalWrite(buzzerPin, LOW);
      delay(210);

      Serial.println("-> Buzzer finalizado");
    } else if (c == 'X') {
      Serial.print("-> BUZZER ON para: ");
      Serial.println(c);
      
      digitalWrite(buzzerPin, HIGH);
      delay(210);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(70);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(70);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(210);
      digitalWrite(buzzerPin, LOW);
      delay(210);

      Serial.println("-> Buzzer finalizado");
    } else if (c == 'Y') {
      Serial.print("-> BUZZER ON para: ");
      Serial.println(c);
      
      digitalWrite(buzzerPin, HIGH);
      delay(210);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(70);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(210);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(210);
      digitalWrite(buzzerPin, LOW);
      delay(210);

      Serial.println("-> Buzzer finalizado");
    } else if (c == 'Z') {
      Serial.print("-> BUZZER ON para: ");
      Serial.println(c);
      
      digitalWrite(buzzerPin, HIGH);
      delay(210);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(210);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(70);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(70);
      digitalWrite(buzzerPin, LOW);
      delay(210);

      Serial.println("-> Buzzer finalizado");
    } else if (c == '1') {
      Serial.print("-> BUZZER ON para: ");
      Serial.println(c);
      
      digitalWrite(buzzerPin, HIGH);
      delay(70);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(210);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(210);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(210);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(210);
      digitalWrite(buzzerPin, LOW);
      delay(210);

      Serial.println("-> Buzzer finalizado");
    } else if (c == '2') {
      Serial.print("-> BUZZER ON para: ");
      Serial.println(c);
      
      digitalWrite(buzzerPin, HIGH);
      delay(70);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(70);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(210);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(210);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(210);
      digitalWrite(buzzerPin, LOW);
      delay(210);

      Serial.println("-> Buzzer finalizado");
    } else if (c == '3') {
      Serial.print("-> BUZZER ON para: ");
      Serial.println(c);
      
      digitalWrite(buzzerPin, HIGH);
      delay(70);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(70);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(70);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(210);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(210);
      digitalWrite(buzzerPin, LOW);
      delay(210);

      Serial.println("-> Buzzer finalizado");
    } else if (c == '4') {
      Serial.print("-> BUZZER ON para: ");
      Serial.println(c);
      
      digitalWrite(buzzerPin, HIGH);
      delay(70);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(70);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(70);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(70);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(210);
      digitalWrite(buzzerPin, LOW);
      delay(210);

      Serial.println("-> Buzzer finalizado");
    } else if (c == '5') {
      Serial.print("-> BUZZER ON para: ");
      Serial.println(c);
      
      digitalWrite(buzzerPin, HIGH);
      delay(70);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(70);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(70);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(70);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(70);
      digitalWrite(buzzerPin, LOW);
      delay(210);

      Serial.println("-> Buzzer finalizado");
    } else if (c == '6') {
      Serial.print("-> BUZZER ON para: ");
      Serial.println(c);
      
      digitalWrite(buzzerPin, HIGH);
      delay(210);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(70);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(70);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(70);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(70);
      digitalWrite(buzzerPin, LOW);
      delay(210);

      Serial.println("-> Buzzer finalizado");
    } else if (c == '7') {
      Serial.print("-> BUZZER ON para: ");
      Serial.println(c);
      
      digitalWrite(buzzerPin, HIGH);
      delay(210);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(210);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(70);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(70);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(70);
      digitalWrite(buzzerPin, LOW);
      delay(210);

      Serial.println("-> Buzzer finalizado");
    } else if (c == '8') {
      Serial.print("-> BUZZER ON para: ");
      Serial.println(c);
      
      digitalWrite(buzzerPin, HIGH);
      delay(210);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(210);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(210);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(70);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(70);
      digitalWrite(buzzerPin, LOW);
      delay(210);

      Serial.println("-> Buzzer finalizado");
    } else if (c == '9') {
      Serial.print("-> BUZZER ON para: ");
      Serial.println(c);
      
      digitalWrite(buzzerPin, HIGH);
      delay(210);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(210);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(210);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(210);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(70);
      digitalWrite(buzzerPin, LOW);
      delay(210);

      Serial.println("-> Buzzer finalizado");
    }if (c == '0') {
      Serial.print("-> BUZZER ON para: ");
      Serial.println(c);

      digitalWrite(buzzerPin, HIGH);
      delay(210);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(210);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(210);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(210);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(70);
      digitalWrite(buzzerPin, LOW);
      delay(210);

      Serial.println("-> Buzzer finalizado");
    } else{
    
    if (c == '\n' || c == '\r' || c == 0) {
    } 
    
    Serial.flush();
  }}
}
