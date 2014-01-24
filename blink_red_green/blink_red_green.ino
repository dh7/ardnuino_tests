/*
  Blink
  Turns on and off green and red LED.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led_green = 12;
int led_red = 13;
int delay_ms = 250;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led_green, OUTPUT);
  pinMode(led_red, OUTPUT);     
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(led_green, HIGH);
  digitalWrite(led_red, LOW);
  delay(delay_ms); 
  digitalWrite(led_green, LOW);
  digitalWrite(led_red, HIGH);
  delay(delay_ms);
}
