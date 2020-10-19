#define _CRT_SECURE_NO_WARNINGS
#include "ToDoList.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <string>
#include <ctime>
#include <sstream>
#define NEWLINE '\n'
using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::left;
using std::atoi;
using namespace std;
//using std::stoi;
using std::fstream;
using std::ifstream;
using std::ofstream;

//Regular constructor
ToDoList::ToDoList()
{
	m_positionOfItems = 0;
}

//Copy constructor
ToDoList::ToDoList(ToDoList &copyFrom)
{
	m_positionOfItems = copyFrom.m_positionOfItems;
	for (int i = 0; i < MAX_SIZE; i++)
	{
		this -> m_array[i].setId(copyFrom.m_array[i].getId());
		this->m_array[i].setTitle(copyFrom.m_array[i].getTitle());
		this->m_array[i].setDescription(copyFrom.m_array[i].getDescription());
		this->m_array[i].setType(copyFrom.m_array[i].getTypeType());
		this->m_array[i].setPriority(copyFrom.m_array[i].getPriority());
		this->m_array[i].setStatus(copyFrom.m_array[i].getStatusStatus());
		this->m_array[i].setCreateDateFile(copyFrom.m_array[i].getCreateDate().month, copyFrom.m_array[i].getCreateDate().day, copyFrom.m_array[i].getCreateDate().year);
		this->m_array[i].setDueDate(copyFrom.m_array[i].getDueDate().month, copyFrom.m_array[i].getDueDate().day, copyFrom.m_array[i].getDueDate().year);
		this->m_array[i].setModifiedDateFile(copyFrom.m_array[i].getModifiedDate().month, copyFrom.m_array[i].getModifiedDate().day, copyFrom.m_array[i].getModifiedDate().year);
	}
}

//Merge 
void ToDoList::merge(ToDoList& merge)
{
	for (int i = 0; i < merge.m_positionOfItems; i++)
	{
		this->m_array[m_positionOfItems].setId(merge.m_array[i].getId());
		this->m_array[m_positionOfItems].setTitle(merge.m_array[i].getTitle());
		this->m_array[m_positionOfItems].setDescription(merge.m_array[i].getDescription());
		this->m_array[m_positionOfItems].setType(merge.m_array[i].getTypeType());
		this->m_array[m_positionOfItems].setPriority(merge.m_array[i].getPriority());
		this->m_array[m_positionOfItems].setStatus(merge.m_array[i].getStatusStatus());
		this->m_array[m_positionOfItems].setCreateDateFile(merge.m_array[i].getCreateDate().month, merge.m_array[i].getCreateDate().day, merge.m_array[i].getCreateDate().year);
		this->m_array[m_positionOfItems].setDueDate(merge.m_array[i].getDueDate().month, merge.m_array[i].getDueDate().day, merge.m_array[i].getDueDate().year);
		this->m_array[m_positionOfItems].setModifiedDateFile(merge.m_array[i].getModifiedDate().month, merge.m_array[i].getModifiedDate().day, merge.m_array[i].getModifiedDate().year);
		m_positionOfItems++;
	}
}

//Clone
void ToDoList::clone(ToDoList& clone)
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		this->m_array[i].setId(clone.m_array[i].getId());
		this->m_array[i].setTitle(clone.m_array[i].getTitle());
		this->m_array[i].setDescription(clone.m_array[i].getDescription());
		this->m_array[i].setType(clone.m_array[i].getTypeType());
		this->m_array[i].setPriority(clone.m_array[i].getPriority());
		this->m_array[i].setStatus(clone.m_array[i].getStatusStatus());
		this->m_array[i].setCreateDateFile(clone.m_array[i].getCreateDate().month, clone.m_array[i].getCreateDate().day, clone.m_array[i].getCreateDate().year);
		this->m_array[i].setDueDate(clone.m_array[i].getDueDate().month, clone.m_array[i].getDueDate().day, clone.m_array[i].getDueDate().year);
		this->m_array[i].setModifiedDateFile(clone.m_array[i].getModifiedDate().month, clone.m_array[i].getModifiedDate().day, clone.m_array[i].getModifiedDate().year);
		this->m_positionOfItems = clone.m_positionOfItems;
	}
}

