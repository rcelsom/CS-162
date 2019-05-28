/***************************************
Program Name: Project 7
Author: Robert Elsom
Date: 2/21/2019
Description: Queue class file for lineups and storing losing characters 
			in a container. Conatins member functions
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
void Queue::addBack(Character* character)	{
	//if list is empty
	if (isEmpty())	{
		head  = new QueueNode(character);
		head->next = head;
		head->prev = head;
	}
	//if one node
	else if (head->next == head)	{
		QueueNode* nodePtr = head;
		nodePtr = new QueueNode(character);
		head->next = nodePtr;
		head->prev = nodePtr;
		nodePtr->next = head;
		nodePtr->prev = head;
	}
	//if more than one node
	else	{
		QueueNode* nodePtr = head->prev;
		QueueNode* newPtr = head;
		newPtr = new QueueNode(character);
		nodePtr->next = newPtr;
		newPtr->next = head;
		head->prev = newPtr;
		newPtr->prev = nodePtr;
	}
}

//creates new character to add to head of list
void Queue::addHead(Character* character)	{
	//add node to back of list
	addBack(character);
	//shift head back one spot to new node
	head = head->prev;
}

//returns value of first node in queue
Character* Queue::getFront()	{
	return head->character;
}

//returns last value in the queue, mostly used for testing purposes
Character* Queue::getBack() {
	QueueNode* temp = head;
	temp = temp->prev;
	return temp->character;
}

//removes first node in queue
void Queue::removeFront()	{
	if (isEmpty())	{
		cout << endl << "Sorry, the team has been defeated." << endl;
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
		//delete garbage->character;
		delete garbage;
		head->prev = nodePtr;
		nodePtr->next = head;
	}
}

//prints the queue in first in first out
void Queue::printQueue()	{
	//if queue is empty
	if (isEmpty())	{
		cout << endl << "There are no values to print" << endl;
	}
	//if queue has atleast one element
	else	{
		QueueNode* nodePtr = head;
		Character* temp = nodePtr->character;
		//print first value 
		cout << endl << temp->getType() << " " << temp->getName() << endl;
		nodePtr = nodePtr->next;
		
		//print rest of values after head until circle back around
		while (nodePtr != head)	{
			temp = nodePtr->character;
			cout << temp->getType() << " " << temp->getName() << endl;
			nodePtr = nodePtr->next;
		}
		cout << endl;
	}
}

//using to print in first in last out
void Queue::printReverseQueue() {
	//if queue is empty
	if (isEmpty()) {
		cout << endl << "There are no values to print" << endl;
	}
	//if queue has atleast one element
	else {
		
		QueueNode* nodePtr = head;
		Character* temp = nodePtr->character;
		//print rest of values after head until circle back around
		do {
			nodePtr = nodePtr->prev;
			temp = nodePtr->character;
			cout << temp->getTeam() << " " << temp->getType() << " " << temp->getName() << endl;
		} while (nodePtr != head);
	}
}

//moves head to next node, meaning previous head is now end of list
void Queue::moveToBack()	{
	head = head->next;
	/*
	QueueNode* nodePtr;
	nodePtr = head;
	head = head->next;
	//may not be needed, check later
	head->prev = nodePtr;
	*/
}

//deconstructor, freeing dynamic memory
Queue::~Queue()	{
	if (!isEmpty())	{
		QueueNode* nodePtr = head->next;
		while (nodePtr != head)	{
			delete nodePtr->character;
			QueueNode *garbage = nodePtr;
			nodePtr = nodePtr->next;
			delete garbage;
		}
		delete head->character;
		delete head;
	}
}