#pragma once

#include <iostream>
#include <ostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

#include "Node.h"
#include "List.h"

using namespace list;
using namespace std;

/*	Documentation (10 pts)
		Student name, Section and Disclaimer
		Proper function and class headers

	Hash Table (35 pts)
		Constructor

		Clear
		Insert
		Retrieve
		Hash
		Overloaded [ ] operator (retrieve)

	Driver (45 pts)
		Read in weights (store in hash table)
		Compute molecular weight of molecules (read from file)
		Print formulas	and molecular weights */



/*	Hash Table
		Create a hash table that is suitable for this project, complete with:
			・Constructor
			・Clear (remove all from hash table)
			・Insert (including a good hash function (not a simple modulus))
				o	Must resolve collisions
			・Retrieve
			・Hash function (something other than simple modulus)
			・Overloaded [ ] operator that works as a retrieve (not insert)
			・Your hash table should be smaller than the number of entries
				o	To ensure collisions

		Use chaining to resolve collisions.
			o	This will require a linked list structure.
			o	You may use the one you created in a previous lab or create one from scratch */




// Hash Table:
/// Purpose: Test the Hash() function.
/// Parameters: HashTable reference
/// Returns: void
/// Pre-Conditions: HashTable object must be declared first.
/// Post-Conditions: 
class HashTable
{
	public:
		const static int CAPACITY = 50;

		HashTable(); // Constructor
		virtual ~HashTable(); // Destructor

		int Hash(string);
		void Insert(string, double, int);
		void Clear();
		double Retrieve(string);
		double operator [](string);
		Node* operator [](int);

	private:
		List elementListArray[CAPACITY];
		Node* _element;
		int _used;
};

// ---------------------------------------------------------------------------------------------------------------------

/*	S.I. Session (4/4/2016):

	Hash Table Methods:

	insert(key, value);
	get/at(key);
	delete(key);

	hash(key) => index
	hash = sum of characters
	index = hash % size;

	load_factor = items / slots;

	Bob = 66 + 79 + 66 = 211

	Q:	What does a hash table do?
	A:	The key is the parameter, and it returns an index.
			hash (key) => index

	* Seperate Chaining:
		- linked lists (easiest)
		- head cells
		- any other sturcture
	
	* Open Addressing:
		- linear probing (next slot in sequence)
		- quadradic probing (2, 4, 8, 16)
		- double hashing

	- clustering:
		Items are more likely to use multiple data slots at once.
			(not a big deal with seperate chaining, but matters a lot with open addressing)
	
	- uniform:
		Items are spread out accross the table.

	Open Addressing is when all items are stored in the array itself.

	Delete specific entry with chaining:
		go to the correct index and ensure the key matches.
		delete the entry
		set the pointer to point to the next node.
*/

// ---------------------------------------------------------------------------------------------------------------------

/*	S.I. Session (4/6/2016):
	
	Q:	What does a hash table do?
	A: A hashing algorithm returns an index when given a key. The key can be anything (a name, a number, etc.).
		hash (key) => index

	1.	Change key into a number (if it isn't one already).
	2.	Restrict number into an index of an array of a given size.
		Example: % n

	For quadradic probing, "size" should be a prime number, or 4 * n + 3;

	For double hashing, you actually use a different hashing algorithm.

	Load Factor (page 617 - 618):
		int LF = _used / CAPACITY;



	------

	string str;
	int sum;

	for (char a : str)
	{

	}
*/