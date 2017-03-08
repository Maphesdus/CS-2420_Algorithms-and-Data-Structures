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

#include "HashTable.h"

/*	Parser

	//Write a driver that will use your hash function to compute the molecular weight of each molecule in the formulas.txt file.

	* There is a test file with a list of molecules (formulas.txt).
		o	One formula per line.
		
	* Parse each line of the test file and compute the molecular weight of each compound
		o	The exact actual molecular weight will not be the sum of the atomic weights in the molecule. Donít worry about this.
		o	But the sum of the atomic weights will approximate this molecular weight
			*	This is what we are computing
		
	Å* Your driver shouldS
		o	Read in the Elements and their weights from a text file
			*	Insert the element abbreviation and its atomic weight (not the molecules) into the hash table
		
	Å* The element abbreviation is the key.
		o	Read in the formulas from a text file (formulas.txt).
		o	Parse the formulas and compute their molecular weight
			*	Parsing means to look at each symbol and extract the information you need
			*	Example: H2O
				ÅE First look at the 'H'-> retrieve the weight in the hash table
				ÅE Look at the '2' multiply the previous weight by 2
				ÅE Look at the O -> retrieve the weight stored for 'O'ÅE
					o	Add this weight to the previous total
			*	Use the atomic weights that are stored in your hash table to help compute these weights
		o	Output the formula and its molecular weight to the screen.
*/

// Function Prototypes:

void HashTest(HashTable&);			/// Used for debugging only.
void RetrieveTest(HashTable&);		/// Used for debugging only.
void PrintAllFormulas(HashTable&);	/// Used for debugging only.

void PrintTable(HashTable&);
void PrintChain(Node*);

void PeriodicTableElements(HashTable&);
void formulas(HashTable&);

double ParseFormula(HashTable&, string&);

const int TEN = 10;
const int TWO = 2;
int step = 0;

// __________________
//	Wait
/// Purpose: Custom "pause" function.
/// Parameters: n/a
/// Returns: void
/// Pre-Conditions: n/a
/// Post-Conditions: Program pauses and waits for the user to press a key before continuing.
void wait()
{
	step++;
	cout << "\nstep: (" << step << "/3)" << endl;

	if (step < 3)
		cout << "Press the \"Any\" key to continue...";

	else if (step == 3)
		cout << "Press the \"Any\" key to quit...";

	cin.get(); 
	cout << "\n";
}


// main:
void main()
{
	cout << "Project 10: Hash Table" << endl;

	HashTable MyHashTable; // Create a new Hash Table.

	//HashTest(MyHashTable); // Test the Hash() function.
	//RetrieveTest(MyHashTable); // Test the retrieve() function.
	//PrintAllFormulas(MyHashTable);
	
	//wait();
	PeriodicTableElements(MyHashTable);

	wait();
	PrintTable(MyHashTable);

	wait();
	formulas(MyHashTable);

	cout << endl;
	wait();
} // End main()


// __________________
// Hash Test:
/// Purpose: Test the Hash() function.
/// Parameters: HashTable reference
/// Returns: void
/// Pre-Conditions: HashTable object must be declared first.
/// Post-Conditions: User input is hashed and output to console.
void HashTest(HashTable& MyHashTable)
{
	string line;

	cout << "Testing Hash() function. Please input some data to hash." << endl;
	cout << "input: ";
	cin >> line;

	cout << "hash: " << MyHashTable.Hash(line) << endl;
}


// __________________
// Retrieve Test:
/// Purpose: Test the Retrieve() function.
/// Parameters: HashTable reference
/// Returns: void
/// Pre-Conditions: HashTable has already been filled with appropriate data.
/// Post-Conditions: A value stored in the HashTable is retrieved and output to the console.
void RetrieveTest(HashTable& MyHashTable)
{
	string input;
	double atomic_weight;
	bool not_finished = true;

	// Test the Retrieve function:
	do
	{
		cout << "Enter an element to retrieve its weight (0 to quit): ";
		cin >> input;

		if (input == "0")
			not_finished = false;
		
		else
		{
			atomic_weight = MyHashTable[input];
			cout << "\tThe atomic weight of the element " << input << " is " << atomic_weight << "." << endl;
		}
	} while (not_finished);
}


