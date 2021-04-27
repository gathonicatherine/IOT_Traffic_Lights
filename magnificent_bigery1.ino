#include <Servo.h>
Servo servo1;
int potpin=0;
int Red = 1;
int Blue = 2;
int Green=3;
int val;
int trigpin=5;
int echopin=6;
long distance;
long duration;
void setup()
{
servo1.attach(11);
 pinMode(Red, OUTPUT);
 pinMode(Blue, OUTPUT);
  pinMode(Green,OUTPUT);
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
}
void loop() {
  
  servo1.write(0);
  val=analogRead(potpin);
  val = map(val, 0,1023,0,100);
  servo1.write(val);
  delay(20);
  
   if(distance <=20){
  digitalWrite(Red,HIGH);
  delay(2500);
  digitalWrite(Red, LOW);
  delay(2500);
   servo1.write(60);
  }
   else  { servo1.write(0);}
  if (distance<=20){
  digitalWrite(Blue, HIGH);
  delay(3000);
  digitalWrite(Blue,LOW);
  delay(3000);
   servo1.write(120);
 }
  else  {servo1.write(0);}
   if (distance<=20){
  digitalWrite(Green,HIGH);
  delay(2000);
  digitalWrite(Green,LOW);
  delayMicroseconds(15);
  servo1.write(180);
    }
    else{servo1.write(0);}
}
  void ultra(){
  digitalWrite(trigpin,LOW);
  delayMicroseconds(10);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(20);
  digitalWrite(trigpin,LOW);
  duration = pulseIn(echopin, HIGH);
  distance=duration*0.343/2;
}

  