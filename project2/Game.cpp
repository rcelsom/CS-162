/***************************************
Program Name: Project2
Author: Robert Elsom
Date: 1/22/2019
Description: Class file for Game class. Displays start
				menu and gets user inputs. Then steps
			 	through the daily zoo routine of feeding, 
				increasing animal ages, updating how much money
				the zoo has remaining, creating random events, 
				and offering user to buy adult animals at the end
				of the day. Then ask if user wants to continue or quit
				as long as the zoo still has money. 
**************************************/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

#include "validInt.hpp"
#include "validStr.hpp"
#include "Animals.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

srand(time(Null));

//starting menu and first three animals are purchased here
void Game::start()	{
	cout << "Welcome to your new zoo!" << endl << endl;
	cout << "First step is to buy 3 new animals" << endl;
	cout << "You currently have 100,000 dollars in your bank account" << endl;
	cout << "Please enter the number for the animal you would like to buy." << endl;
	
	//initial array of animals
	Animals* zooAnimals[] = new Animals[3]; 
	//buys three animals to start the zoo
	for (int i = 0; i < 3; i++)	{ 
		userAnimal = validInt("1. Tiger ($1000) \n2. Penguin ($1000) \n3. Turtle ($100)");
		newAnimal(userAnimal);
	}
}

//runs through the functions in order to simulate one day in the zoo
void Game::turn()	{
	//calls function in order of how they should be called. 
	increaseAges();
	feedintCost();
	subtractFromBankRoll();
	randomEvent();
	calculateProfit();
	addToBankRoll();
	buyAdultAnimal();
	endOfDay();
}

//increases the ages of all the zoo animals
void Game::increaseAges()	{
	for (int i = 0; i < zooAnimals.length() ; i++)	{
		zooAnimals[i] -> incAge();
}

//calculates the total cost to feed all the animals
void Game::feedingCost() 	{
	for (int i = 0; i < zooAnimals.length() ; i++)	{
		dailyFeedCost += zooAnimals[i]->getFoodCost();
}

//subtracts daily feeding cost from money in the bank
void Game::subtractFromBankRoll()	{
	bankRoll -= dailyFeedCost;
}

	//need to finish==============================================================================================================================
//creates a random event that happens at the zoo, one of three possible events
void Game::randomEvent()	{
	
	
}

//calculates profit for all the animals
void Game::calculateProfit()	{
	for (int i = 0; i < zooAnimals.length() ; i++)	{
		profits += zooAnimals[i]->getPayoff();
	}
}

//adds profits anad bonuses to the bank roll
void Game::addToBankRoll()		{
	bankRoll = bankRoll + profits + bonus;
}

//neeed to finish on declaring new adult animal and appending to array=========================================================================================
//creates a new adult animal to the zooAnimal array and updates bank roll
void Game::buyAdultAnimal()	{
	
}

//resets daily variables and prompts user to continue playing or quit if they still have money
void Game::endOfDay()	{
	//reset profit, food cost, and bonuses back to zero
	profits = 0;
	dailyFoodCost = 0;
	bonus - 0;
	
	//check if zoo is bankrupt
	if (bankRoll <= 0)	{
		cout << "Sorry, the zoo is bankrupt." << endl;
		exit(0);
	}
	else {
		continueString = validStr("Please choose one of the following.\n1. Continue\n2. Quit", 1);
		if (continueString == "1")	{
			turn();
		}
		else 	{
			exit(0);
		}
	}
	
}

//fills in initial 3 animal array from start()
void Game::initialAnimals(int choice)	{
	//newAnimalCounter counts which animal is being purchased
	
	if (choice == 1)	{
		//add new tiger to animal array
		zooAnimals[newAnimalCounter] = Tiger(1);	
	}
	else if (choice == 2)	{
		//add new penguin to animal array
		zooAnimals[newAnimalCounter] = Penguin(1);
	}
	else	{
		//add new turtle to animal array
		zooAnimals[newAnimalCounter] = Turtle(1);
	}
	newAnimalCounter++;
}
	
//creates new array to add a newly born animal to the array by copying array to appendArray, adding the new animal
// then making new array equal to old array
void Game:newBorn(int animalType)	{
	//create dynamic array to append by creating array one larger than zoo animals
	Animals* appendArr[] = new Animals[zooAnimals.length() + 1];
	//copy zooAnimal array to new array to append
	for (int i = 0; i < zooAnimals.length(); i++)	{
		appendArr[i] = zooAnimals[i];
	
	//add new animal to appended array
	if (choice == 1)	{
		//add new tiger to append array
		appendArr[appendArr.length()] = Tiger(1);	
	}
	else if (choice == 2)	{
		//add new penguin to append array
		appendArr[appendArr.length()] = Penguin(1);
	}
	else	{
		//add new turtle to append array
		appendArr[appendArr.length()] = Turtle(1);
	}
	
	//delete old zoo array
	delete [] zooAnimals;
		
	//make new zoo array
	Animals* zooAnimals[] = new Animals[appendArr.length()];
	
	//copy appendArr to new zoo array
	for (int i = 0; i < appendArr.length() ; i++)	{
		zooAnimals[i] = appendArr[i];
	
	//delete appended array
	delete [] appendArr;

}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	