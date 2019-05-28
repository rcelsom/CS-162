/***************************************
Program Name: Project 8
Author: Robert Elsom
Date: 2/23/2019
Description: main function for lab 8. Creates arrays from txt files and passes
			them to functions sort, simpleSearch, and binarySearch with their respective
			header and implementation files. 
**************************************/
#include <fstream>
#include <iostream>
#include <string>
#include "validInt.hpp"
#include "simpleSearch.hpp"
#include "binarySearch.hpp"
#include "sort.hpp"
struct Files	{
		std::string name;
		int size;
	};

int main()	{
	//get user inputted integer to search for
	int searchNum = validInt("What is the target value: \n", -10000, 10000);
	
	
	
	Files fileName[4] = {{"num.txt", 9} , {"early.txt", 10}, {"middle.txt", 10}, {"late.txt", 10}};
	
	//open all files
	std::ifstream num(fileName[0].name);
	std::ifstream early(fileName[1].name);
	std::ifstream middle(fileName[2].name);
	std::ifstream late(fileName[3].name);
	
	std::string txtInt;
	int arrayElement;
	int counter;
	
	int numArray[9];
	int earlyArray[10];
	int middleArray[10];
	int lateArray[10];
	
	//store numbers into arrays, reset counter after every array is done storing
	counter = 0;
	while (num >> txtInt)	{
		arrayElement = std::stoi(txtInt);
		numArray[counter] = arrayElement;
		counter++;
	}
	
	counter = 0;
	while (early >> txtInt)	{
		arrayElement = std::stoi(txtInt);
		earlyArray[counter] = arrayElement;
		counter++;
	}
	
	counter = 0;
	while (middle >> txtInt)	{
		arrayElement = std::stoi(txtInt);
		middleArray[counter] = arrayElement;
		counter++;
	}
	
	counter = 0;
	while (late >> txtInt)		{
		arrayElement = std::stoi(txtInt);
		lateArray[counter] = arrayElement;
		counter++;
	}
	
	//simple search calls for arrays
	simpleSearch(numArray, searchNum, fileName[0].name, fileName[0].size);
	simpleSearch(earlyArray, searchNum, fileName[1].name, fileName[1].size);
	simpleSearch(middleArray, searchNum, fileName[2].name, fileName[2].size);
	simpleSearch(lateArray, searchNum, fileName[3].name, fileName[3].size);
	
	//sort calls for arrays and store in output files, returns output file names
	std::cin.ignore();
	std::string numSorted = sort(numArray, fileName[0].name, fileName[0].size);
	std::string earlySorted = sort(earlyArray, fileName[1].name, fileName[1].size);
	std::string middleSorted = sort(middleArray, fileName[2].name, fileName[2].size);
	std::string lateSorted = sort(lateArray, fileName[3].name, fileName[3].size);
	
	//call all binary searches
	binarySearch(numSorted, fileName[0].name, fileName[0].size, searchNum);
	binarySearch(earlySorted, fileName[1].name, fileName[1].size, searchNum);
	binarySearch(middleSorted, fileName[2].name, fileName[2].size, searchNum);	
	binarySearch(lateSorted, fileName[3].name, fileName[3].size, searchNum);
	
	//close all ifstreams
	num.close();
	early.close();
	middle.close();
	late.close();
}
	
	
	