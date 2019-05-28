/***************************************
Program Name: Lab5
Author: Robert Elsom
Date: 2/4/2019
Description: Contains three recursive functions, either
			printing a string in reverse, the sum of integers
			in an array, or the nth triangular number, all of which
			the user set in the main function and are passed as parameters
**************************************/
#include <iostream>
#include <string>
#include "recursive_functions.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;


//reverses user inputted string
void string_reverse(std::string userString)		{
	
	//base case
	if (userString.size() == 1)	{
		cout << userString << endl << endl;
	}
	
	//print last char and recall function with string without the last char
	else{
		cout << userString[userString.size() - 1];
		//used http://www.cplusplus.com/reference/string/string/substr/ to learn
		//how to pass a substring
		string_reverse( userString.substr(0, userString.size() -1));
	}
}

//recursively finds the sum of the array
int sum_of_array(int* array, int size)	{	
	int sum;

	//base case
	if (size <= 1)	{
		return array[0];
	}
	
	//add all numbers down to base case
	else	{
		sum = array[size-1] + sum_of_array(array, size-1);
		return sum;
	}
}


//calculates nth triangular number
int triangular_number(int N)		{
	int number;
	//base case
	if ( N <= 1)	{
		return N;
	}

	//add all the way down to base case
	else 	{
		number = N + triangular_number(N-1);
		return number;
	}	
}