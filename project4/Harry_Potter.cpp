/***************************************
Program Name: Project 3
Author: Robert Elsom
Date: 2/4/2019
Description: Harry Potter class, contains all getters and setters
			for Harry Potter characters along with updateStrength and
			getType.
**************************************/

#include <cstdlib>
#include "Harry_Potter.hpp"
#include <ctime>
#include <iostream>

using std::cout;
using std::endl;


//default constructor
Harry_Potter::Harry_Potter(): Character()	{

}

Harry_Potter::Harry_Potter(int armor, int strength, std::string name) : Character (armor, strength, name)	{
	this->armor = armor;
	this->strength = strength;
	this->name = name;
}

//rolls two 6 sided die and returns the value of the roll
int Harry_Potter::attack()	{
	dieRoll = (rand() % 6 + 1) + (rand() % 6 + 1);
	return dieRoll;
}

//calculates damage inflicted and defenders roll of two 6 sided die
// and updates strength off of it
void Harry_Potter::defense(int attackerRoll)	{
	dieRoll = (rand() % 6 + 1) + (rand() % 6 + 1);
	updateStrength(dieRoll, attackerRoll);
	//test if need to reset using hogwarts special ability and turn hogwarts flag off
	if (this->getStrength() <= 0)	{
		if (!hogwartsFlag)	{
			/*cout << endl << "Harry Potter has been killed! But his special wizard powers brought him"\
			"back to life with double the strength!!!" << endl << endl;*/
			//sets strength to 20 since Harry has no armor
			updateStrength(20);
			hogwartsFlag = true;
		}
	}
}

//returns type, just returning type for printing results
std::string Harry_Potter::getType()	{
	return "Harry Potter";
}

//returns dice roll
int Harry_Potter::getDieRoll()	{
	return dieRoll;
}

Harry_Potter::~Harry_Potter() {	}
