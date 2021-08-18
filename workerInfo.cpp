//****************************************************************************************************
//     File:                workerInfo.cpp
//
//     Student:             Gabrielle McCaleb
//
//     Assignment:          Program #8
//
//     Course Name:         Programming II
//
//     Course Number:       COSC 1560 - 02
//
//     Due:                 March 27, 2020
//
//     This program stores employee informaition.
//
//****************************************************************************************************

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

struct Date
{
	int day,
		month,
		year;
};
struct EInformation
{
	string name;
	int age;
	Date start;
};

EInformation* readEmployee(const string&, int &);
void displayEmployees(const EInformation employee[], int);
EInformation* inputEmployees(EInformation employee[], int &);

//****************************************************************************************************

int main()
{
	string empFile = "Employees";
	int numEmps;
	EInformation *employees = nullptr;
	char input;
	fstream file;

	employees = readEmployee(empFile, numEmps);
	displayEmployees(employees, numEmps);

	do
	{
		cout << "Would you like to add information for additional employees (Y/N)?: ";
		cin >> input;
		if (input == 'y' || input == 'Y')
		{
			employees = inputEmployees(employees, numEmps);
			displayEmployees(employees, numEmps);
		}
	} while (input == 'y' || input == 'Y');


	file.open("Employees.txt", ios::out);

	file << numEmps << endl;
	for (int i = 0; i < numEmps; i++)
	{
		file << employees[i].name << "," << employees[i].age << ",";
		file << employees[i].start.day << "/" << employees[i].start.month << "/" << employees[i].start.year;
		file << endl;
	}


	return 0;
}

//****************************************************************************************************

EInformation* readEmployee(const string& empFile, int & numEmps)
{
	fstream f;
	EInformation *ptr = nullptr;
	string Employee = empFile;

	f.open("Employees.txt", ios::in);
	f >> numEmps;
	f.get();
	ptr = new EInformation[numEmps];

	for (int i = 0; i < numEmps; i++)
	{
		getline(f, ptr[i].name, ',');
		f >> ptr[i].age;
		f.get();
		f >> ptr[i].start.day;
		f.get();
		f >> ptr[i].start.month;
		f.get();
		f >> ptr[i].start.year;
		f.get();
	}

	f.close();
	return ptr;
}

//****************************************************************************************************

void displayEmployees(const EInformation employee[], int numEmps)
{
	cout << endl;
	cout << left << setw(20) << "NAME" << setw(10) << "AGE" << setw(13) << "DATE EMPLOYED" << endl;
	for (int i = 0; i < numEmps; i++)
	{
		cout << left << setw(20) << employee[i].name << setw(10) << employee[i].age;
		cout << employee[i].start.day << "/" << employee[i].start.month;
		cout << "/" << employee[i].start.year << endl;
	}
}

//****************************************************************************************************

EInformation* inputEmployees(EInformation employee[], int & numEmps)
{
	EInformation *newInfo = nullptr;
	int add;
	char s;

	cout << "How many new employees?: ";
	cin >> add;

	newInfo = new EInformation[numEmps + add];
	for (int i = 0; i < numEmps; i++)
	{
		newInfo[i] = employee[i];
	}

	for (int i = numEmps; i < numEmps + add; i++)
	{
		cin.get();
		cout << left << setw(10) << "NAME:";
		getline(cin, newInfo[i].name);
		cout << left << setw(10) << "AGE:";
		cin >> newInfo[i].age;
		cout << left << setw(10) << "EMPLOYED:";
		cin >> newInfo[i].start.day;
		cin >> s;
		cin >> newInfo[i].start.month;
		cin >> s;
		cin >> newInfo[i].start.year;
	}
	cout << endl;
	numEmps += add;

	delete[]employee;


	return newInfo;
}

/*
NAME                AGE       DATE EMPLOYED
Stephen Smith       25        15/12/2001
Susan Kim-Jones     33        9/1/2012
Kun Joom Jadav      52        22/8/1999
Would you like to add information for additional employees (Y/N)?: y
How many new employees?: 2
NAME:     Paul Mitchell
AGE:      26
EMPLOYED: 21/4/2017
NAME:     Grace Waters
AGE:      37
EMPLOYED: 10/6/2008


NAME                AGE       DATE EMPLOYED
Stephen Smith       25        15/12/2001
Susan Kim-Jones     33        9/1/2012
Kun Joom Jadav      52        22/8/1999
Paul Mitchell       26        21/4/2017
Grace Waters        37        10/6/2008
Would you like to add information for additional employees (Y/N)?: n
*/

/*
5
Stephen Smith,25,15/12/2001
Susan Kim-Jones,33,9/1/2012
Kun Joom Jadav,52,22/8/1999
Robert Keys,31,13/9/2004
Jordan Taylor,27,2/10/2010
*/