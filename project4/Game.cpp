/***************************************
Program Name: Project 7
Author: Robert Elsom
Date: 2/21/2019
Description: Game class file, contains functions to set up tournament,
			run fights, and update containers based on outcomes. 
**************************************/
#include "Game.hpp"
#include "Blue_Men.hpp"
#include "Harry_Potter.hpp"
#include "Barbarian.hpp"
#include "Medusa.hpp"
#include "Vampire.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

//creates new character after getting name from user and calls function to add to team lineups
void Game::newCharacter(int choice, int teamNumber)		{
	//add character to back of team 1 lineup
	cout << "What is this Character's name?" << endl;
	cin.ignore();
	std::getline(cin, name);
	
	if (teamNumber == 1)	{
		Character* temp;
		if (choice == 1)	{
			temp = new Blue_Men(3,12, name);
			lineupTeam1.addBack(temp);
		}
		else if (choice == 2)	{
			temp = new Barbarian(0,12, name);
			lineupTeam1.addBack(temp);
		}
		else if (choice == 3)	{
			temp = new Harry_Potter(0,10, name);
			lineupTeam1.addBack(temp);
		}
		else if (choice == 4)	{
			temp = new Medusa(3,8, name);
			lineupTeam1.addBack(temp);
		}
		else {
			temp = new Vampire(1,18, name);
			lineupTeam1.addBack(temp);
		}
		
	}
	
	//add character to back of team 2 lineup
	else	{
		Character* temp2;
		if (choice == 1)	{
			temp2 = new Blue_Men(3,12, name);
			lineupTeam2.addBack(temp2);
		}
		else if (choice == 2)	{
			temp2 = new Barbarian(0,12, name);
			lineupTeam2.addBack(temp2);
		}
		else if (choice == 3)	{
			temp2 = new Harry_Potter(0,10, name);
			lineupTeam2.addBack(temp2);
		}
		else if (choice == 4)	{
			temp2 = new Medusa(3,8, name);
			lineupTeam2.addBack(temp2);
		}
		else {
			temp2 = new Vampire(1,18, name);
			lineupTeam2.addBack(temp2);
		}
		lineupTeam2.printQueue();
		
	}

}

//moves losing character to loser container list
void Game::addToLoser(int teamNumber)		{
	Character* tempCharacter;
	if (teamNumber == 1)	{
		tempCharacter = lineupTeam1.getFront();
		tempCharacter->setTeam("A");
		lineupTeam1.removeFront();
		loserList.addBack(tempCharacter);
	}
	else	{
		tempCharacter = lineupTeam2.getFront();
		tempCharacter->setTeam("B");
		lineupTeam2.removeFront();
		loserList.addBack(tempCharacter);
	}
}

//moves winner of battle to back of line 
void Game::winnerMove(int teamNumber)	{
	if (teamNumber == 1)	{
		lineupTeam1.moveToBack();
	}
	else	{
		lineupTeam2.moveToBack();
	}
}

//updates current score
void Game::updateScore(int winner)	{
	if (winner == 1)	{
		team1Score += 2;
		team2Score -= 1;
	}
	else	{
		team2Score += 2;
		team1Score -= 1;
	}
}

//overall results, battle of all fights
void Game::battle()	{
	Character* tempCharacter;
	while (!lineupTeam1.isEmpty() && !lineupTeam2.isEmpty())	{
		winner = fight();
		
		updateScore(winner);
		
		if (winner == 1)	{
			//recover damage for winner
			tempCharacter = lineupTeam1.getFront();
			tempCharacter->damageRecovery();
			//move loser to loser container
			addToLoser(2);
			//move winner to back of line
			winnerMove(1);
		}
		else	{
			//recover damage for winner
			tempCharacter = lineupTeam2.getFront();
			tempCharacter->damageRecovery();
			//move loser to loser container
			addToLoser(1);
			//move winner to back of line
			winnerMove(2);
		}
	}
	
	//print final stats and scores
	cout << endl << "The final score was... \nTeam A: " << team1Score << "\nTeam B: " << team2Score << endl;
	if (team1Score > team2Score)	{
		cout << "The overall winner was Team A!!" << endl;
	}
	else if (team2Score > team1Score)	{
		cout << "The overall winner was Team B!!" << endl;
	}
	else	{
		cout << "Both teams tied this time!!" << endl;
	}
}

//evaluates fight between two individual characters
int Game::fight()	{
	
	round++;
	Character* tempCharacter = lineupTeam1.getFront();
	Character* tempCharacter2 = lineupTeam2.getFront();
	cout << endl << endl << "Round " << round << ": Team A "<< tempCharacter->getType() << " " << tempCharacter->getName();
	cout <<" vs Team B " << tempCharacter2->getType() << " " << tempCharacter2->getName() << endl;

			
	while (true)	{
		//player 1 attacking player 2, first half of round
		attackRoll = tempCharacter->attack();
		tempCharacter2->defense(attackRoll);
		
		//check if defender dies 
		if (tempCharacter2->getStrength() <= 0)	{
			cout << tempCharacter->getType() << " " << tempCharacter->getName() << " Won!" << endl;
			return 1;
		}
		
		//player 2 attacking player 1, second half of round
		attackRoll = tempCharacter2->attack();
		tempCharacter->defense(attackRoll);
		
		//check if defender dies
		if (tempCharacter->getStrength() <= 0)	{
			cout << tempCharacter2->getType() << " " << tempCharacter2->getName() << " Won!" << endl;
			return 2;
		}
	}
}

//prints loser container
void Game::printLosers()	{
	cout << "The losers starting with the most recent were: " << endl;
	loserList.printReverseQueue();
}

Game::~Game()	{

}