// __________________
// Print Table:
/// Purpose: Print out all the elements contained in the Hash Table's array, along with their weights.
/// Parameters: HashTable reference
/// Returns: void
/// Pre-Conditions: The HashTable must already be filled with elements and their weights.
/// Post-Conditions: Elements and weights contained in the HashTable have been output to the console.
void PrintTable(HashTable& MyHashTable)
{
	cout << "\nInserting elements into Hash Table..." << endl;

	cout << "\tSlot: \tCompound(s): \tWeight:" << endl;

	for (int i = 0; i < MyHashTable.CAPACITY; i++)
	{
		if (MyHashTable[i] != nullptr)
		{
			cout << "\t[" << i << "]:\t" << MyHashTable[i]->compound << "\t\t" << MyHashTable[i]->weight << endl;

			if (MyHashTable[i]->next != nullptr)
				PrintChain(MyHashTable[i]->next);
		}

		else
			cout << "\t[" << i << "]:\t[EMPTY]" << endl;

		cout << endl;
	}
}

// __________________
// Print Chain:
/// Purpose: Print out the complete chain of Nodes in a Linked List.
/// Parameters: Node pointer
/// Returns: void
/// Pre-Conditions: The Linked List must already be filled with Nodes.
/// Post-Conditions: The complete chain of Nodes in the Linked List is output to the console.
void PrintChain(Node* n)
{
	cout << "\t\t" << n->compound << "\t\t" << n->weight << endl;

	if (n->next != nullptr)
		PrintChain(n->next);
}


// __________________
// PeriodicTableElements:
/// Purpose: Read in the elements and their weights from a text file and insert them into the hash table.
/// Parameters: HashTable reference
/// Returns: void
/// Pre-Conditions: A text file of elements must exist to be read in.
/// Post-Conditions: The text file has been read and its contents inserted into the HashTable.
void PeriodicTableElements(HashTable& MyHashTable)
{
	int number;
	string compound;
	double weight;

	ofstream stream;
	ifstream PeriodicTableElements_FILE;
	PeriodicTableElements_FILE.open("PeriodicTableElements.txt");

	cout << "\nGetting data from Periodic Table of Elements..." << endl;

	if (PeriodicTableElements_FILE)
	{
		//	Read in the Elements and their weights from a text file ("PeriodicTableElements.txt").
		//	Insert the element abbreviation and its atomic weight (not the molecules) into the hash table.

		cout << "\tLine: \tKey: \tHash: " << endl;

		while (!PeriodicTableElements_FILE.eof())
		{
			PeriodicTableElements_FILE >> number;
			PeriodicTableElements_FILE >> compound;
			PeriodicTableElements_FILE >> weight;

			MyHashTable.Insert(compound, weight, number);
		}
		PeriodicTableElements_FILE.close();
	}

	else
		cout << "Unable to open file " << "PeriodicTableElements.txt\n";
}



// __________________
// Print All Formulas:
/// Purpose: Test the file input by reading in a text file and outputting its contents to the console.
/// Parameters: HashTable reference
/// Returns: void
/// Pre-Conditions: A text file of elements must exist to be read in.
/// Post-Conditions: Text file has been read and its contents output to the console.
void PrintAllFormulas(HashTable& MyHashTable)
{
	string line;
	ifstream formulas_FILE;
	formulas_FILE.open("formulas.txt");

	cout << "Getting molecular formulas..." << endl;

	if (formulas_FILE)
	{
		///	Print out each molecular formula line by line:
		while (getline(formulas_FILE, line))
		{
			cout << "\t" << line << endl;
		}

		formulas_FILE.close();
	}

	else
		cout << "Unable to open file " << "formulas.txt\n";
}

//	o	Parse the formulas and compute their molecular weight
//		*	Parsing means to look at each symbol and extract the information you need
//		*	Example: H2O
//			ÅE First look at the 'H'->retrieve the weight in the hash table
//			ÅE Look at the '2' multiply the previous weight by 2
//			ÅE Look at the O->retrieve the weight stored for 'O'ÅE
//				~	Add this weight to the previous total
//		*	Use the atomic weights that are stored in your hash table to help compute these weights
//	o	Output the formula and its molecular weight to the screen.

