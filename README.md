ArduinoPowerMonitor
===================

Arduino 3phase AC voltage, current and power monitor (uses EmonLib), outputs to serial

## Dependencies
Depends on emontx's lib EmonLib (a working version is included and should be installed by copying the EmonLib folder to wherever your IDE setup expects libs).

## Setup
Calibration constants in ArduinoPowerMonitor.ino should be adjusted to suit the actual sensors. For more readable output during calibration, enable calibration mode.

## Output
Measured data will be output to serial port in a format of:

    phase1.realPower[Watts], phase1.apparentPower[Watts], phase1.Vrms[Volts], phase1.Irms[Ampers], phase1.powerFactor, phase2.realPower[Watts], phase2.apparentPower[Watts], phase2.Vrms[Volts], phase2.Irms[Ampers], phase2.powerFactor, phase3.realPower[Watts], phase3.apparentPower[Watts], phase3.Vrms[Volts], phase3.Irms[Ampers], phase1.powerFactor

### Example output
    1328.1776,1395.2158,229.5877,6.0773,0.9519,166775.26,1947.8288,227.1191,8.577,0.92,1418.4513,1487.4756,230.4413,6.4552,0.953


# Flow meter support
The code also support [Grundfos VFS 5-100 QT](https://github.com/pingec/ArduinoPowerMonitor/raw/master/resources/Grundfosliterature-3081237.pdf) flow meter connected on pins A6 (flow) and A7 (temp).
To enable it, uncommet the FLOW_METER define.

**Be aware that enabling this will change the output format!**

## Output (flow meter enabled)
An easy way to distinguish logs that show flow meter values from those that don't is to check if the line begins with "FM".

Measured data will be output to serial port in a format of:

    FM,flowmeter.flowrate[l/min],flowmeter.temperature[°C],phase1.realPower[Watts], phase1.apparentPower[Watts], phase1.Vrms[Volts], phase1.Irms[Ampers], phase1.powerFactor, phase2.realPower[Watts], phase2.apparentPower[Watts], phase2.Vrms[Volts], phase2.Irms[Ampers], phase2.powerFactor, phase3.realPower[Watts], phase3.apparentPower[Watts], phase3.Vrms[Volts], phase3.Irms[Ampers], phase1.powerFactor

### Example output
    FM31.24,38.72,1029.57,1465.41,230.07,6.37,0.70,965.36,1406.79,225.80,6.23,0.69,1545.48,2010.47,227.95,8.82,0.77


