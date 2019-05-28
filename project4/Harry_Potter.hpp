/***************************************
Program Name: Project 3
Author: Robert Elsom
Date: 2/4/2019
Description: Header file for Harry Potter class
**************************************/


#ifndef HARRY_POTTER_HPP
#define HARRY_POTTER_HPP
#include <string>
#include "Character.hpp"

class Harry_Potter : public Character	{
private:
	int armor;
	int strength;
	bool hogwartsFlag = false;
	int dieRoll;
	
public:
	Harry_Potter();
	Harry_Potter(int a, int s, std::string name);
	int attack();
	void defense(int attackerRoll);
	int getDieRoll();
	std::string getType();
	~Harry_Potter();	
	
};
#endif