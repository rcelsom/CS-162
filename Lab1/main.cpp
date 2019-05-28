/***************************************
Program Name: Lab 1
Author: Robert Elsom
Date: 1/8/2019
Description: Main file that prompts user for size
			of matrix, calls readMatrix to write to 
			the matrix, and then calls determinate()
			to find the determinate of the matrix. Lastly
			it outputs the matrix filled in with numbers and
			displays the determinate.
**************************************/
#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;

#include "determinate.hpp"
#include "readMatrix.hpp"

int matrixInputValid(int arrSize)	{
	
	while (arrSize != 2 && arrSize != 3)  {
		cout << "Sorry, that is not a valid input. Please try again." << endl;
		cin >> arrSize;
	}
	
	return arrSize;
}

void printOutput(int* array[],int size,int matrixDeterminate) {
	
	cout << endl << "Matrix: "<< endl;
	for (int i = 0; i < size; i++)	{
		for (int j = 0; j < size; j++)	{
			cout << std::setw(10) << array[i][j] << " " ;
		}
		cout << endl;
	}
	cout << endl << "Determinate: " << matrixDeterminate << endl;
	


}

int main()	{

	int size;
	int matrixDeterminate;
	
	cout << "Please pick matrix size. \nFor a 2x2 input 2. \nFor a 3x3 input 3." << endl;
	cin >> size;
	
	matrixInputValid(size);

	//dynamically allocating the array based on user input
	int** array = new int*[size];
	for (int i=0; i < size; i++)	{
		array[i] = new int[size];
	}		
	
	readMatrix(array, size);
	
	matrixDeterminate = determinate(array, size);
	
	printOutput(array, size, matrixDeterminate);
	

	
	//deallocating the memory from the array to stop memory leaks
	for (int i = 0; i < size; i++)	{
		delete [] array[i];
	}
	delete [] array;

	return 0;
}
