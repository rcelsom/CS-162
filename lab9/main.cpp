/***************************************
Program Name: Lab 9
Author: Robert Elsom
Date: 3/2/2019
Description: main function and menu function, main responsible for menu call, 
			menu gets and validates user input then calls other functions
**************************************/
#include <iostream>
#include "validInt.hpp"
#include "Queue.hpp"
#include "Stack.hpp"

using std::cout;
using std::cin;
using std::endl;

//gets and validates user input then calls functions based on input
void menu()	{
	cout << "Welcome to Stack and Queue Containers!"<< endl;
	//get user input
	while (true)	{
		//print start menu
		int choice = validInt("Please choose one of the following: \n"\
								"1. Test buffer \n"\
								"2. Create palindrome \n"\
								"3. Exit\n", 1, 3);
		//get inputs for buffer functions
		if (choice == 1)	{
			int addNum = validInt("What percentage would you like to add a random number to the back of the queue?", 0, 100);
			int rmNum = validInt("What percentage would you like to remove a number from the front of the queue?", 0, 100);
			int rounds = validInt("How many rounds would you like to simulate?", 1, 1000);
			Queue(rounds, addNum, rmNum);
		}
		//get inputs for palindrome
		else if (choice == 2)	{
			std::string word;
			bool validStr;
			cout << "Please enter a word to create a palindrome: " << endl;
			//validates string does not have spaces and is one word
			cin.ignore();
			do	{
				
				std::getline(cin,word);
				validStr = true;
				for (unsigned int i = 0; i < word.length(); i++)	{
					if (word[i] == ' ')	{
						cout << "Sorry, words cannot have spaces. Try again:" << endl;
						validStr = false;
					}
				}
			} while (!validStr);
			std::string palindrome = Stack(word);
		}
		//exit
		else	{
			return;
		}
	}
}

//main only used to call menu
int main()	{
	srand(time(NULL));
	menu();
}