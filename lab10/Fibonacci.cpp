/***************************************
Program Name: Lab 10
Author: Robert Elsom
Date: 3/12/2019
Description: Contains a recursive and iterative fibonacci
			functions to call. 
**************************************/
#include "Fibonacci.hpp"

//using code found at https://www.codeproject.com/tips/109443/fibonacci-recursive-and-non-recursive-c
int Fibonacci::recursiveCall(int terms)	{
	if (terms == 0)	{
		return 0;
	}
	else if (terms == 1)	{
		return 1;
	}
	
	return recursiveCall(terms - 1) + recursiveCall(terms - 2);
	
}

//using code found at https://www.codeproject.com/tips/109443/fibonacci-recursive-and-non-recursive-c
int Fibonacci::iterativeCall(int terms)	{
	int first = 0;
	int second = 1;
	int counter = 2;
	
	while (counter < terms)	{
		int temp = second;
		second += first;
		first = temp;
		counter++;
	}
	
	if (terms == 0)	{
		return 0;
	}
	else	{
		return first + second;
	}
}