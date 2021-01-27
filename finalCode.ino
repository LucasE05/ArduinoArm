#include <Servo.h>
const int POT_PIN = 0;
const int NUM_SERVOS = 4;
Servo servos[NUM_SERVOS];
int servoNum;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //For Serial communication between arduino and IDE.x3
  servos[0].attach(11);
  servos[1].attach(10);
  servos[2].attach(9);
  servos[3].attach(6);
  //servos[4].attach(3);
  servoNum = 0;
  Serial.println(servoNum);  
  for (int i = 0; i < NUM_SERVOS - 1; i++) {
    servos[3].write(96);//360º continuos servo
    servos[i].write(0);
  }
  delay(1000);
}
void mapPot() {
  int pot = analogRead(POT_PIN);
  int pos;
  if (servoNum == 3) {
    pos = map(pot, 0, 1023, 85, 99);
  } else {
    pos = map(pot, 0, 1023, 0, 179);
  }
  Serial.println(pos); 
  //Serial.println(pot);
  servos[servoNum].write(pos);
  delay(15);
}

void loop() {
  while (Serial.available() > 1) {
    char servoChar = Serial.read();
    servoNum = servoChar - '0'; 
    Serial.println(servoNum);
     delay(1000);
  }
  servos[3].write(96);
  mapPot();
}
