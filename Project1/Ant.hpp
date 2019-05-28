/***************************************
Program Name: Project 1
Author: Robert Elsom
Date: 1/10/2019
Description: Header file for Ant class
**************************************/

#ifndef ANT_HPP
#define ANT_HPP

#include <string>

using std::string;

class Ant {
	private:
		int antRow;
		int antCol;
		
		//consider variable orientation as the index of an
		//array {"left", "up", "right", "down"}.So default
		//is up, and when we reach 3 or 0,we need to wrap to other side
		int orientation = 1;
		
	public:
		void setAntRow(int r);
		void setAntCol(int c);
		void setAntLocation(char* ar[]);
		int getAntRow();
		int getAntCol();
		int getOrientation();
		void changeOrientation(int currentOrientation, bool rightTurn);
		void changeSquareColor( char* arr[], char color);
};

#endif
