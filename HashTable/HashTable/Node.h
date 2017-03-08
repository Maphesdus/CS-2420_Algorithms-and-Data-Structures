#pragma once

#include <iostream>
#include <ostream>
#include <string>

using namespace std;

namespace list
{
	/*struct Node
	{
		int data;
		Node* next;

		//Postcondition: Node data is initialized
		Node(int d)
		{
			data = d;
			next = nullptr;
		}
	};*/

	struct Node
	{
		string compound;
		double weight;
		Node *next;

		// Constructor (default):
		Node()
		{
			compound = string();
			weight = double();
			next = nullptr;
		}

		// Constructor (parameterized):
		Node(string key, double value)
		{
			compound = key;
			weight = value;
			next = nullptr;
		}
	};
}