void ToDoList::printTestingThings()
{

	if (m_positionOfItems == 0)
	{
		cout << NEWLINE << "You currently have 0 to-do items" << NEWLINE;
	}
	else {
		//Printing the "Menu"
		cout << NEWLINE << NEWLINE;
		cout << left << setw(3) << "ID" << "|"
			<< left << setw(20) << "Title" << "|"
			<< left << setw(50) << "Description" << "|"
			<< left << setw(10) << "Type" << "|"
			<< left << setw(10) << "Priority" << "|"
			<< left << setw(12) << "Status" << "|"
			<< left << setw(11) << "Create Date" << "|"
			<< left << setw(11) << "Due Date" << "|"
			<< left << setw(11) << "Last Modified Date";
		cout << NEWLINE << NEWLINE;

		for (int i = 0; i < m_positionOfItems; i++)
		{
			//Id
			cout << left << setw(3) << m_array[i].getId() << "|"
				<< left << setw(20) << m_array[i].getTitle() << "|"
				<< left << setw(50) << m_array[i].getDescription() << "|"
				<< left << setw(10) << m_array[i].getType() << "|"
				<< left << setw(10) << m_array[i].getPriority() << "|"
				<< left << setw(12) << m_array[i].getStatus() << "|"
				<< left << setw(3) << m_array[i].getCreateDate().month << left << setw(3) << m_array[i].getCreateDate().day << left << setw(5) << m_array[i].getCreateDate().year << "|"
				<< left << setw(3) << m_array[i].getDueDate().month << left << setw(3) << m_array[i].getDueDate().day << left << setw(5) << m_array[i].getDueDate().year << "|"
				<< left << setw(3) << m_array[i].getModifiedDate().month << left << setw(3) << m_array[i].getModifiedDate().day << left << setw(5) << m_array[i].getModifiedDate().year;
			cout << endl;
		}
	} 
	cout << endl;
}

void ToDoList::printByType(string t)
{
	if (m_positionOfItems == 0)
	{
		cout << NEWLINE << "You currently have 0 to-do items" << NEWLINE;
	}
	else {
		//Printing the "Menu"
		cout << NEWLINE << NEWLINE;
		cout << left << setw(3) << "ID" << "|"
			<< left << setw(20) << "Title" << "|"
			<< left << setw(50) << "Description" << "|"
			<< left << setw(10) << "Type" << "|"
			<< left << setw(10) << "Priority" << "|"
			<< left << setw(12) << "Status" << "|"
			<< left << setw(11) << "Create Date" << "|"
			<< left << setw(11) << "Due Date" << "|"
			<< left << setw(11) << "Last Modified Date";
		cout << NEWLINE << NEWLINE;

		for (int i = 0; i < m_positionOfItems; i++)
		{
			if (m_array[i].getType().compare(t) == 0) {
				cout << left << setw(3) << m_array[i].getId() << "|"
					<< left << setw(20) << m_array[i].getTitle() << "|"
					<< left << setw(50) << m_array[i].getDescription() << "|"
					<< left << setw(10) << m_array[i].getType() << "|"
					<< left << setw(10) << m_array[i].getPriority() << "|"
					<< left << setw(12) << m_array[i].getStatus() << "|"
					<< left << setw(3) << m_array[i].getCreateDate().month << left << setw(3) << m_array[i].getCreateDate().day << left << setw(5) << m_array[i].getCreateDate().year << "|"
					<< left << setw(3) << m_array[i].getDueDate().month << left << setw(3) << m_array[i].getDueDate().day << left << setw(5) << m_array[i].getDueDate().year << "|"
					<< left << setw(3) << m_array[i].getModifiedDate().month << left << setw(3) << m_array[i].getModifiedDate().day << left << setw(5) << m_array[i].getModifiedDate().year;
			}
			cout << endl;
		}
	}
	cout << endl;
}

