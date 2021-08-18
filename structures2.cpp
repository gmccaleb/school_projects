//****************************************************************************************************
//     File:                structures2.cpp
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

struct Speakerinfo
{
	string name;
	string phone;
	string topic;
	int fee;
};

int search(const Speakerinfo[], int);
void sort(Speakerinfo[], int);
void options(Speakerinfo[], int);
void display(const Speakerinfo[], int);


//****************************************************************************************************

int main()
{
	Speakerinfo *speakers = nullptr;
	int sTotal,
		numSpeakers;

	cout << "Enter the number of speakers involved: ";
	cin >> numSpeakers;
	cin.get();

	speakers = new Speakerinfo[numSpeakers];

	for (int i = 0; i < numSpeakers; i++)
	{
		cout << "Enter the name, phone number, topic, and fee for speaker #" << i + 1 << ": " << endl;
		getline(cin, speakers[i].name);
		getline(cin, speakers[i].phone);
		getline(cin, speakers[i].topic);
		cin >> speakers[i].fee;
		cin.get();
		cout << endl;
	}
	sort(speakers, numSpeakers);
	display(speakers, numSpeakers);

	sTotal = search(speakers, numSpeakers);
	if (sTotal == 0)
	{
		cout << "There are no speakers with this topic. " << endl << endl;
	}
	for (int i = 0; i < 5; i++)
	{
		options(speakers, numSpeakers);
	}

	cin.get();
	delete[]speakers;
	return 0;
}

//****************************************************************************************************

int search(const Speakerinfo speaker[], int size)
{
	string topicSearch;

	cout << "Enter a speaking topic to search for: ";
	getline(cin, topicSearch);

	int index = 0,
		total = 0;
	bool found = false;

	while ((index < size) && !found)
	{
		if (speaker[index].topic == topicSearch)
		{
			found = true;
			total++;
			cout << "Name: " << speaker[index].name << endl;
			cout << "Phone: " << speaker[index].phone << endl;
			cout << "Topic: " << speaker[index].topic << endl;
			cout << "Fee: $" << speaker[index].fee << endl;
		}
		found = false;
		index++;
	}
	cout << endl << endl;
	return total;
}

//****************************************************************************************************

void sort(Speakerinfo speaker[], int size)
{
	int total = size;
	bool swap;
	Speakerinfo temp;
	do
	{
		swap = false;
		for (int count = 0; count < (total - 1); count++)
		{
			if (speaker[count].topic > speaker[count + 1].topic)
			{
				swap = true;
				temp = speaker[count];
				speaker[count] = speaker[count + 1];
				speaker[count + 1] = temp;
			}
		}
		total--;
	} while (swap);
}

//****************************************************************************************************

void options(Speakerinfo speaker[], int size)
{
	int option;

	cout << "Choose one of the following options:   " << endl;
	cout << "1) Enter data into the array" << endl;
	cout << "2) Change the contents of a particular element of the array" << endl;
	cout << "3) Display a specific element of the array" << endl;
	cout << "4) Search by a specific topic" << endl;
	cout << "5) Display all the data stored in the array." << endl;

	cin >> option;
	cin.get();
	switch (option)
	{
	case 1: cout << "Enter new information for the speakers: " << endl;
		for (int i = 0; i < size; i++)
		{
			cout << "Enter the name, phone number, topic, and fee for speaker #" << i + 1 << ": " << endl;
			getline(cin, speaker[i].name);
			getline(cin, speaker[i].phone);
			getline(cin, speaker[i].topic);
			cin >> speaker[i].fee;
			cin.get();
			cout << endl;
		}
		sort(speaker, size);
		break;
	case 2: {cout << "Choose which speaker to change: ";
		int num;
		cin >> num;
		cin.get();
		cout << "Enter the name, phone number, topic, and fee for speaker #" << num << ": " << endl;
		getline(cin, speaker[num - 1].name);
		getline(cin, speaker[num - 1].phone);
		getline(cin, speaker[num - 1].topic);
		cin >> speaker[num - 1].fee;
		cin.get();
		cout << endl;
		sort(speaker, size);
	}
			break;
	case 3: cout << "Choose which speaker to display: ";
		int speakerNum;
		cin >> speakerNum;
		cin.get();
		cout << endl;
		cout << speaker[speakerNum - 1].name << endl;
		cout << speaker[speakerNum - 1].phone << endl;
		cout << speaker[speakerNum - 1].topic << endl;
		cout << speaker[speakerNum - 1].fee << endl;
		cout << endl;
		break;
	case 4: { int number;;
		number = search(speaker, size);
		if (number == 0)
		{
			cout << "There is nobody speaking on this topic" << endl;
		}
	}
			break;

	case 5: display(speaker, size);
		break;

	}
}

