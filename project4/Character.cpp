/***************************************
Program Name: Project 3
Author: Robert Elsom
Date: 2/4/2019
Description: Barbarian class, contains all getters and setters
			for barbarian characters along with updateStrength and
			getType.
**************************************/

#include <cstdlib>
#include <iostream>
#include "Character.hpp"
#include <ctime>

Character::Character()	{
	this->armor = 0;
	this->strength = 0;
	this->name = "";
}

Character::Character(int a, int s, std::string name)	{
	this->armor = a;
	this->strength = s;
	this->startStrength = s;
	this->name = name;
}

std::string Character::getName()	{
	return name;
}

void Character::setTeam(std::string teamNum) {
	this->team = "Team " + teamNum;
}

std::string Character::getTeam() {
	return team;
}

void Character::damageRecovery()	{
	dieRoll = rand() % 4;
	if (strength + dieRoll < startStrength)	{
		std::cout << "The winner just recovered " << dieRoll << " points of their health" << std::endl;
		updateStrength(strength + dieRoll);
		std::cout << "Their new health is now " << strength <<std::endl;
	}
	else	{
		std::cout << "The winner just recovered to full health!" << std::endl;
		updateStrength(startStrength);
	}
	
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

Character::~Character()	{

}

