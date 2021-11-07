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
  time_count = time_interval = 10; // time_interval is in seconds
  
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
