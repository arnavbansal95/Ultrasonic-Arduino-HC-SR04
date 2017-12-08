#include <Ultrasonic.h>

Ultrasonic sensor(12,13); // Ultrasonic _ObjectName_(TRIG, ECHO)
long distance;

void setup() 
{
  Serial.begin(9600);
}

void loop()
{
  distance = sensor.readDistance();
  Serial.print(distance);
  Serial.println(" cm");
  delay(100);
}
