/* 
CS 162 Group Project - Critter Parent Class Header File
Date: Feb 7, 2019
Group Members: David Mikulis, James Scanlon, Robert Elsom, Frannie Richert
Class Member Variables: xCoord, yCoord, age
Class Member Functions: move, bread, starve, destructor, constructor
*/

#include "Critter.hpp"


//---------------------------------------------------------Functions for testing
int Critter::getAge()
{
	return this->age;
}

int Critter::getLastMeal()
{
    return this->numTimeStepsSinceLastMeal;
}

//---------------------------------------------------------Default Constructor
Critter::Critter()
{
	xCoord =0;
	yCoord=0;
	age=0;
	timeSinceLastBreed = 0;
	critterType = CRITTER;
	numTimeStepsSinceLastMeal = 0;
}

//---------------------------------------------------------Overloaded Constructor
Critter::Critter(int xCoord, int yCoord, int age)
{
	//based on user input
	 this->xCoord = xCoord;
	 this->yCoord = yCoord;
	 this->age = age;	
	 
	 //default values
	 this->critterType = CRITTER; // initial type is critter, will get overwritten in the ant/dbug classes
	 timeSinceLastBreed = 0;
	 numTimeStepsSinceLastMeal=0;
}


string Critter::getType()
{
	switch (this->critterType) {

	case 0: return "critter";
            
	case 1: return "ant";
            
	case 2: return "doodlebug";

	}
    
    return "critter";
}


//---------------------------------------------------------Helper functions for move/breed
bool Critter::outOfBounds( int boardHeight, int boardWidth, int row, int col)
{
	int rowMin = 0;
	int rowMax = boardHeight - 1; //offsetting by 1 b/c array is addressed starting at 0
	
	int colMin = 0;
	int colMax = boardWidth = 1;
	
	if(row < rowMin || row > rowMax || col < colMin || col > colMax)
	{
		return true;
	} else {
		return false;
	}
	
}

bool Critter::spaceOccupied(Critter***& gBoard, int boardHeight, int boardWidth, int row, int col)
{
    // critter type is a free space. i.e. a space which has not been assigned a type of ant or doodlebug
	
	if (gBoard[row][col]->getType() != "critter" )	 // else critter is either an ant or doodlbug, and space is occupied
	{
		return true;
	}
	else // space is "Free"
	{
		return false;
	}
}

void Critter::removeCritter(Critter***& gBoard, int row, int col)
{
    Critter* temp =  new Critter(row, col, 0);
    delete gBoard[row][col];
    gBoard[row][col] = temp;
}


//---------------------------------------------------------Increase Age, used in Game
void Critter::incrementAgeByOne()
{
	age +=1;
}
		
	
//---------------------------------------------------------Destructor
Critter::~Critter()
{
    
}