void ToDoList::printByPriority(int pNum)
{
	if (m_positionOfItems == 0)
	{
		cout << NEWLINE << "You currently have 0 to-do items" << NEWLINE;
	}
	else {
		//Printing the "Menu"
		cout << NEWLINE << NEWLINE;
		cout << left << setw(3) << "ID" << "|"
			<< left << setw(20) << "Title" << "|"
			<< left << setw(50) << "Description" << "|"
			<< left << setw(10) << "Type" << "|"
			<< left << setw(10) << "Priority" << "|"
			<< left << setw(12) << "Status" << "|"
			<< left << setw(11) << "Create Date" << "|"
			<< left << setw(11) << "Due Date" << "|"
			<< left << setw(11) << "Last Modified Date";
		cout << NEWLINE << NEWLINE;

		for (int i = 0; i < m_positionOfItems; i++)
		{
			if (m_array[i].getPriority() == pNum) {
				cout << left << setw(3) << m_array[i].getId() << "|"
					<< left << setw(20) << m_array[i].getTitle() << "|"
					<< left << setw(50) << m_array[i].getDescription() << "|"
					<< left << setw(10) << m_array[i].getType() << "|"
					<< left << setw(10) << m_array[i].getPriority() << "|"
					<< left << setw(12) << m_array[i].getStatus() << "|"
					<< left << setw(3) << m_array[i].getCreateDate().month << left << setw(3) << m_array[i].getCreateDate().day << left << setw(5) << m_array[i].getCreateDate().year << "|"
					<< left << setw(3) << m_array[i].getDueDate().month << left << setw(3) << m_array[i].getDueDate().day << left << setw(5) << m_array[i].getDueDate().year << "|"
					<< left << setw(3) << m_array[i].getModifiedDate().month << left << setw(3) << m_array[i].getModifiedDate().day << left << setw(5) << m_array[i].getModifiedDate().year;
			}
			cout << endl;
		}
	}
	cout << endl;
}

void ToDoList::printById(int idNum)
{
	if (m_positionOfItems == 0)
	{
		cout << NEWLINE << "You currently have 0 to-do items" << NEWLINE;
	}
	else {
		//Printing the "Menu"
		cout << NEWLINE << NEWLINE;
		cout << left << setw(3) << "ID" << "|"
			<< left << setw(20) << "Title" << "|"
			<< left << setw(50) << "Description" << "|"
			<< left << setw(10) << "Type" << "|"
			<< left << setw(10) << "Priority" << "|"
			<< left << setw(12) << "Status" << "|"
			<< left << setw(11) << "Create Date" << "|"
			<< left << setw(11) << "Due Date" << "|"
			<< left << setw(11) << "Last Modified Date";
		cout << NEWLINE << NEWLINE;

		for (int i = 0; i < m_positionOfItems; i++)
		{
			if (m_array[i].getId() == idNum) {
				cout << left << setw(3) << m_array[i].getId() << "|"
					<< left << setw(20) << m_array[i].getTitle() << "|"
					<< left << setw(50) << m_array[i].getDescription() << "|"
					<< left << setw(10) << m_array[i].getType() << "|"
					<< left << setw(10) << m_array[i].getPriority() << "|"
					<< left << setw(12) << m_array[i].getStatus() << "|"
					<< left << setw(3) << m_array[i].getCreateDate().month << left << setw(3) << m_array[i].getCreateDate().day << left << setw(5) << m_array[i].getCreateDate().year << "|"
					<< left << setw(3) << m_array[i].getDueDate().month << left << setw(3) << m_array[i].getDueDate().day << left << setw(5) << m_array[i].getDueDate().year << "|"
					<< left << setw(3) << m_array[i].getModifiedDate().month << left << setw(3) << m_array[i].getModifiedDate().day << left << setw(5) << m_array[i].getModifiedDate().year;
			}
			cout << endl;
		}
	}
	cout << endl;
}

