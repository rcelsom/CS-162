/***************************************
Program Name: Project2
Author: Robert Elsom
Date: 1/22/2019
Description: Class file for Zoo class. Displays start
				menu and gets user inputs. Then steps
			 	through the daily zoo routine of feeding, 
				increasing animal ages, updating how much money
				the zoo has remaining, creating random events, 
				and offering user to buy adult animals at the end
				of the day. Then ask if user wants to continue or quit
				as long as the zoo still has money. 
**************************************//***************************************
Program Name: Project 2
Author: Robert Elsom
Date: 1/22/2019
Description: Header file for Zoo class
**************************************/
#include "Animal.hpp"
#include <string>

#ifndef ZOO_HPP
#define ZOO_HPP

class Zoo		{
private:
	int bankRoll = 100000;
	int dailyFeedCost = 0;
	int profits = 0;
	int bonus;
	int userAnimal;
	std::string continueString = "";
	Tiger** tigerArr = NULL;
	Penguin** penguinArr = NULL;
	Turtle** turtleArr = NULL;
	//also the size of zooAnimals array
	int numberOfAnimals = 0;
	int randomChoice;
	int numberOfAdults;
	int adultAnimal;
	bool animalsAreBabies;
	int isASickAnimal;
	std::string buyAnimalOption = "";
	int buyAnimal;
	int numberOfTigers = 0;
	int numberOfPenguins = 0;
	int numberOfTurtles = 0;
	int sickAnimalType;
	int defaultTigerSize = 10;
	int defaultPenguinSize = 10;
	int defaultTurtleSize = 10;
	bool hasAnimalType;
	int numberAdultPenguins;
	int numberAdultTigers;
	int numberAdultTurtles;

	
public:
	void start();
	void turn();
	void increaseAges();
	void feedingCost();
	void subtractFromBankRoll();
	void randomEvent();
	void calculateProfit();
	void addToBankRoll();
	void buyAdultAnimal();
	void endOfDay();
	void initialAnimals(int choice);
	void bornAnimal();
	void sickAnimal();
	void bonusCalculator();
	void dailyStats();
	void doubleTigerSize();
	void doublePenguinSize();
	void doubleTurtleSize();
	~Zoo();
};
#endif