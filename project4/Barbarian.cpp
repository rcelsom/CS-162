/***************************************
Program Name: Project 3
Author: Robert Elsom
Date: 2/4/2019
Description: Barbarian class, contains all getters and setters
			for barbarian characters along with updateStrength and
			getType.
**************************************/
#include <cstdlib>
#include "Barbarian.hpp"
#include <ctime>



Barbarian::Barbarian() : Character()	{

}

Barbarian::Barbarian(int armor, int strength, std::string name) : Character (armor, strength, name)	{
	this->armor = armor;
	this->strength = strength;
	this->name = name;
}

//rolls two 6 sided die and returns the value of the roll
int Barbarian::attack()	{
	this->dieRoll = (rand() % 6 + 1) + (rand() % 6 + 1);
	return dieRoll;
}

//calculates damage inflicted and defenders roll of two 6 sided die
// and updates strength off of it
void Barbarian::defense(int attackerRoll)	{
	this->dieRoll = (rand() % 6 + 1) + (rand() % 6 + 1);
	updateStrength(dieRoll, attackerRoll);
}

//returns type, just returning type for printing results
std::string Barbarian::getType()	{
	return "Barbarian";
}

//returns dice roll
int Barbarian::getDieRoll()	{
	return dieRoll;
}

Barbarian::~Barbarian() {	}