//Disclaimer:
// I Edison have not used any code other than my own(or that in the textbook) for this project.
// I also have not used any function or data - structure from the Standard - Template Library.
// I also have not shared my code with any student in this class
// I understand that any violation of this disclaimer will result in a 0 for the project.

//Source.cpp File
//Purpose: Driver for Program

//CS 2420
//Instructor: Todd Peterson
//Class: CS 2420
//Section: 001
//Name: Edison Gray Earnest
//Project: Hash Project
//Date: 4/14/2016

#include "Hash_Table.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;


//declare constants
const int READ_LOOP = 3;

const int ATOMIC_POS = 0;
const int KEY_POS = 1;
const int WEIGHT_POS = 2;

const int TEN = 10;
const int TWO = 2;

const char EMPTY = ' ';


//Function prototypes for Driver

//createTable() Function
//Purpose:Creates the initial table by reading data from a file, breaking it apart and calling function for insert
//Parameters:Hash_Table - the same hash table that we initially created
//Returns:none
void createTable(Hash_Table& atomic_Weights);

//readFormula() Function
//Purpose: Reads each individual formula from a text file, and then calls appropiate functions to calculate formula
//Parameters:Hash_Table - the same hash table that we initially created
//Returns:none
void readFormula(Hash_Table& atomic_Weights);

//KeyParse() Function
//Purpose: To calculate the raw string formula into an atomic weight
//Parameters: Hash_Table - the same hash table that we initially created & formula - the string contains the relevant part of the formula
//Returns:atomic weight of formula
double KeyParse(Hash_Table& atomic_Weights, string & formula);

//driver main
void main()
{
	//create hash table object and call createTable to read in a textfile containing the data
	Hash_Table atomic_Weights;
	createTable(atomic_Weights);

	//this next line of code is useful for seeing how the data is spread out, which has helped me make adjustments to make the has more evenly spread out
	//print basically shows every array spot on the Hash_Table array, and shows where each element is stored. It can be useful or not.
	//atomic_Weights.Print();

	//read in the formulas and get the atomic weight
	readFormula(atomic_Weights);
	atomic_Weights.Clear();

	cout << "Object is Cleared using Clear Funciton. Program is terminating.\n";

	//pause before program ends
	system("pause");
}

//stores and inserts for hash table
void createTable(Hash_Table& atomic_Weights)
{

	//create string i
	string inputLine = "";
	//create input file for ifstream
	ifstream atomic_Input;
	atomic_Input.open("PeriodicTableElements.txt");
	//after opening, if it fails let user know.
	if (atomic_Input.fail())
		cout << "Error! File cannot be read.";
	//if program opens, then loop through the document until end of file. program will save the line of code read, and output it
	else
	{
		while (!atomic_Input.eof())
		{
			//while it is not the end of file, get the next line
			getline(atomic_Input, inputLine);
			//if the size was 0, then there was nothing on the line
			if (inputLine.size() > 0)
			{

				//convert line into individual elements --> Atomic number (may not be needed now, but I could still keep this for later), key, then atomic weight
				string temp = "";

				string key;
				double weight;
				int atomicNum;

				stringstream ss(inputLine); // Insert the string into a stream

				//read the string back, which gets the next set of characters until a space is found.
				for (int i = 0; i < READ_LOOP; i++)
				{
					ss >> temp;

					//stores in order - Atomic Number, Key (Atomic Symbol), Atomic Weight. Loops 3 times to set each in place specifically

					if (i == ATOMIC_POS)
						atomicNum = stoi(temp);

					else if (i == KEY_POS)
						key = temp;

					else if (i == WEIGHT_POS)
						weight = stod(temp);

				}

				//after line has been split up, then insert into the hash table
				atomic_Weights.Insert(key, weight);


				//used for testing purposes
				//cout << "\nKey:\t\t" << key << endl;
				//cout << "\nWeight:\t\t" << weight << endl;
				//cout << "\nAtomic Number:\t" << atomicNum << endl;

			}

		}
		//once program is finished, close the file
		atomic_Input.close();
		cout << "Hash Table Created Successfully." << endl;
	}
}


