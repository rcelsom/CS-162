/***************************************
Program Name: Project 2
Author: Robert Elsom
Date: 1/22/2019
Description: Header file for Turtle class
**************************************/

#ifndef TURTLE_HPP
#define TURTLE_HPP
#include "Animal.hpp"
#include <string>
class Turtle : public Animal	{
protected:
	int age;
	
public:
	Turtle();
	Turtle(int a);
	int getCost();
	int hasBabies();
	int getFoodCost();
	int getPayoff();	
	std::string getType();
	~Turtle();
};
#endif