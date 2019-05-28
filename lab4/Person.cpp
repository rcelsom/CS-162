/***************************************
Program Name: Lab 4
Author: Robert Elsom
Date: 1/27/2019
Description: Parent class for people on OSU campus
			Contains getters and setters for name and
			age for each person and a do_work function
			that generates a random number and returns a 
			message based on whether person is student or 
			instructor
**************************************/

#include <iostream>
#include <string>
#include "Person.hpp"

//default constructor
Person::Person()	{
	this->name = "";
	this->age = -1;
}

//sets persons name and age
Person::Person(std::string n, int a)	{
	this->name = n;
	this->age = a;
}

//returns statement about persons work
void Person::do_work()	{

}

//returns name
std::string Person::get_name()	{
	return name;
}

//returns age
int Person::get_age()	{
	return age;
}

//returns double value
double Person::get_double()	{
	return 0.0;
}

void Person::set_double(double d)	{
	
}

bool Person::is_student()	{
	return false;
}

Person::~Person ()	{}