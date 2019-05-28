/***************************************
Program Name: Lab 10
Author: Robert Elsom
Date: 3/12/2019
Description: Measures the run time between a recursive
			and iterative Fibonaci series and reports the
			time. 
**************************************/
#include "Fibonacci.hpp"
#include "validInt.hpp"
#include <iostream>
#include <chrono>

using std::cout;
using std::cin;
using std::endl;


int menu()	{
	int userChoice = validInt("How many terms would you like to use?", 1, 60);
	return userChoice;
}

int main()	{
	Fibonacci fib;
	//call menu and store how many terms user wants
	int numTerms = menu();
	
	//start clock, chrono code found at https://en.cppreference.com/w/cpp/chrono
	std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
	//run recursive call
	fib.recursiveCall(numTerms);
	//stop clock
	std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
	
	cout << "The recursive time for " << numTerms << " terms is " << duration << " microseconds." << endl;
	
	
	//start clock, chrono code found at https://en.cppreference.com/w/cpp/chrono
	std::chrono::high_resolution_clock::time_point start2 = std::chrono::high_resolution_clock::now();
	//run recursive call
	fib.iterativeCall(numTerms);
	//stop clock
	std::chrono::high_resolution_clock::time_point end2 = std::chrono::high_resolution_clock::now();
	auto duration2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - start2).count();
	
	cout << "The iterative time for " << numTerms << " terms is " << duration2<< " microseconds." << endl;
	
}