//****************************************************************************************************
//     File:                translation.cpp
//
//     Student:             Gabrielle McCaleb
//
//     Assignment:          Program #9
//
//     Course Name:         Programming II
//
//     Course Number:       COSC 1560 - 02
//
//     Due:                 April 3, 2020
//
//     This program stores employee informaition.
//
//****************************************************************************************************

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;

struct Translation
{
	string american;
	string english;
};
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

Translation* readTranslation(const string&, int&);
Person* readTesters(const string&, int&);
void testingOptions(const Translation trans[], Person testers[], int, int);
void takeTest(const Translation trans[], int, Person&);
void displayTesters(const Person testers[], int);
void writeTesters(const string&, Person testers[], int);

//****************************************************************************************************

int main()
{
	string transFile = "Translation",
		testFile = "Testers";
	int numTrans,
		numTests;
	Translation *trans = nullptr;
	Person *testers = nullptr;

	trans = readTranslation(transFile, numTrans);
	testers = readTesters(testFile, numTests);
	testingOptions(trans, testers, numTrans, numTests);

	displayTesters(testers, numTests);


	writeTesters(testFile, testers, numTests);
	return 0;
}

//****************************************************************************************************

Translation* readTranslation(const string& transFile, int& numTrans)
{
	Translation *ptr1 = nullptr;
	fstream f;
	string file = transFile;

	f.open("Translation.txt", ios::in);
	f >> numTrans;
	f.get();
	ptr1 = new Translation[numTrans];

	for (int i = 0; i < numTrans; i++)
	{
		getline(f, ptr1[i].american, ',');
		getline(f, ptr1[i].english);
	}

	f.close();

	return ptr1;
}

//****************************************************************************************************

Person* readTesters(const string& testFile, int& numTests)
{
	Person *ptr = nullptr;
	fstream f;
	string file = testFile;

	f.open("Testers.txt", ios::in);
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

//****************************************************************************************************

void testingOptions(const Translation trans[], Person testers[], int numTrans, int numTests)
{
	int day,
		month,
		year,
		student;
	char s;
	short seed = time(0);
	srand(seed);

	cout << "Today's Date: ";
	cin >> day;
	cin >> s;
	cin >> month;
	cin >> s;
	cin >> year;
	cout << endl;
	cin.get();

	for (int i = 0; i < 3; i++)
	{
		student = rand() % numTests;
		Person p = testers[student];
		cout << "Name: " << testers[student].name << endl;
		takeTest(trans, numTrans, testers[student]);
		testers[student].testTaken.day = day;
		testers[student].testTaken.month = month;
		testers[student].testTaken.year = year;
	}

}

//****************************************************************************************************

void takeTest(const Translation trans[], int numTests, Person &p)
{
	int word,
		correct = 0,
		total = 10;
	double avg = 0;
	string eng;
	cout << "Enter the 'English' version of each 'American' word: " << endl << endl;
	cout << left << setw(24) << "AMERICAN" << "English" << endl;

	short seed = time(0);
	srand(seed);

	for (int i = 0; i < total; i++)
	{
		/*	cout << i + 1 << left << setw(3) << ". "; */
		word = rand() % numTests;
		cout << left << setw(24) << trans[word].american;
		getline(cin, eng);
		if (eng == trans[word].english)
		{
			correct++;
		}
	}
	cout << endl;
	avg = correct / static_cast<double>(total) * 100;
	p.score = avg;
}

//****************************************************************************************************

void displayTesters(const Person testers[], int numTests)
{
	cout << "Test Data: " << endl;
	cout << left << setw(25) << "NAME" << setw(10) << "SCORE" << "DATE TAKEN" << endl;
	for (int i = 0; i < numTests; i++)
	{
		cout << left << setw(25) << testers[i].name << setw(10) << testers[i].score;
		cout << testers[i].testTaken.day << "/" << testers[i].testTaken.month << "/";
		cout << testers[i].testTaken.year << endl << endl;
	}
}

//****************************************************************************************************

void writeTesters(const string& testFile, Person testers[], int numTests)
{
	fstream file;
	file.open("Testers.txt", ios::out);

	file << numTests << endl;
	for (int i = 0; i < numTests; i++)
	{
		file << testers[i].name << endl;
		file << testers[i].score << ",";
		file << testers[i].testTaken.day << "/" << testers[i].testTaken.month << "/";
		file << testers[i].testTaken.year << endl;
	}

	file.close();
}

//****************************************************************************************************

/*
Today's Date: 4/4/2020

Name: Mark James
Enter the 'English' version of each 'American' word:

AMERICAN                English
pants                   trousers
candy                   sweet
pants                   trousers
candy                   sweet
elevator                lift
mailbox                 postbox
trunk                   boot
mailbox                 postbox
candy                   sweet
vacation                holiday

Name: Li Ying
Enter the 'English' version of each 'American' word:

AMERICAN                English
apartment               flat
hood                    bonnet
sidewalk                pavement
vacation                trip
cookie                  buscuit
mailbox                 postbox
restroom                washroom
elevator                lift
candy                   sweet
cookie                  buscuit

Name: Frank Pearse
Enter the 'English' version of each 'American' word:

AMERICAN                English
last name               surname
sweater                 pullover
candy                   treat
restroom                washroom
vacation                holiday
sweater                 pullover
chips                   crisps
sweater                 pullover
sweater                 pullover
elevator                lift

Test Data:
NAME                     SCORE     DATE TAKEN
Steve Smith              90        4/4/2020

Sue Jones                80.8      1/11/2003

Li Ying                  60        4/4/2020

Kun Joom                 10        11/11/2012

Joe Bush                 100       4/4/2020

Kim Long                 65.3      2/12/2018

Fred Ring                33.3      19/5/2019

Frank Pearse             40        4/4/2020

Helen Hu                 88.8      25/8/2018

Mark James               100       4/4/2020

*/