#include <iostream>
int main()	{
	int height = 5;
	int width = 5;
	int*** board;
	
	//create board
	board = new int**[height];
	for(int i = 0; i < height; i++)
	{
		board[i] = new int*[width];		
		
		for(int j = 0; j < width; j++)
		{
			int* tempPtr = new int;
			delete board[i][j];
			board[i][j] = tempPtr;
			
		}
	}	
	
	for(int i = 0; i < height; i++)	{
		for (int j = 0; j < width; j++)	{
			delete board[i][j];
		}
		delete board[i];
	}
	delete [] board;
	
	char letter;
	for (int i = 65; i < 123; i ++)	{
		letter = i;
		std::cout << letter << std::endl;
	}
	
}