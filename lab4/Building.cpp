/***************************************
Program Name: Lab 4
Author: Robert Elsom
Date: 1/27/2019
Description: contains information on buildings
			on the OSU campus including name, size, 
			and address. Contains setters and getters
			for all variables.
**************************************/

#include <iostream>
#include <string>
#include "Building.hpp"

//default constructor
Building::Building()	{
	this->name = "";
	this->size = -1;
	this->address = "";
}

//sets building name, size, and address
Building::Building(std::string n, int s, std::string add)	{
	this->name = n;
	this->size = s;
	this->address = add;
}

//returns buildings name
std::string Building::get_name()	{
	return name;
}

//returns buildings address
std::string Building::get_address()	{
	return address;
}

//returns buildings size
int Building::get_size()	{
	return size;
}

//sets biuldings name
void Building::set_name(std::string n)	{
	this->name = n;
}

//sets buildings size in sq ft
void Building::set_size(int s)	{
	this->size = s;
}

//sets buildings address
void Building::set_address(std::string a)	{
	this->address = a;
}

Building::~Building()	{}
