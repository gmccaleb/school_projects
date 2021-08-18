//****************************************************************************************************
//     File:                studentNames.cpp
//
//     Student:             Gabrielle McCaleb
//
//     Assignment:          Program #2
//
//     Course Name:         Programming II
//
//     Course Number:       COSC 1560 - 02
//
//     Due:                 January 31, 2020
//
//     This program displays the data on students' names.
//
//****************************************************************************************************

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void readNames(ifstream& inputFile, string names[], int);
void displayNames(const string names[], int);
int searchNames(const string names[], int, const string&);
void bubbleSort(string names[], int);
void bubbleSortDescending(string names[], int);
int binarySearchNames(const string names[], int, const string&);
void selectionSort(string names[], int);
void selectionSortDescending(string names[], int);

//****************************************************************************************************

int main()
{
	const int NUM_NAMES = 10;
	string names[NUM_NAMES];
	string fullName;
	int position;
	ifstream sNames("StudentNames.txt");

	readNames(sNames, names, NUM_NAMES);

	displayNames(names, NUM_NAMES);

	cout << "What name do you want to search for? (Last, First): ";
	getline(cin, fullName);

	position = searchNames(names, NUM_NAMES, fullName);
	if (position == -1)
	{
		cout << fullName << " was not found " << endl << endl;
	}
	else
	{
		cout << fullName << " is located in element " << position + 1 << endl << endl;
	}

	bubbleSort(names, NUM_NAMES);
	displayNames(names, NUM_NAMES);

	bubbleSortDescending(names, NUM_NAMES);
	displayNames(names, NUM_NAMES);

	cout << "What name do you want to search for? (Last, First): ";
	getline(cin, fullName);

	bubbleSort(names, NUM_NAMES);
	position = binarySearchNames(names, NUM_NAMES, fullName);
	if (position == -1)
	{
		cout << fullName << " was not found " << endl << endl;
	}
	else
	{
		cout << fullName << " is located in element " << position + 1 << endl << endl;
	}

	selectionSort(names, NUM_NAMES);
	displayNames(names, NUM_NAMES);

	selectionSortDescending(names, NUM_NAMES);
	displayNames(names, NUM_NAMES);

	return 0;
}

//****************************************************************************************************

void readNames(ifstream& sNames, string names[], int num_names)
{
	string str;
	for (int i = 0; i < num_names; i++)
	{
		getline(sNames, names[i]);
	}
}

//****************************************************************************************************

void displayNames(const string names[], int num_names)
{
	for (int i = 0; i < num_names; i++)
	{
		cout << names[i] << endl;
	}
	cout << endl;
}

//****************************************************************************************************

int searchNames(const string names[], int num_names, const string& name)
{
	int index = 0,
		position = -1;
	bool found = false;

	while ((index < num_names) && !found)
	{
		if (names[index] == name)
		{
			found = true;
			position = index;
		}
		index++;
	}

	return position;
}

//****************************************************************************************************

void bubbleSort(string names[], int numNames)
{
	bool swap;
	int total = numNames;
	string temp;

	do
	{
		swap = false;
		for (int count = 0; count < (total - 1); count++)
		{
			if (names[count] > names[count + 1])
			{
				swap = true;
				temp = names[count];
				names[count] = names[count + 1];
				names[count + 1] = temp;
			}

		}
		total--;
	} while (swap);
}

//****************************************************************************************************

void bubbleSortDescending(string names[], int numNames)
{
	bool swap;
	int total = numNames;
	string temp;

	do
	{
		swap = false;
		for (int count = 0; count < (total - 1); count++)
		{
			if (names[count] < names[count + 1])
			{
				swap = true;
				temp = names[count];
				names[count] = names[count + 1];
				names[count + 1] = temp;
			}

		}
		total--;
	} while (swap);
}

//****************************************************************************************************

int binarySearchNames(const string names[], int num_names, const string& name)
{
	int first = 0,
		last = num_names - 1,
		middle,
		position = -1;
	bool found = false;

	while ((first <= last) && !found)
	{
		middle = (first + last) / 2;
		if (names[middle] == name)
		{
			found = true;
			position = middle;
		}
		else
		{
			if (names[middle] > name)
			{
				last = middle - 1;
			}
			else
			{
				first = middle + 1;
			}
		}
	}
	return position;
}

//****************************************************************************************************

void selectionSort(string names[], int num_names)
{
	int minIndex;
	string minValue;

	for (int scan = 0; scan < (num_names - 1); scan++)
	{
		minIndex = scan;
		minValue = names[minIndex];
		for (int index = scan + 1; index < num_names; index++)
		{
			if (names[index] < minValue)
			{
				minValue = names[index];
				minIndex = index;
			}
		}
		names[minIndex] = names[scan];
		names[scan] = minValue;
	}
}
//****************************************************************************************************

void selectionSortDescending(string names[], int num_names)
{
	int minIndex;
	string minValue;

	for (int scan = 0; scan < (num_names - 1); scan++)
	{
		minIndex = scan;
		minValue = names[minIndex];
		for (int index = scan + 1; index < num_names; index++)
		{
			if (names[index] > minValue)
			{
				minValue = names[index];
				minIndex = index;
			}
		}
		names[minIndex] = names[scan];
		names[scan] = minValue;
	}
}



/*
Smith, John
Song, Mona
Jones, Trevor
Li, Na
Zhang, Xiu Ying
Saleem, Mohammad
Lloyd, Arthur
Jones, Rhys
Evans, Olivia
Davies, Emily

What name do you want to search for? (Last, First): McCaleb, Gabrielle
McCaleb, Gabrielle was not found

Davies, Emily
Evans, Olivia
Jones, Rhys
Jones, Trevor
Li, Na
Lloyd, Arthur
Saleem, Mohammad
Smith, John
Song, Mona
Zhang, Xiu Ying

Zhang, Xiu Ying
Song, Mona
Smith, John
Saleem, Mohammad
Lloyd, Arthur
Li, Na
Jones, Trevor
Jones, Rhys
Evans, Olivia
Davies, Emily

What name do you want to search for? (Last, First): Evans, Olivia
Evans, Olivia is located in element 2

Davies, Emily
Evans, Olivia
Jones, Rhys
Jones, Trevor
Li, Na
Lloyd, Arthur
Saleem, Mohammad
Smith, John
Song, Mona
Zhang, Xiu Ying

Zhang, Xiu Ying
Song, Mona
Smith, John
Saleem, Mohammad
Lloyd, Arthur
Li, Na
Jones, Trevor
Jones, Rhys
Evans, Olivia
Davies, Emily
*/