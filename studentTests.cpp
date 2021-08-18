//****************************************************************************************************
//     File:                studentTests.cpp
//
//     Student:             Gabrielle McCaleb
//
//     Assignment:          Program #1
//
//     Course Name:         Programming II
//
//     Course Number:       COSC 1560 - 02
//
//     Due:                 January 31, 2020
//
//     This program displays the data on students' tests.
//
//****************************************************************************************************

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int NUM_TESTS = 8;

void readTestScores(ifstream& f, int[][NUM_TESTS], int, int);
void displayTestScores(const int[][NUM_TESTS], int, int);
int totalOneTest(const int[][NUM_TESTS], int, int, int);
int totalOneStudent(const int[][NUM_TESTS], int, int, int);
double averageOneTest(const int [][NUM_TESTS], int, int , int);
double averageOneStudent(const int[][NUM_TESTS], int, int, int);
int highestOneStudent(const int[][NUM_TESTS], int, int, int);
int topStudent(const int[][NUM_TESTS], int, int);
bool searchStudents(const int [][NUM_TESTS], int, double);
bool searchTests(const int[][NUM_TESTS], int, double);

//****************************************************************************************************

int main()
{
	const int NUM_STUDENTS = 10;
	int testScores[NUM_STUDENTS][NUM_TESTS];
	int testTotal,
		topStu,
		studentTotal,
		highestScore;
	double average,
		testAverage,
		studentAverage;
	bool found;
	ifstream grades("Assignment1Data.txt");

	readTestScores(grades, testScores, NUM_STUDENTS, NUM_TESTS);
	grades.close();
	displayTestScores(testScores, NUM_STUDENTS, NUM_TESTS);

	testTotal = totalOneTest(testScores, NUM_STUDENTS, NUM_TESTS, 3);
	cout << "Total for test 3 is: " << testTotal << endl;
	cout << "Press enter to continue..." << endl << endl;
	cin.ignore();
	testTotal = totalOneTest(testScores, NUM_STUDENTS, NUM_TESTS, 5);
	cout << "Total for test 5 is: " << testTotal << endl;
	cout << "Press enter to continue..." << endl << endl;
	cin.ignore();

	studentTotal = totalOneStudent(testScores, NUM_STUDENTS, NUM_TESTS, 3);
	cout << "Total for student 3 is: " << studentTotal << endl;
	cout << "Press enter to continue..." << endl << endl;
	cin.ignore();
	studentTotal = totalOneStudent(testScores, NUM_STUDENTS, NUM_TESTS, 8);
	cout << "Total for student 8 is: " << studentTotal << endl;
	cout << "Press enter to continue..." << endl << endl;
	cin.ignore();

	testAverage = averageOneTest(testScores, NUM_STUDENTS, NUM_TESTS, 5);
	cout << fixed;
	cout << "Average for test 5 is: " << setprecision(2) << testAverage << endl;
	cout << "Press enter to continue..." << endl << endl;
	cin.ignore();
	testAverage = averageOneTest(testScores, NUM_STUDENTS, NUM_TESTS, 8);
	cout << "Average for test 8 is: " << setprecision(2) << testAverage << endl;
	cout << "Press enter to continue..." << endl << endl;
	cin.ignore();

	studentAverage = averageOneStudent(testScores, NUM_STUDENTS, NUM_TESTS, 5);
	cout << "Average for student 5 is: " << setprecision(2) << studentAverage << endl;
	cout << "Press enter to continue..." << endl << endl;
	cin.ignore();
	studentAverage = averageOneStudent(testScores, NUM_STUDENTS, NUM_TESTS, 9);
	cout << "Average for student 9 is: " << setprecision(2) << studentAverage << endl;
	cout << "Press enter to continue..." << endl << endl;
	cin.ignore();

	highestScore = highestOneStudent(testScores, NUM_STUDENTS, NUM_TESTS, 2);
	cout << "Highest test score for student 2 is: " << highestScore << endl;
	cout << "Press enter to continue..." << endl << endl;
	cin.ignore();

	topStu = topStudent(testScores, NUM_STUDENTS, NUM_TESTS);
	cout << "Top student: " << topStu << endl << endl;

	cout << "Enter an average to search for: ";
	cin >> average;
	cout << endl;

	found = searchStudents(testScores, NUM_STUDENTS, average);
	if (found)
	{
		cout << "A student does have an average score greater than: " << average << endl;
	}
	else
	{
		cout << "A student doesn't have an average score greater than: " << average << endl;
	}
	cout << "Press enter to continue..." << endl << endl;
	cin.ignore();

	found = searchTests(testScores, NUM_STUDENTS, average);
	if (found)
	{
		cout << "A test does have an average score greater than: " << average << endl;
	}
	else
	{
		cout << "A test doesn't have an average score greater than: " << average << endl;
	}
	cout << "Press enter to continue...";

	return 0;
}

//****************************************************************************************************

void readTestScores(ifstream&grades, int scores[][NUM_TESTS],int num_students,int num_tests)
{

		for (int r = 0; r < num_students; r++)
		{
			for (int c = 0; c < num_tests; c++)
			{
				grades >> scores[r][c];
			}
		}
}

