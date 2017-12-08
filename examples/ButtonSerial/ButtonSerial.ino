#include <Ultrasonic.h>

Ultrasonic sensor(12,13); // Ultrasonic _ObjectName_(TRIG, ECHO)

int btn = 2; // Switch -> PIN 2 on Arduino

void setup() 
{
  Serial.begin(9600);
  pinMode(btn, INPUT);
}

void loop()
{
  if(digitalRead(btn)==LOW)
  {
    Serial.print(sensor.readDistance());
    Serial.println(" cm");  
  }
  delay(100);
}
