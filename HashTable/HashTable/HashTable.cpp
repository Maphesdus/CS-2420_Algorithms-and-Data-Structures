// NAME: Adam Armstrong
// SECTION: CS 2420 - 002
// PROFESSOR: Todd S. Peterson
// Due: 4/14/2016

// DISCLAIMER:
// I, Adam Armstrong, have not used any code other than my own (or that in the textbook) for this project.
// I also have not used any function or data-structure from the Standard-Template Library.
// I also have not shared my code with any student in this class.
// I understand that any violation of this disclaimer will result in a 0 for the project.

//	Project 10: Hash Table

		/*	Write a program that will read a molecular formula such as H2SO4 and
			will write out the molecular weight of the compound that it represents.
			Your program should be able to handle bracketed radicals such as in Al2(SO4)3.
			You will need to set up a hash table of atomic weights of elements, indexed by their abbreviations.
			Some elements have one-letter abbreviations, and some two.

			Hash Table
				Create a hash table that is suitable for this project, complete with
					o Constructor
					o Clear (remove all from hash table)
					o Insert (including a good hash function (not a simple modulus))
						o	Must resolve collisions
					o Retrieve
					o Hash function (something other than simple modulus)
					o Overloaded [ ] operator that works as a retrieve (not insert)
					o Your hash table should be smaller than the number of entries
						o	To ensure collisions

				Use chaining to resolve collisions.
					o	This will require a linked list structure.
					o	You may use the one you created in a previous lab or create one from scratch


			Atomic Weights
			o Create a file that contains all of the elements along with their atomic weight.
			o You can get this from any Periodic table. (www.webelements.com)
			o Example:
					H, 1.008
					He, 4.0026
					Li, 6.94
					E
					Rn, 222.02

					Store these in your hash table. */
#include "HashTable.h"


// __________________
// Constructor:
/// Purpose: Create an empty Hash Table.
/// Parameters:
/// Returns: n/a
/// Pre-Conditions:
/// Post-Conditions: The Hash Table has been initialized as an empty Hash Table.
HashTable::HashTable()
{
	_element = nullptr;
	_used = 0;
} // End Constructor


// __________________
// Destructor:
/// Purpose:
/// Parameters:
/// Returns:
/// Pre-Conditions:
/// Post-Conditions:
HashTable::~HashTable()
{
	Clear();
} // End Destructor


// __________________
// Hash:
/// Purpose: Take a string input as a key and convert it into an integer.
/// Parameters: string
/// Returns: int
/// Pre-Conditions: n/a
/// Post-Conditions: String input "key" has been converted into an integer value.
int HashTable::Hash(string key)
{
	// Hash function (something other than simple modulus)

	//	hash(key) = > index
	//	hash = sum of characters
	//	index = hash % size;

	//	load_factor = items / slots;

	int sum = 1;

	for (int i = 0; i < key.length(); i++)
	{
		int ascii = int(key.at(i)); // Get the ascii value of the char at index [i] in the string array.
		sum *= ascii; // Multiply the ascii value by the sum variable, and save the result in sum.
		//cout << "char: " << (key.at(i)) << "\tascii: " << ascii << "\tsum: " << sum << endl;
	}

	sum %= CAPACITY; // sum is equal to sum mod CAPACITY

	return sum;
} // End Hash()


