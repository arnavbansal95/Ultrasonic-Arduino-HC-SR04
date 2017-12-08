#include <Ultrasonic.h>

Ultrasonic sensor(12,13); // Ultrasonic _ObjectName_(TRIG, ECHO)

void setup() 
{
  Serial.begin(9600);
}

void loop()
{
  Serial.print(sensor.getRawData());
  Serial.println(" cm");
  delay(100);
}
