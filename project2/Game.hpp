/***************************************
Program Name: Project 2
Author: Robert Elsom
Date: 1/22/2019
Description: Header file for Game class
**************************************/

#ifndef GAME_HPP
#define GAME_HPP

class Game		{
private:
	int bankRoll = 100000;
	int dialyFeedCost;
	int profits;
	int bonus;
	int userAnimal;
	string continueString;
	int newAnimalCounter = 0;
	
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
	void bornAnimal(int animalType);
	void boughtAniaml(int animalType);
};
#endif