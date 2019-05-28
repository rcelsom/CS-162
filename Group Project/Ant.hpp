/* 
CS 162 Group Project - Ant Child Class Header File
Date: Feb 7, 2019
Group Members: David Mikulis, James Scanlon, Robert Elsom, Frannie Richert
Class Addtl Member Variables: minTimeStepsBetweenBreeding
Class Addtl Member Functions:
*/

#include "Critter.hpp"

#ifndef ANT_HPP
#define ANT_HPP

class Ant : public Critter
{
	private: // no additional data members
		
		const static int minTimeStepsBetweenBreeding = 3;
		void createAnt(Critter***& gBoard, int row, int col);
	
	public:
		
		//default constructor
		Ant();
		
		//overloaded constructor
		Ant(int xCoord, int yCoord, int age);
			
		//critter functions 
		void move();
		void breed(Critter***& board, int boardHeight, int boardWidth );
		void starve(Critter*** board, int boardHeight, int boardWidth){}; // only defined in dbug class
		
		//destructor
		~Ant();
};

#endif
