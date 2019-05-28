/***************************************
Program Name: Project 3
Author: Robert Elsom
Date: 2/4/2019
Description: Blue Men class, contains all getters and setters
			for blue men characters along with updateStrength and
			getType.
**************************************/

#include <cstdlib>
#include "Blue_Men.hpp"
#include <ctime>
#include <cmath>
#include <iostream>


//default constructor
Blue_Men::Blue_Men(): Character()	{
}

Blue_Men::Blue_Men(int armor, int strength) : Character (armor, strength)	{
	this->armor = armor;
	this->strength = strength;
}

//rolls two 10 sided die and returns the value of the roll
int Blue_Men::attack()	{
	dieRoll = (rand() % 10 + 1) + (rand() % 10 + 1);
	return dieRoll;
}

//calculates damage inflicted and defenders roll and updates strength off of it
//Mob ability, for every four points of damage, loose one defense die
void Blue_Men::defense(int attackerRoll)	{
	dieRoll = 0;
	//remove one die roll for every 4 points of strength
	for (int i = 0; i < ceil(getStrength()/4.0) && i < 3; i++)	{
		dieRoll += rand() % 6 + 1;
	}
	
	updateStrength(dieRoll, attackerRoll);
}

//returns type, just returning type for printing results
std::string Blue_Men::getType()	{
	return "Blue Men";
}

//returns dice roll
int Blue_Men::getDieRoll()	{
	return dieRoll;
}

Blue_Men::~Blue_Men() {	}
