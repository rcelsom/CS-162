/***************************************
Program Name: Project2
Author: Robert Elsom
Date: 1/22/2019
Description: Class file for Animal class. 
			 Sets the ages, cost, number of babies,
			 food cost, and daily payoff of an animal object. 
**************************************/
#include "Animal.hpp"


//default constructor, sets the new animals age to 0
Animal::Animal()	{
	this->age = 0;	
}

//constructor that sets the new animals age
Animal::Animal(int a)	{
	this->age = a;
}

//returns the animals age
int Animal::getAge()	{
	return age;
}

//increments the animals age by one day
void Animal::incAge()	{
	this->age += 1;
}

//returns the cost to buy a new animal
int Animal::getCost() 	{
	return cost;
}

//returns how many babies the animal can have
int Animal::hasBabies()	{
	return numberOfBabies;
}

//returns the cost to feed the animal
int Animal::getFoodCost()	{
	return baseFoodCost;
}

//returns how much profit the animal is responsible for
int Animal::getPayoff()		{
	return payoff;
}

std::string Animal::getType()	{
	return "animal";
}

//deconstructor
Animal::~Animal ()		{
	
}

