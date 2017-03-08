#include "BinarySearchTree.h"
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
	BinarySearchTree test;	// A Binary Search Tree that we’ll perform tests on
	char choice;	// A command character entered by the user
	bool hide = false;
	int sleeptime = 100;

	cout << "Initializing root node for empty Binary Search Tree";

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
			case 'P': test.Print();
				break;

			case 'S': cout << "Size is " << test.Size() << '.' << endl;
				break;

			case 'I': test.Insert(get_number());
				break;

			case 'E': test.Erase(get_number());
				cout << "All instances of the specified number have been Erased." << endl;
				break;

			case '<': cout << "Pre-Order Print: " << endl;
				test.PreOrderPrint();
				break;

			case '^': cout << "In-Order Print: " << endl;
				test.InOrderPrint();
				break;

			case '>': cout << "Post-Order Print: " << endl;
				test.PostOrderPrint();
				break;

			case 'H': if (hide == false) { hide = true; cout << "Menu has been disabled. (OFF)" << endl; }
					  else { hide = false; cout << "Menu has been enabled. (ON)" << endl; }
					  break;

			case 'Q': cout << "\n Ridicule is the best test of truth." << endl;
				Sleep(sleeptime*2);
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
	cout << "\n P   Print out the entire Binary Search Tree" << endl;
	cout << " S   Print the result from the Size() function" << endl;

	cout << "\n I   Insert a new number with the Insert(#) function" << endl;
	cout << " E   Erase a number with the Erase(#) function" << endl;

	cout << "\n <   Activate the PreOrder() function" << endl;
	cout << " ^   Activate the InOrder() function" << endl;
	cout << " >   Activate the PostOrder() function" << endl;

	cout << "\n H   Hide the menu" << endl;
	cout << " Q   Quit this test program" << endl;
}

/*	Class Functions :
		Constructor/Destructor

		Size/Count
		Print

		Erase
		Insert

		3 Traversals:
			Pre-Order
			In-Order
			Post-Order
*/

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

	cout << "Please enter a real number for the Binary Search Tree: ";
	cin >> result;
	cout << result << " has been read." << endl;
	return result;
}