/***************************************
Program Name: Project2
Author: Robert Elsom
Date: 1/22/2019
Description: Class file for Penguin class. 
			 Sets the ages, cost, number of babies,
			 food cost, and daily payoff of a Penguin object. 
**************************************/
#include "Penguin.hpp"


//default constructor
Penguin::Penguin() : Animal()	{

}

//constructor that sets the age of a new penguin
Penguin::Penguin(int a) : Animal(a)	{
	
}



//gets the cost of a new penguin
int Penguin::getCost()	{
	return 1000;
}

//returns how many babies a penguin can have
int Penguin::hasBabies()	{
	return 5;
}

//returns how much it cost to feed the penguin
int Penguin::getFoodCost()	{
	return Animal::getFoodCost();
}

//returns how much profit the penguin is responsible for
int Penguin::getPayoff()	{
	return 1000 * .1;
}

std::string Penguin::getType()	{
	return "penguin";
}

//deconstructor
Penguin::~Penguin()	{

}
