/***************************************
Program Name: Lab3
Author: Robert Elsom
Date: 1/19/2019
Description: Main file for lab3. Calls game class which
			then plays the game. 
**************************************/

#include <iostream>
#include "Game.hpp"

int main()	{
	
	Game game;

	game.menu();
	game.playGame();
	
}