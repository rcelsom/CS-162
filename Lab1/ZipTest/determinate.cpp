/***************************************
Program Name: Lab 1
Author: Robert Elsom
Date: 1/8/2019
Description: Takes a pointer to a filled out 
			matrix and calculates and returns 
			the determinate of that matrix
**************************************/

#include "determinate.hpp"

int determinate(int* a[], int detMatrixSize) {
		int det;
		
		//calculates determinate of 2x2 matrix
		if (detMatrixSize == 2) {
			det = a[0][0] * a[1][1] - a[0][1] * a[1][0];
		}
		
		//calculates determinate of a 3x3 matrix
		else	{
			det = a[0][0] * (a[1][1]*a[2][2] - a[1][2]*a[2][1]) 
				- a[0][1] * (a[1][0]*a[2][2] - a[1][2]*a[2][0])
				+ a[0][2] * (a[1][0]*a[2][1] - a[1][1]*a[2][0]);
		}

		return det;
}
