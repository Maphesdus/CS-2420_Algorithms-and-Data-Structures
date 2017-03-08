//Disclaimer:
// I Edison have not used any code other than my own(or that in the textbook) for this project.
// I also have not used any function or data - structure from the Standard - Template Library.
// I also have not shared my code with any student in this class
// I understand that any violation of this disclaimer will result in a 0 for the project.

//Graph.cpp File
//Purpose: Implementation file for Graph Class

//CS 2420
//Instructor: Todd Peterson
//Class: CS 2420
//Section: 001
//Name: Edison Gray Earnest
//Project: Graph Project
//Date: 4/19/2016

#include "Graph.h"

//constructor initializes graph to 0
Graph::Graph()
{
	vSize = 0;

	for (int i = 0; i < MAX_SIZE; i++)
		for (int j = 0; j < MAX_SIZE; j++)
			edges[i][j] = 0;
}

//nothing is used on the heap - instructions never explicitly said, and this graph uses non-interactive driver, so size will never really need to be changed.
Graph::~Graph()
{
}

//add an edge for vertex 1 and 2
bool Graph::add_edge(int v1, int v2, double weight)
{
	//if (vSize < MAX_SIZE && v2 < vSize)

	if (v1 < vSize && v2 < vSize && v1 != v2)
	{
		//swapping v1 and v2 causes it to be undirected - if needed to be changed in the future, delete  the second edges, as that directs edge back.
		edges[v1][v2] = weight;
		edges[v2][v1] = weight;
		return true;
	}
	else
		return false;
	//bool should give a greater application in the future if needed
}

//see header file to know more about simple print vs other prints
void Graph::SimplePrint()
{
	for (int i = 0; i < vSize; i++)
		for (int j = 0; j < vSize; j++)
			if (edges[i][j] != 0)
				cout << "Vertice " << i << " -> Vertice " << j << " = " << edges[i][j] << endl;
}

//see header file to know more about Matrix print vs other prints. This print is probably the easiest to understand
void Graph::MatrixPrint()
{
	if (vSize > 0)
	{
		//cout is messy, but it makes the format look best
		//this indents before doing the top line of format for the indexs
		cout << "\n\t";

		for (int i = 0; i < vSize; i++)
			cout << i << "\t";
		cout << "\n\t";

		//this puts a line at the bottom of the indexs for format again
		for (int i = 0; i < vSize; i++)
			cout << "-------";

		cout << "------";

		//this puts the weights inside, and formats the left index bar
		for (int i = 0; i < vSize; i++)
		{
			cout << "\n" << i << "\t| ";
			for (int j = 0; j < vSize; j++)
				cout << edges[i][j] << "\t ";
			cout << "\n\t|";
		}
		cout << "\n";
	}
}

//see header file to know more about print vs other prints. 
void Graph::Print()
{
	for (int i = 0; i < vSize; i++)
	{
		cout << "Vertice " << i << ": " << endl;

		for (int j = 0; j < vSize; j++)
			cout << "\tEdge to " << j << " is: " << edges[i][j] << endl;
	}
}

//see header file to know more about print vs other prints. 
void Graph::PrintAll()
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		cout << "Vertice " << i + 1 << ": " << endl;

		for (int j = 0; j < MAX_SIZE; j++)
			cout << "\tEdge to " << j + 1 << " is: " << edges[i][j] << endl;
	}
}

//adding a vertex just makes the size increase. This is also a bool that will be able to check to see if this actually adds another size or not because of the hard limit. 
bool Graph::add_vertex()
{
	if (vSize < MAX_SIZE)
	{
		vSize++;
		return true;
	}
	else return false;
}


//this is what i had originally on my driver. This is more of a test file, which is simliar to the example in the book (with a few tweaks)
bool Graph::mult_add_edge()
{
	add_edge(5, 9, 2.1);
	add_edge(0, 5, 9.2);
	add_edge(1, 5, 6.72);

	add_edge(2, 3, .09);
	add_edge(3, 8, 15.9);

	add_edge(4, 2, 7.4);
	add_edge(4, 3, 3.1);
	add_edge(5, 4, 2.8);
	add_edge(6, 4, 1.2);
	add_edge(6, 7, 5.8);

	add_edge(8, 1, 10.2);
	add_edge(8, 9, 11.8);

	return true; 
}

//checks to see if this is an edge or not given v1 and v2 - because this is undirected, order does not matter.
bool Graph::is_edge(int v1, int v2)
{
	if (v1 < vSize && v2 < vSize && edges[v1][v2] != 0)
		return true;
	else
		return false;
}

