//****************************************************************************************************
//     File:                ticTacToe.cpp
//
//     Student:             Gabrielle McCaleb
//
//     Assignment:          Program #13
//
//     Course Name:         Programming I
//
//     Course Number:       COSC 1550 - 03
//
//     Due:                 December 13, 2019
//
//     This program allows the user to play tic tac toe against the computer.
//
//****************************************************************************************************

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

const int COLS = 3;

void displaySpaces(char[][COLS], int, int);
int getChoice(char[][COLS], char[][COLS], int, int, int);
void displayChoices(char[][COLS], int, int);
bool checkWinner(char[][COLS], int, int, int, int);

//****************************************************************************************************

int main()
{
	const int PLAYER = 1,
		CPU = 2,
	    ROWS = 3;
	bool winner;
	char spaces[ROWS][COLS] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
	char choices[ROWS][COLS] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	int cpu,
		player,
		times;
	short seed;

	times = 0;
	seed = time(0);
	srand(seed);

	do
	{
		displaySpaces(spaces, ROWS, COLS);
		player = getChoice(choices, spaces, ROWS, COLS, PLAYER);
		times++;
		winner = checkWinner(choices, ROWS, COLS, player, times);

		if (!winner)
		{
			cpu = getChoice(choices, spaces, ROWS, COLS, CPU);
			times++;
			winner = checkWinner(choices, ROWS, COLS, cpu, times);
		}

		displayChoices(choices, ROWS, COLS);
	} 
	while (!winner && times < 9);

	

	return 0;

}

//****************************************************************************************************

void displaySpaces(char spaces[][COLS], int rows, int cols)
{
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < cols; c++)
			cout << spaces[r][c] << " ";
		cout << endl;
	}
}

//****************************************************************************************************

int getChoice(char choices[][COLS], char spaces[][COLS], int rows, int cols, int x)
{
	int player,
		row,
		col;

	do
	{ 
		if (x == 1)
		{
			cout << "Choose a space ";
			cin >> player;
		}

		else
		{
			do
			{
				player = rand() % 9 + 1;
			} 
			while (choices[rows][cols] == 'x');
		}

		row = (player - 1) / rows;
		col = (player - 1) % cols;	
	} 
	while(spaces[row][col] == ' ');

	if (x == 1)
		choices[row][col] = 'x';
	else
		choices[row][col] = 'o';
	spaces[row][col] = ' ';

	return player;
}

//****************************************************************************************************

void displayChoices(char choices[][COLS], int rows, int cols)
{
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < cols; c++)
			cout << choices[r][c] << " ";
		cout << endl;
	}
	cout << endl;
}

//****************************************************************************************************

bool checkWinner(char choices[][COLS], int rows, int cols, int player, int times)
{
	bool winner = false;
	int row, col;
	
	row = (player - 1) / rows;
	col = (player - 1) % cols;

	if((choices[row][0] == choices[row][1] && choices[row][0] == choices[row][2] && choices[row][0] != ' ')
		||
		(choices[0][col] == choices[1][col] && choices[0][col] == choices[2][col] && choices[0][col] != ' ')
		||
		(choices[0][0] == choices[1][1] && choices[0][0] == choices[2][2] && choices[0][0] != ' ')
		||
		(choices[2][0] == choices[1][1] && choices[2][0] == choices[0][2] && choices[2][0] != ' '))
		winner = true;

	if (winner)
	{
		if ((choices[row][0] == choices[row][1] && choices[row][0] == choices[row][2] && choices[row][0] == 'x')
			||
			(choices[0][col] == choices[1][col] && choices[0][col] == choices[2][col] && choices[0][col] == 'x')
			||
			(choices[0][0] == choices[1][1] && choices[0][0] == choices[2][2] && choices[0][0] == 'x')
			||
			(choices[2][0] == choices[1][1] && choices[2][0] == choices[0][2] && choices[2][0] == 'x'))
			cout << "You win!" << endl;
		else
			cout << "You lost :(" << endl;
	}
	else if (!winner && times == 9)
		cout << "TIE!";

	return winner;
}

//****************************************************************************************************

/*
1 2 3
4 5 6
7 8 9
Choose a space 5

  x o


1 2 3
4
7 8 9
Choose a space 1
x o
  x o


	3
4
7 8 9
Choose a space 7
x o o
  x o
x


4
  8 9
Choose a space 8
x o o
o x o
x x



	9
Choose a space 9
You win!
x o o
o x o
x x x
*/