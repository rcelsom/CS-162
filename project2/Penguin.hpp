/***************************************
Program Name: Project 2
Author: Robert Elsom
Date: 1/22/2019
Description: Header file for Penguin class
**************************************/

#ifndef PENGUIN_HPP
#define PENGUIN_HPP
#include "Animal.hpp"
#include <string>

class Penguin : public Animal	{
	
public:
	Penguin();
	Penguin(int a);
	int getCost();
	int hasBabies();
	int getFoodCost();
	int getPayoff();
	~Penguin();
	std::string getType();
	
};
#endif