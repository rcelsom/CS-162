/***************************************
Program Name: Project 1
Author: Robert Elsom
Date: 1/10/2019
Description: Contains the getters and setters
			for location, row, columns,  and orientation of 
			the ant along with changing the orientatoin of the ant
**************************************/
//need to double check getLocation to make sure pointers are ok
#include "Ant.hpp"


void Ant::setAntCol(int c)  {
    antCol = c;
}

void Ant::setAntRow(int r)  {
    antRow = r;
}

int Ant::getAntRow()    {
    return antRow;
}

int Ant::getAntCol()    {
    return antCol;
}

int Ant::getOrientation()	{
	return orientation;
}

void Ant::setAntLocation(char* ar[])	{
	ar[antRow][antCol]  = '*';
}

void Ant::changeOrientation(int currentOrientation, bool rightTurn)	{
	//if rightTurn is true, means we are turning right, otherwise
	//we are turning left
	if (rightTurn)	{
		//if orientation is on far end of array, reset index
		if (orientation == 3)	{
			orientation = 0;
		}
		else {
			orientation += 1;
		}
	}
	else	{
		if (orientation == 0)	{
			orientation = 3;
		}
		else {
			orientation -= 1;
		}
		
	}
}

void Ant::changeSquareColor(char* arr[], char color)		{
	if (color == ' ')	{
				arr[antRow][antCol] = '#';
			}
			else	{
				arr[antRow][antCol] = ' ';
			}
}	
	