/* 
* Ask the user to enter the attributes
* for to-do item and then insert the to-do item
* to the bottom of the list
*/
void ToDoList::addItem(string title, string description, type t, int priority, status s, int month, int day, int year)
{
	//Title
	m_array[m_positionOfItems].setTitle(title);
	//Description
	m_array[m_positionOfItems].setDescription(description);
	//Type
	m_array[m_positionOfItems].setType(t);
	//Priority
	m_array[m_positionOfItems].setPriority(priority);
	//Status
	m_array[m_positionOfItems].setStatus(s);
	//Create date - no user input
	m_array[m_positionOfItems].setCreateDate();
	//Due date
	m_array[m_positionOfItems].setDueDate(month, day, year);
	//Last modified date - no user input
	m_array[m_positionOfItems].setModifiedDate();
	//Increment of position
	m_positionOfItems++;
}

/*
* Ask the user which attribute
* to edit and then make the change
* to the existing to-do item
*/
void ToDoList::editItemId(int id, int edit)
{
	if (id < m_positionOfItems)
	{
		if (edit == 0)
		{
			//Title
			string title;
			cout << "Please enter the new title" << NEWLINE;
			cin.ignore();
			getline(cin, title);
			m_array[id].setTitle(title);

		}
		else if (edit == 1)
		{
			//Description
			string description;
			cout << "Please enter the new description" << NEWLINE;
			cin.ignore();
			getline(cin, description);
			m_array[id].setDescription(description);
		}
		else if (edit == 2)
		{
			//Type
			int userInput;
			cout << "Enter the type of work by integer : Shopping = 0, Housing = 1, Work = 2" << NEWLINE;
			cin >> userInput;
			cout << NEWLINE;
			type usertype = static_cast<type>(userInput);
			m_array[id].setType(usertype);
		}
		else if (edit == 3)
		{
			//Priority
			int priority;
			cout << "Please enter the priority number 1 through 5" << NEWLINE;
			cin >> priority;
			m_array[id].setPriority(priority);
		}
		else if (edit == 4)
		{
			//Status
			int userInput;
			cout << "Enter the status by integer : Done = 0, InProgress = 1, Hold = 2" << NEWLINE;
			cin >> userInput;
			cout << NEWLINE;
			status userstatus = static_cast<status>(userInput);
			m_array[id].setStatus(userstatus);
		}
		else if (edit == 5)
		{
			//Due date
			int month;
			int day;
			int year;
			cout << "Please enter the month, day, and year for the due date like so : MM DD YYYY" << NEWLINE;
			cin >> month >> day >> year;
			m_array[id].setDueDate(month, day, year);
		}
		else
		{
			cout << "Invalid input : You tried to change a non-existing attribute" << NEWLINE;
		}
	}
	else
	{
		cout << "Invalid input : You tried to choose from a non-existing id" << NEWLINE;
	}
	
	//Last modified date - no user input
	m_array[id].setModifiedDate();
}

void ToDoList::deleteItemId(int id)
{
	//Delete by swapping to-do items
	for (int i = 0; i < m_positionOfItems - id; i++)
	{
		m_array[id + i] = m_array[id + i + 1];
	}
	m_positionOfItems--;
	//Re-set the id
	for (int x = 0; x < MAX_SIZE; x++)
	{
		m_array[x].setId(x);
	}
}

