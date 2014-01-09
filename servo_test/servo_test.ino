/*
  Blink
  Turns on and off green and red LED .
 
  This example code is in the public domain.
 */
 
#include <Servo.h>  
Servo myservo;  // create servo object to control a servo 
 
// Pin 13 has an LED connected on most Arduino boards.
int sensorPin = A0;  
int led_green = 12;
int led_red = 13;
int val = 0;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led_green, OUTPUT);
  pinMode(led_red, OUTPUT);     
    myservo.attach(10);  // attaches the servo on pin 9 to the servo object 
}

// the loop routine runs over and over again forever:
void loop() {
  // reads the value of the potentiometer (value between 0 and 1023)   
  val = analogRead(sensorPin); 
  digitalWrite(led_green, HIGH);
  digitalWrite(led_red, LOW);
  delay(val); 
  digitalWrite(led_green, LOW);
  digitalWrite(led_red, HIGH);
  delay(val);

  val = map(val, 0, 1023, 0, 179);     // scale it to use it with the servo (value between 0 and 180) 
  myservo.write(val);                  // sets the servo position according to the scaled value  
  
}
