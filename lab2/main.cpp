/***************************************
Program Name: Lab 2
Author: Robert Elsom
Date: 1/17/2019
Description: Program promps for user to input file name.
			Then it reads the file, counting how many times each
			letter appears into an array. Then it prompts the user 
			to input an output file name and writing to that file the
			results.
**************************************/

#include <iostream>
#include <string>
#include <fstream>
#include "count_letters.hpp"
#include "output_letters.hpp"


using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::ofstream;

int main()	{

	string inFileName;
	string outFileName;
	ofstream ofs(outFileName);
	//prompts user for file name
	cout << "Please enter file name to get letter frequency from: " << endl;
	
	//store file name
	cin >> inFileName;

	//test file open
	ifstream ifs( inFileName );
	while  (ifs.fail())	{
		cout << "Sorry, that file does not exist." << endl;
		cout <<"Please enter a new name. " << endl;
		cin >> inFileName;
		ifs.open(inFileName);
	}	
		
	while (!ifs.eof())	{
		//declare in while loop to make sure it resets to zero for every call
		int letterArray[26] = {};
		
		//call count_letters(ifstream &, int * to array)
		count_letters(ifs, letterArray);	


		//call output_letters(ofstream &, int*)
		output_letters(ofs, letterArray);
	}	

	//close ofs to make sure it is written from the buffer
	ofs.close();
}
