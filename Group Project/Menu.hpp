/*
CS 162 Group Project - Menu Class Header File
Date: Feb 7, 2019
Group Members: David Mikulis, James Scanlon, Robert Elsom, Frannie Richert
Class Member Variables: userChoice, rows, columns, numberAnts, numberDoodlebugs, timeSteps
Class Member Functions: getTimeSteps, getBoardSize, getNumberAnts, getNumberDoodlebugs, initialMenu, 
						mainMenu, validInt
*/


#ifndef MENU_HPP
#define MENU_HPP

#include <string>


class Menu
{

private:
	int userChoice = 0;
	int rows;
	int columns;
	int numberAnts;
	int numberDoodlebugs;
	int timeSteps;
	bool validFlag = true;
	bool isNumber = false;
	int boardSize[2];
	int testInteger;
	std::string choice;

public:
	//constructor
	Menu();
	int getTimeSteps();
	int* getSizeBoard();
	int getNumberAnts();
	int getNumberDoodlebugs();
	int getRows();
	int getColumns();
	void initialMenu();
	void mainMenu();
	int validInt(std::string prompt, int lowerLimit, int upperLimit);
	//destructor
	~Menu();

};

#endif
