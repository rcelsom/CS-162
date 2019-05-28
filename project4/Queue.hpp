/***************************************
Program Name: Lab 7
Author: Robert Elsom
Date: 2/21/2019
Description: Queue header file. 
**************************************/
#ifndef QUEUE_HPP
#define QUEUE_HPP
#include "Character.hpp"

class Queue	{
private:

	struct QueueNode
	{
		Character* character;
		QueueNode *next;
		QueueNode *prev;
		QueueNode(Character* char1, QueueNode *next1 = nullptr, QueueNode *previous1 = nullptr)
		{
			character = char1;
			next = next1;
			prev = previous1;
		}
	};
	
	QueueNode* head = nullptr;
	
public:
	Queue();
	~Queue();
	bool isEmpty();
	void addBack(Character* character);
	void addHead(Character* character);
	Character* getFront();
	Character* getBack();
	void removeFront();
	void printQueue();
	void printReverseQueue();
	void moveToBack();
};
#endif