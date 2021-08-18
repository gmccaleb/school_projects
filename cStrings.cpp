//****************************************************************************************************
//     File:                cStrings.cpp
//
//     Student:             Gabrielle McCaleb
//
//     Assignment:          Program #6
//
//     Course Name:         Programming II
//
//     Course Number:       COSC 1560 - 02
//
//     Due:                 February 28, 2020
//
//     This program is for c-string practices.
//
//****************************************************************************************************

#include <iostream>
#include <cstring>
using namespace std;

void wordCount(char *, int);

//****************************************************************************************************

int main()
{
	const int SIZE = 20;
	char words[SIZE];
	char *ptr = words;
	int length;

	for (int i = 0; i < 5; i++)
	{
		cout << "Please enter a line of words followed by a period: " << endl;
		cin.getline(words, SIZE);
		length = strlen(words);
		wordCount(ptr, length);
		cout << endl;
	}

	return 0;
}

//****************************************************************************************************

void wordCount(char *ptr, int length)
{
	int count = 1;
	for (int i = 0; i < length; i++)
	{
		if ((!isalpha(ptr[i])) && (isalpha(ptr[i + 1])))
		{
			count++;
		}
	}
	cout << "The word count for your sentence is: " << count << endl;
		count = 0;
}

//****************************************************************************************************

/*
Please enter a line of words followed by a period:
test,test test.
The word count for your sentence is: 3

Please enter a line of words followed by a period:
Webster Groves
The word count for your sentence is: 2

Please enter a line of words followed by a period:
I have good grades.
The word count for your sentence is: 4

Please enter a line of words followed by a period:
This helped me.
The word count for your sentence is: 3

Please enter a line of words followed by a period:
I am age twenty.
The word count for your sentence is: 4
*/
