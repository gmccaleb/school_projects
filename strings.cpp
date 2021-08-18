//****************************************************************************************************
//     File:                strings.cpp
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
//     This program is for string function practices.
//
//****************************************************************************************************

#include <iostream>
#include <string>
using namespace std;

void stringInfo(const string&);

//****************************************************************************************************

int main()
{
	string sentence = "This is a 101 SAMPLE to demonstrate string processing",
		sentenceTwo = sentence;

	stringInfo(sentence);
	cout << endl;
	cout << sentenceTwo << endl;

	sentence.erase(43, 10);
	cout << sentence << endl;

	sentence.swap(sentenceTwo);
	cout << sentence << endl;
	cout << sentenceTwo << endl;

	sentence.append(sentenceTwo, 4, 6);
	cout << sentence;

	return 0;
}

//****************************************************************************************************

void stringInfo(const string& sentence)
{
	int count = 0;

	cout << "This sentence contains the following: " << endl;

	cout << "a size of " << sentence.size() << endl;

	for (int i = 0; i < sentence.size(); i++)
	{
		if (isalpha(sentence[i]))
		{
			count++;
		}
	}
	cout << count << " letters" << endl;
	count = 0;

	for (int i = 0; i < sentence.size(); i++)
	{
		if (isdigit(sentence[i]))
		{
			count++;
		}
	}
	cout << count << " digits" << endl;
	count = 0;

	for (int i = 0; i < sentence.size(); i++)
	{
		if (islower(sentence[i]))
		{
			count++;
		}
	}
	cout << count << " lowercase letters" << endl;
	count = 0;

	for (int i = 0; i < sentence.size(); i++)
	{
		if (isupper(sentence[i]))
		{
			count++;
		}
	}
	cout << count << " uppercase letters." << endl << endl;

	cout << "The character at index 14 is: " << sentence.at(14) << endl;
	cout << "The last character is: " << sentence.back() << endl;
	cout << "Index of the first 's': " << sentence.find('s', 0) << endl;
	cout << "Index of the second 's': " << sentence.find('s', sentence.find('s', 0) + 1) << endl;
}

//****************************************************************************************************

/*
This sentence contains the following:
a size of 53
42 letters
3 digits
35 lowercase letters
7 uppercase letters.

The character at index 14 is: S
The last character is: g
Index of the first 's': 3
Index of the second 's': 6

This is a 101 SAMPLE to demonstrate string processing
This is a 101 SAMPLE to demonstrate string
This is a 101 SAMPLE to demonstrate string processing
This is a 101 SAMPLE to demonstrate string
This is a 101 SAMPLE to demonstrate string processing is a
*/