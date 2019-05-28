 /***************************************
Program Name: Lab6
Author: Robert Elsom
Date: 2/9/2019
Description: Header file for Menu class 
**************************************/

#ifndef MENU_HPP
#define MENU_HPP

#include <string>

class Menu {
private:
	int testInteger;
	bool validFlag = false;
	bool isNumber = true;
	std::string choice;
	int userChoice;
	bool firstTime =true;
	int firstOption;
public:
	Menu();
	~Menu();
	int startMenu();
	int validInt(std::string prompt, int lowerLimit, int upperLimit);


};
#endif