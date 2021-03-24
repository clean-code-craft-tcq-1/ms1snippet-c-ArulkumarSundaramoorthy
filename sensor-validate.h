/* *************************************************************************
* File Name   :	sensor-validate.h
* Description : Validate SOC & Current Readings
* Functions	  : - 
* ************************************************************************* */
#ifndef SENSOR_VALIDATE_H
#define SENSOR_VALIDATE_H

/* ***************************** Prototypes ***************************** */
int checkSuddenJump(double value, double nextValue, double maxDelta);
int validateSOCreadings(double* values, int numOfValues);
int validateCurrentreadings(double* values, int numOfValues);

	
#endif
