
/*
CS 162 Group Project - Menu Class Function Definitions
Date: Feb 7, 2019
Group Members: David Mikulis, James Scanlon, Robert Elsom, Frannie Richert
Class Member Variables:
Class Member Functions:
*/

#include "Menu.hpp"
#include <iostream>
#include <ctype.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;

//constructor
Menu::Menu()	{
	this->rows = -1;
	this->columns = -1;
	this->numberAnts = -1;
	this->numberDoodlebugs = -1;
	this->timeSteps = -1;
}

//validates user input is and int between lower and upper limit 
int Menu::validInt(std::string prompt, int lowerLimit, int upperLimit)	{
	validFlag = false;
	isNumber = true;

	while(validFlag == false)	{
		cout << prompt;
		cin >> choice;
		
		/*
		//check if negative number
		if (choice[0] != '-' && !isdigit(choice[0]))	{
			isNumber = false;
		}
		*/
		
		//changes flag isNumber if any part of input is not a digit, change i to start at 1
		//to check for negative number
		for (unsigned int i = 0; i <choice.length(); i++)    {
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
	

//displays initial menu and gets board size, number of ants, number of doodlebugs, 
//and number of time steps
void Menu::initialMenu()	{
	cout << "Welcome to Predator-Prey game!" << endl;
	timeSteps = validInt( "How many time steps would you like to run?\n", 1, 10000);
	rows = validInt("How many rows does the board have?\n", 2, 400);
	columns = validInt("How many columns does the board have?\n", 2, 400);
	//upper limit makes sure it does not over flow the board and leaves atleast one space
	//for doodlebug
	numberAnts = validInt("How many ants would you like?\n", 1, (rows*columns-1));
	//upper limit makes sure it does not overflow the board based on number of ants
	numberDoodlebugs = validInt("How many doodlebugs would you like?\n", 1, ((rows*columns)-numberAnts)); 
	cout << columns  << rows << numberAnts << numberDoodlebugs << endl;
}

//continue menu that reprompts for number of time steps
void Menu::mainMenu()	{
	userChoice = validInt("Please choose one of the following.\n1. Enter new number of time steps\n"\
						  "2. Exit\n", 1, 2);
	if (userChoice == 1)	{
		timeSteps = validInt ("How many time steps would you like to run?\n", 1, 10000);
	}
	else	{
		return;
	}
}

//returns time steps
int Menu::getTimeSteps()	{
	return timeSteps;
}

//returns size of board in array {rows, columns}
int* Menu::getSizeBoard()	{
	boardSize[0] = rows;
	boardSize[1] = columns;
	return boardSize;
}

//returns number of rows
int Menu::getRows()	{
	return rows;
}

//returns number of columns
int Menu::getColumns()	{
	return columns;
}

//returns number of ants
int Menu::getNumberAnts()	{
	return numberAnts;
}

//returns number of doodlebugs
int Menu::getNumberDoodlebugs()	{
	return numberDoodlebugs;
}


//destructor
Menu::~Menu()	{	}