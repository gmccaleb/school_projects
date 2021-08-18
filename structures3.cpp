//****************************************************************************************************
//     File:                structures3.cpp
//
//     Student:             Gabrielle McCaleb
//
//     Assignment:          Program #7
//
//     Course Name:         Programming II
//
//     Course Number:       COSC 1560 - 02
//
//     Due:                 March 20, 2020
//
//     This program is for structure practices.
//
//****************************************************************************************************

#include <iostream>
#include <string>
using namespace std;

struct Student
{
	string studentName;
	int studentID;
	int test[3];
};

void enterData(Student[], int);
void displayData(const Student[], int);
void nameSort(Student[], int);
void avgSort(Student[], int);

//****************************************************************************************************

int main()
{
	const int NUMSTUDENTS = 5;
	Student person[NUMSTUDENTS];

	enterData(person, NUMSTUDENTS);
	displayData(person, NUMSTUDENTS);
	cout << "Students sorted by name " << endl;
	nameSort(person, NUMSTUDENTS);
	cout << endl << "Students sorted by average test score " << endl;
	avgSort(person, NUMSTUDENTS);

	return 0;
}

//****************************************************************************************************

void enterData(Student person[], int numstudents)
{
	for (int i = 0; i < numstudents; i++)
	{
		cout << "Enter the Name, I.D. number, and 3 test scores for student " << i + 1 << endl;
		getline(cin, person[i].studentName);
		cin >> person[i].studentID;
		for (int j = 0; j < 3; j++)
		{
			cin >> person[i].test[j];
		}
		cin.get();
	}
}

//****************************************************************************************************

void displayData(const Student person[], int numstudents)
{
	for (int i = 0; i < numstudents; i++)
	{
		cout << endl;
		cout << "Student: " << i + 1 << endl;
		cout << "Name: " << person[i].studentName << endl;
		cout << "I.D. number: " << person[i].studentID << endl;
		for (int j = 0; j < 3; j++)
		{
			cout << "Test" << j + 1 << ": " << person[i].test[j] << ", ";
		}
	}
	cout << endl << endl;
}

//****************************************************************************************************

void nameSort(Student person[], int numstudents)
{
	int total = numstudents;
	bool swap;
	Student temp;
	do
	{
		swap = false;
		for (int count = 0; count < (total - 1); count++)
		{
			if (person[count].studentName > person[count + 1].studentName)
			{
				swap = true;
				temp = person[count];
				person[count] = person[count + 1];
				person[count + 1] = temp;
			}

		}
		total--;
	} while (swap);

	for (int i = 0; i < numstudents; i++)
	{
		cout << endl << "Student" << i + 1 << ": " << endl;
		cout << "Name: " << person[i].studentName << endl;
		cout << "I.D. number: " << person[i].studentID << endl;
		cout << "Test scores: ";
		for (int j = 0; j < 3; j++)
		{
			cout << person[i].test[j] << " ";
		}
	}
	cout << endl << endl;
}

//****************************************************************************************************

void avgSort(Student person[], int numstudents)
{
	int total = numstudents,
		tempTotal = 0;
	bool swap;
	double temp;
	const int SIZE = 5;
	double avg[SIZE];
	Student tempS;

	for (int i = 0; i < numstudents; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			tempTotal += person[i].test[j];
		}
		avg[i] = tempTotal / 3.0;
		tempTotal = 0;
	}
	do
	{
		swap = false;
		for (int count = 0; count < (total - 1); count++)
		{
			if (avg[count] < avg[count + 1])
			{
				swap = true;
				temp = avg[count];
				tempS = person[count];
				avg[count] = avg[count + 1];
				avg[count + 1] = temp;
				person[count] = person[count + 1];
				person[count + 1] = tempS;

			}

		}
		total--;
	} while (swap);

	for (int i = 0; i < numstudents; i++)
	{
		cout << endl << "Student" << i + 1 << ": " << endl;
		cout << "Name: " << person[i].studentName << endl;
		cout << "I.D. number: " << person[i].studentID << endl;
		cout << "Test scores: ";
		for (int j = 0; j < 3; j++)
		{
			cout << person[i].test[j] << " ";
		}
		cout << endl << "Average: " << avg[i];
		
	}
	cout << endl;
}

//****************************************************************************************************

/*
Enter the Name, I.D. number, and 3 test scores for student 1
Ellie Smith
3894
97 94 89
Enter the Name, I.D. number, and 3 test scores for student 2
Ellis Smith
8392
89 83 95
Enter the Name, I.D. number, and 3 test scores for student 3
Zola James
4934
82 83 90
Enter the Name, I.D. number, and 3 test scores for student 4
Ashley Ford
0439
74 79 82
Enter the Name, I.D. number, and 3 test scores for student 5
James Jordan
8953
100 100 82

Student: 1
Name: Ellie Smith
I.D. number: 3894
Test1: 97, Test2: 94, Test3: 89,
Student: 2
Name: Ellis Smith
I.D. number: 8392
Test1: 89, Test2: 83, Test3: 95,
Student: 3
Name: Zola James
I.D. number: 4934
Test1: 82, Test2: 83, Test3: 90,
Student: 4
Name: Ashley Ford
I.D. number: 439
Test1: 74, Test2: 79, Test3: 82,
Student: 5
Name: James Jordan
I.D. number: 8953
Test1: 100, Test2: 100, Test3: 82,

Students sorted by name

Student1:
Name: Ashley Ford
I.D. number: 439
Test scores: 74 79 82
Student2:
Name: Ellie Smith
I.D. number: 3894
Test scores: 97 94 89
Student3:
Name: Ellis Smith
I.D. number: 8392
Test scores: 89 83 95
Student4:
Name: James Jordan
I.D. number: 8953
Test scores: 100 100 82
Student5:
Name: Zola James
I.D. number: 4934
Test scores: 82 83 90


Students sorted by average test score

Student1:
Name: James Jordan
I.D. number: 8953
Test scores: 100 100 82
Average: 94
Student2:
Name: Ellie Smith
I.D. number: 3894
Test scores: 97 94 89
Average: 93.3333
Student3:
Name: Ellis Smith
I.D. number: 8392
Test scores: 89 83 95
Average: 89
Student4:
Name: Zola James
I.D. number: 4934
Test scores: 82 83 90
Average: 85
Student5:
Name: Ashley Ford
I.D. number: 439
Test scores: 74 79 82
Average: 78.3333
*/