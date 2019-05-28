
#include "Menu.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main()	{
	Menu menu;
	menu.initialMenu();
	int rows;
	int columns;
	int* boardSize = menu.getSizeBoard();
	
	cout << "board size: " << boardSize[0] << " x " << boardSize[1] << endl;
	cout << "Row: " << menu.getRows() << "\t" << "Col: " << menu.getColumns() << endl;
	cout << "Time steps: "  << menu.getTimeSteps() << endl;
	cout << "Area: " << menu.getRows() * menu.getColumns() << endl;
	cout << "Ant: " << menu.getNumberAnts()	<< endl;
	cout << "Doodlebugs: " << menu.getNumberDoodlebugs() << endl;
}
	