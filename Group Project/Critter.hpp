/* 
CS 162 Group Project - Critter Parent Class Header File
Date: Feb 7, 2019
Group Members: David Mikulis, James Scanlon, Robert Elsom, Frannie Richert
Class Member Variables: xCoord, yCoord, age
Class Member Functions: move, bread, starve, destructor, constructor
*/

#include <string>
using std::string;

#ifndef CRITTER_HPP
#define CRITTER_HPP

enum DIRECTIONS {UP, RIGHT, DOWN, LEFT}; // order is important, moving clockwise
enum CRITTER_TYPES {CRITTER, ANT, DOODLEBUG};

class Critter
{
	protected: // so child classes can access these variables
	
		int xCoord; // on 2 dimensional grid
		int yCoord;
		int age; // in days (i.e. time steps)
		int critterType;
		int timeSinceLastBreed;
		int numTimeStepsSinceLastMeal;
		
		const static int minTimeStepsBetweenBreeding = -500; // doesn't mean anything i
		
		int boardHeight;
		int boardWidth;
		
		//assist with critter functions
		void removeCritter(Critter***& board, int row, int col);
		bool outOfBounds(int boardHeight, int boardWidth, int row, int col);
		bool spaceOccupied(Critter***& board, int boardHeight, int boardWidth, int row, int col);		
		       

	public:
		
		//default constructor
		Critter();
		
		//overloaded constructor
		Critter(int xCoord, int yCoord, int age);
		
		//get for testing
		int getAge();
		string getType();
        int getLastMeal();
		
		// critter functions that are SHARED b/t the two critters
		virtual void move(Critter***& board, int boardHeight, int boardWidth){};
		virtual void breed(Critter***& board, int boardHeight, int boardWidth){};
		virtual void starve(Critter***& board, int boardHeight, int boardWidth){}; // only defined in dbug class
		
		//used in game play after each time step
		void incrementAgeByOne();
		
		//destructor
		virtual ~Critter();
};

#endif
