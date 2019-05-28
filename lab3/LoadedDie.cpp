/***************************************
Program Name: Lab3
Author: Robert Elsom
Date: 1/19/2019
Description: Class file for LoadedDie. 
			Contains functions to set the number of
			sides of the die and a roll function that 
			returns the outcome of a role
**************************************/
#include <cstdlib>
#include "LoadedDie.hpp"

//creates LoadedDie using Die default constructor
LoadedDie::LoadedDie() : Die()	{
	
}

//creates LoadedDie using Die constructor
LoadedDie::LoadedDie(int sides) : Die (sides)	{
	this -> N = sides;

}

//Represents rolling a LoadedDie, inherits roll from Die class then
//if number is less than half the number of sides, returns the number of sides
int LoadedDie::roll()	{
	//returns only the number of sides from sides/2 to sides
	//so if 6 sides, only returns 3-6
	rollResults = Die::roll();
	
	if (rollResults < N / 2)	{
		return N;
	}
	else	{
		return rollResults;
	}
}

//LoadedDie destructor
LoadedDie::~LoadedDie()	{

}