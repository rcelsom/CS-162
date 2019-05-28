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
**************************************/
//uploaded to flip, use valgrind to find memory errors, currently just dumping when num animals gets large or random times, probably something in random event functions===========================

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

#include "validInt.hpp"
#include "validStr.hpp"
#include "Zoo.hpp"
#include "Animal.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

//extra credit create new animal class where user can create an animal
//status message to txt file then read that text file to display that days text
//options for different feed types to select at start of each day, cheap doubles chances of sickness, medium is normal, expensive half chance of sickness


//starting menu and first three animals are purchased here
void Zoo::start()	{
	//sets time so there are truly random events, has nothing to do with start menu but rather randomEvents()
	srand(time(NULL));
	//create arrays for each animal size 10
	tigerArr = new Tiger*[10];
	penguinArr = new Penguin*[10];
	turtleArr = new Turtle*[10];
	
	
	cout << "Welcome to your new zoo!" << endl << endl;
	cout << "First step is to buy 3 new animals" << endl;
	cout << "You currently have 100,000 dollars in your bank account" << endl;
	cout << "Please enter the number for the animal you would like to buy." << endl;
	
	//buys three animals to start the zoo
	for (int i = 0; i < 3; i++)	{ 
		userAnimal = validInt("1. Tiger ($10,000) \n2. Penguin ($1,000) \n3. Turtle ($100)\n");
		initialAnimals(userAnimal);
	}
	turn();
}

//fills in initial 3 animal array from start()
//all initialized to zero since increase age at the start of Turn function 
//will make them all one day old on the first day of the zoo.
void Zoo::initialAnimals(int typeOfAnimal)	{
	
	if (typeOfAnimal == 1)	{
		//add new tiger to animal array
		delete tigerArr[numberOfTigers];
		tigerArr[numberOfTigers] = new Tiger();	
		numberOfTigers++;
		cout << "Congratulations! You just bought a Tiger!" << endl << endl;
	}
	
	else if (typeOfAnimal == 2)	{
		//add new penguin to animal array
		delete penguinArr[numberOfPenguins];
		penguinArr[numberOfPenguins] = new Penguin();
		numberOfPenguins++;
		cout << "Congratulations! You just bought a Penguin!" << endl << endl;
	}
	
	else	{
		//add new turtle to animal array
		delete turtleArr[numberOfTurtles];
		turtleArr[numberOfTurtles] = new Turtle();
		numberOfTurtles++;
		cout << "Congratulations! You just bought a Turtle!" << endl << endl;
	}
	
	numberOfAnimals++;
	if (numberOfAnimals < 3)	{
		cout << "Please pick your next animal. "<< endl;
	}
}



//runs through the functions in order to simulate one day in the zoo
void Zoo::turn()	{
	//reset bonus after the day ends
	bonus = 0;
	//calls function in order of how they should be called. 
	increaseAges();
	feedingCost();
	subtractFromBankRoll();
	randomEvent();
	calculateProfit();
	addToBankRoll();
	dailyStats();
	buyAdultAnimal();
	endOfDay();
}
//increases the ages of all the zoo animals
void Zoo::increaseAges()	{

	//increase age of tigers
	for (int i = 0; i < numberOfTigers; i++)	{
		tigerArr[i]->incAge();
	}
	//increase age of penguins
	for (int i = 0; i < numberOfPenguins; i++)	{
		penguinArr[i]->incAge();
	}
	//increase age of turtles
	for (int i = 0; i < numberOfTurtles; i++)	{
		turtleArr[i]->incAge();
	}
	
}

//calculates the total cost to feed all the animals
void Zoo::feedingCost() 	{
	dailyFeedCost = 0;
	//calculate feed for tigers
	for (int i = 0; i < numberOfTigers; i++)	{
		dailyFeedCost += tigerArr[i]->getFoodCost();
	}
	//calculate feed for penguins
	for (int i = 0; i < numberOfPenguins; i++)	{
		dailyFeedCost += penguinArr[i]->getFoodCost();
	}
	//calculate feed for turtles
	for (int i = 0; i < numberOfTurtles; i++)	{
		dailyFeedCost += turtleArr[i]->getFoodCost();
	}
}

