/***************************************
Program Name: Project 1
Author: Robert Elsom
Date: 1/10/2019
Description: Presents the start and repeat menu
			to the user along with the starting 
			prompts, which it returns the answers to 
			in an int array. 
**************************************/

/**************************************************
For menu with repeat option, pass true in second parameter
of function call each time calling the repeat option
***************************************************/


#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>

//need to include all header files in order to call set functions based on input.
#include "menu.hpp"
#include "Ant.hpp"
#include "validInt.hpp"
#include "validStr.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

void menu(int* responseArr, bool repeatMenu)	{
	string choice;
	string startChoice;
	int boardRow;
	int boardCol;
	int steps;
	int playerRow;
	int playerCol;
	string randomChoice;
	bool randomInputValid = false;





	//contains all strings to plug in as prompts
	string startingTitle = "Welcome to Langston's Ant.\n";
    string startingPrompt = "Please choose one of the following. \n";
    startingPrompt += "1. Start Langston's Ant simulation \n";
    startingPrompt += "2. Quit.";
	string boardRowPrompt = "Number of rows on the board: ";
	string boardColPrompt = "Number of columns on the board: ";
	string stepsPrompt = "Number of steps: ";
	string randomChoicePrompt = "Would you like to start the ant at a random position(Y/N)?";
	string playerRowPrompt = "Starting row of the ant: ";
	string playerColumnPrompt = "Starting column of the ant: ";
	string repeatPromptTitle = "Simulation has ended. Please choose one of the following. \n";
	string repeatPrompt = "1. Repeat Langston's Ant. \n";
	repeatPrompt += "2.Quit.";

	
		//if first time running program, display starting title and prompt
	if (repeatMenu == false)	{
		cout << startingTitle;
		startChoice = validStr(startingPrompt, 1);
		responseArr[6] = 1;
	}
	else {
		cout <<repeatPromptTitle;
		startChoice = validStr(repeatPrompt, 1);
	}
		
	if (startChoice == "1")	{
		boardRow = validInt(boardRowPrompt, 1);
		boardCol = validInt(boardColPrompt, 1);
		steps = validInt(stepsPrompt, 0);
		responseArr[0] = boardRow;
		responseArr[1] = boardCol;
		responseArr[2] = steps;


		while(randomInputValid == false)	{
			randomChoice = validStr(randomChoicePrompt, 2);
			if (randomChoice == "Y" || randomChoice == "y")	{
				randomInputValid = true;
				srand(time(NULL));
				playerRow = rand() % boardRow;
				playerCol = rand() % boardCol;
			}
			else {
				randomInputValid = true;
				playerRow = validInt(playerRowPrompt, 2, boardRow, boardCol, "row");
				playerCol = validInt(playerColumnPrompt, 2, boardRow, boardCol, "col");
			}
			responseArr[3] = playerRow;
			responseArr[4] = playerCol;
		}
	}
	
	else 	{
		exit(0);
	}
}