/* 
CS 162 Group Project - Doodlebug Child Class Function Definitions
Date: Feb 7, 2019
Group Members: David Mikulis, James Scanlon, Robert Elsom, Frannie Richert
Class Member Addtl Variables: number of time steps since last meal,
							  minTimeStepsBetweenBreeding
Class Member Addtl Functions: starve
*/

#include "Doodlebug.hpp"
#include <cstdlib>


//---------------------------------------------------------Constructor
Doodlebug::Doodlebug()
{

}


Doodlebug::Doodlebug(int xCoord, int yCoord, int age) : Critter::Critter(xCoord, yCoord, age)
{
	this->xCoord = xCoord;
	this->yCoord = yCoord;
	this->age = age;	
	this->critterType = DOODLEBUG;
}

//---------------------------------------------------------Move
void Doodlebug::move(Critter*** board, int boardHeight, int boardWidth)
{
	
	eatAnt(board, antRow, antCol);

	
	
	
	//update numTimeStepsSinceLastMeal at the end of this function
    incrementAgeByOne();
    numTimeStepsSinceLastMeal += 1;
	starve();
}

//---------------------------------------------------------Breed Doodlebug

void Doodlebug::createDoodlebug(Critter***& gBoard, int row, int col)
{	
	Critter* temp =  new Doodlebug(row, col, 0);
	delete gBoard[row][col];
	gBoard[row][col] = temp;	  
}

void Doodlebug::eatAnt(Critter*** board, int antRow, int antCol)	
{

	removeCritter(board, antRow, antCol)
	timeSinceLastMeal = -1;  //set to -1 so it is at 0 after end of move() function 
	
}

void Doodlebug::breed(Critter***& gBoard, int height, int width)
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
	
	-check if there is an ant
		-if ant	
			call eatAnt
			move to new square
	
	if(age > 0 && timeSinceLastBreed >= minTimeStepsBetweenBreeding)
	{
		canBreed = true;
	}
	
	if(canBreed == true)
	{						
		//order: UP (x-1), RIGHT(y+1), DOWN(x+1), LEFT(y-1)		
		bool availSpaces[4] = { !Critter::outOfBounds( height, width, xUP, yUP) 			&& !Critter::spaceOccupied(gBoard,height, width, xUP, yUP) ,
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
							createDoodlebug(gBoard, xUP, yUP);						
							
						} else if (i == 1){ //RIGHT					
							createDoodlebug(gBoard, xRIGHT, yRIGHT);
							
						} else if (i == 2){ //DOWN						
							createDoodlebug(gBoard, xDOWN, yDOWN);
							
						} else if (i == 3){ //LEFT						
							createDoodlebug(gBoard, xLEFT, yLEFT);
						}
					}
				}					
			}				
		}	
		
	}			
} 
//---------------------------------------------------------Starve
void Doodlebug::starve(Critter*** board, int row, int col)
{
	if (timeSinceLastMeal >= 3)	
	{
		removeCritter(board, row, col);
	}
}



//---------------------------------------------------------Desructor
Doodlebug::~Doodlebug()
{
    
}
