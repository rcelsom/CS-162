/***************************************
Program Name: lab 4
Author: Robert Elsom
Date: 1/27/2019
Description: Checks that inputted value from the menu function
			fits in the parameters of the program and is a double value,
			If it does, it returns the double that was tested.
**************************************/

#include <string>
#include <iostream>
#include <ctype.h>
#include <cmath>
#include <cstdlib>
#include "validDbl.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

double validDbl(std::string prompt, double lowerLimit, double upperLimit)	{
	
	double testDouble;
	bool validFlag = false;
	bool isNumber ;
	string choice;
	int periodCounter ;

	while(validFlag == false)	{
		isNumber = true;
		periodCounter = 0;
		
		cout << prompt;
		cin >> choice;

		//changes flag isNumber if any part of input is not a digit or decimal
		for (unsigned int i = 0; i <choice.length(); i++)    {
			if (!isdigit(choice[i]) && choice[i] != '.')    {
			   isNumber = false;
			}
			//check that there is only one period in the number
			if (choice[i] == '.')	{
				periodCounter++;
				
				//if there is more than on period, set number to false
				if(periodCounter > 1)	{
					isNumber = false;
				}				
			}
		}

		if(!isNumber)   {
			cout<< "Sorry, that is not a valid input" << endl;
		}
		
		//if variable choice passes as being a number, now verify that board size is in range
		//fit in the limits of the program parameters
		else   {
			testDouble = stod(choice);
			
			
			if ( testDouble > upperLimit )	{
				cout << "Sorry, that number is too large" << endl;
			}
			else if (testDouble < lowerLimit)	{
				cout << "Sorry, that number is too small"<< endl;
			}
			else{
				validFlag = true;
			}
		}
	}

	return testDouble;
}
	
	
