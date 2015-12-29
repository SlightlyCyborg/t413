/*
 Fading

 This example shows how to fade an LED using the analogWrite() function.

 The circuit:
 * LED attached from digital pin 9 to ground.

 Created 1 Nov 2008
 By David A. Mellis
 modified 30 Aug 2011
 By Tom Igoe

 http://arduino.cc/en/Tutorial/Fading

 This example code is in the public domain.

 */


int speed_pin = 2;
int f_pin = 3;
int b_pin = 4;
String dir;

void setup() {
  // nothing happens in setup
  dir = "f";
  pinMode(f_pin, OUTPUT);
  pinMode(b_pin, OUTPUT);
}

void loop() {
  
  if(dir == "f"){
    digitalWrite(f_pin, HIGH);
    digitalWrite(b_pin, LOW);
    dir = "b";
  }else{
    digitalWrite(f_pin, LOW);
    digitalWrite(b_pin, HIGH);
    dir = "f";
  }
  // fade in from min to max in increments of 5 points:
  for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
    // sets the value (range from 0 to 255):
    analogWrite(speed_pin, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    delay(100);
  }

  // fade out from max to min in increments of 5 points:
  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
    // sets the value (range from 0 to 255):
    analogWrite(speed_pin, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    delay(100);
  }
}


