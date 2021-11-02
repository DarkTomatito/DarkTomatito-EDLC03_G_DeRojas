#include <Servo.h>
#include "Volume3.h"
#define speakerPin 9
Servo servo1;
int angl = 60;
int volu = 50;
int med = 35;
void setup() {
  Serial.begin(9600);
  pinMode(8,OUTPUT);
  pinMode(7,INPUT);
  pinMode(6,OUTPUT);
  pinMode(5,INPUT);
  servo1.attach(10);
}
void loop() {
  int S1 = digitalRead(7);
  int S2 = digitalRead(5);
  Serial.print(S1);
  Serial.print(",");
  Serial.print(S2);
  Serial.print(",");
  Serial.print(med);
  Serial.println();
   if(S1 == HIGH){
    digitalWrite(8,HIGH);
    angl = angl + 9;
    if(angl > 180){
      angl = 180;
      }
    servo1.write(angl);
    med = med - 5;
    if(med < 0){
      med =0;
      }
    }
  if(S2 == HIGH){
    digitalWrite(6,HIGH);
    angl = angl - 18;
    if(angl < 0){
      angl = 0;
      }
    servo1.write(angl);
    med = med + 10;
    if(med > 100){
      med = 100;
      }
    }
  if(med >= 1 && med <= 25){
    vol.tone(speakerPin, 131, volu);
    delay(8000);
    }
  if(med >= 26 && med <= 50){
    vol.tone(speakerPin, 196, volu);
    }
  if(med >= 51 && med <= 75){
    vol.tone(speakerPin, 330, volu);
    delay(4000);
    }
  if(med >= 76 && med <= 100){
    vol.tone(speakerPin, 523, volu);
    delay(1000);
    }
}
