/* 
CS 162 Group Project - Game Class Header File
Date: Feb 7, 2019
Group Members: David Mikulis, James Scanlon, Robert Elsom, Frannie Richert
Class Member Variables: 
Class Member Functions: 
*/

#include "Critter.hpp"


#ifndef GAME_HPP
#define GAME_HPP

class Game
{
	private:
		Critter*** board;
		int width;
		int height;
		int numAnts;
		int numDoodlebugs;
		char antSym = 79;
		char doodlebugSym = 88;
		char spaceSym = 32;		
		
		void createBoard(int height, int width, int numAnts, int numDoodlebugs);
		
	public:
		
		//default constructor
		Game();
		
		//overloaded constructor
		Game(int height, int width, int numAnts, int numDoodlebugs);		
		
		//board functions
		Critter*** getBoard();
		int getBoardHeight();
		int getBoardWidth();
		int getNumAnts();
		int getNumDoodlebugs();
		void printBoard();		
		
		//critter functions
        void moveCritters();
		void breedCritters();
		void starveDoodlebugs();
		
		//destructor	
		~Game();
};

#endif
