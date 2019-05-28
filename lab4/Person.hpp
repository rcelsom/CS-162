/***************************************
Program Name: Lab4
Author: Robert Elsom
Date: 1/26/2019
Description: Header file for Person class
**************************************/
#include "Student.hpp"
#include "Instructor.hpp"
#ifndef PERSON_HPP
#define PERSON_HPP
#include <string>

class Person{

protected: 
	std::string name;
	int age;
	
public:
	Person();
	Person(std::string n, int a);
	virtual void do_work();
	virtual std::string get_name();
	virtual int get_age();
	virtual double get_double();
	virtual void set_double(double d);
	virtual bool is_student();
	virtual ~Person();
};
#endif