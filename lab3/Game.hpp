/***************************************
Program Name: Lab3
Author: Robert Elsom
Date: 1/19/2019
Description: Header file for Game class
**************************************/
#include "Die.hpp"
#include "LoadedDie.hpp"

#ifndef GAME_HPP
#define	GAME_HPP


class Game	{
	
private:
	int rounds;
	int sidesP1;
	int sidesP2;
	int p1Wins = 0;
	int p2Wins = 0;
	int ties = 0;
	int p1Roll;
	int p2Roll;
	std::string p1DieType = "";
	std::string p2DieType = "";
	std::string playerWon;
	std::string typeDieP1 = "1";
	std::string typeDieP2 = "1";
	std::string startingChoice;
	Die* player1;
	Die* player2;



public:
	~Game();
	void menu();
	void printRound();
	void printFinal();
	void userInput();
	void setDieType();
	void playGame();
};

#endif