#pragma once
#include "AVLtree.h"

// NAME: Adam Armstrong
// SECTION: CS 2420 - 002
// PROFESSOR: Todd S. Peterson
// Due: 3/24/2016

// DISCLAIMER:
// I, Adam Armstrong, have not used any code other than my own (or that in the textbook) for this project.
// I also have not used any function or data-structure from the Standard-Template Library.
// I also have not shared my code with any student in this class.
// I understand that any violation of this disclaimer will result in a 0 for the project.

//	Project 08: AVL Tree

	/*	Testing
		•	Create an interactive testing harness that will allow you to insert elements and print the tree.
			This means that there is a menu and input and display options.
		•	Show the tabbed print function that we discussed in class and is in BST homework

		•	Test your algorithm by inserting the following sequences of integers
			o	They will require the tree to be balanced in different ways.

				?	10 15 20 25 30 35
				?	10 15 20 25 30 22
				?	35 30 25 20 15 10
				?	35 30 25 20 15 22
		•	The test by the grader may or may not use the above sequences of numbers.

		Note
		•	Start Early!
		•	The rebalance function looks straight-forward, but can be tricky to implement correctly.
		•	You need to update height after each insert and after each rotate.
			o	You should not adjust the height for every node in the tree, just those nodes visited in the insert function.

	*/


#include "AVLtree.h"
#include <Windows.h>
#include <cctype>	// Provides toupper
#include <iostream>	// Provides cout and cin
#include <cstdlib>	// Provides EXIT_SUCCESS
using namespace std;

void print_menu();
char get_user_command();
int get_number();

// main:
int main()

{
	AVLtree test;	// An AVL Tree that we’ll perform tests on
	char choice;	// A command character entered by the user
	bool hide = false;
	int sleeptime = 100;

	cout << "Initializing root node for empty AVL Tree";

	for (int i = 0; i < 3; i++)
	{
		Sleep(sleeptime);
		cout << ".";
	}

	cout << " Initalized." << endl;
	Sleep(sleeptime);

	do
	{
		if (hide == false)
			print_menu();
		choice = toupper(get_user_command());

		switch (choice)
		{
		case 'I': test.Insert(get_number());
			break;

		case 'P': test.Print();
			break;



		/*
		case 'L': cout << "RotateLeft: " << endl;
			test.RotateLeft();
			break;

		case 'R': cout << "RotateRight: " << endl;
			test.RotateLeft();
			break;

		case 'B': cout << "Rebalance: " << endl;
			test.Rebalance();
			break;

		case 'U': cout << "UpdateHeight: " << endl;
			test.UpdateHeight();
			break;
		*/



		case 'H': if (hide == false) { hide = true; cout << "Menu has been disabled. (OFF)" << endl; }
				  else { hide = false; cout << "Menu has been enabled. (ON)" << endl; }
				  break;

		case 'Q': cout << "\n Ridicule is the best test of truth." << endl;
			Sleep(sleeptime * 2);
			break;

		default:  cout << choice << " is invalid." << endl;
		}
	} while ((choice != 'Q'));

	return EXIT_SUCCESS;
}

// Print Menu:
void print_menu()
{
	cout << endl; // Print blank line before the menu
	cout << "\nThe following choices are available: " << endl;

	cout << "\n I   Insert a new number with the Insert(#) function" << endl;
	cout << " P   Print out the entire AVL Tree" << endl;

	//cout << "\n L   Rotate Left" << endl;
	//cout << " R   Rotate Right" << endl;
	//cout << " B   Rebalance" << endl;
	//cout << " U   Update Height" << endl;

	cout << "\n H   Hide/Unhide this menu" << endl;
	cout << " Q   Quit this test program" << endl;
}


// Get User Command:
char get_user_command()
{
	char command;

	cout << "\nEnter choice: ";
	cin >> command; // Input of characters skips blanks and newline character

	return command;
}

// Get Number:
int get_number()
{
	int result;

	cout << "Please enter a real number for the AVL Tree: ";
	cin >> result;
	cout << result << " has been read." << endl;
	return result;
}


// __________________
//	Swap (by pointer)
/// Purpose: Swap two integers.
/// Parameters: Two int pointers
/// Returns: void
/// Pre-Conditions: n/a
/// Post-Conditions: The two integer values have been swapped with each other.
void swap_pointers(int *a, int *b)
{
	int c = *a;
	*a = *b;
	*b = c;
}


// __________________
//	Swap (by reference)
/// Purpose: Swap two integers.
/// Parameters: Two int references
/// Returns: void
/// Pre-Conditions: n/a
/// Post-Conditions: The two integer values have been swapped with each other.
void swap_reference(int &a, int &b)
{
	int c = a;
	a = b;
	b = c;
}

//	NOTE:
///	References are exactly like pointers at the compiler level.
///	The only difference is that you don't have to dereference a reference like you do a poitner.
///	Deferencing is for finding a value at an address, rather than the address itself.