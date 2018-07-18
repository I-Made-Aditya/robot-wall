#include <Servo.h>
Servo servo1; 
int trig=2;
int echo=3;

void setup()
{
  servo1.attach(2); //pin sinyal servo terkoneksi pada pin 2 arduino
}
void loop()
{
  servo1.write(60);
  delay(800);
  servo1.write(0);
  delay(800);
  servo1.write(120);
  delay(800);
  servo1.write(60);
  delay(800);
}
