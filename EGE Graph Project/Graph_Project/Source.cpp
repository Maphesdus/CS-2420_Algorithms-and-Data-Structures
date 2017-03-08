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
//Project: Graph Project
//Date: 4/19/2016

#include "Graph.h"
#include <iostream>
#include <string>

using namespace std;

const int DEFAULT_SIZE = 10;

void main()
{
	Graph test;

	//instructions did not give specifics on size. The capacity could hold up to 20 verticies
	//for the time being, driver only sets 10 vertexes up originally. 0-9 are used
	cout << "\nPART 1 - ADDING 10 VERTICIES AND MANUALLY CONNECTING UNDIRECTED EDGES." << endl;
	for (int i = 0; i < DEFAULT_SIZE; i++)
		test.add_vertex();

	//calls add_edge(v1, v2, weight) -> I basically do this function instead of manually using the driver to insert each.
	//Because driver is not interactive, driver will be simpler with out having each add_edge added individually.
	test.mult_add_edge();

	cout << "\nPART 2 - DISPLAYING GRAPH AS A MATRIX." << endl;

	//Graph class has multiple ways to print the graph. Matrix is probably the easiest way to see graph, but it can also be printed in the following that has been coded out.
	//test.SimplePrint();
	//test.Print();
	//test.PrintAll();
	test.MatrixPrint();

	cout << "\nPART 3 - DISPLAYING PATH INDEX FOR DFS." << endl;
	//DepthFirstSearch uses recursion and helper function
	test.DepthFirstSearch();

	cout << "\nPART 4 - DISPLAYING ORDERED PAIRS FOR SHORTEST PATH STARTING AT INDEX 0." << endl;
	//Algorithim is probably the same ideally, but not implemented 100% as the alrogithim given to us. Alrogithim correctly displays output and ordered pairs for the edges that I used.
	test.CalcShortDist();

	system("pause");
}