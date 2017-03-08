 #pragma once

#include "Node.h"

#include <cstdlib>
#include <iostream>
#include <ostream>

using namespace std;

namespace list
{
	struct List
	{
		List(){ head = nullptr; } /// Constructor
		~List(); /// Destructor

		void addEnd(string, double);
		void print();
		void insert(string, double);
		bool find (string);
		int size();

		// Helper Functions:
		void destroy(Node *n);
		void addEnd_helper(Node*&, Node*&);
		void print_helper(Node*);
		void insert_helper(Node*, string, double);
		bool find_helper(Node*, string);
		int size_helper(Node*);

		Node* head;
	};
}