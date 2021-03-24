/* *************************************************************************
* File Name   :	sensor-validate.c
* Description : Validate SOC & Current Readings
* Functions   : 1. checkSuddenJump
*		2. validateSOCreadings
*		3. validateCurrentreadings
* ************************************************************************* */

/* ***************************** Header Files ***************************** */
#include "sensor-validate.h"

/* *************************************************************************
* Function Name : CheckSuddenJump
* Description   : Check the sudden jump
* Arguments     : 1. value - values for compare
*		  2. nextValue - another values for compare
*	          3. maxDelta - Maximum acceptable changes
* Returns       : 0 or 1
* ************************************************************************* */
int checkSuddenJump(double value, double nextValue, double maxDelta) {
	
	if(nextValue - value > maxDelta) {
		return 0;
	}
	
	return 1;
}

/* *************************************************************************
* Function Name : validateSOCreadings
* Description   : validate the SOC readings
* Arguments     : 1. values - list of SOC values
*		  2. numOfValues - Number of SOC values
* Returns	: 0 or 1
* ************************************************************************* */
int validateSOCreadings(double* values, int numOfValues) {
		int lastButOneIndex = numOfValues - 1;
		for(int i = 0; i < lastButOneIndex; i++) 
		{
			if(!checkSuddenJump(values[i], values[i + 1], 0.05)) 
			{
				return 0;
			}
		}
	return 1;
}

/* *************************************************************************
* Function Name : validateCurrentreadings
* Description   : validate the Current readings
* Arguments	: 1. values - list of Current values
*		  2. numOfValues - Number of Current values
* Returns	: 0 or 1
* ************************************************************************* */
int validateCurrentreadings(double* values, int numOfValues) {
		int lastButOneIndex = numOfValues - 1;
		for(int i = 0; i < lastButOneIndex; i++) 
		{
			if(!checkSuddenJump(values[i], values[i + 1], 0.1)) 
			{
				return 0;
			}
		}
	return 1;
}
