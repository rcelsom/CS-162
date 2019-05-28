/***************************************
Program Name: Lab3
Author: Robert Elsom
Date: 1/19/2019
Description: Header file for Die class 
*************************************/

#ifndef	DIE_HPP
#define DIE_HPP

class Die	{

private:
	int N;
	int rollResults;
	Die* p1;
	Die* p2;
public:
	Die();
	Die(int numSides);
	int getSides();
	virtual int roll();
	virtual ~Die();
};
#endif