// __________________
// Insert (page 602):
/// Purpose: Insert a new element into the Hash Table.
/// Parameters: sting, double
/// Returns: void
/// Pre-Conditions: entry.key >= 0. Also if entry.key is not already a key in the table, then the table has a space for another record (that is, size() < CAPACITY).
/// Post-Conditions: If the table already had a record with a key equal to entry.key, then that record is replaced by entry. Otherwise entry has been added as a new record of the table.
void HashTable::Insert(string key, double value, int number)
{
	//	Insert (including a good hash function (not a simple modulus))
	//		EMust resolve collisions
	
	Node* n = new Node();

	// Create a new Node pointer ("n1") and store the element compound ("key") and element weight ("value") in it.
	Node* n1 = new Node();
	n1->compound = key;
	n1->weight = value;

	// Create a second Node pointer ("n2")
	Node* n2 = new Node();
	
	cout << "\t" << number << "\t" << key << "\t" << Hash(key) << endl;

	// Basic open-address storage by hashing algorithm (page 601):

	/// Check to ensure there are no existing Nodes at the array index determined by the current key.
	/// If there are none, simply copy the Node pointer into that slot in the array.

	//	1.	For a record with key value given by "key", compute the index "hash(key)".
	int index = Hash(key);

	//	2.	If data[hash(key)] does not already contain a record,
	//		then store the record in data[hash(key)] and end the storage algorithm.
	if (elementListArray[index].size() == 0)
	{
		elementListArray[index].insert(key, value);
		_used++;
		return;
	}


	/// _____________________________________________________________________________________________________________________________
	/// If there *IS* a Node already in that slot in the array... (Linear Probing)
	//	3.	If the location data[hash(key)] already contains a record, then try data[hash(key)+1].
	//		If that location already contains a record, try data[hash(key)+2], and so forth, until a vacant position is found.
	//		When the highest number of array positions is reached, simply go to the start of the array.
	//		For example, if the array indexes are 0...99, and 98 is the key, then try 98, 99, 0, 1, and so on, in that order.
	
	/*else if (elementListArray[index].size() != 0 && _used < CAPACITY - 1)
	{
		for (int i = 0; i < CAPACITY; i++)
		{
			if (elementListArray[index + i].size() == 0)
			{
				elementListArray[index + i].insert(key, value);
				_used++;
				return;
			}
		}
	}*/
	/// Note: the above code is for linear probing (page 613), not chained hashing.
	/// _____________________________________________________________________________________________________________________________


	/// If there *IS* a Node already in that slot in the array... (Chained Hashing)
	//	3_alternate.	If the location data[hash(key)] already contains a record, then try the "next" value of the current Node.
	//					If that node already contains a record, try it's "next" value. Loop until a nullptr is reached.
	else if (elementListArray[index].size() != 0)
	{
		elementListArray[index].addEnd(key, value);
		_used++;
		return;
	}


	/*else if (elementListArray[index].size() != 0 && _used >= CAPACITY - 1)
	{
		int pos = 0;
		elementListArray[index].insert(key, value);
		n2 = elementListArray[index].head->next;

		elementListArray[index].print();

		while (elementListArray[index].head->next != nullptr)
		{
			//cout << "\t\t\t\t[" << n2->compound << "] -> " << pos << endl;
			n2 = n2->next;
			pos++;
		}

		if (n2 == nullptr)
		{
			n2 = n1;

			//cout << "[" << elementArray[index] << "] -> " << pos << endl;
			//cout << "\t\t\t\t[" << index << ":" << pos << "] = " << n2->compound << endl;
		}

		_used++;
		return;
	}*/
}// End Insert()


// __________________
// Clear:
/// Purpose: Clear all elements from the Hash Table.
/// Parameters: n/a
/// Returns: void
/// Pre-Conditions: n/a
/// Post-Conditions: Hash Table has been cleared of all elements.
void HashTable::Clear()
{
	Node* n_ptr;

	//	Clear (remove all from hash table)

	//	1. Iterate over table
	//	2. For each slot that isn't null, delete all nodes in that slot.
	for (int i = 0; i < CAPACITY; i++)
	{
		n_ptr = elementListArray[i].head;

		if (n_ptr != nullptr)
		{
			delete n_ptr;
			elementListArray[i].head = nullptr;
		}

		//delete elementListArray[i];

		/*while (n_ptr != nullptr)
		{
			Node* old_ptr = n_ptr;			
			n_ptr = n_ptr->next;
			delete old_ptr;
		}*/
	}
} // End Clear()


// __________________
// Retrieve:
// Helper function for the constructor (?)
/// Purpose: Retrieve the weight of the element given by the key.
/// Parameters: string
/// Returns: double
/// Pre-Conditions: n/a
/// Post-Conditions: The weight of the element given by the key has been returned as a double.
double HashTable::Retrieve(string key)
{
	Node* n_ptr = elementListArray[Hash(key)].head;

	if (n_ptr->compound != key && n_ptr->next == nullptr)
		return 0;

	else
	{
		while (n_ptr->compound != key)
			n_ptr = n_ptr->next;

		return n_ptr->weight;
	}
}// End Retrieve()


// __________________
// Operator [] (return double):
/// Purpose: Return the weight of a given element stored at the index hashed from the given key.
/// Parameters: string
/// Returns: double
/// Pre-Conditions: n/a
/// Post-Conditions: The weight of the given element has been returned as a double.
double HashTable::operator[](string key)
{
	//	Overloaded[] operator that works as a retrieve (not insert)
	//		* Example: The line "h[key]" will return the weight of element stored in HashTable 'h' at index 'key'.
	return Retrieve(key);
}// End Operator []()


 // __________________
 // Operator [] (return Node*):
 /// Purpose: Return a pointer to the Node stored at the given index.
 /// Parameters: int
 /// Returns: Node pointer
 /// Pre-Conditions: n/a
 /// Post-Conditions: The element at the given index has been returned as a Node pointer.
Node* HashTable::operator[](int i)
{
	//	Overloaded[] operator that works as a retrieve (not insert)
	//		* Example: The line "h[i]" will return the Node of element 'h' stored at index 'i'.
	return  elementListArray[i].head;
}// End Operator []()