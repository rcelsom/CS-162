/***************************************
Program Name: Lab 1 
Author: Robert Elsom
Date: 1/8/2019
Description: Takes in size of the matrix the
			user inputted, wither 2x2 or 3x3
			and prompts the user to input values
			into the matrices.
**************************************/
#include <iostream>
#include "readMatrix.hpp"

using std::cout;
using std::cin;
using std::endl;


void readMatrix(int* ptrMatrix[], int matrixSize) {
	

	if (matrixSize==2) {
		cout << "Please enter four integers to plug into the matrix: " << endl;
		cin >> ptrMatrix[0][0] >> ptrMatrix[0][1] >> ptrMatrix[1][0] >> ptrMatrix[1][1]; 
	
	}

	else {
		cout << "Please enter nine integers to plug into the matrix" << endl;
		for (int i = 0; i < matrixSize; i++)	{
			for (int j = 0; j < matrixSize; j++)	{
			cin >> ptrMatrix[i][j];
			}		

		}
	
	}


	return;
}
