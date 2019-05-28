/***************************************
Program Name: Lab6
Author: Robert Elsom
Date: 2/9/2019
Description: Menu to get user input to create linked list
			along with adding nodes to the list. 
**************************************/
#include <iostream>
#include "Menu.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;


//constructor
Menu::Menu()	{	
}

//gets user input and returns choice
int Menu::startMenu()	{
	/*if (firstTime == true)	{
		firstTime = false;
		firstOption = validInt("\nPlease choose one of the following: \n1. Create list from txt file\n"\
								"2. Create custom list\n", 1, 2);
	}
	if (firstOption == 1)	{
		//input from files
	}*/
	userChoice = -1;
	
	userChoice = validInt ("\nChoose one of the following options: \n\n1. Add a new node to the head.\n"\
						"2. Add a new node to the tail. \n3. Delete from head. \n4. Delete from tail.\n"\
						"5. Traverse the list reversely. \n6. Print head \n7. Print tail. \n8. Exit\n", 1, 9);

	return userChoice;
}

//validates user input
int Menu::validInt( string prompt, int lowerLimit, int upperLimit)	{
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

//deconstructor
Menu::~Menu()	{	}