//reads formula from file
void readFormula(Hash_Table& atomic_Weights)
{

	//create string i
	string formulaLine = "";
	//create input file for ifstream
	ifstream input;
	input.open("formulas.txt");
	//after opening, if it fails let user know.
	if (input.fail())
		cout << "Error! File cannot be read.";
	//if program opens, then loop through the document until end of file. program will save the line of code read, and output it
	else
	{
		cout << "\nFormula and Atomic Weight:\n";

		while (!input.eof())
		{
			//while it is not the end of file, get the next line
			getline(input, formulaLine);
			//if the size was 0, then there was nothing on the line
			if (formulaLine.size() > 0)
			{

				//output formula
				//output Parse -> uses formula to convert it to atomic weights
				cout << left << setw(TEN) << formulaLine << " \t" << KeyParse(atomic_Weights, formulaLine) << " g/mol" << endl;
			}
		}
		//once program is finished, close the file
		input.close();
		cout << "\nEnd of file found. File closed.\n" << endl;
	}
}

//takes a string formula and calculates into an atomic weight
double KeyParse(Hash_Table& atomic_Weights, string & formula)
{

	//declare variables
	double sum = 0; //for total sum of formula
	double tempSum = 0; //used to sum a value in parenthesis

	string tempKey; //used for building a string for a possible key
	double multiplier; //useful in case function has a digit to multiply element with

	int peak;

	//loop is required to go at least until we have reached the end. I have done this by doing a for loop, that will most likely NEVER run the entire time.
	//the inner loop controls i's value, but incrimenting can still be useful
	for (int i = 0; i < formula.length(); i++)
	{
		tempKey = "";
		multiplier = 1;
		tempSum = 0;
		peak = i;

		//formula file has empty strings - I better first check to make sure all empty strings are skipped
		if (formula[i] != EMPTY)
		{

			//if left parenthesis is found, then we are going to need to create another inner formula to call recursively
			if (atomic_Weights.isLeftPar(formula[i]))
			{

				peak++;
				//keep adding to formula until the right parenthesis is filled
				while (!atomic_Weights.isRightPar(formula[peak]))
					tempKey += formula[peak++];

				//set index to peak - 
				i = peak;

				//recursively call this again to get the inner loops atomic weight
				tempSum = KeyParse(atomic_Weights, tempKey);

				//if there is a number after this, then the multiplier needs to increase to that number
				if (atomic_Weights.isNumber(formula[i + 1]))
				{
					char temp = formula[++i];

					multiplier = temp - '0';
				}
				//calculate the new sum
				sum = sum + (tempSum * multiplier);

			}
			//if not a parenthesis, then we only need to worry about an upper case letter
			else if (atomic_Weights.isUpperCase(formula[i]))
			{
				//if Uppercase, then find the next lowercases until you reach something other than an lowercase
				do
				{
					tempKey += formula[peak++];
				} while (atomic_Weights.isLowerCase(formula[peak]));

				i = peak - 1;

				//we should have our key now. Get it's atomic weight now.
				tempSum = atomic_Weights[tempKey];

				//check to see if there is a number at the end - this adjust multipliers
				if (atomic_Weights.isNumber(formula[i + 1]))
				{
					char temp = formula[++i];

					multiplier = temp - '0';
					
					//in rare examples, the teacher is going to trick us with a data file that has more than 10. I account for this by seeing if there is another number
					//after the previous. If so, then it is a more than a single digit.
					if ((i + 1) < formula.length())
					{
						if (atomic_Weights.isNumber(formula[i + 1]))
						{
							multiplier *= TEN;

							char temp = formula[++i];

							multiplier += temp - '0';

							i--;
						}
					}
				}
				//update sum
				sum = sum + (tempSum * multiplier);
			}
		}
	}
	//return sum
	return sum;
}