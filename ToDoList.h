//#pragma once
#define _CRT_SECURE_NO_WARNINGS
#ifndef TODOLIST_H
#define TODOLIST_H
#include "ToDo.h"
#include <iostream>
#include <string>

//Max size constant 
#define MAX_SIZE 100

class ToDoList {
private:
	ToDo m_array[MAX_SIZE];
	int m_positionOfItems;

public: 
	//Constructor
	ToDoList();
	//Copy Constructor 
	ToDoList(ToDoList &copyFrom);
	//Merge
	void merge(ToDoList& merge);
	//Clone
	void clone(ToDoList& clone);
	//Printing
	void printTestingThings();
	void printByType(string t);
	void printByPriority(int pNum);
	void printById(int idNum);
	//Adding, edditing, and deleting
	void addItem(string title, string description, type t, int priority, status s, int month, int day, int year);
	void editItemId(int id, int edit);
	void deleteItemId(int id);
	void deleteItemType();
	void deleteItemStatus();
	//File functions
	void writeToFile();
	void readFromFile();
	//SORTS
	void swapItems(int one, int two);
	void sortByPriority();
	void sortByDueDate();
	void sortCreateDate();
	void sortByTypePriority();
	void sortByTypeDueDate();
};

#endif