void ToDoList::deleteItemType()
{
	//Type
	int userInput;
	cout << "Enter the type you would like to delete : Shopping = 0, Housing = 1, Work = 2" << NEWLINE;
	cin >> userInput;
	cout << NEWLINE;
	string toDelete;
	if (userInput == 0)
	{
		toDelete = "Shopping";
	}
	else if (userInput == 1)
	{
		toDelete = "Housing";
	}
	else if (userInput == 2)
	{
		toDelete = "Work";
	}
	int temp = m_positionOfItems;
	for (int i = 0; i < temp; i++)
	{
		//If the strings are equal...
		//Compare returns 0 if equal
		if (toDelete.compare(m_array[i].getType()) == 0)
		{
			deleteItemId(m_array[i].getId());
		}
		
	}
	
}

void ToDoList::deleteItemStatus()
{
	//Status
	int userInput;
	cout << "Enter the type you would like to delete : Done = 0, InProgress = 1, Hold = 2" << NEWLINE;
	cin >> userInput;
	cout << NEWLINE;
	string toDelete;
	if (userInput == 0)
	{
		toDelete = "Done";
	}
	else if (userInput == 1)
	{
		toDelete = "InProgress";
	}
	else if (userInput == 2)
	{
		toDelete = "Hold";
	}
	int temp = m_positionOfItems;
	for (int i = 0; i < m_positionOfItems; i++)
	{
		//If the strings are equal...
		//Compare returns 0 if equal
		if (toDelete.compare(m_array[i].getStatus()) == 0)
		{
			deleteItemId(m_array[i].getId());
		}

	}
}

void ToDoList::writeToFile()
{
	
	ofstream outfile;
	outfile.open("writeToFile.txt");
	if (!outfile.is_open())
	{
		cout << "Error : File can not be opened";
	}
	/*Printing the "Menu"
	outfile << "ID" << ","
		<< "Title" << ","
		<<  "Description" << ","
		<<  "Type" << ","
		<<  "Priority" << ","
		<<  "Status" << ","
		<<  "Create Date" << ","
		<<  "Due Date" << ","
		<<  "Last Modified Date";
	outfile << NEWLINE << NEWLINE;*/

	for (int i = 0; i < m_positionOfItems; i++)
	{
		outfile << m_array[i].getId() << ","
			<< m_array[i].getTitle() << ","
			<< m_array[i].getDescription() << ","
			<< m_array[i].getType() << ","
			<< m_array[i].getPriority() << ","
			<< m_array[i].getStatus() << ",";
	    //CREATE DATE
		if (m_array[i].getCreateDate().month < 10)
		{
			outfile << "0";
		}
		outfile << m_array[i].getCreateDate().month;

		if (m_array[i].getCreateDate().day < 10)
		{
			outfile << "0";
		}
		outfile << m_array[i].getCreateDate().day << m_array[i].getCreateDate().year << ",";
		//DUE DATE
		if (m_array[i].getDueDate().month < 10)
		{
			outfile << "0";
		}
		outfile << m_array[i].getDueDate().month;

		if (m_array[i].getDueDate().day < 10)
		{
			outfile << "0";
		}
		outfile << m_array[i].getDueDate().day << m_array[i].getDueDate().year << ",";
		//MODIFIED DATE
		if (m_array[i].getModifiedDate().month < 10)
		{
			outfile << "0";
		}
		outfile << m_array[i].getModifiedDate().month;

		if (m_array[i].getModifiedDate().day < 10)
		{
			outfile << "0";
		}
		outfile << m_array[i].getModifiedDate().day << m_array[i].getModifiedDate().year;

		outfile << NEWLINE;
	}
	outfile.close();
}