//recursively calls helper function to go through depth first, searching for new indexs and then adding them to the used array
void Graph::DepthFirstSearch()
{
	if (vSize > 0)
	{
		int used[MAX_SIZE];

		for (int j = 0; j < MAX_SIZE; j++)
			used[j] = 0;

		int * temp;
		temp = used; //pointer used because it's hard to pass array by reference. It's easier just to have a pointer.
		cout << "\nDFS Path:   ";
		int tempSize = 0;
		HelperDFS(temp, 0, tempSize);
		cout << " End \n\n";
	}
}


void Graph::HelperDFS(int*& usedArray, int current, int& size)
{
	//cout is for format to show the direction
	cout << current << "  ->  ";
	usedArray[size++] = current;

	//for loop for is edge
	for (int i = 0; i < vSize; i++)
	{
		if (is_edge(current, i))
		{
			//if there is an edge, then check to see that we have not already went to that location yet

			// check to see that i is not on printArray's
			if (!is_On_Array(usedArray, i, size))
				HelperDFS(usedArray, i, size);
		}
	}
}

//function that checks to see if the index is on the array yet - the array is storing every index that we have been using yet. returns true if is is, and false if it isn't (false tells us that we can actually use this index, because it hasn't been used yet)
bool Graph::is_On_Array(int* usedArray, int index, int size)
{
	for (int i = 0; i < size; i++)
		if (usedArray[i] == index)
			return true;

	return false;
}


//calculates the shortest distance
void Graph::CalcShortDist()
{
	//declare useful variables
	int temp = 0;
	int current = 0;
	double distance = 0;

	//check for size first
	if (vSize > 0)
	{
		int used[MAX_SIZE]; //what is already being used
		int shortest[MAX_SIZE];//for the same index as used, shortest will hold the index of used's max

		for (int j = 0; j < MAX_SIZE; j++)
		{
			used[j] = 0;
			shortest[j] = 0;
		}

		// the shortest weight at the index, which basically using Used as a reference
		int size = 0;

		int* usedPtr = used;
		int* shortestPtr = shortest;
		int i = 0;
		cout << "\nOrder Pair Start ";
		do
		{

			used[size++] = current;


			for (int i = 0; i < size; i++)
				shortest[i] = FindClosest(used[i], usedPtr);

			temp = 0;
			temp = MinWeightIndex(usedPtr, shortestPtr, size);

			//-1 indicates whether or not there are anymore available spots to go to. when -1 comes back from the previous function, that means that the program is nearing the end of the calculation
			if (temp != -1)
			{
				cout << " -> (" << used[temp] << ", " << shortest[temp] << ")";
				current = temp;
				distance += edges[used[current]][shortest[current]];
				current = shortest[current];
			}
		} while (temp >= 0);//as long as the error -1 isn't coming up, this function should still keep looping as there are more things to search

		cout << " -> End" << endl;
	}
	cout << "Total Distance for Shortest Path: " << distance << "\n" << endl; //display distance
}

//returns index of the closest index that is touches
int Graph::FindClosest(int v, int*& usedArray)
{
	int closest_verticie = -1;

	for (int i = 0; i < vSize; i++)
		if (edges[v][i] > 0) 
		{
			if (closest_verticie == -1 && (!is_On_Array(usedArray, i, vSize))) //if there isn't a smallest yet, as long as the weight is NOT 0, AND it's not already on the usedArray, this should be literally switched with anything
				closest_verticie = i;
			else //else -> in cases where there is already something set to closest_verticie, then check to make sure that whatever is at this index, IS NOT actually smaller. this is now the lowest
				if (edges[v][i] < edges[v][closest_verticie] && (!is_On_Array(usedArray, i, vSize)))
					closest_verticie = i;
		}
			
	return closest_verticie;
}

//returns index of the absolute shortestest
int Graph::MinWeightIndex(int* used, int* shortest, int size)
{
	int index_of_min = -1;
	double tempMin = 0;


	for (int i = 0; i < size; i++)
		if (shortest[i] != -1)//checks to make sure that it's not at -1 yet - these should always be skipped as this pretty much says that there are no more verticies that can be accessed for this index
		{
			tempMin = edges[used[i]][shortest[i]];

			if (tempMin != 0)
			{
				//this number is good - let's compare it to any previous number
				if (index_of_min == -1)
					index_of_min = i;
				else
					if (edges[used[i]][shortest[i]] < (edges[used[index_of_min]][shortest[index_of_min]]))
						index_of_min = i;
			}
		}
	return index_of_min;
}