#include <Servo.h>

Servo myservo;
// 0 = posizione 0 gradi, 1 = posizione 180 gradi
// Iniziamo a 1, perché il servo parte da 180
int statoServo = 1; 

void setup() {
  myservo.attach(9);
  
  // Posizione di partenza: 180 gradi
  myservo.write(60); 
  
  Serial.begin(9600);
  Serial.println("--- DRS available, you can use it within 1 second gap from the car in front in the DRS zones ---");
  Serial.println("SM available, press 's' to open it, you can use in the SM zones on track");
}

void loop() {
  if (Serial.available() > 0) {
    char comando = Serial.read();

    if (comando == 's') {
      if (statoServo == 1) {
        // Se è a 180, lo mandiamo a 0
        myservo.write(0); 
        statoServo = 0;
        Serial.println("SM ON");
      } else {
        // Se è a 0, lo riportiamo a 180
        myservo.write(60);
        statoServo = 1;
        Serial.println("SM OFF");
      }
    }
  }
}