void ToDoList::readFromFile()
{
	ifstream infile;
	infile.open("writeToFile.txt");
	if (!infile.is_open())
	{
		cout << "Error : File can not be opened";
	}
	cout << "Reading from the file" << endl;
	//Resets items to zero
	m_positionOfItems = 0;
	//while (!infile.eof())
	//{
		string getId;
		string title;
		string description;
		string typeString;
		string priority;
		string statusString;
		string createDate;
		string dueDate;
		string lastModifiedDate;
		string extra;
		string line;
		
		while (getline(infile, line)) {
			stringstream ss(line);
			getline(ss, getId, ',');
			getline(ss, title, ',');
			getline(ss, description, ',');
			getline(ss, typeString, ',');
			getline(ss, priority, ',');
			getline(ss, statusString, ',');
			getline(ss, createDate, ',');
			getline(ss, dueDate, ',');
			getline(ss, lastModifiedDate, ',');
			//getline(infile, extra, '\n');
			//infile.ignore(10000, '\n');
			//cout << endl;


		//TYPE
			int typeInt = 0;
			if (typeString.compare("Shopping") == 0)
			{
				typeInt = 0;
			}
			else if (typeString.compare("Housing") == 0)
			{
				typeInt = 1;
			}
			else if (typeString.compare("Work") == 0)
			{
				typeInt = 2;
			}
			type filetype = static_cast<type>(typeInt);
			//PRIORITY
			int priorityPass = std::atoi(priority.c_str());
			//STATUS
			int statusInt = 0;
			if (statusString.compare("Done") == 0)
			{
				statusInt = 0;
			}
			else if (statusString.compare("InProgress") == 0)
			{
				statusInt = 1;
			}
			else if (statusString.compare("Hold") == 0)
			{
				statusInt = 2;
			}
			status filestatus = static_cast<status>(statusInt);

			//DATES

			int createDateMonth = std::atoi(createDate.substr(0, 2).c_str());
			int createDateDay = std::atoi(createDate.substr(2, 2).c_str());
			int createDateYear = std::atoi(createDate.substr(4, 4).c_str());

			int dueDateMonth = std::atoi(dueDate.substr(0, 2).c_str());
			int dueDateDay = std::atoi(dueDate.substr(2, 2).c_str());
			int dueDateYear = std::atoi(dueDate.substr(4, 4).c_str());

			int modifiedDateMonth = std::atoi(lastModifiedDate.substr(0, 2).c_str());
			int modifiedDateDay = std::atoi(lastModifiedDate.substr(2, 2).c_str());
			int modifiedDateYear = std::atoi(lastModifiedDate.substr(4, 4).c_str());

			//addItem(string title, string description, type t, int priority, status s, int month, int day, int year)

			m_array[m_positionOfItems].setCreateDateFile(createDateMonth, createDateDay, createDateYear);
			m_array[m_positionOfItems].setModifiedDateFile(modifiedDateMonth, modifiedDateDay, modifiedDateYear);

			addItem(title, description, filetype, priorityPass, filestatus, dueDateMonth, dueDateDay, dueDateYear);
			//m_positionOfItems++;
		}
	//}

	infile.close();
}

