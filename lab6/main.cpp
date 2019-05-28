 /***************************************
Program Name: Lab6
Author: Robert Elsom
Date: 2/9/2019
Description: Creates menu object, then edits linkedList
			based on user input from menu class.
**************************************/
#include <fstream>
#include <iostream>
#include <string>
#include "linkedList.hpp"
#include "Menu.hpp"
#include "validInt.hpp"

using std::string;
int startMenu(bool firstRun)	{
	int userChoice;
	
	if (firstRun)	{
		userChoice = validInt("\nPlease choose one of the following: \n1. Create list from txt file\n"\
								"2. Create custom list\n", 1, 2);
	
		if (userChoice == 1)	{
			return -1;
		}
	}
	
	userChoice = validInt ("\nChoose one of the following options: \n\n1. Add a new node to the head.\n"\
						"2. Add a new node to the tail. \n3. Delete from head. \n4. Delete from tail.\n"\
						"5. Traverse the list reversely. \n6. Print head \n7. Print tail. \n8. Exit\n", 1, 9);

	return userChoice;
}

void startFromTxtFile(linkedList* list)	{
	int number;
	std::string txtNums;
	std::ifstream ifs("numberList.txt");
	
	//storing people from txt file into person vector
	while (!ifs.eof())	{
		std::getline(ifs, txtNums);
		number = std::stoi(txtNums);
		list->addToHead(number, true);
	}
	ifs.close();
	list->printList();
}	


int main()		{
	
	int userChoice = 0;
	bool exitFlag = false;
	int number;
	std::string txtNums;
	//create and call menu
	linkedList list;
	bool firstRun = true;
	linkedList* listPtr = &list;
	
	while (!exitFlag)	{
		userChoice = startMenu(firstRun);

		firstRun = false;
		//create from txt file
		if (userChoice == -1)	{
			startFromTxtFile(listPtr);
		}
		//Add new node to head
		else if (userChoice == 1)	
		{
			number = validInt("What number would you like to add?", -100000,100000);
			list.addToHead(number, false);
		}
		
		//add new node to tail
		else if (userChoice == 2)
		{
			number = validInt("What number would you like to add?", -100000,100000);
			list.addToTail(number);
		}
		
		//Delete from head
		else if (userChoice == 3)
		{
			list.deleteFromHead();
		}
		
		//delete from tail
		else if (userChoice == 4)
		{
			list.deleteFromTail();
		}
		
		//traverse list reversely
		else if (userChoice == 5)
		{
			list.printReverse();
		}
		
		//print head
		else if (userChoice == 6)
		{
			list.printHead();
		}
		
		//print tail
		else if (userChoice == 7)
		{
			list.printTail();
		}
		else	{
			exitFlag = true;
		}
	}
}