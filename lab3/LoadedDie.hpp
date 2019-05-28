/***************************************
Program Name: Lab3
Author: Robert Elsom
Date: 1/19/2019
Description: Header file for LoadedDie class
**************************************/
#include "Die.hpp"


#ifndef LOADED_DIE_HPP
#define	LOADED_DIE_HPP

class LoadedDie : public Die	{

protected:
	int N;
	int rollResults;
	
public:
	LoadedDie();
	LoadedDie(int n);
	int roll();
	~LoadedDie();
};

#endif