//subtracts daily feeding cost from money in the bank
void Zoo::subtractFromBankRoll()	{
	bankRoll -= dailyFeedCost;
}

//creates a random event that happens at the zoo, one of four possible events
void Zoo::randomEvent()	{
	//set animalsAreBabies are true for each check, in case all the adults die somehow
	animalsAreBabies = true;
	numberOfAdults = 0;
	numberAdultTigers = 0;
	numberAdultPenguins = 0;
	numberAdultTurtles = 0;

	//check if any tigers are adults
	for ( int i = 0; i < numberOfTigers; i++)	{
		if (tigerArr[i]->getAge() >= 3)	{
			animalsAreBabies = false;
			numberAdultTigers++;
			numberOfAdults++;
		}
	}
	//check if any penguins are adults
	for ( int i = 0; i < numberOfPenguins; i++)	{
		if (penguinArr[i]->getAge() >= 3)	{
			animalsAreBabies = false;
			numberAdultPenguins++;
			numberOfAdults++;
		}
	}
	//check if any turtles are adults
	for ( int i = 0; i < numberOfTurtles; i++)	{
		if (turtleArr[i]->getAge() >= 3)	{
			animalsAreBabies = false;
			numberAdultTurtles++;
			numberOfAdults++;
		}
	}

	//if all animals are babies, only 2 random event options
	if (animalsAreBabies)	{
		randomChoice = rand() % 3;
	}
	else {
		randomChoice = rand() % 4;
	}
	
	//a zoo animal gets sick and dies
	if (randomChoice == 0)	{
		sickAnimal();
	}
	//a bonus in profits from 250 to 500 for every tiger
	else if (randomChoice == 1)	{
		bonusCalculator();
	}
	//no random event this day
	else if(randomChoice == 2)	{
	
	}	
	//a random adult animal has a baby
	else 	{
		bornAnimal();
	}

}
	
	

//calculates profit for all the animals
void Zoo::calculateProfit()	{
	profits = 0;
	
	//calculate feed for tigers
	for (int i = 0; i < numberOfTigers; i++)	{
		profits += tigerArr[i]->getPayoff();
	}
	//calculate feed for penguins
	for (int i = 0; i < numberOfPenguins; i++)	{
		profits += penguinArr[i]->getPayoff();
	}
	//calculate feed for turtles
	for (int i = 0; i < numberOfTurtles; i++)	{
		profits += turtleArr[i]->getPayoff();
	}
}

//adds profits anad bonuses to the bank roll
void Zoo::addToBankRoll()		{
	bankRoll = bankRoll + profits + bonus;
}

//displays results of cost and profits for the day======================================================need to put into txt file and read from file==================================
void Zoo::dailyStats()	{
	cout << "Today's Food Cost were: " << dailyFeedCost << endl;
	cout << "Today's Total Profit was: " << profits + bonus << endl;
	cout << "Current Animal Count" << endl << "Tiger: "<<numberOfTigers;
	cout << "\tPenguin: "<<numberOfPenguins << "\tTurtle: " << numberOfTurtles << endl;
	cout << "The zoo has $"<<bankRoll << " in the bank." << endl << endl;	
}


