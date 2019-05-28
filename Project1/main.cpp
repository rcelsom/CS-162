/***************************************
Program Name: Project 1
Author: Robert Elsom
Date: 1/10/2019
Description: Presents Menu, takes user input to build board
			and starting location and then simulates Langston's
			ant. Also contains function for figuring out what the
			next square will be during simulation. 
**************************************/

#include <iostream>
#include <iomanip>
#include "Ant.hpp"
#include "menu.hpp"
#include "Board.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::cin;

void nextSquareLocation(int antRow, int antCol, int orientation, int boardRow, int boardCol, int* nextArray)	{
	//if orientation is up wrap if reach top of board
	if (orientation == 1)	{
		if (antRow == 0)	{
			nextArray[0] = boardRow - 1;
			nextArray[1] = antCol;
		}
		else	{
			nextArray[0] = antRow - 1;
			nextArray[1] = antCol;
		}
	}
	//if going down, wrap if reach bottom of board
	else if (orientation == 3)	{
		if (antRow == boardRow-1)	{
			nextArray[0] = 0;
			nextArray[1] = antCol;
		}
		else	{
			nextArray[0] = antRow + 1;
			nextArray[1] = antCol;
		}
	}
	//if going left, wrap if reach left side of board
	else if (orientation == 0) {
		if (antCol == 0)	{
			nextArray[0] = antRow;
			nextArray[1] = boardCol - 1;
		}
		else	{
			nextArray[0] = antRow;
			nextArray[1] = antCol - 1;
		}
	}
	//if going left, wrap if reach right side of board
	else if (orientation == 2) {
		if (antCol == boardCol - 1)	{
			nextArray[0] = antRow;
			nextArray[1] = 0;
		}
		else	{
			nextArray[0] = antRow;
			nextArray[1] = antCol + 1;
		}
	}
	
}

int main()	{
	int antRow =0;
	int antCol;
	int boardRow;
	int boardCol;
	int totalSteps;
	int responseArr[5];
	int nextArray[2];
	Board board;
	Ant ant;
	

	menu(responseArr);
	while(true)	{
		//inputting menu propmts into variables
		boardRow = responseArr[0];
		boardCol = responseArr[1];
		totalSteps = responseArr[2];
		antRow = responseArr[3];
		antCol = responseArr[4];
		cout << antRow << " " << antCol << endl;
	
		board.setBoardRow(boardRow);
		board.setBoardCol(boardCol);
		ant.setAntRow(antRow);
		ant.setAntCol(antCol);
		
		//need to declare inside while loop so that it resets to white when
		//repeating the function
		char squareColor = ' ';
	
		//dynamically creating the board
		char** boardArray = new char*[boardRow];
		for (int i=0; i < boardRow; i++)	{
			boardArray[i] = new char[boardCol];
		}		
	
		//filling in board with white spaces
		board.fillArray(boardArray);
		//sets starting location of ant
		ant.setAntLocation(boardArray);
		board.printBoard(boardArray);	

		for (int i = 0; i < totalSteps ; i++)	{
			//get next square based on orientation
			nextSquareLocation(ant.getAntRow(), ant.getAntCol(), ant.getOrientation(), boardRow, boardCol, nextArray); 
			int nextRow = nextArray[0];
			int nextCol = nextArray[1];
		
			//get next square color
			char nextSqColor = boardArray[nextRow][nextCol];

			//change color of current location
			ant.changeSquareColor(boardArray, squareColor);
			//move ant to next location
			ant.setAntRow(nextRow);
			ant.setAntCol(nextCol);
			ant.setAntLocation(boardArray);
			//update ant row to current location
			antRow = ant.getAntRow();
			antCol = ant.getAntCol();
		
			//change orientation based on if next square color is a space
			//pass true for right turn, else pass false for left turn
			if (nextSqColor == ' ')	{
				ant.changeOrientation(ant.getOrientation(), true);
			}
			else	{
				ant.changeOrientation(ant.getOrientation(), false);
			}
		
		
			//change next square color to previous square color
			squareColor = nextSqColor;
			
			//output board after making move
			board.printBoard(boardArray);
		}
	
		//deallocating the dynamic array
		for (int i = 0; i < boardRow; i++)	{
			delete [] boardArray[i];
		}
		delete [] boardArray;
		
		//pass true into function call to get repeat option
		menu(responseArr, true);
	}

	return 0;
	
	
}
