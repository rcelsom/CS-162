 /***************************************
Program Name: Lab6
Author: Robert Elsom
Date: 2/9/2019
Description: Contains head and tail that point to beginning
			and end of node object along with printing different 
			parts of the node list and adding to the node list
**************************************/

#include <iostream>
#include "linkedList.hpp"


using std::cout;
using std::cin;
using std::endl;
using std::string;

//constructor
linkedList::linkedList()	{
	Node list;
	head = nullptr;
	tail = nullptr;
}

//adds node to head 
void linkedList::addToHead(int num, bool txtfile = false)	{
	//if list is empty
	if (head == nullptr)	{
		head = new Node(num);
		//point head and tail to same element
		tail = head;
	}
	
	else	{
		//change head to new element and point new element to prev head
		Node *oldPtr = head;
		head = new Node(num);
		head->next = oldPtr;
		//change prev new element to null and prev tail to new element
		oldPtr->previous = head;
		head->previous = nullptr;
	}
	
	//do not print if adding from txt file
	if (!txtfile)	{
		printList();
	}
}

//adds node to tail
void linkedList::addToTail(int num)	{
	
	if (head == nullptr)	{
		head = new Node(num);
		//point head and tail to same element
		tail = head;
	}
	
	else	{
		Node *oldPtr = tail;
		tail = new Node(num);
		tail->previous = oldPtr;
		oldPtr->next = tail;
		tail->next = nullptr;
	}
	
	printList();
}

//deletes first node
void linkedList::deleteFromHead()	{
	
	if (head==nullptr)	{
		cout << endl << "Sorry, this list is empty." << endl;
	}
	
	//if only one element
	else if (head->next == nullptr)	{
		garbage = head;
		tail = nullptr;
		head = nullptr;
		delete garbage;
		cout << endl << "The list is now empty." << endl;
	}
	
	else	{
		garbage = head;
		head = head->next;
		delete garbage;
		head->previous = nullptr;
		printList();
	}
	
	
}

//deletes last node
void linkedList::deleteFromTail()	{
	
	if (head == nullptr)	{
		cout << endl << "Sorry, this list is empty." << endl;
	}
	
	//if only one element
	else if (head->next== nullptr)	{
		garbage = tail;
		tail = nullptr;
		head = nullptr;
		delete garbage;
		cout << endl << "The list is now empty." << endl;
	}
	
	else 	{
		garbage = tail;
		cout << garbage->val << endl;
		tail = tail->previous;
		delete garbage;
		tail->next = nullptr;
		printList();
	}
	
	
}

//prints list from head to tail
void linkedList::printList()	{
	
	if (head == nullptr)	{
		cout << endl << "There are no values to print" << endl;
	}
	else	{
		nodePtr = head;
		cout << endl << "The node values are: " << endl;
		while (nodePtr != tail)	{
			cout << nodePtr->val << "   ";
			nodePtr = nodePtr->next;
		}
		cout << tail->val << endl;
	}
}

//prints list in reverse using tail ptr
void linkedList::printReverse()	{
	
	if (head == nullptr)	{
		cout << endl << "Sorry, the list is empty." << endl;
	}
	
	else	{
		cout << endl << "The node values in reverse order are: " << endl;
		printPtr = tail;
		
		//print up to head, was getting seg fault when printing all the way to head
		//for some reason I couldn't figure out. 
		while (printPtr != head)	{
			cout << printPtr->val << "   ";
			if (printPtr->previous != nullptr)	{
				printPtr = printPtr->previous;
			}
		}
		cout << head->val << endl;
	}
}

//prints head node
void linkedList::printHead()	{
	if (head)	{
		cout << endl << "The head value is: " << head->val << endl << endl;
	}
	
	else{
		cout << endl << "Sorry, the list is empty." << endl;
	}
}

//prints tail node
void linkedList::printTail()	{
	if (head)	{
		cout << endl << "The tail value is: " << tail->val << endl << endl;
	}
	
	else{
		cout << endl<< "Sorry, the list is empty." << endl;
	}
}

//reads txt file and adds to list
void linkedList::createFromFile()	{
	
	
}

int linkedList::validInt( string prompt, int lowerLimit, int upperLimit)	{
	while(validFlag == false)	{
		cout << prompt;
		cin >> choice;
		
		//check if negative number
		if (choice[0] != '-' && !isdigit(choice[0]))	{
			isNumber = false;
		}
		
		//changes flag isNumber if any part of input is not a digit after first which could be negative sign
		for (unsigned int i = 1; i <choice.length(); i++)    {
			if (!isdigit(choice[i]))    {
			   isNumber = false;
			}
		}

		if(!isNumber)   {
			cout<< "Sorry, that is not a valid input" << endl;
			isNumber= true;
		}

		//if variable choice passes as being a number, now verify that it is in range and
		//fit in the limits of the program parameters
		else   {
			testInteger = stoi(choice);

			if (testInteger > upperLimit || testInteger < lowerLimit)	{
				cout << "Sorry, that number must be in the range " << lowerLimit << " to " << upperLimit << "." << endl << endl;
			}
			else{
				validFlag = true;
			}
		}
	}
	return testInteger;	
}

//deconstructor
linkedList::~linkedList()	{
	nodePtr = head;
	while (nodePtr != nullptr)	{
		garbage = nodePtr;
		nodePtr = nodePtr->next;
		delete garbage;
	}
}
	
	

