//Disclaimer:
// I Edison have not used any code other than my own(or that in the textbook) for this project.
// I also have not used any function or data - structure from the Standard - Template Library.
// I also have not shared my code with any student in this class
// I understand that any violation of this disclaimer will result in a 0 for the project.

//Hash_Table.cpp File
//Purpose: Implementation file for Hash - Createsa a hash array and uses a prime number less than size ensure collisions

//CS 2420
//Instructor: Todd Peterson
//Class: CS 2420
//Section: 001
//Name: Edison Gray Earnest
//Project: Hash Project
//Date: 4/14/2016

#include "Hash_Table.h"

//create constructor and initialize it
Hash_Table::Hash_Table()
{
	HashArray = new Node*[PRIME_SIZE];

	for (int i = 0; i < PRIME_SIZE; i++)
		HashArray[i] = nullptr;
}

//deconstructor for hash table
Hash_Table::~Hash_Table()
{
	//go through individually first. any arrays that initially point to null can be skipped. Otherwise recursively delete
	for (int i = 0; i < PRIME_SIZE; i++)
		if (HashArray[i] != nullptr)
			DeleteHelper(HashArray[i]);

	//lastly delete the array
	delete [] HashArray;
}

//recursively helps delete the array
void Hash_Table::DeleteHelper(Node*& current)
{
	//traverse to last spot first, then delete from tail to head
	if (current->next != nullptr)
		DeleteHelper(current->next);

		delete current;
}

//is like delete, but reinitializes everything back to nullptr
void Hash_Table::Clear()
{
	for (int i = 0; i < PRIME_SIZE; i++)
		if (HashArray[i] != nullptr)
		{
			DeleteHelper(HashArray[i]);
			HashArray[i] = nullptr;
		}
}

//print function that is not currently in use
void Hash_Table::Print()
{
	for (int i = 0; i < PRIME_SIZE; i++)
	{
		cout << "\nIndex: " << i << endl;

		if (HashArray[i] == nullptr)
		{
			cout << "\tKey: N/A" << endl;
			cout << "\tWeight: N/A" << endl;

		}
		else
		{

			Node* current = HashArray[i];

			while (current != nullptr)
			{
			cout << "\tKey: " << current->key << endl;
			cout << "\tWeight: " << current->weight << endl;

			current = current->next;
			}
		}
	}
}

//insert function
void Hash_Table::Insert(string key, double weight)
{
	int hash = 0;

	//takes key, finds ascii value of the total key squared, and then moduleses it by the prime
	hash = Hash(key);
	
	hash %= PRIME_SIZE;

	Node* newNode = new Node(key, weight);
	
	//if this array has nothing at the hash currently, then this will be the first and replace what is there currently (nullptr)
	if (HashArray[hash] == nullptr)
		HashArray[hash] = newNode;

	//else we need to find the last node
	else
	{
		//have a function that returns the last node		
		Node* lastNode;
		lastNode = InsertHelper(HashArray[hash]);
		//set the last's next to the new node.
		lastNode->next = newNode;
	}
}

//this function will search through node's given, and return last node.
Node* Hash_Table::InsertHelper(Node* current)
{
	if (current->next != nullptr)
		return InsertHelper(current->next);

	else
		return current;
}

//hash takes a key, and gives it a hash value (not totally finished -> insert function moduluses, which may need to be changed)
// There may be things at this index which causes collisions, but that should be handled by insert function
int Hash_Table::Hash(string key)
{
	int sum = 0;
	char temp;

	//for the key's length, get the sum of the ascii squared values of each character.
	for (int i = 0; i < key.length(); i++)
	{
		temp = key[i];
		sum += calcAscii(temp);
	}
	//return entire sum
	return sum;
}

//ascii calc takes a character and returns the int value of it, squared.
int Hash_Table::calcAscii(char a)
{
	int decimal = 0;

	decimal = (int)a;

	return decimal*decimal;
}

//this is not currently in use. This simple function sets a default bool value to false, then uses the key to find a possible hash. If it finds anything
//that is exactly like it, then the default value get switched to true.
bool Hash_Table::isKey(string iKey)
{
	bool defaultVal = false;

	//find hash value
	int tempIndex = Hash(iKey);
	tempIndex %= PRIME_SIZE;

	//find what is at the hash index already
	Node* current = HashArray[tempIndex];

	//if it is null, then this is false as nothing is currently at this index
	if (current == nullptr)
		return defaultVal;
	//not null - search through the rest of the list for the key to match up
	else
	{
		while (current != nullptr)
		{
			//if keys match, then switch the default value to true.
			if (current->key == iKey)
				defaultVal = true;

			current = current->next;
		}
	}
	//return default value
	return defaultVal;
}

//retrieves an atomic number given the Key
double Hash_Table::Retrieve(string iKey)
{
	//set default values
	double defaultVal = 0;

	//get the hash value
	int tempIndex = Hash(iKey);
	tempIndex %= PRIME_SIZE;

	//use pointer to search index 
	Node* current = HashArray[tempIndex];

	//if there is nothing there, then return 0 (nothing)
	if (current == nullptr)
		return defaultVal;
	//there is something there
	else
	{
		while (current != nullptr && defaultVal == 0)
		{
			//compare keys until we have searched through all of them, or switched the default value
			if (current->key == iKey)
				defaultVal = current->weight;
			else
				current = current->next;
		}
	}
	//return the atomic number
	return defaultVal;
}

//simple calculation takes keys ascii value, and compares it to the ascii values for number 0-9
bool Hash_Table::isNumber(char key)
{
	int decimal = (int)key;

	if (decimal >= ASCII_ZERO && decimal <= ASCII_NINE)
		return true;

	else
		return false;
}

//simple calculation takes keys ascii value, and compares it to the left parenthesis ascii value
bool Hash_Table::isLeftPar(char key)
{
	int decimal = (int)key;

	if (decimal == ASCII_LPARENTH)
		return true;

	else
		return false;
}

//simple calculation takes keys ascii value, and compares it to the right parenthesis ascii value
bool Hash_Table::isRightPar(char key)
{
	int decimal = (int)key;

	if (decimal == ASCII_RPARENTH)
		return true;

	else
		return false;
}

//simple calculation takes keys ascii value, and compares it to lower case values 
bool Hash_Table::isLowerCase(char key)
{
	int decimal = (int)key;

	if (decimal >= ASCII_LOWBEGIN && decimal <= ASCII_LOWEND)
		return true;

	else
		return false;
}

//simple calculation takes keys ascii value, and compares it to upper case values 
bool Hash_Table::isUpperCase(char key)
{
	int decimal = (int)key;

	if (decimal >= ASCII_HIGHBEGIN && decimal <= ASCII_HIGHEND)
		return true;

	else
		return false;
}

//operator relies on retrieve function
double Hash_Table::operator[](string iKey)
{
	return Retrieve(iKey);
}