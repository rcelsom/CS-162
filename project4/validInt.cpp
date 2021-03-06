/***************************************
Program Name: Project 7
Author: Robert Elsom
Date: 2/21/2019
Description: Checks that inputted integer from the menu function
			fits in the parameters of the program. If 
			it does, it returns the integer that was tested.
**************************************/

#include <string>
#include <iostream>
#include <ctype.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int validInt( string prompt, int lowerLimit, int upperLimit)	{
	int testInteger;
	bool validFlag = false;
	bool isNumber = true;
	string choice;

	while(validFlag == false)	{
		cout << prompt;
		cin >> choice;
		
		//check if negative number
		if (choice[0] != '-' && !isdigit(choice[0]))	{
			isNumber = false;
		}
		
		//changes flag isNumber if any part of input is not a digit after first which could be negative sign
		for (unsigned int i = 1; i <choice.length(); i++)    {
			if (!isdigit(choice[i]))    {
			   isNumber = false;
			}
		}

		if(!isNumber)   {
			cout<< "Sorry, that is not a valid input" << endl;
			isNumber= true;
		}

		//if variable choice passes as being a number, now verify that it is in range and
		//fit in the limits of the program parameters
		else   {
			testInteger = stoi(choice);

			if (testInteger > upperLimit || testInteger < lowerLimit)	{
				cout << "Sorry, that number must be in the range " << lowerLimit << " to " << upperLimit << "." << endl << endl;
			}
			else{
				validFlag = true;
			}
		}
	}

	return testInteger;
	
}
