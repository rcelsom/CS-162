/* 
CS 162 Group Project - Game Class Function Definition File
Date: Feb 7, 2019
Group Members: David Mikulis, James Scanlon, Robert Elsom, Frannie Richert
Class Member Variables: 
Class Member Functions: 
*/

#include <cstdlib>
using std::rand;

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "Game.hpp"
#include "Ant.hpp"
#include "Doodlebug.hpp"



//---------------------------------------------------------default constructor
Game::Game()
{
	// default is 20x20, 5 ants, 100 dbugs
	height = 20; // i.e. rows
	width = 20; // i.e. columns
	
	createBoard(height, width, 5, 100);
	
}

//---------------------------------------------------------constructor
Game::Game(int height, int width, int numAnts, int numDoodlebugs)
{

	this->height = height;
	this->width = width;
	this->numAnts = numAnts;
	this->numDoodlebugs = numDoodlebugs;

	createBoard(height, width, numAnts, numDoodlebugs);
}	

//---------------------------------------------------------create Board function

void Game::createBoard(int height, int width, int numAnts, int numDoodlebugs)
{
	
	//create board
	board = new Critter**[height];
	for(int i = 0; i < height; i++)
	{
		board[i] = new Critter*[width];		
		
		for(int j = 0; j < width; j++)
		{
			Critter* tempPtr = new Critter();
			delete board[i][j];
			board[i][j] = tempPtr;
			
		}
	}	
		
	int rand1 = -5; // row num
	int rand2 = -5; // col num
	
	//adding ants
	for(int i = 0; i < numAnts; i ++)
	{
		 do {			 
			
			rand1 = rand() % (height-1); // will return a random number b/t 0 and height for rows 
			rand2 = rand() % (width-1); // will return a random number b/t 0 and width for columns 
			 
		 } while(board[rand1][rand2]->getType() != "critter"); // !critter type indicates cell is already occupied 
	
		Critter* temp =  new Ant(rand1, rand2, 0);
		delete board[rand1][rand2];
		board[rand1][rand2] = temp;
	}
	
	//adding doodlebugs
	for(int i = 0; i < numDoodlebugs; i ++)
	{
		 do {			 
			
			rand1 = rand() % (height-1); // will return a random number b/t 0 and height for rows 
			rand2 = rand() % (width-1); // will return a random number b/t 0 and width for columns 
			 
		 } while(board[rand1][rand2]->getType() != "critter"); // !critter type indicates cell is already occupied 
	
		Critter* temp =  new Doodlebug(rand1, rand2, 0);
		delete board[rand1][rand2];
		board[rand1][rand2] = temp;
	}
	
	
}	

//---------------------------------------------------------board functions
Critter*** Game::getBoard()
{
	return board;	
}

int Game::getBoardHeight()
{
	
	return height;
	
}

int Game::getBoardWidth()
{
	
	return width;
	
}	

int Game::getNumAnts()
{

	return numAnts; 
	
}

int  Game::getNumDoodlebugs()
{

	return numDoodlebugs;

}
	
void Game::printBoard()
{
    {	
		for (int i = 0; i < height + 2; i++)	{
			cout << "-";
		}
		cout << endl;
		
        for (int i = 0; i < height; i++)
        {
			cout << "|";
            for (int j = 0; j < width; j++)
            {
                if (getBoard()[i][j]->getType() == "ant")
                    cout << antSym;
                else if (getBoard()[i][j]->getType() == "doodlebug")
                    cout << doodlebugSym;
                else
                    cout << spaceSym;
            }
            cout << "|" << endl;
        }
        
        for (int i = 0; i < height + 2; i++)	{
			cout << "-";
		}
		cout << endl << endl;
    } 
	
}

//---------------------------------------------------------move/breed/starve loop critter functions

//occurs at BEGINNING of time step
void Game::moveCritters(){
	
	//doodlebugs move first
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (board[i][j]->getType() == "doodlebug")
                board[i][j]->move(board, height, width);
        }
    }
    
	//ants move second
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (board[i][j]->getType() == "ant")
                board[i][j]->move(board, height, width);
        }
    }
}


//will occurr at the END of the time step
void Game::breedCritters()
{
	//no order to breeding
	for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (board[i][j]->getType() != "critter")
                board[i][j]->breed(board, height, width);
           }
     }
 }    


//will occur at the END of the timestep
void Game::starveDoodlebugs()
{

	for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (board[i][j]->getType() == "doodlebug")
                board[i][j]->starve(board, i, j);
        }
    }
}




//---------------------------------------------------------destructor
Game::~Game(){
		
	for(int i = 0; i < height; i++)	{
		for (int j = 0; j < width; j++)	{
			delete board[i][j];
		}
		delete board[i];
	}
	delete [] board;
}
