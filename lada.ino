#include<Servo.h>

int trigPin = 3;
int echoPin = 4;
Servo servo;
long duration, cm, inches;
int EN1 = 5;
int IN1 = 6;
int IN2 = 7;
int EN2 = 8;
int IN3 = 9;
int IN4 = 10;
 
void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(EN1, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(EN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  servo.attach(2);
}
 
void loop()
{
 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  
  cm = (duration/2)/ 29.1;
  inches = (duration/2) / 74; 
  
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  
  delay(250);
  if (cm<=10){
    digitalWrite(IN2, LOW);
    digitalWrite(IN4, LOW);
    servo.write(60);
    delay(800);
    servo.write(0);
    delay(800);
    servo.write(120);
    delay(800);
    servo.write(60);
    delay(800);
  }
  else{
    digitalWrite(IN2, HIGH);
    digitalWrite(IN4, HIGH);
    servo.write(60);
  }
}
