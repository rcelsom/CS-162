/***************************************
Program Name: Project 1
Author: Robert Elsom
Date: 1/10/2019
Description:Header file for Board class
**************************************/

#ifndef BOARD_HPP
#define BOARD_HPP

class Board {
	private:
		int boardRow;
		int boardCol;
		int steps;


	public:
		void setBoardRow(int r);
		void setBoardCol(int c);
		int getBoardRow();
		int getBoardCol();
		void fillArray(char* ar[]);
		void printBoard(char* arr[]);
		


};
#endif
