/***************************************
Program Name: Lab 7
Author: Robert Elsom
Date: 2/21/2019
Description: Main file for using Queue class
			contains main functions along with 
			menu function
**************************************/

#include <iostream>
#include "validInt.hpp"
#include "Queue.hpp"

using std::cout;
using std::cin;
using std::endl;

int menu()	{
	int choice;
	
	choice = validInt("\nChoose one of the following\n"\
					  "1. Enter a value to be added to the back of the queue\n"\
					  "2. Display first node (front) value\n"\
					  "3. Remove first node (front) value\n"\
					  "4. Display the queue contents\n"\
					  "5. Exit\n\n", 1, 5);
	return choice;
}

int main()	{
	int userChoice = 0;
	int addNum;
	Queue queue;
	
	cout << endl << "Welcome to Queue!" << endl;
	
	while (userChoice != 5)	{
		userChoice = menu();
		
		//add node to end of queue
		if (userChoice == 1)	{
			addNum = validInt("\nWhat integer would you like to add?\n", -100000, 100000);
			cout << endl;
			queue.addBack(addNum);
		}
		
		//diplay first node
		else if (userChoice == 2)	{
			if (!queue.isEmpty())	{
				cout << endl << "The first node value is " << queue.getFront() << endl;
			}
			else {
				cout << endl << "Sorry, the list is empty" << endl;
			}
		}
		
		//Remove first node
		else if (userChoice == 3)	{
			queue.removeFront();
		}
		//Display queue contents\n
		else if (userChoice == 4)	{
			queue.printQueue();
		}
		// else exit
	}
		
	return 0;
}