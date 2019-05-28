 /***************************************
Program Name: Lab6
Author: Robert Elsom
Date: 2/9/2019
Description: Header file for Node class
**************************************/

#ifndef NODE_HPP
#define NODE_HPP

class Node {
private:
	struct ListNode
	{
		int val;
		ListNode *next;
		ListNode *previous;
		ListNode(int val1, ListNode *next1 = nullptr, ListNode *previous1 = nullptr)
		{
			val = val1;
			next = next1;
			previous = previous1;
		}
	};
	Node* next;
	Node* previous;
	int val;
	friend class linkedList;

public:
	Node();
	Node(int value);
	~Node();
	
};
#endif