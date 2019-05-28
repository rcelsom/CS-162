/***************************************
Program Name: Lab 4
Author: Robert Elsom
Date: 1/27/2019
Description: Derived class for people on OSU campus
			Contains getter and setter for rating of the students
			and a do_work function that generates a random number 
			and returns a message based on whether person is student or 
			instructor and a is student function that always returns false
**************************************/
#include <iostream>
#include <string>
#include "Student.hpp"

//defualt constructor
Student::Student() {
	this->name = "";
	this->age = -1;
}

//sets students name and age
Student::Student(std::string n, int age) 	{
	this->name = n;
	this->age = age;
}

//overload constructor that also sets the gpa
Student::Student(std::string n, int age, double gpa)	{
	this->name = n;
	this->age = age;
	this->GPA = gpa;
	std::cout << "N: " << name << std::endl;

}

//sets students gpa
void Student::set_double(double g)	{
	this->GPA = g;
}

//returns students gpa
double Student::get_double()	{
	return GPA;
}

//outputs how many random hours the students 
//study per week
void Student::do_work()	{
	std::cout << std::endl << name << " did " << rand() % 50 << " hours of homework." << std::endl;
}

//returns true since it is a student
bool Student::is_student()	{
	return true;
}

Student::~Student()	{ }