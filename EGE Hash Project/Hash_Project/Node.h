
//Disclaimer:
// I Edison have not used any code other than my own(or that in the textbook) for this project.
// I also have not used any function or data - structure from the Standard - Template Library.
// I also have not shared my code with any student in this class
// I understand that any violation of this disclaimer will result in a 0 for the project.

//Node.h File
//Purpose: header file for Node

//CS 2420
//Instructor: Todd Peterson
//Class: CS 2420
//Section: 001
//Name: Edison Gray Earnest
//Project: Hash Project
//Date: 4/14/2016

#include <iostream>
#include <string>

using namespace std;


#pragma once
class Node
{
public:
	//Node()
	//Purpose:inilizes program
	//Parameters:none
	//Returns:none
	Node();

	//Node(string _key, double _weight)
	//Purpose:parameterized constructor for program
	//Parameters:none
	//Returns:none
	Node(string _key, double _weight);

	//~Node()
	//Purpose:destructor for program
	//Parameters:none
	//Returns:none
	~Node();

	//variables
	Node * next;
	string key;
	double weight;

};

