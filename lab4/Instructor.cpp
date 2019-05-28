/***************************************
Program Name: Lab 4
Author: Robert Elsom
Date: 1/27/2019
Description: Derived class for people on OSU campus
			Contains getter and setter for rating of the instructor
			and a do_work function that generates a random number 
			and returns a message based on whether person is student or 
			instructor and a is student function that always returns false
**************************************/
#include <iostream>
#include <string>
#include "Instructor.hpp"

//default constructor
Instructor::Instructor() {
	this->name = "";
	this->age = -1;
}

//sets persons name and age
Instructor::Instructor(std::string name, int age) {
	this->name = name;
	this->age = age;
}

//overload constructor that also sets the instructors rating
Instructor::Instructor(std::string name, int age, double rating)	{
	this->name = name;
	this->age = age;
	this->rating = rating;
}

//sets instructors rating
void Instructor::set_double(double r)	{
	this->rating = r;
}

//returns instructors double
double Instructor::get_double()	{
	return rating;
}

//returns how many hours the instructor works,
//hours are random
void Instructor::do_work()	{
	std::cout << std::endl << name << " graded papers for "<< rand() % 50 << " hours." << std::endl;	
}

//returns false since it is not a student
bool Instructor::is_student()	{
	return false;
}

Instructor::~Instructor()	{}

