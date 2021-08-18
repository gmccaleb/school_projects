//****************************************************************************************************
//     File:                pointers2.cpp
//
//     Student:             Gabrielle McCaleb
//
//     Assignment:          Program #4
//
//     Course Name:         Programming II
//
//     Course Number:       COSC 1560 - 02
//
//     Due:                 February 14, 2020
//
//     This program uses pointers and arrays.
//
//****************************************************************************************************

#include <iostream>
using namespace std;

void arrayDisplay(const int numbers[], int);
void pointerDisplay(int *, int);
void userPointer(int numbers[], int);
void addValues(int numbers[], int);

//****************************************************************************************************

int main()
{
	const int SIZE = 5;
	int numbers[SIZE] = { 10, 22, 34, 48, 59 };
	int *ptr = numbers;

	arrayDisplay(numbers, SIZE);
	pointerDisplay(ptr, SIZE);
	userPointer(numbers, SIZE);
	addValues(numbers, SIZE);
}
//****************************************************************************************************

void arrayDisplay(const int numbers[], int size)
{
	cout << "Values are: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << numbers[i] << " ";
	}
	cout << endl;

	cout << "Addresses of values: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << &numbers[i] << " ";
	}
	cout << endl;
}

//****************************************************************************************************

void pointerDisplay(int *ptr, int size)
{
	cout << "Values are: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << *ptr << " ";
		ptr++;
	}

	cout << endl;
	ptr = ptr - size;

	cout << "Addresses of values: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << ptr << " ";
		ptr++;
	}
	cout << endl << endl;
}

//****************************************************************************************************

void userPointer(int numbers[], int size)
{
	int num1,
		num2,
		num3;
	int *ptr = numbers;

	do
	{
		cout << "Enter 3 numbers between 1 and 5: " << endl;
		cin >> num1 >> num2 >> num3;
	} while ((num1 < 0 || num1 > 5) || (num2 < 0 || num2 > 5) || (num3 < 0 || num3 > 5));

	cout << "Value " << num1 << " is: " << *(ptr + num1 - 1) << endl;
	cout << "Index: " << num1 - 1 << endl;
	cout << "Address: " << ptr + num1 - 1 << endl << endl;

	cout << "Value " << num2 << " is: " << *(ptr + num2 - 1) << endl;
	cout << "Index: " << num2 - 1 << endl;
	cout << "Address: " << ptr + num2 - 1 << endl << endl;

	cout << "Value " << num3 << " is: " << *(ptr + num3 - 1) << endl;
	cout << "Index: " << num3 - 1 << endl;
	cout << "Address: " << ptr + num3 - 1 << endl << endl;
}

//****************************************************************************************************

void addValues(int numbers[], int size)
{
	int num1,
		num2;
	do
	{
		cout << "Choose two numbers between 1 and 5: " << endl;
		cin >> num1 >> num2;
	} while ((num1 < 0 || num1 > 5) || (num2 < 0 || num2 > 5));

	int *ptr1 = &numbers[num1 - 1],
		*ptr2 = &numbers[num2 - 1];

	cout << "Sum of values: " << *ptr1 + *ptr2;
}

//****************************************************************************************************

/*
Values are:
10 22 34 48 59
Addresses of values:
010FFC8C 010FFC90 010FFC94 010FFC98 010FFC9C
Values are:
10 22 34 48 59
Addresses of values:
010FFC8C 010FFC90 010FFC94 010FFC98 010FFC9C

Enter 3 numbers between 1 and 5:
1 3 5
Value 1 is: 10
Index: 0
Address: 010FFC8C

Value 3 is: 34
Index: 2
Address: 010FFC94

Value 5 is: 59
Index: 4
Address: 010FFC9C

Choose two numbers between 1 and 5:
2 4
Sum of values: 70
*/