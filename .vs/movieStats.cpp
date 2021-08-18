//****************************************************************************************************
//     File:                movieStats.cpp
//
//     Student:             Gabrielle McCaleb
//
//     Assignment:          Program #5
//
//     Course Name:         Programming II
//
//     Course Number:       COSC 1560 - 02
//
//     Due:                 February 21, 2020
//
//     This program is for statistical data on the number of movies students see montthly.
//
//****************************************************************************************************

#include <iostream>
using namespace std;

double mean(const int values[], int);
double median(const int values[], int);
int mode(const int values[], int);

//****************************************************************************************************

int main()
{
	int most,
		temp,
		students;
	int *ptr = nullptr;
	double average,
		middle;
	bool swap;

	do
	{
		cout << "How many students were surveyed? ";
		cin >> students;
	} while (students < 0);

	ptr = new int[students];

	for (int i = 0; i < students; i++)
	{
		do
		{
			cout << "Enter number of movies seen by student " << i + 1 << ": ";
			cin >> ptr[i];
		} while (ptr[i] < 0);
	}
	cout << endl;

	int total = students;
	do
	{
		swap = false;
		for (int count = 0; count < (total - 1); count++)
		{
			if (ptr[count] > ptr[count + 1])
			{
				swap = true;
				temp = ptr[count];
				ptr[count] = ptr[count + 1];
				ptr[count + 1] = temp;
			}
		}
		total--;
	}
	while (swap);

	average = mean(ptr, students);
	cout << "The mean of movies seen monthly is: " << average << endl;

	middle = median(ptr, students);
	cout << "The median amount of movies seen monthly is: " << middle << endl;

	most = mode(ptr, students);
	cout << "The mode of movies seen monthly is: " << most << endl;

	return 0;
}

//****************************************************************************************************

double mean(const int values[], int students)
{
	int total = 0;
	double avg;

	for (int i = 0; i < students; i++)
	{
		total += values[i];
	}
	avg = total / static_cast<double>(students);

	return avg;
}

//****************************************************************************************************

double median(const int values[], int students)
{
	int middle,
		last = students - 1;
	double median;

	middle = last / 2;
	if (students % 2 == 0)
	{
		int temp1 = middle + 1;
		median = (values[temp1] + values[middle]) / 2.0;
	}
	else
	{
		median = values[middle];
	}

	return median;
}

//****************************************************************************************************

int mode(const int values[], int size)
{
	int most = 1,
		mode = 1,
		tempCount = 1,


		lastNumber = values[0];

	for (int index = 1; index < size; index++)
	{
		if (lastNumber == values[index])
		{
			tempCount++;
			if (tempCount > most)
			{
				most = tempCount;
				mode = values[index];
			}
		}
		else
		{
			lastNumber = values[index];
			if (tempCount > most)
			{
				most = tempCount;
				mode = values[index];
			}
			tempCount = 1;
		}

	}

	return mode;
}

//****************************************************************************************************

/*
How many students were surveyed? 10
Enter number of movies seen by student 1: 1
Enter number of movies seen by student 2: 7
Enter number of movies seen by student 3: 5
Enter number of movies seen by student 4: 2
Enter number of movies seen by student 5: 3
Enter number of movies seen by student 6: 1
Enter number of movies seen by student 7: 1
Enter number of movies seen by student 8: 0
Enter number of movies seen by student 9: 2
Enter number of movies seen by student 10: 0

The mean of movies seen monthly is: 2.2
The median amount of movies seen monthly is: 1.5
The mode of movies seen monthly is: 1
*/

/*
How many students were surveyed? 7
Enter number of movies seen by student 1: 0
Enter number of movies seen by student 2: 3
Enter number of movies seen by student 3: 4
Enter number of movies seen by student 4: 2
Enter number of movies seen by student 5: 2
Enter number of movies seen by student 6: 3
Enter number of movies seen by student 7: 1

The mean of movies seen monthly is: 2.14286
The median amount of movies seen monthly is: 2
The mode of movies seen monthly is: 2
*/

/*
How many students were surveyed? 5
Enter number of movies seen by student 1: 2
Enter number of movies seen by student 2: 4
Enter number of movies seen by student 3: 0
Enter number of movies seen by student 4: 2
Enter number of movies seen by student 5: 3

The mean of movies seen monthly is: 2.2
The median amount of movies seen monthly is: 2
The mode of movies seen monthly is: 2
*/