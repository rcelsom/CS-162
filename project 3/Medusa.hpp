/***************************************
Program Name: Project 3
Author: Robert Elsom
Date: 2/4/2019
Description: Header file for Medusa class
**************************************/


#ifndef MEDUSA_HPP
#define MEDUSA_HPP
#include <string>
#include "Character.hpp"

class Medusa : public Character	{
private:
	int armor;
	int strength;
	int dieRoll;
	
public:
	Medusa();
	Medusa(int a, int s);
	int attack();
	void defense(int attackerRoll);
	int getDieRoll();
	std::string getType();
	~Medusa();	
	
};
#endif