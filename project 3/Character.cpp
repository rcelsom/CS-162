/***************************************
Program Name: Project 3
Author: Robert Elsom
Date: 2/4/2019
Description: Barbarian class, contains all getters and setters
			for barbarian characters along with updateStrength and
			getType.
**************************************/
#include <cstdlib>
#include "Character.hpp"
#include <ctime>

Character::Character()	{
	this->armor = 0;
	this->strength = 0;
}

Character::Character(int a, int s)	{
	this->armor = a;
	this->strength = s; 
}

void Character::updateStrength( int dieRoll, int attack)	{
	//make sure character is not gaining strength
	if (attack - dieRoll - armor >= 0)	{
		this->strength -= (attack - dieRoll - armor);
	}
}

void Character::updateStrength(int dieRoll)	{
	this->strength = dieRoll;
}

int Character::getArmor()	{
	return armor;
}

int Character::getStrength()	{
	return strength;
}

int Character::getDieRoll()	{
	return dieRoll;
}

Character::~Character()	{	}