//****************************************************************************************************

void display(const Speakerinfo speaker[], int size)
{
	cout << "List of speakers sorted by topic: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "Speaker: " << i + 1 << endl;
		cout << "Name: " << speaker[i].name << endl;
		cout << "Phone: " << speaker[i].phone << endl;
		cout << "Topic: " << speaker[i].topic << endl;
		cout << "Fee: $" << speaker[i].fee << endl;
	}
	cout << endl;
}

//****************************************************************************************************

/*
Enter the number of speakers involved: 3
Enter the name, phone number, topic, and fee for speaker #1:
Ronnie Schmidt
342-404-7891
Climate change
35

Enter the name, phone number, topic, and fee for speaker #2:
Denise Baldwin
636-402-7416
Business ethics
75

Enter the name, phone number, topic, and fee for speaker #3:
Bill Roland
504-627-1435
Business management
125

List of speakers sorted by topic:
Speaker: 1
Name: Denise Baldwin
Phone: 636-402-7416
Topic: Business ethics
Fee: $75
Speaker: 2
Name: Bill Roland
Phone: 504-627-1435
Topic: Business management
Fee: $125
Speaker: 3
Name: Ronnie Schmidt
Phone: 342-404-7891
Topic: Climate change
Fee: $35

Enter a speaking topic to search for: Diversity and Inclusion


There are no speakers with this topic.

Choose one of the following options:
1) Enter data into the array
2) Change the contents of a particular element of the array
3) Display a specific element of the array
4) Search by a specific topic
5) Display all the data stored in the array.
2
Choose which speaker to change: 3
Enter the name, phone number, topic, and fee for speaker #3:
Blake Moore
394-650-3118
Diversity and Inclusion
90

Choose one of the following options:
1) Enter data into the array
2) Change the contents of a particular element of the array
3) Display a specific element of the array
4) Search by a specific topic
5) Display all the data stored in the array.
3
Choose which speaker to display: 1

Denise Baldwin
636-402-7416
Business ethics
75

Choose one of the following options:
1) Enter data into the array
2) Change the contents of a particular element of the array
3) Display a specific element of the array
4) Search by a specific topic
5) Display all the data stored in the array.
2
Choose which speaker to change: 1
Enter the name, phone number, topic, and fee for speaker #1:
Nicole Lawson
305-280-6419
Internship opportunities
75

Choose one of the following options:
1) Enter data into the array
2) Change the contents of a particular element of the array
3) Display a specific element of the array
4) Search by a specific topic
5) Display all the data stored in the array.
5
List of speakers sorted by topic:
Speaker: 1
Name: Bill Roland
Phone: 504-627-1435
Topic: Business management
Fee: $125
Speaker: 2
Name: Blake Moore
Phone: 394-650-3118
Topic: Diversity and Inclusion
Fee: $90
Speaker: 3
Name: Nicole Lawson
Phone: 305-280-6419
Topic: Internship opportunities
Fee: $75

Choose one of the following options:
1) Enter data into the array
2) Change the contents of a particular element of the array
3) Display a specific element of the array
4) Search by a specific topic
5) Display all the data stored in the array.
1
Enter new information for the speakers:
Enter the name, phone number, topic, and fee for speaker #1:
David Russo
437-211-4780
Microsoft basics
35

Enter the name, phone number, topic, and fee for speaker #2:
Tyler Grey
843-294-3821
Computing basics
50

Enter the name, phone number, topic, and fee for speaker #3:
Owen Hunt
481-394-4500
Network essentials
75
*/

