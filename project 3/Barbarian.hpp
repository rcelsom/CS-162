/***************************************
Program Name: Project 3
Author: Robert Elsom
Date: 2/4/2019
Description: Header file for Barbarian class
**************************************/

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP
#include <string>
#include "Character.hpp"

class Barbarian : public Character	{
private:
	int armor;
	int strength;
	int dieRoll;
	
public:
	Barbarian();
	Barbarian(int armor, int sides);
	int attack();
	void defense(int attackerRoll);
	int getDieRoll();
	std::string getType();
	~Barbarian();	
	
};
#endif