// This program is meant for Arduino Leonardo. 
// This can be used for keeping the computer active or 
// prevent it from going to sleep. 
// This basically acts as an external hardware mouse.

// Note: Once it is programmed, to reprogram, short PIN#12 to GND

#include <Mouse.h>

const int buttonPin = 12;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_BUILTIN, LOW);
  
  int time_count, time_interval;
  time_count = time_interval = 50; // time_interval is in seconds
  
  while(digitalRead(12) == HIGH){
    if(time_count > time_interval){
      time_count = 0;
      digitalWrite(LED_BUILTIN, HIGH);
      Mouse.move(0,100);  //down
      delay(1000);
      Mouse.move(0,-75); //up
      delay(1000);
      Mouse.move(-50,0);  //left
      delay(1000);
      Mouse.move(100,0);   //right
      delay(1000);
      Mouse.move(-50,0);  //left
      delay(1000);
      Mouse.move(0,-25); //up
      digitalWrite(LED_BUILTIN, LOW);
    }
    time_count++;
    delay(1000);
  }

}
