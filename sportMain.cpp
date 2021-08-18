//****************************************************************************************************
//     File:                sportMain.cpp
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

void sportOperations(Sport *s, int);
void populateAll(Sport *s, int);
void displayAll(Sport *s, int);
void displayAvg(Sport *s, int);
void displaySportInfo(Sport *s);
void nextEvent(Sport *s, int);

//****************************************************************************************************

int main()
{
	int size;
	Sport *group = nullptr;
	Sport s;

	cout << "How many sports need to be processed?: ";
	cin >> size;
	cin.get();
	group = new Sport[size];

	cout << endl;
	populateAll(group, size);
	for (int i = 0; i < size; i++)
	{
		group[i].display();
	}

	displayAvg(group, size);

	for (int i = 0; i < 5; i++)
		sportOperations(group, size);

	return 0;
}

//****************************************************************************************************

void sportOperations(Sport *s, int size)
{
	char option;

	cout << "\nChoose an option:\n";
	cout << "     a) Populate all sports\n";
	cout << "     b) Display sports\n";
	cout << "     c) Update a particular sport\n";
	cout << "     d) Display a particular sport\n";
	cout << "     e) Display a particular sport's name, next game, or teams playing\n";
	cout << "     f) Display average number of teams\n";
	cout << "     g) Display name of sport that is played first\n";
	cin >> option;

	switch (option)
	{
	case 'a':
		populateAll(s, size);
		break;
	case 'b':
		displayAll(s, size);
		break;
	case 'c':
		int n;
		cout << "Which sport would you like to update? #: ";
		cin >> n;
		cin.get();
		s[n - 1].populate();
		break;
	case 'd':
		int a;
		cout << "What sport do you want to display? #: ";
		cin >> a;
		cin.get();
		s[a - 1].display();
		break;
	case 'e':
		displaySportInfo(s);
		break;
	case 'f':
		displayAvg(s, size);
		break;
	case 'g':
		nextEvent(s, size);
		break;
	}
}

//****************************************************************************************************

void populateAll(Sport *s, int size)
{
	cout << "Enter the information regarding the " << size << " sports teams:\n";
	for (int i = 0; i < size; i++)
	{
		s[i].populate();
	}
	cout << endl;
}

//****************************************************************************************************

void displayAll(Sport *s, int size)
{
	for (int i = 0; i < size; i++)
	{
		s[i].display();
	}
	cout << endl;
}

//****************************************************************************************************

void displaySportInfo(Sport *s)
{
	int n1,
		n2;
	cout << "What sport do you want to display? #: ";
	cin >> n1;
	cin.get();
	cout << "1. Name 2. Next Game 3. Teams Playing\nChoose one: ";
	cin >> n2;
	cin.get();
	if (n2 == 1)
	{
		cout << "Sport #" << n1 << " name: " << s[n1 - 1].getName() << endl;
	}
	else if (n2 == 2)
	{
		cout << "Sport #" << n1 << " next game: " << s[n1 - 1].getNextGame().day << "/";
		cout << s[n1 - 1].getNextGame().month << "/" << s[n1 - 1].getNextGame().year << endl;
	}
	else
	{
		cout << "Sport #" << n1 << " number of teams playing: " << s[n1 - 1].getTeams() << endl;
	}
}

//****************************************************************************************************

void displayAvg(Sport *s, int size)
{
	double avg;
	int total = 0;
	fixed;

	for (int i = 0; i < size; i++)
	{
		total += s[i].getTeams();
	}

	avg = total / static_cast<double>(size);
	cout << "Average number of teams participating: " << setprecision(2) << avg << endl << endl;
}

//****************************************************************************************************

