/***************************************
Program Name: Project 7
Author: Robert Elsom
Date: 2/21/2019
Description: Game header file.
**************************************/
#include "Queue.hpp"
#include <string>

#ifndef GAME_HPP
#define GAME_HPP
class Game 	{
private:
	Queue lineupTeam1;
	Queue lineupTeam2;
	Queue loserList;
	int team1Score = 0;
	int team2Score = 0;
	int score = 0;
	std::string name;
	int round = 0;
	int winner;
	int attackRoll;
	
public:
	void newCharacter(int choice, int teamNumber);
	void addToLoser(int winningTeam);
	void winnerMove(int winningTeam);
	void battle();
	int fight();
	int getScore(int teamNumber);
	void updateScore(int );
	void printLosers();
	~Game();
	
};
#endif