/***************************************
Program Name: Project 3
Author: Robert Elsom
Date: 2/4/2019
Description: character class header file, sets all
			functions to zero to make the class abstract
**************************************/


#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <string>
#include "Character.hpp"

class Character {
protected:
	int armor;
	int strength;
	int dieRoll;
	int startStrength;
	std::string name;
	std::string team;

public:
	Character();
	Character(int a, int s, std::string name);
	std::string getName();
	void damageRecovery();
	void setTeam(std::string teamNum);
	std::string getTeam();
	virtual int attack() = 0; 
	virtual void defense(int attackerRoll) = 0;
	void updateStrength(int dieRoll);
	void updateStrength(int dieRoll, int attackerRoll);
	int getArmor();
	int getStrength();
	virtual std::string getType() = 0;
	virtual int getDieRoll();
	virtual ~Character();

};
#endif
