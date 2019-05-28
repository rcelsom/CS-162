/***************************************
Program Name: Project 1
Author: Robert Elsom
Date: 1/10/2019
Description: Checks that inputted integer from the menu function
			fits in the parameters of the program. If 
			it does, it returns the integer that was tested.
**************************************/

/**********************************************************
*Test case 0 = number of steps
*	to reuse: change upperLimitRounds and lowerLimitRounds
*			  to upper and lower limits
*
*Test case 1 = Size of Board
*	to reuse: change upperLimitSides and lowerLimitSides
*			  to upper and lower limits
*			  
*Test case 2 = Starting position of the player
*	to reuse: Change playerName to name of player
***********************************************************/
#include <string>
#include <iostream>
#include <ctype.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int validInt( string prompt, int testCase, int sideDice )	{
	int testInteger;
	bool validFlag = false;
	bool isNumber = true;
	string choice;
	//upper and lower limit for number of sides of dice, number of rounds
	int upperLimitSides = 400;
	int lowerLimitSides = 2;
	int upperLimitRounds = 100000;
	int lowerLimitRounds = 1;
	string playerName = "ant";

	//lower limit for rows and cols of starting position of player
	int lowerLimit2 = 0;
	
	//testing input against limits for number of rounds
	if (testCase == 0)	{

		while(validFlag == false)	{
		    cout << prompt << endl;
		    cin >> choice;

			//changes flag isNumber if any part of input is not a digit
			for (unsigned int i = 0; i <choice.length(); i++)    {
			    if (!isdigit(choice[i]))    {
			       isNumber = false;
			    }
			}

			if(!isNumber)   {
			    cout<< "Sorry, that is not a valid input" << endl;
			    isNumber= true;
			}

			//if variable choice passes as being a number, now verify that board size and steps fit
			//fit in the limits of the program parameters
			else   {
			    testInteger = stoi(choice);

			    if (testInteger > upperLimitRounds)	{
		    		cout << "Sorry, that number is too large" << endl;
		    	}
		      	else if (testInteger < lowerLimitRounds)	{
		    		cout << "Sorry, the number must be greater than " << lowerLimitRounds -1 << endl;
		    	}
				else{
					validFlag = true;
				}
			}
	    }

		return testInteger;
	}

	//if we are testing the valid input for the size of the board
	if (testCase == 1)	{

		while(validFlag == false)	{
		    cout << prompt;
		    cin >> choice;

			//changes flag isNumber if any part of input is not a digit
			for (unsigned int i = 0; i <choice.length(); i++)    {
			    if (!isdigit(choice[i]))    {
			       isNumber = false;
			    }
			}

			if(!isNumber)   {
			    cout<< "Sorry, that is not a valid input" << endl;
			    isNumber= true;
			}

			//if variable choice passes as being a number, now verify that board size is in range
			//fit in the limits of the program parameters
			else   {
			    testInteger = stoi(choice);

			    if (testInteger > upperLimitSides)	{
		    		cout << "Sorry, that number is too large" << endl;
		    	}
		      	else if (testInteger < lowerLimitSides)	{
		    		cout << "Sorry, the number must be greater than "<< lowerLimitSides-1 << endl;
		    	}
				else{
					validFlag = true;
				}
			}
	    }

		return testInteger;
	}

	// testing valid number of sides on the die
	else if (testCase == 2)	{
		while(validFlag == false)	{
		    cout << prompt << endl;
		    cin >> choice;

			//changes flag isNumber if any part of input is not a digit
			for (unsigned int i = 0; i < choice.length(); i++)    {
			    if (!isdigit(choice[i]))    {
			       isNumber = false;
			    }
			}

			if(!isNumber)   {
			    cout<< "Sorry, that is not a valid input " << endl;
			    isNumber= true;
			}
	    }

		return testInteger;
	}

	return 0;
}
