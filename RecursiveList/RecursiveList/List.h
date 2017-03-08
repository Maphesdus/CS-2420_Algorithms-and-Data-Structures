#pragma once

#include <cstdlib>
#include "Node.h"
#include <iostream>
using namespace std;

namespace list_2
{
	class List
	{
	public:
		// postcondition: list is initialized
		List(){ head = nullptr; } /// Constructor

		// postcondition: all nodes are destroyed using recursion
		~List(); /// Destructor

		// postcondition: add element d at the end of the list using recursion
		void addEnd(int d);

		// postcondition: print the list using recursion
		void print();

		// precondition: list is in sorted order (don't use addEnd with this function)
		// postcondition: d is inserted into the list so the list maintains sorted order using recursison.
		void insert(int d);

		// postcondition: if d is in the list then find returns true else find returns false
		bool find (int d);

		// postcondition: size is returned. Must be calculated using recursion.
		int size();

	private:
		Node *head;

		// helper function for the destructor
		void destroy(Node *n);

		// Add other helper functions here to complete your program.
		// They should all contain one or more Node* as parameters
		
		void addEnd_helper(Node*&, Node*&);
		void print_helper(Node*);
		void insert_helper(Node*, int);
		bool find_helper(Node*, int);
		int size_helper(Node*);
	};
}

/*
	EAll functions in the List class are to be created recursively or they are given no credit.
		o	This includes the Size() function.

	ECreate a List class with the following functions:
		o	Constructor
		o	Destructor : delete all nodes
			>	Use the destroy helper function
		o	print : use cout to print all nodes
		o	find : see if a value is in the list
		o	addEnd (value)
		o	insert(value)
			>	Only works if the list is already sorted.
			>	Consider passing in two Node* to your helper function as parameters.
			>	Does not work well with the addEnd function.
	
	ETest these separately
		o	Int Size()
			>	Must be computed recursively not stored.
		o	Any other helper functions that you need to create the above
			>	Hint: most if not all need helper functions with one or more Node* parameters.
*/