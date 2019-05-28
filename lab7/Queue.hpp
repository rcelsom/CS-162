/***************************************
Program Name: Lab 7
Author: Robert Elsom
Date: 2/21/2019
Description: Queue header file. 
**************************************/

#ifndef QUEUE_HPP
#define QUEUE_HPP
class Queue	{

private:

	struct QueueNode
	{
		int val;
		QueueNode *next;
		QueueNode *prev;
		QueueNode(int val1, QueueNode *next1 = nullptr, QueueNode *previous1 = nullptr)
		{
			val = val1;
			next = next1;
			prev = previous1;
		}
	};
	
	QueueNode* head = nullptr;
	
public:
	Queue();
	~Queue();
	bool isEmpty();
	void addBack(int val);
	int getFront();
	void removeFront();
	void printQueue();
};
#endif