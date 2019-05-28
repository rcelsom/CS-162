/***************************************
Program Name: Project 8
Author: Robert Elsom
Date: 2/23/2019
Description: Completes binary search on array parameter from output files
**************************************/
#include <iostream>
#include <string>
#include <fstream>
#include "binarySearch.hpp"

using std::endl;

void binarySearch(std::string sortedFileName, std::string name, int size, int target)	{
	int first = 0;
	int last = size - 1;
	int middle;
	int* array = new int[size]();
	int counter = 0;
	bool found = false;
	std::string number;
	
	//get sorted array from output file
	std::ifstream arrayInput(sortedFileName);
	
	
	if (arrayInput.fail())	{
		std::cout << endl << "Sorry, the output file did not have a valid name and could not be opened." << endl << endl;
	}
	else	{
		//store file ints into an array
		while (arrayInput >> number)	{
			array[counter] = std::stoi(number);
			counter++;
		}
		
		//perform binary search based on number of values, found code on page 607 of text book
		while (!found && first <= last)		{
			middle = (first + last) / 2;
			if (array[middle] == target)	{
				found = true;
			}
			else if (array[middle] > target)	{
				last = middle - 1;
			}
			else	{
				first = middle + 1;
			}
		}
		
		//print results like in simple search
		if (found)	{
			std::cout << name << ": target value found" << endl << endl;
		}
		else{
			std::cout << name <<": target value not found" << endl << endl;
		}
	}
	
	delete [] array;
	
}	