//creates a new adult animal to add to that animals array and updates bank roll
void Zoo::buyAdultAnimal()	{
	buyAnimalOption = validStr("Would you like to buy an adult animal to add to your zoo (y/n)?" ,2);
	if (buyAnimalOption == "y" || buyAnimalOption == "Y")	{
		buyAnimal = validInt("1. Tiger ($10,000) \n2. Penguin ($1,000) \n3. Turtle ($100)\n");
		numberOfAnimals++;
		
		if (buyAnimal == 1)	{
			//check if need to increase size of array
			if (numberOfTigers >= defaultTigerSize - 1)	{
				doubleTigerSize();
			}
			//add new animal
			delete tigerArr[numberOfTigers];
			tigerArr[numberOfTigers] = new Tiger(3);
			numberOfTigers++;
			//update bankroll
			bankRoll -= tigerArr[0]->getCost();
		}
		
		else if (buyAnimal == 2)	{
			//check if need to increase size of array
			if (numberOfPenguins >= defaultPenguinSize - 1)	{
				doublePenguinSize();
			}
			//add new animal
			delete penguinArr[numberOfPenguins];
			penguinArr[numberOfPenguins] = new Penguin(3);
			numberOfPenguins++;
			bankRoll -= penguinArr[0]->getCost();
		}
		
		else	{
			//check if need to increase size of array
			if (numberOfTurtles >= defaultTurtleSize - 1 )	{
				doubleTurtleSize();
			}
			//add new animal
			delete turtleArr[numberOfTurtles];
			turtleArr[numberOfTurtles] = new Turtle(3);
			numberOfTurtles++;
			bankRoll -= turtleArr[0]->getCost();
		}
	}
}

//resets daily variables, displays daily results, and prompts user to continue playing or quit if they still have money
void Zoo::endOfDay()	{
	
	//check if zoo is bankrupt
	if (bankRoll <= 0)	{
		
		//display bankrupcy
		cout << "Sorry, the zoo is bankrupt." << endl;
		return;
	}
	else {
		continueString = validStr("Please choose one of the following.\n1. Continue\n2. Quit", 1);
		if (continueString == "1")	{
			turn();
		}
		else 	{
			
			
			return;
		}
	}
}


//adds new born animal to that animals array
void Zoo::bornAnimal()	{
	//pick which animals can have baby then pick randomly
	adultAnimal = rand() % numberOfAdults;

	if (adultAnimal <= numberAdultTigers && numberAdultTigers != 0)	{
		//make sure array is large enough
		if (numberOfTigers >= defaultTigerSize)	{
			doubleTigerSize();
		}
		delete tigerArr[numberOfTigers];
		tigerArr[numberOfTigers] = new Tiger();
		numberOfTigers++;
		numberOfAnimals++;
	}
	
	//checks if it is greater than number of tigers and there is atleast one adult penguin
	if (adultAnimal <= numberAdultPenguins && adultAnimal > numberOfTigers && numberAdultPenguins !=0)	{
		//make sure array is large enough for number of babies
		if (numberOfPenguins >= defaultPenguinSize - 5)	{
			doublePenguinSize();
		}
		
		for (int i = 0; i < penguinArr[0]->hasBabies(); i++)	{
			delete penguinArr[numberOfPenguins];
			penguinArr[numberOfPenguins] = new Penguin();
			numberOfPenguins++;
			numberOfAnimals++;
		}
	}
	
	//checks if it is greater than number of tigers and penguins and there is atleast one adult turtle
	if (adultAnimal <= numberAdultTurtles && adultAnimal > numberOfPenguins && numberAdultTurtles !=0)	{
		//make sure array is large enough for number of babies
		if (numberOfTurtles >= defaultTurtleSize - 10)	{
			doubleTurtleSize();
		}
		
		for (int i = 0; i < turtleArr[0]->hasBabies(); i++)	{
			delete turtleArr[numberOfTurtles];
			turtleArr[numberOfTurtles] = new Turtle();
			numberOfTurtles++;
			numberOfAnimals++;
		}
	}
}	

