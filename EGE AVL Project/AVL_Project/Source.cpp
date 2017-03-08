//Disclaimer:
// I Edison have not used any code other than my own(or that in the textbook) for this project.
// I also have not used any function or data - structure from the Standard - Template Library.
// I also have not shared my code with any student in this class
// I understand that any violation of this disclaimer will result in a 0 for the project.

//Source.cpp File
//Purpose: Driver for program that was mostly given by instructor

//CS 2420
//Instructor: Todd Peterson
//Class: CS 2420
//Section: 001
//Name: Edison Gray Earnest
//Project: AVL Tree Project
//Date: 3/25/2016

#include <string>
#include <iostream>
#include "AVL_Tree.h"

using namespace std;


// PROTOTYPES for functions used by this test program:
void print_menu();
// Postcondition: A menu of choices for this program has been written to cout.

char get_user_command();
// Postcondition: The user has been prompted to enter a one character command.
// The next character has been read (skipping blanks and newline characters), 
// and this character has been returned.


int get_number();
// Postcondition: The user has been prompted to enter a real number. The
// number has been read, echoed to the screen, and returned by the function.




int main()
{
	AVL_Tree test; // A Binary tree object that we’ll perform tests on
	char choice;   // A command character entered by the user

				   //function has been updated to support new keys from it's reuse of the sequence program
	do
	{
		print_menu();
		choice = toupper(get_user_command());
		switch (choice)
		{
		case 'U': test.InOrder();
			break;
			//case 'A': print_all(test);
			break;
		case 'S': cout << test.Size();
			break;
			//case 'O': test.PostOrder();
			//	break;
		case 'P': test.Print();
			break;
		case 'I': test.Insert(get_number());
			break;
		case 'D': {
			test.Erase(get_number());
			cout << "The integar was removed from the Binary tree" << endl;
		}
				  break;
		case 'Q': cout << "Program Terminating" << endl;
			break;
		default:  cout << choice << " is invalid." << endl;
		}
	} while ((choice != 'Q'));

	return EXIT_SUCCESS;
}

//print menu was taken from sequence class, and updated so that it works with this program
void print_menu()
// Library facilities used: iostream.h
{
	cout << endl; // Print blank line before the menu
	cout << "\nThe following choices are available: " << endl;
	cout << " I   Insert a number" << endl;
	cout << " D   Delete a number if it exists" << endl;
	cout << " P   Print Binary Tree" << endl;
	//cout << " A   Print All Traversals" << endl;
	//cout << " R   Print the Pre-Order Traversals" << endl;
	cout << " U   Print the In-Order Traversals" << endl;
	//cout << " O   Print the Post-Order Traversals" << endl;
	cout << " S   Print the Size of the Binary Tree" << endl;
	cout << " Q   Quit this test program" << endl;
}

char get_user_command()
// Library facilities used: iostream
{
	char command;

	cout << "Enter choice: ";
	cin >> command; // Input of characters skips blanks and newline character
	cout << "\n";
	return command;
}



int get_number()
// Library facilities used: iostream
{
	int result;

	cout << "Please enter a real number for the sequence: ";
	cin >> result;
	cout << result << " has been read." << endl;
	return result;
}
