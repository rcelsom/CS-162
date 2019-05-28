/* Main for Testing Purposes richertf*/

#include <iostream>
#include <string>
using std::string;
using std::endl;
using std::cout;
using std::cin;

#include <cstdlib>
using std::rand;
//add time and srand later


#include "Ant.hpp"
#include "Doodlebug.hpp"
#include "Critter.hpp"
#include "Game.hpp"
#include "Menu.hpp"

int main()
{
	srand(time(0));
	cout << "test" << endl;
	
	//makes board off of menu inputs
	
	 Menu menu;
    menu.initialMenu();
    
    Game g2(menu.getRows(), menu.getColumns(), menu.getNumberAnts(), menu.getNumberDoodlebugs());
    for (int i = 0; i < menu.getTimeSteps(); i++)    {
        g2.moveCritters();
        g2.printBoard();
    }
	Game g1; // default board is 20x20, ants = 5, dbugs = 100
	

    /*
    // James Testing
    Game testGame(10, 10, 0, 0);                // creates empty board; easy to see
    //testGame.createDoodlebug(1,1);
    //testGame.createAnt(0,0);
    testGame.printBoard();
    //testGame.removeCritter(0, 0);                   // remove critter test
    testGame.printBoard();
    cout << testGame.getBoard()[0][0]->getAge() << endl;        // confirms critter removed
    cout << testGame.getBoard()[1][1]->getAge() << endl;        // confirms living critter aged from move()
    cout << testGame.getBoard()[1][1]->getLastMeal() << endl;   // confirms living critter's eating time increased
    
    for (int i = 0; i < 10; i++)                        // starve the doodlebug
    {
        testGame.moveCritters();
    }
    testGame.printBoard();                                  // confirm doodlebug death via print+ get functions
    cout << testGame.getBoard()[1][1]->getAge() << endl;
    cout << testGame.getBoard()[1][1]->getLastMeal() << endl;

	return 0;
	*/
}
