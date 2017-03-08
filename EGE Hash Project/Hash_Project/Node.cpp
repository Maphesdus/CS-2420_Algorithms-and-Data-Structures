//Disclaimer:
// I Edison have not used any code other than my own(or that in the textbook) for this project.
// I also have not used any function or data - structure from the Standard - Template Library.
// I also have not shared my code with any student in this class
// I understand that any violation of this disclaimer will result in a 0 for the project.

//Node.cpp File
//Purpose: Implementation file for Node class

//CS 2420
//Instructor: Todd Peterson
//Class: CS 2420
//Section: 001
//Name: Edison Gray Earnest
//Project: Hash Project
//Date: 4/14/2016

#include "Node.h"


//initializes next to null, and everything else to their null/default positions
Node::Node()
{
	next = nullptr;
	weight = 0;
	key = "";
}

//initializes Node to a key and weight, along with setting next to nullptr
Node::Node(string _key, double _weight)
{
	next = nullptr;
	weight = _weight;
	key = _key;

}

//not in use - nodes are handled by Hash_Table
Node::~Node()
{
}
