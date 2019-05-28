/***************************************
Program Name: Project 3
Author: Robert Elsom
Date: 2/4/2019
Description: Vampire class, contains all getters and setters
			for vampire characters along with updateStrength and
			getType.
**************************************/
#include <cstdlib>
#include "Vampire.hpp"
#include <ctime>
#include <iostream>

using std::cout;
using std::endl;

//default constructor
Vampire::Vampire(): Character ()	{

}

Vampire::Vampire(int armor, int strength, std::string name) : Character (armor, strength, name)	{
	this->armor = armor;
	this->strength = strength;
	this->name = name;
}


//rolls one 12 sided die and returns the value of the roll
int Vampire::attack()	{
	dieRoll = rand() % 12 + 1;
	return dieRoll;
}

//calculates damage inflicted and defenders roll and updates strength off of it
void Vampire::defense(int attackerRoll)	{
	//charm test, if 1, attacker was charmed and no attack happens
	charm = rand() % 2;
	if (charm == 1)	{
		//cout << endl << "The Vampire charmed the attacker, so no damage was inflicted this round." << endl << endl;
		//set die roll to attackerRoll to make formula output nice but does not affect the strength
		dieRoll = attackerRoll - 1;
		updateStrength(dieRoll, attackerRoll);
	}
	else {
		//defense roll, if charm did not work
		dieRoll = rand() % 6 + 1;
		updateStrength(dieRoll, attackerRoll);
	}
}

//returns type, just returning type for printing results
std::string Vampire::getType()	{
	return "Vampire";
}

//returns dice roll
int Vampire::getDieRoll()	{
	return dieRoll;
}

Vampire::~Vampire() {

}