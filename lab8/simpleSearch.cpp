/***************************************
Program Name: Project 8
Author: Robert Elsom
Date: 2/23/2019
Description: Performs simple search to search entire array. 
**************************************/
#include <iostream>
#include "simpleSearch.hpp"

using std::endl;

void simpleSearch(int* arrayPtr, int testValue, std::string name, int size)	{
	bool found = false;
	
	for (int i = 0; i < size; i++)	{
		if (arrayPtr[i] == testValue)	{
			found = true;
		}
	}
	
	if (found)	{
		std::cout << endl << name <<": target value found" << endl;
	}
	else	{
		std::cout << endl << name <<": target value not found" << endl;
	}
}
