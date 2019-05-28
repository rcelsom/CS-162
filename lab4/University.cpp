/***************************************
Program Name: Lab4
Author: Robert Elsom
Date: 1/26/2019
Description: Class file for University Class.
            Conatins name, building objects, and 
			people objects for Oregon State information
			system. Includes getters and setters for new 
			people and buildings.
**************************************/
#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>

#include "Building.hpp"
#include "Person.hpp"
#include "Student.hpp"
#include "Instructor.hpp"
#include "validInt.hpp"
#include "validStr.hpp"
#include "validDbl.hpp"
#include "University.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::string;
using std::vector;
using std::ifstream;



//constructor that creates vectors for building and persons
//and gets user to make 2 buildings, 1 student, and one instructor
University::University()	{
	
	ifstream ifs("People.txt");
	
	//storing people from txt file into person vector
	while (!ifs.eof())	{
		std::getline(ifs, line);
		
		//store name from file into tempName
		if (line[0] == 'N')	{
			for (unsigned int j = 6; j < line.size() -1; j++)	{
				tempName += line[j];
			}
		}
		//store age from file into tempAge
		if (line[0] == 'A')	{
			for (unsigned int j = 5; j < line.size(); j++)	{
				tempAgeStr += line[j];
			}
			tempAge = stoi(tempAgeStr);
		}
		//store gpa in tempGpa and make new student into vector
		if (line[0] == 'G')	{
			for (unsigned int j = 5; j < line.size(); j++)	{
				tempGPAStr += line[j];
			}
			tempGPA = stod(tempGPAStr);
			personVect.push_back(new Student(tempName, tempAge, tempGPA));
			people++;
			
			//reset after each line, so reset each run through
			tempName = "";
			tempAgeStr = "";
			tempGPAStr = "";
			tempRatingStr = "";
			
		}
		//store rating in tempRation and make new instructor in person vector
		else if ( line[0] == 'R')	{
			for (unsigned int j = 7; j < line.size(); j++)	{
				tempRatingStr += line[j];
			}
			tempRating = stod(tempRatingStr);
			personVect.push_back(new Instructor(tempName, tempAge, tempRating));
			people++;
			
			//reset after each line, so reset each run through
			tempName = "";
			tempAgeStr = "";
			tempGPAStr = "";
			tempRatingStr = "";
		}
	}
	ifs.close();
	
	//create first two buildings
	buildingVect.push_back(new Building("Dixon Recreation Center" , 173776, "425 SW 26th Street"));
	buildings++;
	buildingVect.push_back(new Building("Austin Hall", 107613, "2751 SW Jefferson Way"));
	buildings++;
	buildingVect.push_back(new Building("Gill Coliseum" , 257106, "660 SW 26th Street"));
	buildings++;
}



//creates new Building object and ask user to 
//input values for that building
void University::make_new_building()	{
	
	cout << "What is the building's name?" << endl;
	cin.ignore();
	getline(cin, tempName);
	//input square footage and check if it is between 1 and 1,000,000
	tempSize = validInt("What is the building's tempSize? (in sq ft)" , 1, 1000000);
	cout << "What is the building's address?" << endl;
	cin.ignore();
	getline(cin, tempAddress);
	buildingVect.push_back(new Building(tempName, tempSize, tempAddress));
	
	//increasing number of buildings counter
	buildings++;
}



//creates new person and ask user to input
//values for that person, needs to differentiate
//between student and instructor
void University::make_new_person ()	{
	
	cout << "Would you like to make a student or an instructor?" << endl;
	personType = validStr("1. Student\n2. Instructor", "1", "2");
	
	std::ofstream ofs("People.txt", std::ios_base::app);
	
	cout << "What is this person's name?" << endl;
	cin.ignore();
	getline(cin, tempName);
	ofs << "Name: " << tempName << endl;
	//prompt to input age and and make sure it is between 16 and 100
	tempAge = validInt("What is this person's age?\n" , 10, 100);
	ofs << "Age: " << tempAge << endl;
	
	if (personType == "1")	{
		//add student to persons vector
		personVect.push_back(new Student(tempName, tempAge));
		//add gpa to that students object
		tempGPA = validDbl("What is this student's GPA?\n", 0.0, 4.0);
		ofs << "GPA: " << std::fixed << std::setprecision(1) << tempGPA << endl << endl;
		personVect[ personVect.size()-1 ]->set_double(tempGPA);
	}
	else	{
		//add instructor to persons vector
		personVect.push_back(new Instructor(tempName, tempAge, tempRating));
		//add rating to instructor object
		tempRating = validDbl("What is this instructor's rating?\n" , 0.0, 5.0);
		ofs << "Rating: " << std::fixed << std::setprecision(1) << tempRating << endl << endl;
		personVect[ personVect.size()-1 ]->set_double(tempRating);
	}
	
	//increasing number of people counter
	people++;
	ofs.close();
}


