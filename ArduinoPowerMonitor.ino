#include "EmonLib.h"
EnergyMonitor emon1;             // Create an instance 
EnergyMonitor emon2;             // Create an instance 
EnergyMonitor emon3;             // Create an instance 

void setup()
{
  Serial.begin(9600); 
  
  emon1.current(5, 29 * 1.01); // Current: input pin, calibration. Cur Const= Ratio/BurdenR. 1800/62 = 29.
  emon1.voltage(2, 186.9, 1.7);  // Voltage: input pin, calibration, phase_shift
  
  emon2.current(4, 29 * 1.01); // Current: input pin, calibration. Cur Const= Ratio/BurdenR. 1800/62 = 29.
  emon2.voltage(1, 187.5, 1.7);  // Voltage: input pin, calibration, phase_shift
  
  emon3.current(3, 29 * 1.01); // Current: input pin, calibration. Cur Const= Ratio/BurdenR. 1800/62 = 29.
  emon3.voltage(0, 188.9, 1.7);  // Voltage: input pin, calibration, phase_shift
}

void loop()
{
	emon1.calcVI(20,2000);          // Calculate all. No.of crossings, time-out
	emon2.calcVI(20,2000);          // Calculate all. No.of crossings, time-out
	emon3.calcVI(20,2000);          // Calculate all. No.of crossings, time-out
  
    Serial.print(emon1.realPower);
	Serial.print(',');
    Serial.print(emon1.apparentPower);
	Serial.print(',');
    Serial.print(emon1.Vrms);
	Serial.print(',');
    Serial.print(emon1.Irms);
	Serial.print(',');
    Serial.print(emon1.powerFactor);
	Serial.print(',');
    
	Serial.print(emon2.realPower);   
	Serial.print(',');	
    Serial.print(emon2.apparentPower);
	Serial.print(',');
    Serial.print(emon2.Vrms);
	Serial.print(',');
    Serial.print(emon2.Irms);
	Serial.print(',');
    Serial.print(emon2.powerFactor);
	Serial.print(',');
    
    Serial.print(emon3.realPower);
    Serial.print(',');
    Serial.print(emon3.apparentPower);
    Serial.print(',');
    Serial.print(emon3.Vrms);
    Serial.print(',');
    Serial.print(emon3.Irms);
    Serial.print(',');
    Serial.println(emon3.powerFactor);        
	
}
