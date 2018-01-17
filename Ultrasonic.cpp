/*
	Ultrasonic (HC-SR04) - Sensing with Advanced Accuracy

	Ultrasonic Waves follow the properties of generic sound waves, hence 
	there might be a change in speed (microscopic) in either direction with 
	change in temperature. This change generates error in calculation and 
	hence different distant values are obtained for the same object kept at 
	a fixed  distance. To overcome this, a special algorithm is used which 
	returns the exact distance. 
	
	
	The circuit:
		* VCC connection of the sensor attached to +5V
		* GND connection of the sensor attached to ground
		* TRIG connection of the sensor (User Defined)
		* ECHO connection of the sensor (User Defined)
	
	Created by Arnav Bansal. Last Edited: 10 January, 2018.
	Github: https://github.com/arnavbansal95/Ultrasonic-Arduino-HC-SR04
	
*/

#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#include "Ultrasonic.h"

long ARRAY[25];
int COUNT_ARRAY[25];

Ultrasonic::Ultrasonic(int trig, int echo)
{
   pinMode(trig,OUTPUT);
   pinMode(echo,INPUT);
   trig_pin=trig;
   echo_pin=echo;
   Time_out=24000;  // 24000 µs = 400cm -> Max Range of HCSR04
}

long Ultrasonic::getRawData()
{
	digitalWrite(trig_pin, LOW);
	delayMicroseconds(2);
	digitalWrite(trig_pin, HIGH);
	delayMicroseconds(10);
	digitalWrite(trig_pin, LOW);
	pinMode(echo_pin, INPUT);
	duration = pulseIn(echo_pin, HIGH, Time_out);
	if ( duration == 0 ) 
	{
		duration = Time_out; 
	}
	raw_dist = duration / 29 / 2;
	return raw_dist;
}

void Ultrasonic::getArrayData()
{
	for(int i=0;i<25;i++)
	{
		ARRAY[i] = getRawData();
	}
}

void Ultrasonic::getCountArray()
{
	for(int i=0;i<25;i++)
	{
		long ele;
		int count = 0;
		ele = ARRAY[i];
		for(int j=0;j<25;j++)
		{
			if(ele == ARRAY[j])
			{
				count++;
			}
		}
		COUNT_ARRAY[i] = count;
	}
}

int Ultrasonic::getMaxElemPos()
{
	int max_ele = COUNT_ARRAY[0];
	int pos = 0;
	for(int i=1;i<25;i++)
	{
		if(COUNT_ARRAY[i] > max_ele)
		{
			max_ele = COUNT_ARRAY[i];
			pos = i;
		}
	}
	return pos;
}

long Ultrasonic::readDistance()
{
	getArrayData();
	getCountArray();
	return ARRAY[getMaxElemPos()];
}