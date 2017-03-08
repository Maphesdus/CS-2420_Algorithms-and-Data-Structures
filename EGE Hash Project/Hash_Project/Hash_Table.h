//Disclaimer:
// I Edison have not used any code other than my own(or that in the textbook) for this project.
// I also have not used any function or data - structure from the Standard - Template Library.
// I also have not shared my code with any student in this class
// I understand that any violation of this disclaimer will result in a 0 for the project.

//Hash_Table.h File
//Purpose: header file for Hash

//CS 2420
//Instructor: Todd Peterson
//Class: CS 2420
//Section: 001
//Name: Edison Gray Earnest
//Project: Hash Project
//Date: 4/14/2016

#include "Node.h"
#include <iostream>
#include <string>

using namespace std;


//declare constants and ascii number. Ascii numbers should help make finding out whether a character is a specific type (0-9, parenthesis/symbol, upper/lower case, etc)
const int PRIME_SIZE = 89;
const int ASCII_ZERO = 48;
const int ASCII_NINE = 57;

const int ASCII_LPARENTH = 40;
const int ASCII_RPARENTH = 41;

const int ASCII_LOWBEGIN = 97;
const int ASCII_LOWEND = 122;

const int ASCII_HIGHBEGIN = 65;
const int ASCII_HIGHEND = 90;


#pragma once
class Hash_Table
{
public:

	//Hash_Table()
	//Purpose:inilizes program
	//Parameters:none
	//Returns:none
	Hash_Table();

	//~Hash_Table()
	//Purpose:destructor for program - calls delete helper to finish deleting
	//Parameters:none
	//Returns:none
	~Hash_Table();

	//DeleteHelper()
	//Purpose:is given a node to traverse to and recursively finds the end, and deletes from the tail to the head.
	//Parameters:Node - recursively searches through nodes (node to node->next)
	//Returns:none
	void DeleteHelper(Node*& current);

	//Print()
	//Purpose:prints the Hash Array in a readable manner. Not currently implemented but can still be switched on later if needed
	//Parameters:none
	//Returns:none
	void Hash_Table::Print();

	//Insert()
	//Purpose:Insert finds the exact spot where a key can be used, and calls InsertHelper when avoiding collsions
	//Parameters:Key - the key that is turned into a hash, which weight is stored at
	//Returns:none
	void Insert(string key, double weight);

	//InsertHelper()
	//Purpose:Recursively searches through program to find the end of the node. This node is returned, so that the next collision is handled by adding it to the end.
	//Parameters:current -> the current node passed through, which will be traversed
	//Returns:Node* -> the node of the very end of the chain
	Node* InsertHelper(Node* current);

	//Clear()
	//Purpose:A function that acts similiar to a deconstructor, but replaces everything to nullptr (erasing hash)
	//Parameters:none
	//Returns:none
	void Clear();

	//Retrieve()
	//Purpose:is a function that can be given a key, and will return the correct atomic value of that key
	//Parameters:key - the string of the element
	//Returns:double - the atomic weight of the element
	double Retrieve(string key);

	//isKey()
	//Purpose:Not currently used, but returns bool (yes/true if the string given is a key, no/false if not)
	//Parameters:isKey - the sting that might be a key on the hash
	//Returns:bool - true if the key matches the an already created key on the hash table
	bool isKey(string key);

	//isNumber()
	//Purpose:simple calculation that compares ascii values which determiens whether or not the character passed in is a number.
	//Parameters:key - unknown character
	//Returns:returns true if key is a number. False if else.
	bool isNumber(char key);

	//isLeftPar()
	//Purpose:simple calculation that compares ascii values which determiens whether or not the character passed in is a left parenthesis.
	//Parameters:key - unknown character
	//Returns:returns true if key is a left parenthesis. False if else.
	bool isLeftPar(char key);

	//isRightPar()
	//Purpose:simple calculation that compares ascii values which determiens whether or not the character passed in is a right parenthesis.
	//Parameters:key - unknown character
	//Returns:returns true if key is a right parenthesis. False if else.
	bool isRightPar(char key);

	//isLowerCase()
	//Purpose:simple calculation that compares ascii values which determiens whether or not the character passed in is a lower case letter.
	//Parameters:key - unknown character
	//Returns:returns true if key is a lower case letter. False if else.
	bool isLowerCase(char key);

	//isUpperCase()
	//Purpose:simple calculation that compares ascii values which determiens whether or not the character passed in is an upper case letter.
	//Parameters:key - unknown character
	//Returns:returns true if key is a upper case letter. False if else.
	bool isUpperCase(char key);

	//Hash()
	//Purpose:takes a key, calls an ascii function, and then moduluses by a prime size. This creates a hash value that is returned as int, which is where the key is going to be stored.
	//Parameters:key - the key
	//Returns:int - the hash value for the key (sum of the keys ascii values squared)
	int Hash(string key);

	//calcAscii()
	//Purpose:finds ascii value for a, then squares it before returning. This helps the array be more spread out
	//Parameters:char a - the character that is to be converted to ascii
	//Returns:int - the ascii value of a squared
	int calcAscii(char a);

	//operator[]
	//Purpose:overloads [] so that --> hash_object[KEY] = atomic weight.
	//Parameters:iKey - the key that we are retrieving the atomic weight from
	//Returns:double - the atomic weight
	double operator[](string iKey);
	
	Node** HashArray;
};

