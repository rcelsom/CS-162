/***************************************
Program Name: Project 3
Author: Robert Elsom
Date: 2/4/2019
Description: Header file for Vampire class
**************************************/

#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP
#include <string>
#include "Character.hpp"

class Vampire : public Character	{
private:
	int armor;
	int strength;
	int dieRoll;
	int charm;
	
public:
	Vampire();
	Vampire(int a, int s);
	int attack();
	void defense(int attackerRoll);
	int getDieRoll();
	std::string getType();
	~Vampire();	
	
};
#endif