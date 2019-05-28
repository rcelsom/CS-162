/***************************************
Program Name: Lab3
Author: Robert Elsom
Date: 1/19/2019
Description: Class file for Die. 
			Contains functions to set the number of
			sides of the die and a roll function that 
			returns the outcome of a role
**************************************/
#include <cstdlib>
#include "Die.hpp"
#include <ctime>

//Die default constructor, sets the number of sides of the die to 0
Die::Die()	{
	this->N = 0;
	//set here so it returns a random number everytime roll() is called
	srand(time(NULL));
}

//Die constructor, sets number of sides equal to the parameter
Die::Die(int numSides)	{
	this->N =  numSides;
}

//Returns the number of sides of the Die
int Die::getSides()	{
	return N;
}

//Returns a random value in range 1 to N to represent rolling the die. 
int Die::roll()	{
	rollResults = (rand() % (N - 1)) + 1; 	
	return rollResults;
}

//Die deconstructor
Die::~Die()	{

}