//	For example: H2O
//		Take the weight of H (look up H on the Hash Table),
//		multiply that weight by 2,
//		and then add the result to the weight of O (look up O on the Hash Table).


// __________________
// formulas:
/// Purpose: Open the input file ("formulas.txt"), read in each line from the file.
/// Parameters: HashTable reference
/// Returns: void
/// Pre-Conditions: HashTable has been filled with appropreate data about atomic weights.
/// Post-Conditions: All formulas have been read in, had their atomic weights calculated, and the result output to the console.
void formulas(HashTable& MyHashTable)
{
	string line;
	double total_weight = 0;
	
	ofstream stream;
	ifstream formulas_FILE;
	formulas_FILE.open("formulas.txt");

	cout << "Getting molecular formulas..." << endl;

	if (formulas_FILE)
	{
		cout << "\nformulas.txt:" << endl;

		while (getline(formulas_FILE, line))
		{
			cout << "\tElement: " << line << "\n\t Compound(s): \tWeight:" << endl;
			total_weight = ParseFormula(MyHashTable, line);
			cout << "\tTotal Weight: " << total_weight << "\n" << endl;
		}

		formulas_FILE.close();
	}

	else
		cout << "Unable to open file " << "formulas.txt\n";
}


// __________________
//	Parse Formula:
/// Purpose: Takes a string formula and calculates into an atomic weight.
/// Parameters: HashTable reference, string reference
/// Returns: double
/// Pre-Conditions: Formula has been read in as a string from text file.
/// Post-Conditions: Atomic weight of the elements in the forumula is returned as a double.
double ParseFormula(HashTable& MyHashTable, string& line)
{
	double weight = 0;
	double tempWeight = 0;
	string tempElement;
	double multiplier;
	int peekNext;
	char leftParen = '(';
	char rightParen = ')';
	char space = ' ';
	char zero_c = '0';


	// Iterate over each character in the line for the length of the line:
	for (int i = 0; i < line.length(); i++)
	{
		tempElement = "";
		multiplier = 1;
		tempWeight = 0;
		peekNext = i;

		// If the character at index [i] is *NOT* an empty space:
		if (line[i] != space)
		{
			// If the character at index [i] is a left parenthesis:
			if (line[i] == leftParen)
			{
				peekNext++;

				// While the next character is *NOT* a right parenthesis:
				while (line[peekNext] != rightParen)
					tempElement += line[peekNext++];

				i = peekNext;

				// Recursive function call:
				tempWeight = ParseFormula(MyHashTable, tempElement);

				// If the character at index [i + 1] is a number:
				if (isdigit(line[i + 1]))
				{
					char temp = line[++i];
					multiplier = temp - zero_c;
				}

				// Multiply the weight by the appropriate modifier:
				weight += (tempWeight * multiplier);
			}

			// If the character at index [i] is an uppercase letter:
			else if (isupper(line[i]))
			{
				// While the next character is a lowercase letter:
				do tempElement += line[peekNext++];
				while (islower(line[peekNext]));
				i = peekNext - 1;

				// Look up element weight in Hash Table:
				tempWeight = MyHashTable[tempElement];

				// If the character at index [i] is a left parenthesis:
				if (isdigit(line[i + 1]))
				{
					char temp = line[++i];
					multiplier = temp - zero_c;

					// If index [i + 1] is still less than the length of the line:
					if ((i + 1) < line.length())
					{
						// If the character at index [i + 1] is a number:
						if (isdigit(line[i + 1]))
						{
							multiplier *= TEN;
							char temp = line[++i];
							multiplier += temp - zero_c;
							i--;
						}
					}
				}

				cout << "\t  " << tempElement << "\t\t " << tempWeight << endl;
				weight += (tempWeight * multiplier);

				if (multiplier > 1)
					cout << "\t  " << tempElement << multiplier << "\t\t " << weight << endl;
			}
		}
	}

	return weight;
}