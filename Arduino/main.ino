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
    
    
    if (c >= 'a' && c <= 'z') {
      c = c - 32; 
      
    }

    if (c == ' ') {
      
      delay(280);

    }

    if (c == 'A') {
      

      digitalWrite(buzzerPin, HIGH);
      delay(70);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(210);
      digitalWrite(buzzerPin, LOW);
      delay(210);

      
    } else if (c == 'B') {
      
      
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

      
    } else if (c == 'C') {
      

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

      
    } else if (c == 'D') {
      
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

    } else if (c == 'E') {
      
      digitalWrite(buzzerPin, HIGH);
      delay(70);
      digitalWrite(buzzerPin, LOW);
      delay(210);

    } else if (c == 'F') {
      
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

    } else if (c == 'G') {
    
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

    } else if (c == 'H') {
      
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

    } else if (c == 'I') {
      
      digitalWrite(buzzerPin, HIGH);
      delay(70);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(70);
      digitalWrite(buzzerPin, LOW);
      delay(210);

    } else if (c == 'J') {
      
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

    } else if (c == 'K') {
      
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

    } else if (c == 'L') {
      
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

    } else if (c == 'M') {
      
      digitalWrite(buzzerPin, HIGH);
      delay(210);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(210);
      digitalWrite(buzzerPin, LOW);
      delay(210);

    } else if (c == 'N') {
      
      digitalWrite(buzzerPin, HIGH);
      delay(210);
      digitalWrite(buzzerPin, LOW);
      delay(70);
      digitalWrite(buzzerPin, HIGH);
      delay(70);
      digitalWrite(buzzerPin, LOW);
      delay(210);

    } else if (c == 'O') {
      
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

    } else if (c == 'P') {
      
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

    } else if (c == 'Q') {
      
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

    } else if (c == 'R') {
      
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

    } else if (c == 'S') {
      
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

    } else if (c == 'T') {
      
      digitalWrite(buzzerPin, HIGH);
      delay(210);
      digitalWrite(buzzerPin, LOW);
      delay(210);

    } else if (c == 'U') {
      
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

    } else if (c == 'V') {
      
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

    } else if (c == 'W') {
      
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

    } else if (c == 'X') {
      
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

    } else if (c == 'Y') {
      
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

    } else if (c == 'Z') {
      
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

    } else if (c == '1') {
      
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

    } else if (c == '2') {
      
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

    } else if (c == '3') {
      
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

    } else if (c == '4') {
      
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

    } else if (c == '5') {
      
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

    } else if (c == '6') {
      
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

    } else if (c == '7') {
      
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

    } else if (c == '8') {
      
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

    } else if (c == '9') {
      
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

    }if (c == '0') {

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

    } else{
    
    if (c == '\n' || c == '\r' || c == 0) {
    } 
    
    Serial.flush();
  }}
}
