/***************************************
Program Name: Project 1
Author: Robert Elsom
Date: 1/10/2019
Description: Checks that inputted string from the menu function
			fits in the parameters of the program. If 
			it does, it returns the string that was tested.
**************************************/

#include <string>
#include <iostream>
#include <ctype.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;

string validStr(string prompt, string choice1, string choice2)	{
	string testString;
	bool validFlag = false;
	string userChoice;

	while (validFlag == false)	{
		cout << prompt << endl;
		cin >> userChoice;
		
		if (userChoice == choice1 || userChoice == choice2)	{
			validFlag = true;
			return userChoice;
		}
		else	{
			cout << "Sorry, that is not a valid option" << endl;
		
		}
	}	
}