void nextEvent(Sport *s, int size)
{
	Date next;
	Sport t;
	int earliest = 0;

	cout << "Next scheduled event:\n";
	for (int i = 1; i < size; i++)
	{
		t = s[i];
		if (t.getNextGame().year < s[earliest].getNextGame().year)
		{
			earliest = i;
		}
		else if ((t.getNextGame().year == s[earliest].getNextGame().year) &&
			(t.getNextGame().month < s[earliest].getNextGame().month))
		{
			earliest = i;

		}
		else if ((t.getNextGame().year == s[earliest].getNextGame().year) &&
			(t.getNextGame().month == s[earliest].getNextGame().month))
		{
			if (t.getNextGame().day < s[earliest].getNextGame().day)

			{
				earliest = i;

			}
		}
	}

	s[earliest].display();
}

//****************************************************************************************************

/*
How many sports need to be processed?: 3

Enter the information regarding the 3 sports teams:
Sport: Basketball
Date of next game: 15/10/2012
Number of teams playing: 6
Team 1: Cyclones
Team 2: Panthers
Team 3: Spartans
Team 4: Pirates
Team 5: Flyers
Team 6: Blue Jays

Sport: Tennis
Date of next game: 27/8/2012
Number of teams playing: 2
Team 1: Cyclones
Team 2: Blue Jays

Sport: Track & Field
Date of next game: 7/3/2013
Number of teams playing: 5
Team 1: Cyclones
Team 2: Hawks
Team 3: Flyers
Team 4: Hornets
Team 5: Pioneers


Sport:         Next Game:     # of Teams:
Basketball     15/10/2012      6
Teams participating: Cyclones, Panthers, Spartans, Pirates, Flyers, Blue Jays,
Lowest character in name: B

Sport:         Next Game:     # of Teams:
Tennis         27/8/2012      2
Teams participating: Cyclones, Blue Jays,
Lowest character in name: T

Sport:         Next Game:     # of Teams:
Track & Field  7/3/2013      5
Teams participating: Cyclones, Hawks, Flyers, Hornets, Pioneers,
Lowest character in name:

Average number of teams participating: 4.3


Choose an option:
	 a) Populate all sports
	 b) Display sports
	 c) Update a particular sport
	 d) Display a particular sport
	 e) Display a particular sport's name, next game, or teams playing
	 f) Display average number of teams
	 g) Display name of sport that is played first
g
Next scheduled event:
Sport:         Next Game:     # of Teams:
Tennis         27/8/2012      2
Teams participating: Cyclones, Blue Jays,
Lowest character in name: T


Choose an option:
	 a) Populate all sports
	 b) Display sports
	 c) Update a particular sport
	 d) Display a particular sport
	 e) Display a particular sport's name, next game, or teams playing
	 f) Display average number of teams
	 g) Display name of sport that is played first
c
Which sport would you like to update? #: 3
Sport: Track & Field
Date of next game: 24/5/2012
Number of teams playing: 7
Team 1: Cyclones
Team 2: Hawks
Team 3: Spartans
Team 4: Hornets
Team 5: Blue Jays
Team 6: Pirates
Team 7: Sparks


Choose an option:
	 a) Populate all sports
	 b) Display sports
	 c) Update a particular sport
	 d) Display a particular sport
	 e) Display a particular sport's name, next game, or teams playing
	 f) Display average number of teams
	 g) Display name of sport that is played first
d
What sport do you want to display? #: 1
Sport:         Next Game:     # of Teams:
Basketball     15/10/2012      6
Teams participating: Cyclones, Panthers, Spartans, Pirates, Flyers, Blue Jays,
Lowest character in name: B


Choose an option:
	 a) Populate all sports
	 b) Display sports
	 c) Update a particular sport
	 d) Display a particular sport
	 e) Display a particular sport's name, next game, or teams playing
	 f) Display average number of teams
	 g) Display name of sport that is played first
e
What sport do you want to display? #: 2
1. Name 2. Next Game 3. Teams Playing
Choose one: 2
Sport #2 next game: 27/8/2012

Choose an option:
	 a) Populate all sports
	 b) Display sports
	 c) Update a particular sport
	 d) Display a particular sport
	 e) Display a particular sport's name, next game, or teams playing
	 f) Display average number of teams
	 g) Display name of sport that is played first
f
Average number of teams participating: 5
*/