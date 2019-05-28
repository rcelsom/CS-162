/***************************************
Program Name: Lab3
Author: Robert Elsom
Date: 1/19/2019
Description: Displays menu to user, if user 
			chooses to play, then prompts user
			for input including number of rounds to play
			, number if sides per dice, and type of dice.
			Then calls class Die and loadedDie to play game 
			for number of rounds and calculates score after each
			round. Dispalys results for each round. 
**************************************/

#include <iostream>
#include <cstdlib>
#include <string>

#include "Game.hpp"
#include "validStr.hpp"
#include "validInt.hpp"


using std::cout;
using std::cin;
using std::endl;
using std::string;

//starting menu
void Game::menu()	{
	cout << "Welcome to Dice War" << endl;
	cout << "Please choose one of the following. " << endl;
	cout << "1. Play Dice War" << endl << "2. Quit" << endl;
	startingChoice = validStr("",1);
	
	if (startingChoice == "2")	{
		exit(0);
	}
	
	userInput();

}


//gets user input for number of rounds, number of sides, and type of die.
void Game::userInput()	{
	rounds = validInt("Enter the number of rounds: ",0);
	
	//input for player 1
	cout << "\t\tPlayer 1 Input " << endl;
	sidesP1 = validInt("Number of sides: ",  1);
	cout << "Type of Die: " << endl;
	typeDieP1 = validStr("  1. Normal Die \n  2. Loaded Die", 1);
	
	//input for player 2
	cout << "\t\tPlayer 2 Input " << endl;
	sidesP2 = validInt("Number of sides: ",  1);
	cout << "Type of Die: " << endl;
	typeDieP2 = validStr("  1. Normal Die \n  2. Loaded Die", 1);

	setDieType();
}




//creating Die objects based on die type for each player
void Game::setDieType()	{
	
	if (typeDieP1 == "1")	{
		player1 = new Die(sidesP1);
		p1DieType = "Normal ";
		}
	else if (typeDieP1 == "2") {
		player1 = new LoadedDie(sidesP1);
		p1DieType = "Loaded ";
	}
	if (typeDieP2 == "1")	{
		player2 = new Die( sidesP2);
		p2DieType = "Normal ";
	}
	else if (typeDieP2 == "2")	{
		player2 = new LoadedDie( sidesP2);
		p2DieType = "Loaded ";
	}
}

//loop through rounds
void Game::playGame()	{

	for (int i = 0; i < rounds; i++)	{
		p1Roll = player1->roll();
		p2Roll = player2->roll();
		if (p1Roll < p2Roll)	{
			p2Wins += 1;
			playerWon = "Player 2 won";
			printRound();
		}
		else if (p1Roll > p2Roll)	{
			p1Wins += 1;
			playerWon = "Player 1 won";
			printRound();
		}
		else 	{
			ties += 1;	
			playerWon = "It was a tie";
			printRound();
		}
	}

	printFinal();
}
	
//print board after round
void Game::printRound() {
		cout << "--------------------------------------------------------------" << endl;
		cout << playerWon <<" this round!" << endl << "Current Score: " << p1Wins << " - " << p2Wins;
		cout << " - " << ties << endl << endl;
		cout << "\tPlayer 1:" << endl << "Rolled Number: " << p1Roll << endl << "Score: " << p1Wins << endl; 
		cout << "Number of sides: " << sidesP1 << endl << "Type of Die: " << p1DieType << endl << endl;
		cout << "\tPlayer 2:" <<  endl << "Rolled Number: " << p2Roll << endl << "Score: " << p2Wins << endl; 
		cout << "Number of sides: " << sidesP2 << endl << "Type of Die: " << p2DieType << endl << endl;
		cout << "\tTies: " << ties << endl;
		cout << "--------------------------------------------------------------" << endl;
}

//prints final results and delete new objects
void Game::printFinal()	{
		cout << "--------------------------------------------------------------" << endl;
		if (p2Wins > p1Wins)	{
			cout << "Player 2's " << sidesP2 << "-sided " << p2DieType << "Die won the game!!!" << endl;
		}
		else if (p2Wins < p1Wins)	{
			cout << "Player 1's " << sidesP1 << "-sided " << p1DieType<< "Die won the game!!!" << endl;
		}
		else	{
			cout << "This game was a tie!!" << endl;
		}
		cout << "Final Score: "<< endl << "Player 1: "<< p1Wins;
		cout << "\tPlayer 2: " << p2Wins << "\tTies: " << ties << endl;
		cout << "--------------------------------------------------------------" << endl;

}

//Game deconstructor
Game::~Game()	{
	delete player1;
	delete player2;	
}

