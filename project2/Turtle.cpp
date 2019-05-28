/***************************************
Program Name: Project2
Author: Robert Elsom
Date: 1/22/2019
Description: Class file for Turtle class. 
			 Sets the ages, cost, number of babies,
			 food cost, and daily payoff of a Turtle object. 
**************************************/
#include "Turtle.hpp"
#include "Animal.hpp"

//default constructor
Turtle::Turtle() : Animal()	{

}
//constructor that sets the age of the new Turtle
Turtle::Turtle(int a) : Animal(a)	{
	this -> age = a;
}

//gets the cost of the turtle
int Turtle::getCost()	{
	return 100;
}
//get how many babies the turtle can have
int Turtle::hasBabies()	{
	return 10;
}
//gets the cost of food to feed the turtle each day
int Turtle::getFoodCost()	{
	return Animal::getFoodCost() * .5;
}
//gets how much profit the turtle is resposible for
int Turtle::getPayoff()	{
	return 100 * .05;
}

std::string Turtle::getType()	{
	return "turtle";
}

//deconstructor
Turtle::~Turtle()	{

}
