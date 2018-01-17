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

#ifndef Ultrasonic_h
#define Ultrasonic_h

#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

class Ultrasonic
{
  public:
    Ultrasonic(int trig, int echo);
	long getRawData();
	void getArrayData();
	void getCountArray();
	int getMaxElemPos();
	long readDistance();
	
  private:
    int trig_pin;
    int echo_pin;
	long Time_out;
    long duration, raw_dist;
};

#endif
