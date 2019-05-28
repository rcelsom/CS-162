/***************************************
Program Name: Lab4
Author: Robert Elsom
Date: 1/26/2019
Description: Header file for Student class
**************************************/

#ifndef STUDENT_HPP
#define STUDENT_HPP
#include <string>
#include "Person.hpp"

class Student : public Person{

private:
	double GPA;
	
public:
	Student();
	~Student();
	Student(std::string name, int age);
	Student(std::string name, int age, double gpa);
	double get_double();
	void set_double(double g);
	bool is_student();
	void do_work();

};
#endif