//****************************************************************************************************

void displayTestScores(const int scores[][NUM_TESTS], int num_students, int num_tests)
{
	cout << "All test scores: " << endl;

	for (int r = 0; r < num_students; r++)
	{
		cout << endl;
		for (int c = 0; c < num_tests; c++)
		{
			cout << scores[r][c] << " ";
		}
	}

	cout << endl;
	cout << "Press enter to continue..." << endl << endl;
	cin.ignore();
}

//****************************************************************************************************

int totalOneTest(const int scores[][NUM_TESTS], int num_students, int num_tests, int testNum)
{
	int col,
		total = 0;

	col = testNum - 1;

	for (int r = 0; r < num_students; r++)
	{
		total += scores[r][col];
	}

	return total;
}

//****************************************************************************************************

int totalOneStudent(const int scores[][NUM_TESTS], int num_students, int num_tests, int studentNum)
{
	int row,
		total = 0;

	row = studentNum - 1;

	for (int c = 0; c < num_students; c++)
	{
		total += scores[c][row];
	}

	return total;
}

//****************************************************************************************************

double averageOneTest(const int scores[][NUM_TESTS], int num_students, int num_tests, int testNum)
{
	double avg;
	int total;

	total = totalOneTest(scores, num_students, NUM_TESTS, testNum);

	avg = total / static_cast<double>(num_students);

	return avg;
}

//****************************************************************************************************

double averageOneStudent(const int scores[][NUM_TESTS], int num_students, int num_tests, int studentNum)
{
	double avg;
	int row,
		total = 0;

	row = studentNum - 1;

	for (int c = 0; c < num_tests; c++)
	{
		total += scores[row][c];
	}

	avg = total / static_cast<double>(num_tests);

	return avg;
}

//****************************************************************************************************

int highestOneStudent(const int scores[][NUM_TESTS], int num_students, int num_tests, int studentNum)
{
	int row,
		max = 0;

	row = studentNum - 1;

	for (int c = 0; c < num_tests; c++)
	{
		if (scores[row][c] > max)
		{
			max = scores[row][c];
		}
	}

	return max;
}

//****************************************************************************************************

int topStudent(const int scores[][NUM_TESTS], int num_students, int num_tests)
{
	
	const int SIZE = 10;
	double avg[SIZE];
	double max =0;
	int total,
		topStudent = 1;

	for (int r = 0; r < num_students; r++)
	{
		total = 0;
		for (int c = 0; c < num_tests; c++)
		{
			total += scores[r][c];
		}

		avg[r] = total / static_cast<double>(num_tests);

		if (avg[r] > max)
		{
			max = avg[r];
			topStudent = r + 1;
		}
	}

	return topStudent;
}

//****************************************************************************************************

bool searchStudents(const int scores[][NUM_TESTS], int num_students, double average)
{
	const int NUM_STUDENTS = 10;
	int index = 0,
		total = 0;
	bool found = false;
	double studentAvg[NUM_STUDENTS];

	for (int r = 0; r < num_students; r++)
	{
		for (int c = 0; c < NUM_TESTS; c++)
		{
			total += scores[r][c];
			studentAvg[r] = total / static_cast<double>(NUM_TESTS);
		}
	}
	while (!found && (index < NUM_STUDENTS))
	{
		if (studentAvg[index] > average)
		{
			found = true;
		}
		index++;
	}

	return found;
}

//****************************************************************************************************

bool searchTests(const int scores[][NUM_TESTS], int num_students, double average)
{
	int index = 0,
		total = 0;
	bool found = false;
	double testAvg[NUM_TESTS];
	
	for (int c = 0; c < NUM_TESTS; c++)
	{
		for (int r = 0; r < num_students; r++)
		{
			total += scores[r][c];
			testAvg[c] = total / static_cast<double>(num_students);
		}
	}

	while (!found && (index < NUM_TESTS))
	{
		if (testAvg[index] > average)
		{
			found = true;
		}
		index++;
	}

	return found;
}

//****************************************************************************************************

/*
All test scores:

87 90 65 45 88 89 75 80
89 85 78 56 90 91 99 82
80 90 72 95 99 66 77 88
90 65 80 98 99 76 77 88
55 75 66 99 99 56 87 86
30 60 80 90 99 56 67 88
90 55 95 35 98 86 37 88
99 97 99 98 98 96 87 83
90 65 80 98 99 76 87 88
35 75 60 99 99 56 87 88
Press enter to continue...


Total for test 3 is: 775
Press enter to continue...


Total for test 5 is: 968
Press enter to continue...


Total for student 3 is: 775
Press enter to continue...


Total for student 8 is: 859
Press enter to continue...


Average for test 5 is: 96.80
Press enter to continue...


Average for test 8 is: 85.90
Press enter to continue...


Average for student 5 is: 77.88
Press enter to continue...


Average for student 9 is: 85.38
Press enter to continue...


Highest test score for student 2 is: 99
Press enter to continue...


Top student: 8

Enter an average to search for:
80.00

A student does have an average score greater than: 80.00
Press enter to continue...

A test does have an average score greater than: 80.00
Press enter to continue...
*/
