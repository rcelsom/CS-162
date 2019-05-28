/***************************************
Program Name: Lab 2
Author: Robert Elsom
Date: 1/17/2019
Description:Count_letters function is passed an ifstream
			object and an array. It then counts how many times
			the letters appear in the object and stores the results
			in the array. 
**************************************/

#include <iostream>
#include <fstream>
#include "output_letters.hpp"

using std::cout;
using std::cin;
using std::endl;

void output_letters(std::ofstream &outputFile, int numberLetters[])		{
	
	char alphabet[26] = {'a'};
	std::string outputFileName;
	
	//start at i=1 to start at letter a, initializes rest of array to letters of the alphabet
	for (int i = 1; i < 26; i ++)	{
		alphabet[i] = alphabet[i-1] + 1;
	}
	
	cout << "Please enter the file name where you would like the results stored." << endl;
	cin >> outputFileName;
	
	std::ofstream ofs(outputFileName);
	
	//storing output into ofstream object
	for (int i = 0; i < 26; i++)	{
		ofs << alphabet[i] << ": " << numberLetters[i] << endl << endl;
		
	}
}