/***************************************
Program Name: Lab 7
Author: Robert Elsom
Date: 2/21/2019
Description: Queue class file. Conatins member functions
			to check if queue is empty, add to back of queue,
			get first node in queue, remove first node, and print
			along with constructor and destructor.
**************************************/
#include <iostream>
#include "Queue.hpp"

using std::cout;
using std::endl;

//default constructor
Queue::Queue()	{
	head = nullptr;
}

//returns true if Queue is empty
bool Queue::isEmpty()	{
	if (head == nullptr)	{
		return true;
	}
	else	{
		return false;
	}
}

//adds node to back of Queue
void Queue::addBack(int val)	{
	//if list is empty
	if (isEmpty())	{
		head  = new QueueNode(val);
		head->next = head;
		head->prev = head;
	}
	//if one node
	else if (head->next == head)	{
		QueueNode* nodePtr = head;
		nodePtr = new QueueNode(val);
		head->next = nodePtr;
		head->prev = nodePtr;
		nodePtr->next = head;
		nodePtr->prev = head;
	}
	//if more than one node
	else	{
		QueueNode* nodePtr = head->prev;
		QueueNode* newPtr = head->prev;
		newPtr = new QueueNode(val);
		nodePtr->next = newPtr;
		newPtr->next = head;
		head->prev = newPtr;
		newPtr->prev = head;
	}
}

//returns value of first node in queue
int Queue::getFront()	{
	return head->val;
}

//removes first node in queue
void Queue::removeFront()	{
	if (isEmpty())	{
		cout << endl << "Sorry, this list is empty." << endl;
	}
	
	//if only one element
	else if (head->next == head)	{
		QueueNode* garbage = head;
		garbage = head;
		head = nullptr;
		delete garbage;
	}
	//if two elements
	else if (head->next == head->prev)	{
		QueueNode* garbage = head;
		head = head->next;
		delete garbage;
		head->next = head;
		head->prev = head;
	}
	//if more than two elements
	else	{
		QueueNode* garbage = head;
		QueueNode* nodePtr = head->prev;
		head = head->next;
		delete garbage;
		head->prev = nodePtr;
		nodePtr->next = head;
	}
}

//prints the queue
void Queue::printQueue()	{
	//if queue is empty
	if (isEmpty())	{
		cout << endl << "There are no values to print" << endl;
	}
	//if queue has atleast one element
	else	{
		QueueNode* nodePtr = head;
		cout << endl << "The queue value(s) are: " << endl;
		
		//print first value 
		cout << nodePtr->val << "   ";
		nodePtr = nodePtr->next;
		
		//print rest of values after head until circle back around
		while (nodePtr != head)	{
			cout << nodePtr->val << "   ";
			nodePtr = nodePtr->next;
		}
		cout << endl;
	}
}

//deconstructor, freeing dynamic memory
Queue::~Queue()	{
	if (!isEmpty())	{
		QueueNode* nodePtr = head->next;
		while (nodePtr != head)	{
			QueueNode *garbage = nodePtr;
			nodePtr = nodePtr->next;
			delete garbage;
		}
		delete head;
	}
}