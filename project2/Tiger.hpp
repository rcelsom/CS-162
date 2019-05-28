/***************************************
Program Name: Project 2
Author: Robert Elsom
Date: 1/22/2019
Description: Header file for Tiger class
**************************************/


#ifndef TIGER_HPP
#define TIGER_HPP
#include "Animal.hpp"
#include <string>

class Tiger : public Animal	{
protected:
	int age;
	
public:
	Tiger();
	Tiger(int a);
	int getCost();
	int hasBabies();
	int getFoodCost();
	int getPayoff();
	std::string getType();
	~Tiger();

};
#endif