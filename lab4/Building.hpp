/***************************************
Program Name: Lab4
Author: Robert Elsom
Date: 1/26/2019
Description: Header file for Building class
**************************************/

#ifndef BUILDING_HPP
#define BUILDING_HPP
#include <string>

class Building{
	
private:
	std::string name;
	int size;
	std::string address;
	
public: 
	Building();
	Building(std::string n, int s, std::string add);
	std::string get_name();
	std::string get_address();
	int get_size();
	void set_name(std::string n);
	void set_size(int s);
	void set_address(std::string a);
	~Building();
	
	
};
#endif