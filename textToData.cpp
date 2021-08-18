//****************************************************************************************************
//     File:                textToData.cpp
//
//     Student:             Gabrielle McCaleb
//
//     Assignment:          Program #10
//
//     Course Name:         Programming II
//
//     Course Number:       COSC 1560 - 02
//
//     Due:                 April 10, 2020
//
//     This program transfers the contents of a text file to a data file.
//
//****************************************************************************************************

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

struct Date
{
	int day,
		month,
		year;
};
struct Person
{
	char name[20];
	double score;
	Date testTaken;
};

Person* readTesters(const string& testFile, int&);

//****************************************************************************************************

int main()
{
	string testFile = "Testers.txt";
	Person *testers1 = nullptr;
	int numTests;
	fstream f;
	Person p;
	int numTesters;

	testers1 = readTesters(testFile, numTests);

	f.open("Testers.dat", ios::out | ios::binary);
	f.write(reinterpret_cast<char*>(&numTests), sizeof(numTests));
	f.write(reinterpret_cast<char*>(testers1), sizeof(Person)*numTests);
	f.close();

	f.open("Testers.dat", ios::in | ios::binary);
	f.read(reinterpret_cast<char*>(&numTesters), sizeof(numTesters));

	cout << "Testers information: " << endl;
	cout << left << setw(25) << "NAME" << setw(10) << "SCORE" << "DATE TAKEN" << endl;

	f.seekg(sizeof(int), ios::beg);
	for (int i = 0; i < numTesters; i++)
	{
		f.read(reinterpret_cast<char*>(&p), sizeof(Person));
		cout << left << setw(25) << p.name << setw(10) << p.score;
		cout << p.testTaken.day << "/" << p.testTaken.month << "/";
		cout << p.testTaken.year << endl << endl;
	}
	f.close();


	return 0;
}

//****************************************************************************************************

Person* readTesters(const string& testFile, int& numTests)
{
	Person *ptr = nullptr;
	fstream f;

	f.open(testFile, ios::in);
	f >> numTests;
	f.get();
	ptr = new Person[numTests];

	for (int i = 0; i < numTests; i++)
	{
		f.getline(ptr[i].name, 20);
		f >> ptr[i].score;
		f.get();
		f >> ptr[i].testTaken.day;
		f.get();
		f >> ptr[i].testTaken.month;
		f.get();
		f >> ptr[i].testTaken.year;
		f.get();
	}

	f.close();
	return ptr;
}

