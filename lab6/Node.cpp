 /***************************************
Program Name: Lab6
Author: Robert Elsom
Date: 2/9/2019
Description: Header file for Node class
**************************************/
#include "Node.hpp"

Node::Node()	{
	this->next = nullptr;
	this->previous = nullptr;
}

Node::Node(int val)	{
	this->val = val;
}

Node::~Node()	{	}