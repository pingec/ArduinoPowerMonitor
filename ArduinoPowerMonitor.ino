#include "EmonLib.h"
EnergyMonitor emon1;             // Create an instance 
EnergyMonitor emon2;             // Create an instance 
EnergyMonitor emon3;             // Create an instance 

//#define CALIBRATION_MODE       // Uncomment for calibration mode (outputs less data)
#define FLOW_METER             // Uncomment if you have a Grundfos VFS 5-100 QT flow meter connected on A6 (flow) and A7 (temp)

#if defined(FLOW_METER)
	//vcc adjustment, for flow meter only, emon calculations have their own constant that among other things, adjust for this as well
	const float flow_vcc_calibration = 1; 
#endif

void setup()
{
Serial.begin(9600); 

	emon1.current(0, 29 * 1.08); // Current: input pin, calibration. Cur Const= Ratio/BurdenR. 1800/62 = 29.
	emon1.voltage(3, 148, 1.7);  // Voltage: input pin, calibration, phase_shift

	emon2.current(1, 29 * 1.08); // Current: input pin, calibration. Cur Const= Ratio/BurdenR. 1800/62 = 29.
	emon2.voltage(4, 147.5, 1.7);  // Voltage: input pin, calibration, phase_shift

	emon3.current(2, 29 * 1.075); // Current: input pin, calibration. Cur Const= Ratio/BurdenR. 1800/62 = 29.
	emon3.voltage(5, 147.5, 1.7);  // Voltage: input pin, calibration, phase_shift
}

void loop()
{
	emon1.calcVI(20,2000);          // Calculate all. No.of crossings, time-out
	emon2.calcVI(20,2000);          // Calculate all. No.of crossings, time-out
	emon3.calcVI(20,2000);          // Calculate all. No.of crossings, time-out

#if defined(FLOW_METER)

	float vcc = emon1.readVcc() * flow_vcc_calibration / 1000.0;

	int f = analogRead(A6);
	float flow_ = f * (vcc / 1023.0);
	int t = analogRead(A7);
	float temp_ = t * (vcc / 1023.0);

	float flow = (flow_ - 0.375) / 0.03125;
	float temp = (temp_ - 0.5) / 0.03;

	Serial.print("FM");
	Serial.print(flow);
	Serial.print(',');    
	Serial.print(temp);
	Serial.print(',');
	
#endif


#if defined(CALIBRATION_MODE)

	Serial.print("Vrms: ");
	Serial.print(emon1.Vrms);
	Serial.print(',');    
	Serial.print(emon2.Vrms);
	Serial.print(',');   
	Serial.print(emon3.Vrms);

	Serial.print("         "); 

	Serial.print("Irms: ");
	Serial.print(emon1.Irms);
	Serial.print(',');    
	Serial.print(emon2.Irms);
	Serial.print(',');   
	Serial.print(emon3.Irms); 

	Serial.print("         "); 

	Serial.print("RealPower: ");
	Serial.print(emon1.realPower);
	Serial.print(',');    
	Serial.print(emon2.realPower);
	Serial.print(',');   
	Serial.println(emon3.realPower); 
	
#else

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

#endif    

}
