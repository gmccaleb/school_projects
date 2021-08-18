//****************************************************************************************************
//     File:                studentNames.cpp
//
//     Student:             Gabrielle McCaleb
//
//     Assignment:          Program #3
//
//     Course Name:         Programming II
//
//     Course Number:       COSC 1560 - 02
//
//     Due:                 February 7, 2020
//
//     This program displays the data on students' names.
//
//****************************************************************************************************


#include <iostream>
using namespace std;

//****************************************************************************************************

int main()
{
	int n1 = 10,
		n2 = 25,
		n3 = 50;
	int *p1 = &n1,
		*p2 = &n2;

	*p1 *= 2;
	cout << *p1 << endl;
	cout << *p1 + *p2 << endl;
	p1 = &n3;
	cout << *p1 + *p2;

	return 0;
}

//****************************************************************************************************

/*
20
45
75
*/