//picks a random animal that gets sick and dies, then removes the animal from the zooAnimal array
void Zoo::sickAnimal()	{
	hasAnimalType = false;
	sickAnimalType = rand() % 3;
	
	//make sure there is an animal of that type before trying to delete it
	while (!hasAnimalType)	{	
		if (sickAnimalType == 0 && numberOfTigers == 0)	{
			sickAnimalType = rand() % 3;
		}
		else if (sickAnimalType == 1 && numberOfPenguins == 0)	{
			sickAnimalType = rand() % 3;
		}
		else if (sickAnimalType == 2 && numberOfTurtles == 0)	{
			sickAnimalType = rand() % 3;
		}
		else	{
			hasAnimalType = true;
		}
	}

	//delete a tiger
	if (sickAnimalType == 0)	{
		isASickAnimal = rand() % numberOfTigers;
		cout << "Sorry, your " << tigerArr[isASickAnimal]->getAge() <<" day old ";
		cout << tigerArr[isASickAnimal]->getType() <<" got sick and died." << endl;
		
		delete tigerArr[isASickAnimal];
		//shift all elements after sick animal down
		for (int i = isASickAnimal; i < numberOfTigers; i++)	{
			tigerArr[i] = tigerArr[i+1];
		}
		numberOfTigers--;
	}
	
	//delete a penguin
	else if (sickAnimalType == 1)	{
		isASickAnimal = rand() % numberOfPenguins;
		cout << "Sorry, your " << penguinArr[isASickAnimal]->getAge() <<" day old ";
		cout << penguinArr[isASickAnimal]->getType() <<" got sick and died." << endl;
		
		delete penguinArr[isASickAnimal];
		//shift all elements after sick animal down
		for (int i = isASickAnimal; i < numberOfPenguins; i++)	{
			penguinArr[i] = penguinArr[i+1];
		}
		numberOfPenguins--;
	}
	
	//delete a turtle
	else	{
		isASickAnimal = rand() % numberOfTurtles;
		cout << "Sorry, your " << turtleArr[isASickAnimal]->getAge() <<" day old ";
		cout << turtleArr[isASickAnimal]->getType() <<" got sick and died." << endl;
		
		delete turtleArr[isASickAnimal];
		//shift all elements after sick animal down
		for (int i = isASickAnimal; i < numberOfTurtles; i++)	{
			turtleArr[i] = turtleArr[i+1];
		}
		numberOfTurtles--;
	}
	
	numberOfAnimals--;
}

//calculates random bonus between 250 and 500 for each tiger the zoo has
void Zoo::bonusCalculator()	{
	bonus = 0;
	for (int i = 0; i < numberOfTigers; i++)	{
		bonus += (rand() % 250 + 250);		
	}
	if (numberOfTigers != 0)	{
		//need to add to file to read and write from============================================================================================================================
		cout << "Congratulations! The tigers have brought in more visitors! You recieved $";
		cout << bonus << " in bonuses today!" << endl;
		profits += bonus;
	}
	else	{
		cout << "Everyone wanted to see tigers, but since you do not have any, you do not get a bonus" << endl;
	}
}
	
//double size of tiger array
void Zoo::doubleTigerSize()	{
	
	defaultTigerSize *= 2;
	Tiger** newTigerArr = new Tiger*[defaultTigerSize];

	for (int i = 0; i < numberOfTigers; i++)	{
		newTigerArr[i] = tigerArr[i];
	}

	delete [] tigerArr;
	
	tigerArr = newTigerArr;
}

//double size of penguin array
void Zoo::doublePenguinSize()	{
	
	defaultPenguinSize *= 2;
	Penguin** newPenguinArr = new Penguin*[defaultPenguinSize];

	for (int i = 0; i < numberOfPenguins; i++)	{
		newPenguinArr[i] = penguinArr[i];
	}


	delete [] penguinArr;
	
	penguinArr = newPenguinArr;
}

//double size of turtle array
void Zoo::doubleTurtleSize() {
	defaultTurtleSize = defaultTurtleSize * 2;
	Turtle** newTurtleArr = new Turtle*[defaultTurtleSize];

	for (int i = 0; i < numberOfTurtles; i++)	{
		newTurtleArr[i] = turtleArr[i];
	}
	
	delete [] turtleArr;
	
	turtleArr = newTurtleArr;

}

Zoo::~Zoo()	{
	for (int i = 0; i < defaultPenguinSize; i++)	{
		delete penguinArr[i];
	}
	delete [] penguinArr;
	
	for (int i = 0; i < defaultTigerSize; i++)	{
		delete tigerArr[i];
	}
	delete [] tigerArr;
	
	for (int i = 0; i < defaultTurtleSize; i++)	{
		delete turtleArr[i];
	}
	delete [] turtleArr;
	
}
		
	
	
	
	
	
	
	
	
	
	
	
	