//****************************************************************************************************
//     File:                binaryTranslation.cpp
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
void takeTest(const Translation trans[], int, Person&);
void testersUpdates(const Translation t[], int, const string&);
void displayTesters(const string&);

//****************************************************************************************************

int main()
{
	string transFile = "Translation.txt",
		testFile = "Testers.dat";
	Translation *words = nullptr;
	int numTrans =5;

	words = readTranslation(transFile, numTrans);
	displayTesters(testFile);
	testersUpdates(words, numTrans, testFile);
	displayTesters(testFile);
	return 0;
}

//****************************************************************************************************

Translation* readTranslation(const string& transFile, int& numTrans)
{
	Translation *ptr1 = nullptr;
	fstream f;

	f.open(transFile, ios::in);
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

void testersUpdates(const Translation t[], int numT, const string& testFile)
{
	fstream f;
	Person p;
	char s;
	int numP,
		day,
		month,
		year,
		tester;
	short seed = time(0);
	srand(seed);

	f.open(testFile, ios::in | ios::out | ios::binary);
	f.read(reinterpret_cast<char*>(&numP), sizeof(int));

	cout << "Today's date: ";
	cin >> day;
	cin >> s;
	cin >> month;
	cin >> s;
	cin >> year;
	cin.get();
	cout << endl;

	for (int i = 0; i < 3; i++)
	{
		tester = rand() % numP;
		f.seekg(sizeof(int) + tester * sizeof(Person), ios::beg);
		f.read(reinterpret_cast<char*>(&p), sizeof(Person));
		takeTest(t, numT, p);
		p.testTaken.day = day;
		p.testTaken.month = month;
		p.testTaken.year = year;
		f.seekp(sizeof(int) + tester * sizeof(Person), ios::beg);
		f.write(reinterpret_cast<char*>(&p), sizeof(Person));
	}
	f.close();
}

//****************************************************************************************************

void displayTesters(const string& testFile)
{
	fstream f;
	int numTesters;
	Person p;

	f.open(testFile, ios::in | ios::binary);
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
}

//****************************************************************************************************


