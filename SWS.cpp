#include <Servo.h>
#include <Servo.h>
#define sen1 A0
int moisture = 0;
Servo tap_servo;

int sensor_pin = 4;
int tap_servo_pin =5;
int val = 0;

void setup(){
  pinMode(sensor_pin,INPUT);
  pinMode(sen1, INPUT);
  tap_servo.attach(tap_servo_pin);
  
  
}

void loop(){
  delay(1000);
  val = digitalRead(sensor_pin);
  moisture = analogRead(sen1);
   
  delay(500);
  if(val == 0)
  {
    moisture = analogRead(sen1);
    delay(500);
    if(moisture>=40)
    {
      tap_servo.write(0);
      delay(5000);
      tap_servo.write(75);
      delay(2000);
    }
    else if(moisture<100)
    {
      tap_servo.write(135);
      delay(5000);
      tap_servo.write(75);
      delay(2000);
    }
     
  }
  
}
