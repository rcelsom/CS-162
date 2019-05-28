/***************************************
Program Name: Project 1
Author: Robert Elsom
Date: 1/10/2019
Description: Checks that inputted string from the menu function
			fits in the parameters of the program. If 
			it does, it returns the string that was tested.
**************************************/

/**********************************************
Test case 1 = starting menu prompt
	to reuse: change number of menu options
			  update if statement to contain all options

Test case 2 = Y or N question
	to reuse: no changes necessary
**********************************************/
#include <string>
#include <iostream>
#include <ctype.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;

string validStr(string prompt, int testCase)	{
	string testString;
	bool validFlag = false;
	string userChoice;
	
	//write all menu options
	string firstMenuChoice1 = "1";
	string firstMenuChoice2 = "2";
	//quit choice for first test case
	
	//test case for first menu prompt
	if (testCase == 1)	{
		while (validFlag == false)	{
			cout << prompt << endl;
			cin >> userChoice;
			
			//need to add options for future tests
			if (userChoice == firstMenuChoice1 || userChoice == firstMenuChoice2)	{
				validFlag = true;
				return userChoice;
			}
			else	{
				cout << "Sorry, that is not a valid option" << endl;
			
			}
		}	
	}
	//yes or no test case using Y and N
	else if (testCase == 2)	{
		while (validFlag == false)	{
			cout << prompt << endl;
			cin >> userChoice;
		
			if (userChoice == "Y" || userChoice == "y" || userChoice == "N" || userChoice == "n")	{
				validFlag = true;
				return userChoice;
			}
			else	{
				cout << "Sorry, that is not a valid option" << endl;
			
			}
		}	
	}
	return "";
}