/***************************************
Program Name: Lab5
Author: Robert Elsom
Date: 2/4/2019
Description: main function for lab 5, contains
			the menu and options for the user to 
			pick a recursive function to use, either
			printing a string in reverse, the sum of integers
			in an array, or the nth triangular number, all of 
			which the user chooses and inputs. 
**************************************/
#include <iostream>
#include <string>
#include "recursive_functions.hpp"
#include "validInt.hpp"

using std::endl;
using std::cout;
using std::cin;
using std::string;


int main()	{
	int functionChosen;
	string userString;
	int arraySize;
	int nthNumber;
	int sum;
	int number;
	
//while statement to keep repeating menu	
	while (true)	{
		//use valid int to verify it is a valid choice for menu call
		functionChosen = validInt("Please choose a function to call.\n 1. Reverse a string \
		\n 2. Sum of an array \n 3. Print nth triangular number\n 4. Quit\n" , 1 , 4);
		
		
		//function call for reversing a string
		if (functionChosen == 1)	{
			cout << "Please enter a string to reverse:" << endl;
			cin.ignore();
			std::getline(cin, userString);
			cout << endl << "Reversed String: " << endl;
			string_reverse(userString);
		}

		
		//function call for sum of an array
		else if (functionChosen == 2)	{
			arraySize = validInt("How many integers are in the array? \n", 1, 1000);
			int* numberArray = new int[arraySize];
		
			for (int i = 0; i < arraySize; i++)	{
				numberArray[i] = validInt("Please enter a new number for the array:  ", -100000, 100000);
			}
			
			sum = sum_of_array(numberArray, arraySize);
			cout << "The sum of the array is: "<< sum << endl << endl;
			delete[] numberArray;
		}
		
		
		//function call for showing the nth triangular number
		else if (functionChosen == 3)	{
			string suffix;
			nthNumber = validInt ( "Please enter what triangular number you would like to see: \n" , 1, 10000);
			number = triangular_number(nthNumber);
			
			//finding right suffix for print statement
			if (nthNumber % 10 == 1)	{
				suffix = "st";
			}
			else if (nthNumber % 10 == 2)	{
				suffix = "nd";
			}
			else if (nthNumber % 10 == 3)	{
				suffix = "rd";
			}
			else {
				suffix = "th";
			}
			
			//print number
			cout << "The " << nthNumber << suffix << " triangular number is: " << number << endl << endl;
		}
		
		
		//if user chooses to exit
		else {
			return 0;
		}
	}
}