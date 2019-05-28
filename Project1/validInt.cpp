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
*	to reuse: change upperLimitSteps and lowerLimitSteps
*			  to upper and lower limits
*
*Test case 1 = Size of Board
*	to reuse: change upperLimitBoard and lowerLimitBoard
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

int validInt( string prompt, int testCase, int boardRow, int boardCol, string rowOrCol )	{
	int testInteger;
	bool validFlag = false;
	bool isNumber = true;
	string choice;
	//upper and lower limit for number of rows, cols, and steps for test case 1
	int upperLimitBoard = 400;
	int lowerLimitBoard = 1;
	int upperLimitSteps = 100000;
	int lowerLimitSteps = 0;
	string playerName = "ant";

	//lower limit for rows and cols of starting position of player
	int lowerLimit2 = 0;
	
	//testing input against limits for number of steps
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

			    if (testInteger > upperLimitSteps)	{
		    		cout << "Sorry, that number is too large" << endl;
		    	}
		      	else if (testInteger < lowerLimitSteps)	{
		    		cout << "Sorry, the number must be greater than 0"<< endl;
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

			//if variable choice passes as being a number, now verify that board size is in range
			//fit in the limits of the program parameters
			else   {
			    testInteger = stoi(choice);

			    if (testInteger > upperLimitBoard)	{
		    		cout << "Sorry, that number is too large" << endl;
		    	}
		      	else if (testInteger < lowerLimitBoard)	{
		    		cout << "Sorry, the number must be greater than 0"<< endl;
		    	}
				else{
					validFlag = true;
				}
			}
	    }

		return testInteger;
	}

	// testing valid starting position of the player.
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

			//if variable choice passes as being a number, now verify that player starting position is on board
			else   {
			    testInteger = stoi(choice);

				if (rowOrCol == "row")	{
					if (testInteger >= boardRow || testInteger < lowerLimit2)	{
						cout << "Sorry, the "<< playerName<<" must start on the board" << endl;
					}
					else	{
						validFlag = true;
					}
				}
				else	{
					if (testInteger >= boardCol || testInteger < lowerLimit2)	{
						cout << "Sorry, the " << playerName<<" must start on the board" << endl;
					}
					else {
						validFlag = true;
					}
				}
	   	    }
	    }

		return testInteger;
	}

	return 0;
}
