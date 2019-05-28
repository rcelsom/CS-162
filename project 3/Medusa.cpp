/***************************************
Program Name: Project 3
Author: Robert Elsom
Date: 2/4/2019
Description: Medusa class, contains all getters and setters
			for Medusa characters along with updateStrength and
			getType.
**************************************/

#include <cstdlib>
#include "Medusa.hpp"
#include <ctime>
#include <iostream>


//default constructor
Medusa::Medusa() : Character()	{
	
}

Medusa::Medusa(int armor, int strength) : Character (armor, strength)	{
	this->armor = armor;
	this->strength = strength;
}

//rolls two 6 sided die and returns the value of the roll
//includes glare ability that instantly kills the other character
int Medusa::attack()	{
	dieRoll = (rand() % 6 + 1) + (rand() % 6 + 1);
		
	//medusa's glare ability
	if (dieRoll == 12)	{
		//greater than maximum strength any player can have
		std::cout << std::endl <<"The defender looked Madusa in the eyes! She glared at them!";
		std::cout << std::endl<< std::endl ;
		return 30;
	}
	else	{
		return dieRoll;
	}
}

//calculates damage inflicted and defenders roll of one 6 sided die
// and updates strength off of it
void Medusa::defense(int attackerRoll)	{
	dieRoll = rand() % 6 + 1;
	updateStrength(dieRoll, attackerRoll);
}

//returns type, just returning type for printing results
std::string Medusa::getType()	{
	return "Medusa";
}

//returns dice roll
int Medusa::getDieRoll()	{
	return dieRoll;
}

Medusa::~Medusa() {	}