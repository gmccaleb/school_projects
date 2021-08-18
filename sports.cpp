//****************************************************************************************************
//     File:                sports.cpp
//
//     Student:             Gabrielle McCaleb
//
//     Assignment:          Program #12
//
//     Course Name:         Programming II
//
//     Course Number:       COSC 1560 - 02
//
//     Due:                 April 24, 2020
//
//     This program stores and displays the inforation about the sports organization.
//
//****************************************************************************************************

#include <string>
#include "Sport.h"
#include <iostream>
#include <iomanip>

using namespace std;

Sport::Sport()
{
	teamNames = nullptr;
}

Sport::Sport(const string&n = "")
{
	setName(n);
	teamNames = nullptr;
}
void Sport::setNextGame(Date d)
{
	if (d.month == 2 && ((d.day >= 1) && (d.day <= 29))) //checks for February
		nextGame.day = d.day;
	else if ((d.day >= 1) && (d.day <= 31))
		nextGame.day = d.day;
	else
		nextGame.day = 1;

	if ((d.month >= 1) && (d.month <= 12))
		nextGame.month = d.month;
	else
		nextGame.month = 1;
	if (d.year >= 2000 && d.year <= 2020)
		nextGame.year = d.year;
	else
		nextGame.year = 2000;
}
void Sport::setTeams(int t)
{
	if (t < 0)
		teams = 5;
	else
		teams = t;
}
string* Sport::getTeamNames()
{
	return teamNames;
}
void Sport::setTeamNames(int teams)
{
	teamNames = new string[teams];
	for (int i = 0; i < teams; i++)
	{
		cout << "Team " << i + 1 << ": ";
		getline(cin, teamNames[i]);
	}
}
char Sport::findLowest()
{
	char lowest = name[0];

	for (int i = 1; i < name.size(); i++)
	{
		if (name[i] < lowest)
			lowest = name[i];
	}

	return lowest;
}
void Sport::populate()
{
	string n;
	Date ng;
	int t;

	cout << "Sport: ";
	getline(cin, n);
	setName(n);
	cout << "Date of next game: ";
	cin >> ng.day;
	cin.get();
	cin >> ng.month;
	cin.get();
	cin >> ng.year;
	cin.get();
	setNextGame(ng);
	cout << "Number of teams playing: ";
	cin >> t;
	setTeams(t);
	cin.get();
	setTeamNames(teams);
	cout << endl;

}
void Sport::display()
{
	cout << left << setw(15) << "Sport:" << setw(15) << "Next Game:" << "# of Teams:" << endl;
	cout << left << setw(15) << getName();
	cout << getNextGame().day << "/" << getNextGame().month << "/" << left << setw(10) << getNextGame().year;
	cout << left << setw(4) << getTeams() << endl;
	cout << "Teams participating: ";
	for (int i = 0; i < teams; i++)
	{
		cout << teamNames[i] << ", ";
	}
	cout << endl;
	cout << "Lowest character in name: " << findLowest() << endl << endl;
}
Sport::~Sport()
{
	delete[]teamNames;
}
//****************************************************************************************************
