/***************************************
Program Name: Lab 9
Author: Robert Elsom
Date: 3/2/2019
Description: Receives a string parameter and outputs
			a palindrome using the stack container
**************************************/
#include "Stack.hpp"
#include <stack>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

std::string Stack(std::string startWord)	{
	std::stack<char> str;
	string palindrome = startWord;
	
	//pop word onto stack
	for(unsigned int i = 0; i < startWord.length() ; i++)	{
		str.push(startWord[i]);
	}

	//print word, then rest of palindrome from stack
	cout << "--------------------------------------------------------------" << endl;
	cout << endl <<"The created palindrome is:  " <<  startWord;
	for (unsigned int i = 0; i < startWord.length(); i++)	{
		palindrome += str.top();
		cout << str.top();
		str.pop();
	}
	cout << endl;
	cout << "--------------------------------------------------------------" << endl;  
	//return new palindrome
	return palindrome;
}