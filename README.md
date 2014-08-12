ArduinoPowerMonitor
===================

Arduino 3phase AC voltage, current and power monitor (uses EmonLib), outputs to serial

##Dependencies
Depends on emontx's lib EmonLib (a working version is included and should be installed by copying the EmonLib folder to wherever your IDE setup expects libs).

##Setup
Calibration constants in main.ino should be adjusted to suit the actual sensors.

##Output
Measured data will be output to serial port in a format of:

    phase1.realPower[Watts], phase1.apparentPower[Watts], phase1.Vrms[Volts], phase1.Irms[Ampers], phase1.powerFactor, phase2.realPower[Watts], phase2.apparentPower[Watts], phase2.Vrms[Volts], phase2.Irms[Ampers], phase2.powerFactor, phase3.realPower[Watts], phase3.apparentPower[Watts], phase3.Vrms[Volts], phase3.Irms[Ampers], phase1.powerFactor

###Example output
    1328.1776,1395.2158,229.5877,6.0773,0.9519,166775.26,1947.8288,227.1191,8.577,0.92,1418.4513,1487.4756,230.4413,6.4552,0.953

