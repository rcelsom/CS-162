/***************************************
Program Name: Project 3
Author: Robert Elsom
Date: 2/4/2019
Description: main function and round funntion, gets users prompts 
			and creates two players. Then plays rounds with those players until 
			one is dead, printing the stats of each round as it happens. Lastly, 
			displays who wins and ask user if they would like to repeat the simulation.
**************************************/

#include <iostream>
#include <ctime>
#include "Character.hpp"
#include "validInt.hpp"
#include "Harry_Potter.hpp"
#include "Medusa.hpp"
#include "Blue_Men.hpp"
#include "Barbarian.hpp"
#include "Vampire.hpp"

using std::cout;
using std::cin;
using std::endl;

bool round(Character* char1, Character* char2)	{
	int attackRoll;
	int damage;
	
	
	
	cout << "-----------------------------------------------------" << endl;
	//player 1 attacking player 2, first half of round
	int tempStrength = char2->getStrength();
	attackRoll = char1->attack();
	char2->defense(attackRoll);
	if (char1->getDieRoll() - char2->getDieRoll() - char2->getArmor() < 0)	{
		damage = 0;
	}
	else	{
		damage = char1->getDieRoll() - char2->getDieRoll() - char2->getArmor();
	}
	
	//printing stats
	cout << "Attacker: "<< char1->getType() << endl;
	cout << "Defender: " << char2->getType() << endl;
	cout << "  Armor: " << char2->getArmor() << endl;
	cout << "  Strength: " << tempStrength << endl << endl;
	cout << "Attacker's Die Roll: " << char1->getDieRoll() << endl;
	cout << "Defender's Die Roll: " << char2->getDieRoll() << endl;
	cout << "Total Attack Damage: " << char1->getDieRoll() << " - ";
	cout << char2->getDieRoll() << " - " << char2->getArmor();
	cout << " = " << damage << endl;
	
	//set remaining strength to 0 if negative
	if (char2->getStrength() < 0)	{
		cout << "Updated Defender Strength: 0" << endl;
	}
	else	{
		cout << "Updated Defender Strength: " << char2->getStrength() << endl;
	}
	cout << "-----------------------------------------------------" << endl;
	
	//check if defender dies 
	if (char2->getStrength() <= 0)	{
		return true;
	}
	
	//player 2 attacking player 1, second half of round
	tempStrength = char1->getStrength();
	attackRoll = char2->attack();
	char1->defense(attackRoll);
	//checking for negative attack
	if (char2->getDieRoll() - char1->getDieRoll() - char1->getArmor() < 0)	{
		damage = 0;
	}
	else	{
		damage = char2->getDieRoll() - char1->getDieRoll() - char1->getArmor();
	}
	//printing round stats
	cout << "Attacker: "<< char2->getType() << endl;
	cout << "Defender: " << char1->getType() << endl;
	cout << "   Armor: " << char1->getArmor() << endl;
	cout << "   Strength: " << tempStrength << endl << endl;
	cout << "Attacker's Die Roll: " << char2->getDieRoll() << endl;	
	cout << "Defender's Die Roll: " << char1->getDieRoll() << endl;
	cout << "Total Attack Damage: " << char2->getDieRoll() << " - ";
	cout << char1->getDieRoll() << " - " << char1->getArmor();
	cout << " = " << damage << endl;
	
	//set remaining strength to 0 if negative
	if (char1->getStrength() < 0)	{
		cout << "Updated Defender Strength: 0" << endl;
	}
	else	{
		cout << "Updated Defender Strength: " << char1->getStrength() << endl;
	}
	cout << "-----------------------------------------------------" << endl << endl;
	
	//check if defender dies 
	if (char1->getStrength() <= 0)	{
		return true;
	}
	
	return false;
}

int main()		{
	int repeatChoice = 1;
	//set time for rand function
	srand(time(NULL));
	
	//contains repeat option if user wants to play again
	while (repeatChoice != 2)	{
		int firstPlayer;
		int secondPlayer;
		Character* player1;
		Character* player2;
		bool gameOver = false;
		
		
		//Create two characters
		cout << "Welcome to the game! Please choose one of the following: " << endl;
		//create first player
		firstPlayer = validInt("First character: \n 1. Vampire \n 2. Barbarian \n 3. Blue Men \
								\n 4. Medusa \n 5. Harry Potter \n\n", 1, 5);
		if (firstPlayer == 1)	{
			Vampire* vamp1 = new Vampire(1,18);
			player1 = vamp1;
		}
		else if (firstPlayer == 2)	{
			Barbarian* barb1 = new Barbarian(0,12);
			player1 = barb1;
		}
		else if (firstPlayer == 3)	{
			Blue_Men* blue1 = new Blue_Men(3,12);
			player1 = blue1;
		}
		else if (firstPlayer == 4)	{
			Medusa* medu1 = new Medusa(3,8);
			player1 = medu1;
		}
		else {
			Harry_Potter* harr1 = new Harry_Potter(0,10);
			player1 = harr1;
		}
		
		//create second player
		secondPlayer = validInt("Second character: \n 1. Vampire \n 2. Barbarian \n 3. Blue Men \
								\n 4. Medusa \n 5. Harry Potter \n\n", 1, 5);
		if (secondPlayer == 1)	{
			Vampire* vamp2 = new Vampire(1,18);
			player2 = vamp2;
		}
		else if (secondPlayer == 2)	{
			Barbarian* barb2 = new Barbarian(0,12);
			player2 = barb2;
		}
		else if (secondPlayer == 3)	{
			Blue_Men* blue2 = new Blue_Men(3,12);
			player2 = blue2;
		}
		else if (secondPlayer == 4)	{
			Medusa* medu2 = new Medusa(3,8);
			player2 = medu2;
		}
		else {
			Harry_Potter* harr2 = new Harry_Potter(0,10);
			player2 = harr2;
		}
		
		//play rounds and checks if one character dies
		while (!gameOver)	{
			gameOver = round(player1, player2);
		}
		
		//if one player dies play final screen
		if(gameOver)	{
			if (player1->getStrength() <= 0 && player1->getType() != player2->getType())	{
				cout << "Game over! " << player2->getType() << " killed " << player1->getType() << "!!!" << endl;
			}
			else if (player2->getStrength() <= 0 && player1->getType() != player2->getType())	{
				cout << "Game over! " << player1->getType() << " killed " << player2->getType() << "!!!" << endl; 
			}
			else if (player1->getStrength() <= 0 && player1->getType() == player2->getType())	{
				cout << "Game over! " << player2->getType() << " #2 killed " << player1->getType() << " #1 !!!" << endl;
			}
			else if (player2->getStrength() <= 0 && player1->getType() == player2->getType())	{
				cout << "Game over! " << player2->getType() << " #1 killed " << player1->getType() << " #2 !!!" << endl;
			}
		}	
		
		//free memory
		delete player1;
		delete player2;
		
		//repeat prompt
		repeatChoice = validInt("\nPlease pick one of the following: \n 1. Play Again \n 2. Exit\n", 1, 2);
	}
}
