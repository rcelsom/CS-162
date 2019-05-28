/***************************************
Program Name: Project 3
Author: Robert Elsom
Date: 2/4/2019
Description: Header file for Blue Men class
**************************************/

#ifndef BLUE_MEN_HPP
#define BLUE_MEN_HPP
#include <string>
#include "Character.hpp"

class Blue_Men : public Character	{
private:
	int armor;
	int strength;
	int dieRoll;
	
public:
	Blue_Men();
	Blue_Men(int a, int s, std::string name);
	int attack();
	void defense(int attackerRoll);
	int getDieRoll();
	std::string getType();
	~Blue_Men();	
	
};
#endif