//outprints list of all buildings and their information
void University::print_all_buildings()	{
	cout << "------------------------------" << endl;
	cout << std::setw(15) <<"BUILDINGS" << endl;
	cout << "------------------------------" << endl << endl;
	for (int i = 0; i < buildings; i++)	{
		cout << "Name: " << buildingVect[i]->get_name() << endl;
		cout << "Size: " << buildingVect[i]->get_size() << endl;
		cout << "Address: " << buildingVect[i]->get_address() << endl << endl;
	}
}


//outprints list of all people and their information
void University::print_all_people()	{
	
	cout << "------------------------------" << endl;
	cout << std::setw(15) <<"PEOPLE" << endl;
	cout << "------------------------------" << endl << endl;
	
	ifstream ifs("People.txt");
	
	
	while (!ifs.eof())	{
		std::getline(ifs, line);
		cout << line << endl;
	}
	ifs.close();
	

	/*
	for (int i = 0; i < people; i++)	{
		cout << "Name: " << personVect[i]->get_name() << endl;
		cout << "Age: " << personVect[i]->get_age() << endl;
		
		if (personVect[i]->is_student())	{
			cout << "Occupation: Student" << endl;
			cout << "GPA: " << std::fixed << std::setprecision(1);
			cout << personVect[i]->get_double() << endl << endl;
		}
		else	{
			cout << "Occupation: Instructor" << endl;
			cout << "Rating: "<<  std::fixed << std::setprecision(1);
			cout << personVect[i]->get_double() << endl << endl;
		}
	}
	*/
}


//displays start menu and gets user inputs
void University::menu()	{
	while (true)	{
		cout << "\nWelcome to Oregon State University Information System." << endl;
		cout << "------------------------------------------------------" << endl<< endl;
		cout << "1. Print information about buildings." << endl;
		cout << "2. Print information on all people at the University." << endl;
		cout << "3. Choose a person to do work." << endl;
		cout << "4. Add a building to the University system." << endl;
		cout << "5. Add a person to the University system." << endl;
		cout << "6. Exit program" << endl;
		menuOption = validInt("\nPlease pick one of the above options\n", 1, 6);
		
		//call function based on user option
		if (menuOption == 1)	{
			print_all_buildings();
		}
		else if (menuOption == 2) 	{
			print_all_people();
		}
		else if (menuOption == 3)	{
			choose_one_person();
		}
		else if (menuOption == 4)	{
			make_new_building();
		}
		else if (menuOption == 5)	{
			make_new_person();
		}
		else	{
			return;
		}
	}
}


//for option 3 in menu, outputs list of all people and gets
//user to choose one person to do work
void University::choose_one_person()	{
	
	//make sure there is atleast one person to display
	if (people > 0)	{
		//display names
		cout << "Here is the list of all people at the college." << endl;
		print_peoples_names();
		//pick names
		chosenPerson = validInt("\nPlease enter the number of the person you would like to do work?\n", 1, people);
		personVect[chosenPerson - 1]->do_work();
	}
	else {
		cout << "Sorry, there are no people to display" << endl;
	}
}


//prints all peoples names
void University::print_peoples_names()	{
	//open file
	ifstream ifs("People.txt");
	int i = 1;
	
	//output the names line starting at char 7, which is the start of the actual name
	while (!ifs.eof())	{
		std::getline(ifs, line);
		
		if (line[0] == 'N')	{
			cout << i << ": ";
			for (unsigned int j = 6; j < line.size(); j++)	{
				cout << line[j];
			}
			cout << endl;
			i++;
		}
	}
	ifs.close();
}


University::~University()	{
	for (int i = 0; i < people; i++)	{
		delete personVect[i];
	}
	for (int i = 0; i < buildings; i++)	{
		delete buildingVect[i];
	}
}