/***************************************
Program Name: Lab 9
Author: Robert Elsom
Date: 3/2/2019
Description: Header file for Queue class
**************************************/

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <queue>
class Queue	{
private:
	std::queue<int> buffer;
	int rounds;
	int addPercentage;
	int rmPercentage;
	int average;
	bool passed;
	double prevLength = 0.0;
public:	
	Queue();
	Queue(int rounds, int add, int rm);
	void simulation();
	void printResults(std::queue<int> tempQueue, int round);
	bool addNumber();
	bool rmNumber();
	
};
#endif

