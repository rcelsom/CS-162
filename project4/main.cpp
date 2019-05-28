/***************************************
Program Name: Project 7
Author: Robert Elsom
Date: 2/21/2019
Description: main and menu functions from Project 7.
			Sets up function calls and gets user input to 
			pass to game class. 
**************************************/
#include <iostream>
#include "validInt.hpp"
#include "validStr.hpp"
#include "Game.hpp"

using std::cout;
using std::cin;
using std::endl;

//menu function to get input prompts
void menu()	{
	cout << "Welcome to Fantasy Combat!" << endl;
	int choice = validInt("Choose one of the following: \n1.Play \n2.Exit", 1, 2);
	if (choice == 1)	{
		while (choice == 1)	{
			Game game;
			int characterChoice;
			
			//create empty lineups
			int sizeTeam1 = validInt("\nHow many fighters for team 1?\n" , 1, 30);
			int sizeTeam2 = validInt("\nHow many fighters for team 2?\n" , 1, 30);
			
			//create new fighters for team one lineup
			for (int i = 0; i < sizeTeam1; i++)	{
				characterChoice = validInt("What character would you like to add to Team 1's lineup? \n"\
											"1. Blue Men \n2. Barbarian \n3. Harry Potter \n4. Medusa \n5.Vampire", 1, 5);
				game.newCharacter(characterChoice, 1);
			}
			
			//create new fighters for team twos lineup
			for (int i = 0; i < sizeTeam2; i++)	{
				characterChoice = validInt("What character would you like to add to Team 2's lineup? \n"\
											"1. Blue Men \n2. Barbarian \n3. Harry Potter \n4. Medusa \n5.Vampire", 1, 5);
				game.newCharacter(characterChoice, 2);
			}
			
			//start battle
			game.battle();
			
			//option to print losers
			std::string loserPrintChoice = validStr("\nWould you like to print a list of losers? (Y/N)\n", 2);
			if (loserPrintChoice == "Y" || loserPrintChoice == "y")	{
				game.printLosers();
			}
			
			//option to repeat
			choice =  validInt("\n\nChoose one of the following: \n1.Play Again \n2.Exit\n", 1, 2);
		}
	}
	else	{
		return;
	}
	
}

int main()	{
	menu();
}