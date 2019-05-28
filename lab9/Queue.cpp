/***************************************
Program Name: Lab 9
Author: Robert Elsom
Date: 3/2/2019
Description: Creates a queue with a percentage to add to the back
			and percentage to remove from the front for each round. 
			After adding or removing numbers from the queue, the function
			outputs the values still in the queue and the average length of
			the queue throughout the simulation. 
**************************************/
#include "Queue.hpp"
#include <cstdlib>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

Queue::Queue()	{
	rounds = 0;
	addPercentage = 0;
	rmPercentage = 0;
}

Queue::Queue(int rnds, int add, int rm)	{
	rounds = rnds;
	addPercentage = add;
	rmPercentage = rm;	
	simulation();
}

//simulates rounds and adds or removes values from buffer queue
void Queue::simulation()		{
	//runs simulation for rounds
	for (int i = 0; i < rounds; i++)	{
		passed = addNumber();
		//pops random number onto back of queue
		if (passed)	{
			buffer.push(rand() % 1000 + 1);
		}
		passed = rmNumber();
		//removes front number
		if (passed)	{
			buffer.pop();
		}
		printResults(buffer, i+1);
	}
}

//test if need to add number to queue
bool Queue::addNumber()	{
	if ((rand() % 100 + 1) <= addPercentage)	{
		return true;
	}
	else	{
		return false;
	}
}

//test if need to remove value from front of queue
bool Queue::rmNumber()	{
	if ((rand() % 100 + 1) <= rmPercentage && !buffer.empty())	{
		return true;
	}
	else	{
		return false;
	}
}

void Queue::printResults(std::queue<int> tempQueue, int round)	{
	cout << "--------------------------------------------------------------" << endl;
	//print contents of buffer
	cout <<  "The buffer contains: ";
	for (unsigned int i = 0; i < buffer.size(); i++)	{
		cout << tempQueue.front() << "  ";
		tempQueue.pop();
	}
	//print size of buffer
	cout << endl << "The length of the buffer is: " << buffer.size() << endl;
	
	//calculate average length
	double avLength = (prevLength * (round - 1) + buffer.size()) / round;
	//print average length of buffer
	cout << "The average length of the buffer is: " << avLength <<endl << endl;
	//save length for next round
	prevLength = avLength;
	cout << "--------------------------------------------------------------" << endl;
}













