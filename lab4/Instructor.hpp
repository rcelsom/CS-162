/***************************************
Program Name: Lab4
Author: Robert Elsom
Date: 1/26/2019
Description: Header file for Instructor class
**************************************/

#ifndef INSTRUCTOR_HPP
#define INSTRUCTOR_HPP
#include <string>
#include "Person.hpp"

class Instructor : public Person {

private: 
	double rating;
	
public:
	Instructor();
	Instructor(std::string name, int age);
	Instructor(std::string name, int age, double rating);
	void set_double(double r);
	double get_double();
	void do_work();
	bool is_student();
	~Instructor();
	
	
};
#endif