void ToDoList::swapItems(int one, int two)
{
	ToDo temp;
	//ID 
	/*
	temp.setId(m_array[one].getId());
	m_array[one].setId(m_array[two].getId());
	m_array[two].setId(temp.getId());*/
	//Title
	temp.setTitle(m_array[one].getTitle());
	m_array[one].setTitle(m_array[two].getTitle());
	m_array[two].setTitle(temp.getTitle());
	//Description
	temp.setDescription(m_array[one].getDescription());
	m_array[one].setDescription(m_array[two].getDescription());
	m_array[two].setDescription(temp.getDescription());
	//Priority
	temp.setPriority(m_array[one].getPriority());
	m_array[one].setPriority(m_array[two].getPriority());
	m_array[two].setPriority(temp.getPriority());
	//Type
	temp.setType(m_array[one].getTypeType());
	m_array[one].setType(m_array[two].getTypeType());
	m_array[two].setType(temp.getTypeType());
	//Status
	temp.setStatus(m_array[one].getStatusStatus());
	m_array[one].setStatus(m_array[two].getStatusStatus());
	m_array[two].setStatus(temp.getStatusStatus());
	//get month, day , and year
	//Create date
	temp.setCreateDateFile(m_array[one].getCreateDate().month, m_array[one].getCreateDate().day, m_array[one].getCreateDate().year);
	m_array[one].setCreateDateFile(m_array[two].getCreateDate().month, m_array[two].getCreateDate().day, m_array[two].getCreateDate().year);
	m_array[two].setCreateDateFile(temp.getCreateDate().month, temp.getCreateDate().day, temp.getCreateDate().year);

	//Due date
	temp.setDueDate(m_array[one].getDueDate().month, m_array[one].getDueDate().day, m_array[one].getDueDate().year);
	m_array[one].setDueDate(m_array[two].getDueDate().month, m_array[two].getDueDate().day, m_array[two].getDueDate().year);
	m_array[two].setDueDate(temp.getDueDate().month, temp.getDueDate().day, temp.getDueDate().year);

	//Modified Date
	temp.setModifiedDateFile(m_array[one].getModifiedDate().month, m_array[one].getModifiedDate().day, m_array[one].getModifiedDate().year);
	m_array[one].setModifiedDateFile(m_array[two].getModifiedDate().month, m_array[two].getModifiedDate().day, m_array[two].getModifiedDate().year);
	m_array[two].setModifiedDateFile(temp.getModifiedDate().month, temp.getModifiedDate().day, temp.getModifiedDate().year);

}

void ToDoList::sortByPriority()
{
	int i, j, min;
	for (i = 0; i < m_positionOfItems - 1; i++)
	{
		min = i;
		for (j = i + 1; j < m_positionOfItems; j++)
		{
			if (m_array[j].getPriority() < m_array[min].getPriority())
			{
				min = j;
			}
		}
		swapItems(i, min);
	}
}

void ToDoList::sortByDueDate()
{
	int i, j, min;
	for (i = 0; i < m_positionOfItems - 1; i++)
	{
		min = i;
		for (j = i + 1; j < m_positionOfItems; j++)
		{
			bool checkDates = false;
			if (m_array[j].getDueDate().month < m_array[min].getDueDate().month
				|| m_array[j].getDueDate().day < m_array[min].getDueDate().day
				|| m_array[j].getDueDate().year < m_array[min].getDueDate().year)
			{
				checkDates = true;
			}

			if (checkDates)
			{
				min = j;
			}
		}
		swapItems(i, min);
	}
}
void ToDoList::sortCreateDate()
{
	int i, j, min;
	for (i = 0; i < m_positionOfItems - 1; i++)
	{
		min = i;
		for (j = i + 1; j < m_positionOfItems; j++)
		{
			bool checkDates = false;
			if (m_array[j].getCreateDate().month < m_array[min].getCreateDate().month
				|| m_array[j].getCreateDate().day < m_array[min].getCreateDate().day
				|| m_array[j].getCreateDate().year < m_array[min].getCreateDate().year)
			{
				checkDates = true;
			}

			if (checkDates)
			{
				min = j;
			}
		}
		swapItems(i, min);
	}
}

