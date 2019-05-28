/* 
CS 162 Group Project - Ant Child Class Header File
Date: Feb 7, 2019
Group Members: David Mikulis, James Scanlon, Robert Elsom, Frannie Richert
Class Addtl Member Variables: minTimeStepsBetweenBreeding
Class Addtl Member Functions:
*/

#include "Ant.hpp"
#include <cstdlib>


//---------------------------------------------------------Constructor
Ant::Ant()
{

}


//---------------------------------------------------------overloaded constructor
Ant::Ant(int xCoord, int yCoord, int age) : Critter::Critter(xCoord, yCoord, age)
{
	this->xCoord = xCoord;
	 this->yCoord = yCoord;
	 this->age = age;	
	this->critterType = ANT;
}


//---------------------------------------------------------Move
void Ant::move()
{
	//update numTimeStepsSinceLastMeal at the end of this function
    incrementAgeByOne();
}

//---------------------------------------------------------Breed Ant

void Ant::createAnt(Critter***& gBoard, int row, int col)
{	
	Critter* temp =  new Ant(row, col, 0);
	delete gBoard[row][col];
	gBoard[row][col] = temp;	  
}


void Ant::breed(Critter***& gBoard, int height, int width)
{
	int xUP = xCoord-1;
	int yUP = yCoord;	
	int xRIGHT = xCoord;
	int yRIGHT = yCoord+1;	
	int xDOWN = xCoord+1;
	int yDOWN = yCoord;		
	int xLEFT = xCoord;
	int yLEFT = yCoord-1;
	
	int countAvail = 0;
	int countLoop = 0;
	int randNum = 0;	
	bool canBreed = false;
	
	if(age > 0 && timeSinceLastBreed >= minTimeStepsBetweenBreeding)
	{
		canBreed = true;
	}
	
	if(canBreed == true)
	{						
		//order: UP (x-1), RIGHT(y+1), DOWN(x+1), LEFT(y-1)		
		bool availSpaces[4] = { !Critter::outOfBounds( height, width, xUP, yUP) 			&& !Critter::spaceOccupied(gBoard, height, width, xUP, yUP) ,
								!Critter::outOfBounds( height, width, xRIGHT, yRIGHT) 		&& !Critter::spaceOccupied(gBoard,height, width, xRIGHT, yRIGHT),
								!Critter::outOfBounds( height, width, xDOWN, yDOWN) 		&& !Critter::spaceOccupied(gBoard,height, width, xDOWN, yDOWN),
								!Critter::outOfBounds( height, width, xLEFT, yLEFT) 		&& !Critter::spaceOccupied(gBoard,height, width, xLEFT, yLEFT)
					};
			
		// counting available spaces
		for(int j = 0; j < 4; j ++)
		{
			if(availSpaces[j] == true)
			{
				countAvail +=1 ;
			}		
		}
		
		//if spaces available, randomly pick one
		if(countAvail > 0) // spaces available to breed into
		{
			randNum = rand() % countAvail +1; // rand num b/t 1 and count available
			
			for(int i = 0; i < 4; i++)
			{				
				//increment count each time a space is available
				if(availSpaces[i] == true)
				{
					countLoop +=1;
					
					//when the random value is reached
					if( countLoop == randNum)
					{					
						//order: UP (x-1), RIGHT(y+1), DOWN(x+1), LEFT(y-1)
						if(i == 0){ // UP					{
							createAnt(gBoard, xUP, yUP);						
							
						} else if (i == 1){ //RIGHT					
							createAnt(gBoard, xRIGHT, yRIGHT);
							
						} else if (i == 2){ //DOWN						
							createAnt(gBoard, xDOWN, yDOWN);
							
						} else if (i == 3){ //LEFT						
							createAnt(gBoard, xLEFT, yLEFT);
						}
					}
				}					
			}				
		}	
		
	}			
} 
	

//---------------------------------------------------------Desructor
Ant::~Ant()
{
    
}
