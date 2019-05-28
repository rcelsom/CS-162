/***************************************
Program Name: Project2
Author: Robert Elsom
Date: 1/22/2019
Description: Class file for Tiger class. 
			 Sets the ages, cost, number of babies,
			 food cost, and daily payoff of a tiger object. 
**************************************/
#include "Tiger.hpp"
#include "Animal.hpp"

//default constructor
Tiger::Tiger() : Animal()	{

}

//constructor that sets the age of a new tiger
Tiger::Tiger(int a) : Animal(a)	{
	
}



//returns the cost to buy a new tiger
int Tiger::getCost()	{
	return 10000;
}

//returns how many babies a tiger can have
int Tiger::hasBabies()	{
	return 1;
}

//returns the cost to feed the tiger 
int Tiger::getFoodCost()	{
	return Animal::getFoodCost() * 5;
}

//returns how much profit the tiger is responsible for
int Tiger::getPayoff()	{
	return  .2 * 10000;
}

std::string Tiger::getType()	{
	return "tiger";
}

//deconstructor
Tiger::~Tiger()	{

}

