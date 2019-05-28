/***************************************
Program Name: Project 2
Author: Robert Elsom
Date: 1/22/2019
Description: Header file for Animal class
**************************************/
#include "Tiger.hpp"
#include "Penguin.hpp"
#include "Turtle.hpp"
#include <string>

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

class Animal	{
protected:
	int age;
	int cost = 0;
	int numberOfBabies = 0;
	int baseFoodCost = 10;
	int payoff = 0;
	
public:
	Animal();
	Animal(int a);
	int getAge();
	void incAge();
	virtual int getCost();
	virtual int hasBabies();
	virtual int getFoodCost();
	virtual int getPayoff();	
	virtual ~Animal();
	virtual std::string getType();
};
#endif