void ToDoList::sortByTypePriority()
{
	//Shopping
	int check = 0;
	int checkShop = 0;
	int i;
	for (i = 0; i < m_positionOfItems; i++)
	{
		if (m_array[i].getType().compare("Shopping") == 0)
		{
			swapItems(check, i);
			check++;
			checkShop++;
		}
	}
	//Housing
	int j;
	int checkHousing = checkShop;
	for (j = check; j < m_positionOfItems; j++)
	{
		if (m_array[j].getType().compare("Housing") == 0)
		{
			swapItems(check, j);
			check++;
			checkHousing++;
		}
	}
	//Work
	int k;
	int checkWork = checkHousing;
	for (k = check; k < m_positionOfItems; k++)
	{
		if (m_array[k].getType().compare("Work") == 0)
		{
			swapItems(check, k);
			check++;
			checkWork++;
		}
	}
	//PRIORITY
	//Shopping
	int shopPosition = 0;
	int x, m, min_one;
	for (x = 0; x < checkShop - 1; x++)
	{
		min_one = x;
		for (m = x + 1; m < checkShop; m++)
		{
			if (m_array[m].getPriority() < m_array[min_one].getPriority())
			{
				min_one = m;
			}
		}
		swapItems(x, min_one);
	}
	//Housing
	int y, n, min_two;
	for (y = checkShop + 1; y < checkHousing - 1; y++)
	{
		min_two = y;
		for (n = y + 1; n < checkHousing; n++)
		{
			if (m_array[n].getPriority() < m_array[min_two].getPriority())
			{
				min_two = n;
			}
		}
		swapItems(y, min_two);
	}
	//Work
	int z, p, min_three;
	for (z = checkHousing + 1; z < checkWork - 1; z++)
	{
		min_three = z;
		for (p = z + 1; p < checkWork; p++)
		{
			if (m_array[p].getPriority() < m_array[min_three].getPriority())
			{
				min_three = p;
			}
		}
		swapItems(z, min_three);
	}
}

void ToDoList::sortByTypeDueDate()
{
	//Shopping
	int check = 0;
	int checkShop = 0;
	int i;
	for (i = 0; i < m_positionOfItems; i++)
	{
		if (m_array[i].getType().compare("Shopping") == 0)
		{
			swapItems(check, i);
			check++;
			checkShop++;
		}
	}
	//Housing
	int j;
	int checkHousing = checkShop;
	for (j = check; j < m_positionOfItems; j++)
	{
		if (m_array[j].getType().compare("Housing") == 0)
		{
			swapItems(check, j);
			check++;
			checkHousing++;
		}
	}
	//Work
	int k;
	int checkWork = checkHousing;
	for (k = check; k < m_positionOfItems; k++)
	{
		if (m_array[k].getType().compare("Work") == 0)
		{
			swapItems(check, k);
			check++;
			checkWork++;
		}
	}
	//PRIORITY
	//Shopping
	int shopPosition = 0;
	int x, m, min_one;
	for (x = 0; x < checkShop - 1; x++)
	{
		min_one = x;
		for (m = x + 1; m < checkShop; m++)
		{
			bool checkDates = false;
			if (m_array[m].getDueDate().month < m_array[min_one].getDueDate().month
				|| m_array[m].getDueDate().day < m_array[min_one].getDueDate().day
				|| m_array[m].getDueDate().year < m_array[min_one].getDueDate().year)
			{
				checkDates = true;
			}

			if (checkDates)
			{
				min_one = m;
			}
		}
		swapItems(x, min_one);
	}
	//Housing
	int y, n, min_two;
	for (y = checkShop; y < checkHousing - 1; y++)
	{
		min_two = y;
		for (n = y + 1; n < checkHousing; n++)
		{
			bool checkDates = false;
			if (m_array[n].getDueDate().month < m_array[min_two].getDueDate().month
				|| m_array[n].getDueDate().day < m_array[min_two].getDueDate().day
				|| m_array[n].getDueDate().year < m_array[min_two].getDueDate().year)
			{
				checkDates = true;
			}

			if (checkDates)
			{
				min_two = n;
			}
		}
		swapItems(y, min_two);
	}
	//Work
	int z, p, min_three;
	for (z = checkHousing; z < checkWork - 1; z++)
	{
		min_three = z;
		for (p = z + 1; p < checkWork; p++)
		{
			bool checkDates = false;
			if (m_array[p].getDueDate().month < m_array[min_three].getDueDate().month
				|| m_array[p].getDueDate().day < m_array[min_three].getDueDate().day
				|| m_array[p].getDueDate().year < m_array[min_three].getDueDate().year)
			{
				checkDates = true;
			}

			if (checkDates)
			{
				min_three = p;
			}
		}
		swapItems(z, min_three);
	}

}