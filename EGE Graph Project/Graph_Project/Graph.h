//Disclaimer:
// I Edison have not used any code other than my own(or that in the textbook) for this project.
// I also have not used any function or data - structure from the Standard - Template Library.
// I also have not shared my code with any student in this class
// I understand that any violation of this disclaimer will result in a 0 for the project.

//Graph.h File
//Purpose: Header File for Graph Class

//CS 2420
//Instructor: Todd Peterson
//Class: CS 2420
//Section: 001
//Name: Edison Gray Earnest
//Project: Graph Project
//Date: 4/19/2016


#pragma once
#include <iostream>
#include <string>

using namespace std;

//declare constants
const int MAX_SIZE = 20;

class Graph
{
public:

	//Graph()
	//Purpose:Initializes Graph Class
	//Parameters:none
	//Returns:none
	Graph();

	//~Graph()
	//Purpose:Destructor for Graph Class - not currently used
	//Parameters:none
	//Returns:none
	~Graph();

	//add_edge()
	//Purpose:Adds an Edge to a graph
	//Parameters:v1 & v2 - the verticies & weight - the distance between the two verticies
	//Returns:bool - if verticies are within scope of graph's parameters & they are not equal to each other, true is returned.
	bool add_edge(int v1, int v2, double weight);


	//mult_add_edge()
	//Purpose:Adds multple edges using add_edge function - This used to just be in my driver, but this makes it simplier now
	//Parameters:none
	//Returns:none
	bool mult_add_edge();

	//add_vertex()
	//Purpose:adds a vertex by increasing the size on the array.
	//Parameters:none
	//Returns:bool - true if a vertex was added, false if not.
	bool add_vertex();

	//is_edge()
	//Purpose:Takes in 2 verticies, and returns true if they are connected by a weighted edge.
	//Parameters:v1 & v2 - the verticies passed in
	//Returns:bool - true if there is and edge, false if there is not.
	bool is_edge(int v1, int v2);

	//DepthFirstSearch()
	//Purpose:Recursively calls helper function that uses recursion as a stack, and goes through each edge depth first starting at index 0 (I guess that could be changed later on though)
	//Parameters:none
	//Returns:none
	void DepthFirstSearch();

	//MatrixPrint()
	//Purpose:Prints verticies and edges in a way that is Matrix-friendly instead of a list.
	//Parameters:none
	//Returns:none
	void MatrixPrint();

	//SimplePrint()
	//Purpose:Only prints the Edges on each verticy, ignoring all non-connected parts. 
	//Parameters:none
	//Returns:none
	void SimplePrint();

	//Print()
	//Purpose: Prints only the verticies used (0-size). This may be useful for testing purposes, or displaying the entire edges reguardless of if there is one or not.
	//Parameters:none
	//Returns:none
	void Print();

	//PrintAll()
	//Purpose: Prints entire list (0-MAX) reguardless of the verticies actually used - This is for testing purposes
	//Parameters:none
	//Returns:none
	void PrintAll();

	//CalcShortDist()
	//Purpose:Calculates the ordered pairs for which the shortest route is through the graph. This function calls other functions and creates arrays for it.
	//Parameters:none
	//Returns:none
	void CalcShortDist();

	//MinWeightIndex()
	//Purpose:Takes 2 arrays and returns the absolute shortest distance between the entire list. The shortest one is the path that is needed to be taken in order for this calculation to work.
	//Parameters:used*- the indexs that are used which points to -> shortest* - the pointer that stores the lowest vertex. at used[i], (the vertex), the other vertex for the currents shortest distance is at shortest[i] 
	//Returns:int - the vertex of used[i] that has the shortest shortest[i] weight.
	int MinWeightIndex(int* used, int* shortest, int size);

	//FindClosest()
	//Purpose: searches 1 vertex, and uses the usedArray as a reference to the previously visited indexs. Vertex is searched for the closest weight, but will ignore any indexs that are already on the list.
	//Parameters:v - the index vertex that we are searching & usedArray - Array of the previously visited index
	//Returns:int - returns the index 0-size that has the shortest distance. Function may return a -1 in the case that there are no more available indexs to search through at that vertex
	int FindClosest(int v, int*& usedArray);

	//is_On_Array()
	//Purpose:Takes in an array, and determines whether or not the index is on the array yet. This is useful for anytime I need to check to see if I've already been to a specific index
	//Parameters:usedArray* - array that holds the previously visited indexs &index- the index in question & size- the lengh of the array
	//Returns:bool - true if it is on the array, false if it isn't
	bool is_On_Array(int* usedArray, int index, int size);

	//HelperDFS()
	//Purpose:Uses Recursion as a form of stack, and goes through all vertivies until all possible paths are found
	//Parameters:int* - Array that keeps track of what was already visited & current -the index we are currently at & size - the size of what is on the array so far
	//Returns:none
	void HelperDFS(int*& usedArray, int current, int& size);

	//Public Data Members:
	double edges[MAX_SIZE][MAX_SIZE];
	int vSize;
};

