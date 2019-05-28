/***************************************
Program Name: Project 8
Author: Robert Elsom
Date: 2/23/2019
Description: Sorts array parameter and stores in output files along with printing sorted arrays,
			then returns the output file name back to main in order to use in binarySearch
**************************************/
#include <fstream>
#include <iostream>
#include "sort.hpp"

std::string sort(int* array, std::string name, int size)	{
	std::string outputFileName;
	bool validStr = false;
	//prompt user for output file name
	std::cout << std::endl << "Please enter a name for the output file: " << std::endl;
	
	
	
	//validate string is .txt file
	while(! validStr)	{
		std::getline(std::cin, outputFileName);
	
		//make sure file name starts with letter or number
		if ((outputFileName[0] >= 48 && outputFileName[0] <=57) || (outputFileName[0] >= 65 && outputFileName[0] <=90)\
			|| (outputFileName[0] >=97 && outputFileName[0] <=122))	{	
			validStr = true;
			//since cannot have .txt with less than four characters, automatically add .txt
			if (outputFileName.length() <= 4)	{
				outputFileName += ".txt";
			}
			//test if name already has .txt, if not add it on
			unsigned int i = outputFileName.length() - 4;
			if( outputFileName[i] != '.' || outputFileName[i+1] != 't' || outputFileName[i+2] != 'x'\
			|| outputFileName[i+3] != 't')	{
				outputFileName += ".txt";
			}
		}
		else	{
			std::cout <<"Sorry, that is not valid file name. Try again."  << std::endl;
		}
	}
	//sort values, bubble sort algorithm found on pg 615 of text book 
	int temp;
	bool madeASwap;
	
	do {
		madeASwap = false;
		for (int i = 0; i < size - 1; i++)	{
			if (array[i] > array[i+1])	{
				temp = array[i];
				array[i] = array[i+1];
				array[i+1] = temp;
				madeASwap = true;
			}
		}
	}	while (madeASwap);
	
	//store in output file and print each number sorted
	std::ofstream ofs(outputFileName);
	
	std::cout << std::endl << "The sorted values for " << name << " are: " << std::endl;
	
	for (int i = 0; i < size; i++)	{
		ofs << array[i] << " ";
		std::cout << array[i] << "   ";
	}
	std::cout << std::endl;
	std::cout << "They are stored in " << outputFileName << std::endl << std::endl;
	ofs.close();
	
	return outputFileName;
}