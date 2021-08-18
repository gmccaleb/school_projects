//****************************************************************************************************
//     File:                structures.cpp
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
	const int SIZE = 10;
	Speakerinfo speaker[SIZE];
	int sTotal;

	for (int i = 0; i < SIZE; i++)
	{
		cout << "Enter the name, phone number, topic, and fee for speaker #" << i + 1 << ": " << endl;
		getline(cin, speaker[i].name);
		getline(cin, speaker[i].phone);
		getline(cin, speaker[i].topic);
		cin >> speaker[i].fee;
		cin.get();
		cout << endl;
	}
	sort(speaker, SIZE);
	display(speaker, SIZE);

	sTotal = search(speaker, SIZE);
	if (sTotal == 0)
	{
		cout << "There are no speakers with this topic. " << endl << endl;
	}
	for (int i = 0; i < 5; i++)
	{
		options(speaker, SIZE);
	}

	cin.get();
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
Enter the name, phone number, topic, and fee for speaker #1:
Roman Nox
583-249-2091
Diversity
55

Enter the name, phone number, topic, and fee for speaker #2:
Blake Moore
472-489-9580
Business management
125

Enter the name, phone number, topic, and fee for speaker #3:
Mekhi Pickens
748-239-9283
Business ethics
90

Enter the name, phone number, topic, and fee for speaker #4:
Robert Lawson
504-358-8565
Financial literacy
75

Enter the name, phone number, topic, and fee for speaker #5:
Zola Ware
389-230-3301
Diversity
55

Enter the name, phone number, topic, and fee for speaker #6:
Charles Scott
348-560-4829
Internship opportunities
65

Enter the name, phone number, topic, and fee for speaker #7:
Ashley Ford
904-237-4581
Resume building
100

Enter the name, phone number, topic, and fee for speaker #8:
Darryl Herd
858-431-9043
Microsoft basics
35

Enter the name, phone number, topic, and fee for speaker #9:
Sophie Hunt
743-238-0510
Human rights
55

Enter the name, phone number, topic, and fee for speaker #10:
Nelson Lewis
392-241-3005
Climate change
40

List of speakers sorted by topic:
Speaker: 1
Name: Mekhi Pickens
Phone: 748-239-9283
Topic: Business ethics
Fee: $90
Speaker: 2
Name: Blake Moore
Phone: 472-489-9580
Topic: Business management
Fee: $125
Speaker: 3
Name: Nelson Lewis
Phone: 392-241-3005
Topic: Climate change
Fee: $40
Speaker: 4
Name: Roman Nox
Phone: 583-249-2091
Topic: Diversity
Fee: $55
Speaker: 5
Name: Zola Ware
Phone: 389-230-3301
Topic: Diversity
Fee: $55
Speaker: 6
Name: Robert Lawson
Phone: 504-358-8565
Topic: Financial literacy
Fee: $75
Speaker: 7
Name: Sophie Hunt
Phone: 743-238-0510
Topic: Human rights
Fee: $55
Speaker: 8
Name: Charles Scott
Phone: 348-560-4829
Topic: Internship opportunities
Fee: $65
Speaker: 9
Name: Darryl Herd
Phone: 858-431-9043
Topic: Microsoft basics
Fee: $35
Speaker: 10
Name: Ashley Ford
Phone: 904-237-4581
Topic: Resume building
Fee: $100

Enter a speaking topic to search for: Diversity
Name: Roman Nox
Phone: 583-249-2091
Topic: Diversity
Fee: $55
Name: Zola Ware
Phone: 389-230-3301
Topic: Diversity
Fee: $55


Choose one of the following options:
1) Enter data into the array
2) Change the contents of a particular element of the array
3) Display a specific element of the array
4) Search by a specific topic
5) Display all the data stored in the array.
4
Enter a speaking topic to search for: Internship opportunities
Name: Charles Scott
Phone: 348-560-4829
Topic: Internship opportunities
Fee: $65


Choose one of the following options:
1) Enter data into the array
2) Change the contents of a particular element of the array
3) Display a specific element of the array
4) Search by a specific topic
5) Display all the data stored in the array.
2
Choose which speaker to change: 3
Enter the name, phone number, topic, and fee for speaker #3:
Felix Smith
484-347-0008
Networking basics
85

Choose one of the following options:
1) Enter data into the array
2) Change the contents of a particular element of the array
3) Display a specific element of the array
4) Search by a specific topic
5) Display all the data stored in the array.
3
Choose which speaker to display: 3

Roman Nox
583-249-2091
Diversity
55

Choose one of the following options:
1) Enter data into the array
2) Change the contents of a particular element of the array
3) Display a specific element of the array
4) Search by a specific topic
5) Display all the data stored in the array.
4
Enter a speaking topic to search for: Women rights


There is nobody speaking on this topic
Choose one of the following options:
1) Enter data into the array
2) Change the contents of a particular element of the array
3) Display a specific element of the array
4) Search by a specific topic
5) Display all the data stored in the array.
5
List of speakers sorted by topic:
Speaker: 1
Name: Mekhi Pickens
Phone: 748-239-9283
Topic: Business ethics
Fee: $90
Speaker: 2
Name: Blake Moore
Phone: 472-489-9580
Topic: Business management
Fee: $125
Speaker: 3
Name: Roman Nox
Phone: 583-249-2091
Topic: Diversity
Fee: $55
Speaker: 4
Name: Zola Ware
Phone: 389-230-3301
Topic: Diversity
Fee: $55
Speaker: 5
Name: Robert Lawson
Phone: 504-358-8565
Topic: Financial literacy
Fee: $75
Speaker: 6
Name: Sophie Hunt
Phone: 743-238-0510
Topic: Human rights
Fee: $55
Speaker: 7
Name: Charles Scott
Phone: 348-560-4829
Topic: Internship opportunities
Fee: $65
Speaker: 8
Name: Darryl Herd
Phone: 858-431-9043
Topic: Microsoft basics
Fee: $35
Speaker: 9
Name: Felix Smith
Phone: 484-347-0008
Topic: Networking basics
Fee: $85
Speaker: 10
Name: Ashley Ford
Phone: 904-237-4581
Topic: Resume building
Fee: $100
*/

