#include <Arduino.h>

const int buzzerPin = 8;
const int dit = 70;
const int dah = 210;
const int delayposletra = 250;

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
      
      delay(300);
    }

    if (c == 'A') {
      

      digitalWrite(buzzerPin, HIGH);
      delay(dit);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dah);
      digitalWrite(buzzerPin, LOW);
      delay(delayposletra);

      
    } else if (c == 'B') {
      
      
      digitalWrite(buzzerPin, HIGH);
      delay(dah);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dit);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dit);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dit);
      digitalWrite(buzzerPin, LOW);
      delay(delayposletra);

      
    } else if (c == 'C') {
      

      digitalWrite(buzzerPin, HIGH);
      delay(dah);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dit);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dah);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dit);
      digitalWrite(buzzerPin, LOW);
      delay(delayposletra);

      
    } else if (c == 'D') {
      
      digitalWrite(buzzerPin, HIGH);
      delay(dah);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dit);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dit);
      digitalWrite(buzzerPin, LOW);
      delay(delayposletra);

    } else if (c == 'E') {
      
      digitalWrite(buzzerPin, HIGH);
      delay(dit);
      digitalWrite(buzzerPin, LOW);
      delay(delayposletra);

    } else if (c == 'F') {
      
      digitalWrite(buzzerPin, HIGH);
      delay(dit);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dit);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dah);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dit);
      digitalWrite(buzzerPin, LOW);
      delay(delayposletra);

    } else if (c == 'G') {
    
      digitalWrite(buzzerPin, HIGH);
      delay(dah);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dah);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dit);
      digitalWrite(buzzerPin, LOW);
      delay(delayposletra);

    } else if (c == 'H') {
      
      digitalWrite(buzzerPin, HIGH);
      delay(dit);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dit);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dit);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dit);
      digitalWrite(buzzerPin, LOW);
      delay(delayposletra);

    } else if (c == 'I') {
      
      digitalWrite(buzzerPin, HIGH);
      delay(dit);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dit);
      digitalWrite(buzzerPin, LOW);
      delay(delayposletra);

    } else if (c == 'J') {
      
      digitalWrite(buzzerPin, HIGH);
      delay(dit);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dah);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dah);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dah);
      digitalWrite(buzzerPin, LOW);
      delay(delayposletra);

    } else if (c == 'K') {
      
      digitalWrite(buzzerPin, HIGH);
      delay(dah);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dit);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dah);
      digitalWrite(buzzerPin, LOW);
      delay(delayposletra);

    } else if (c == 'L') {
      
      digitalWrite(buzzerPin, HIGH);
      delay(dit);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dah);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dit);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dit);
      digitalWrite(buzzerPin, LOW);
      delay(delayposletra);

    } else if (c == 'M') {
      
      digitalWrite(buzzerPin, HIGH);
      delay(dah);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dah);
      digitalWrite(buzzerPin, LOW);
      delay(delayposletra);

    } else if (c == 'N') {
      
      digitalWrite(buzzerPin, HIGH);
      delay(dah);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dit);
      digitalWrite(buzzerPin, LOW);
      delay(delayposletra);

    } else if (c == 'O') {
      
      digitalWrite(buzzerPin, HIGH);
      delay(dah);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dah);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dah);
      digitalWrite(buzzerPin, LOW);
      delay(delayposletra);

    } else if (c == 'P') {
      
      digitalWrite(buzzerPin, HIGH);
      delay(dit);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dah);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dah);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dit);
      digitalWrite(buzzerPin, LOW);
      delay(delayposletra);

    } else if (c == 'Q') {
      
      digitalWrite(buzzerPin, HIGH);
      delay(dah);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dah);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dit);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dah);
      digitalWrite(buzzerPin, LOW);
      delay(delayposletra);

    } else if (c == 'R') {
      
      digitalWrite(buzzerPin, HIGH);
      delay(dit);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dah);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dit);
      digitalWrite(buzzerPin, LOW);
      delay(delayposletra);

    } else if (c == 'S') {
      
      digitalWrite(buzzerPin, HIGH);
      delay(dit);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dit);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dit);
      digitalWrite(buzzerPin, LOW);
      delay(delayposletra);

    } else if (c == 'T') {
      
      digitalWrite(buzzerPin, HIGH);
      delay(dah);
      digitalWrite(buzzerPin, LOW);
      delay(delayposletra);

    } else if (c == 'U') {
      
      digitalWrite(buzzerPin, HIGH);
      delay(dit);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dit);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dah);
      digitalWrite(buzzerPin, LOW);
      delay(delayposletra);

    } else if (c == 'V') {
      
      digitalWrite(buzzerPin, HIGH);
      delay(dit);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dit);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dit);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dah);
      digitalWrite(buzzerPin, LOW);
      delay(delayposletra);

    } else if (c == 'W') {
      
      digitalWrite(buzzerPin, HIGH);
      delay(dit);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dah);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dah);
      digitalWrite(buzzerPin, LOW);
      delay(delayposletra);

    } else if (c == 'X') {
      
      digitalWrite(buzzerPin, HIGH);
      delay(dah);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dit);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dit);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dah);
      digitalWrite(buzzerPin, LOW);
      delay(delayposletra);

    } else if (c == 'Y') {
      
      digitalWrite(buzzerPin, HIGH);
      delay(dah);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dit);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dah);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dah);
      digitalWrite(buzzerPin, LOW);
      delay(delayposletra);

    } else if (c == 'Z') {
      
      digitalWrite(buzzerPin, HIGH);
      delay(dah);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dah);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dit);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dit);
      digitalWrite(buzzerPin, LOW);
      delay(delayposletra);

    } else if (c == '1') {
      
      digitalWrite(buzzerPin, HIGH);
      delay(dit);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dah);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dah);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dah);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dah);
      digitalWrite(buzzerPin, LOW);
      delay(delayposletra);

    } else if (c == '2') {
      
      digitalWrite(buzzerPin, HIGH);
      delay(dit);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dit);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dah);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dah);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dah);
      digitalWrite(buzzerPin, LOW);
      delay(delayposletra);

    } else if (c == '3') {
      
      digitalWrite(buzzerPin, HIGH);
      delay(dit);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dit);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dit);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dah);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dah);
      digitalWrite(buzzerPin, LOW);
      delay(delayposletra);

    } else if (c == '4') {
      
      digitalWrite(buzzerPin, HIGH);
      delay(dit);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dit);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dit);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dit);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dah);
      digitalWrite(buzzerPin, LOW);
      delay(delayposletra);

    } else if (c == '5') {
      
      digitalWrite(buzzerPin, HIGH);
      delay(dit);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dit);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dit);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dit);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dit);
      digitalWrite(buzzerPin, LOW);
      delay(delayposletra);

    } else if (c == '6') {
      
      digitalWrite(buzzerPin, HIGH);
      delay(dah);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dit);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dit);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dit);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dit);
      digitalWrite(buzzerPin, LOW);
      delay(delayposletra);

    } else if (c == '7') {
      
      digitalWrite(buzzerPin, HIGH);
      delay(dah);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dah);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dit);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dit);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dit);
      digitalWrite(buzzerPin, LOW);
      delay(delayposletra);

    } else if (c == '8') {
      
      digitalWrite(buzzerPin, HIGH);
      delay(dah);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dah);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dah);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dit);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dit);
      digitalWrite(buzzerPin, LOW);
      delay(delayposletra);

    } else if (c == '9') {
      
      digitalWrite(buzzerPin, HIGH);
      delay(dah);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dah);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dah);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dah);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dit);
      digitalWrite(buzzerPin, LOW);
      delay(delayposletra);

    }if (c == '0') {

      digitalWrite(buzzerPin, HIGH);
      delay(dah);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dah);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dah);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dah);
      digitalWrite(buzzerPin, LOW);
      delay(dit);
      digitalWrite(buzzerPin, HIGH);
      delay(dit);
      digitalWrite(buzzerPin, LOW);
      delay(delayposletra);

    } else{
    
    if (c == '\n' || c == '\r' || c == 0) {
    } 
    
    Serial.flush();
  }}
}
