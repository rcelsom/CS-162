/* 
CS 162 Group Project - Doodlebug Child Class Function Definitions
Date: Feb 7, 2019
Group Members: David Mikulis, James Scanlon, Robert Elsom, Frannie Richert
Class Member Addtl Variables: number of time steps since last meal,
							  minTimeStepsBetweenBreeding
Class Member Addtl Functions: starve
*/

#include "Critter.hpp"

#ifndef DOODLEBUG_HPP
#define DOODLEBUG_HPP

class Doodlebug : public Critter
{
	private:
			
		const static int minTimeStepsBetweenBreeding = 8;
		void createDoodlebug(Critter***& gBoard, int row, int col);
		int timeSinceLastMeal;
		
	public:
		
		//constructor
		Doodlebug();
		
		//overloaded constructor
		Doodlebug(int xCoord, int yCoord, int age);			
		
		//starve function, specific to doodlebug
		void starve(Critter*** board, int boardHeight, int boardWidth);
		void eatAnt(Critter*** board, int antRow, int antCol);
		
		// critter functions that are SHARED b/t the two critters
		void move(Critter*** board, int boardHeight, int boardWidth);
		void breed(Critter***& board, int boardHeight, int boardWidth );
		

		//destructor
		virtual ~Doodlebug();
};

#endif
