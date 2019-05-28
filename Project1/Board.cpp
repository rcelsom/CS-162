/***************************************
Program Name: Project 1
Author: Robert Elsom
Date: 1/10/2019
Description: Board class that is responsible for 
			getting and setting the board rows and column
			sizes, filling the board with spaces, and outputting
			the board to the screen.
**************************************/
//still need to finish changeSquareColor, currentSquareColor
#include <iostream>
#include "Board.hpp"

using std::cout;
using std::cin;
using std::endl;

void Board::setBoardCol(int c)  {
    boardCol = c;
}

void Board::setBoardRow(int r)  {
    boardRow = r;
}

int Board::getBoardCol()    {
    return boardCol;
}

int Board::getBoardRow()    {
    return boardRow;
}

void Board::fillArray(char* ar[])	{
	for (int i = 0; i < boardRow; i++) 	{
		for (int j = 0; j < boardCol; j++)	{
			ar[i][j] =' ' ;
		}
	}
}

void Board::printBoard(char* arr[])	{
	for (int i = 0; i < boardCol+2; i++)	{
		cout <<"-";
	}
	cout << endl;
	
	for (int j = 0; j < boardRow ; j++)	{
		cout << "|";
		for (int k = 0; k < boardCol ; k++)	{
			cout << arr[j][k];
		}
		cout << "|" << endl;
	}
	for (int i = 0; i < boardCol+2; i++)	{
		cout << '-';
	}
	cout << endl;
}


	