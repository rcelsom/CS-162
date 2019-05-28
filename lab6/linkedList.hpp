 /***************************************
Program Name: Lab6
Author: Robert Elsom
Date: 2/9/2019
Description: Header file for linkedList class
**************************************/

#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP
#include "Node.hpp"
#include <string>

class linkedList  	{
private:
	Node* head = nullptr;
	Node* tail = nullptr;
	int num = 0;
	Node* nodePtr;
	Node* garbage;
	Node* printPtr;
	
	//validInt variables
	int testInteger;
	bool validFlag = false;
	bool isNumber = true;
	std::string choice;

public:
	linkedList();
	void addToHead(int, bool);
	void addToTail(int );
	void deleteFromHead();
	void deleteFromTail();
	void printList();
	void printReverse();
	void printHead();
	void printTail();
	void createFromFile();
	int validInt(std::string prompt, int lowerLimit, int upperLimit);
	~linkedList();
	
};
#endif