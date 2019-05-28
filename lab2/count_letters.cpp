/***************************************
Program Name: Lab 2
Author: Robert Elsom
Date: 1/17/2019
Description:output_letters function is passed an ifstream
			object and an array. It 
**************************************/

#include <iostream>
#include <fstream>
#include "count_letters.hpp"
#include <string>
#include <cctype>


using std::ifstream;
using std::string;

void count_letters(ifstream &inputFile, int numOfLetters[])	{
	
	string paragraph;
	char alphabet[26] = {'a'};
		
	//start at i=1 to start at letter b since a is already initialized, initializes rest of array to letters of the alphabet
	for (int i = 1; i < 26; i ++)	{
		alphabet[i] = alphabet[i-1] + 1;
	}
	
	//get entire line
	getline(inputFile, paragraph);
	
	/* need to comment out since rubric says needs to count number of new line characters
	//if line is blank, get next line
	if (paragraph.empty())	{
		getline(inputFile, paragraph);
	}
	*/
	
	//compares every letter in the paragraph to every letter in the alphabet
	//and stores number of times letter appears in numOfLetters
	for (unsigned int i = 0; i < paragraph.length(); i++)	{
		for (int j = 0; j < 26; j++)	{
			if (std::tolower(paragraph[i]) == alphabet[j])	{
				numOfLetters[j] += 1;
			}
		}
	}
	
	
}