/***************************************
Program Name: Lab4
Author: Robert Elsom
Date: 1/26/2019
Description: Header file for Unviersity class
**************************************/

#ifndef UNIVERSITY_HPP
#define UNIVERSITY_HPP
#include <string>
#include <vector>

class University {
#include "Building.hpp"
#include "Person.hpp"

private:
	std::vector<Building*> buildingVect;
	std::vector<Person*> personVect;
	std::string line;
	const std::string name = "Oregon State University";
	int buildings = 0;
	int people = 0;
	std::string tempAgeStr;
	std::string tempGPAStr;
	std::string tempRatingStr;
	std::string personType;
	std::string tempName;
	int tempSize;
	int tempAge;
	std::string tempAddress;
	double tempGPA;
	double tempRating;
	int chosenPerson;
	int menuOption;

public:
	University();
	void make_new_building();
	void make_new_person();
	void print_all_buildings();
	void print_all_people();
	Building get_building_info();
	Person get_person_info();
	void menu();
	void choose_one_person();
	void print_peoples_names();
	~University();

	
};
#endif
