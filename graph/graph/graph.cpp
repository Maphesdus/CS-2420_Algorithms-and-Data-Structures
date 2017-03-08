// NAME: Adam Armstrong
// SECTION: CS 2420 - 002
// PROFESSOR: Todd S. Peterson
// Due: 4/22/2016

// DISCLAIMER:
// I, Adam Armstrong, have not used any code other than my own (or that in the textbook) for this project.
// I also have not used any function or data-structure from the Standard-Template Library.
// I also have not shared my code with any student in this class.
// I understand that any violation of this disclaimer will result in a 0 for the project.

//		Project 11:  Graph(s)
///		(Discussed in Chapter 15 in the book.)

#include "graph.h"


// Constructor:
/// Purpose:
/// Parameters:
/// Returns:
/// Pre-Conditions:
/// Post-Conditions:
graph::graph()
{

}

// Destructor:
/// Purpose:
/// Parameters:
/// Returns:
/// Pre-Conditions:
/// Post-Conditions:
graph::~graph()
{

}

// Add Edge:
/// Purpose:
/// Parameters:
/// Returns:
/// Pre-Conditions:
/// Post-Conditions:
void graph::add_edge()
{

}

// Add Vertex:
/// Purpose:
/// Parameters:
/// Returns:
/// Pre-Conditions:
/// Post-Conditions:
void graph::add_vertex()
{

}

// Is Edge:
/// Purpose:
/// Parameters:
/// Returns:
/// Pre-Conditions:
/// Post-Conditions:
void graph::is_edge()
{

}

// Depth First Search:
/// Purpose:
/// Parameters:
/// Returns:
/// Pre-Conditions:
/// Post-Conditions:
void graph::depth_first_search()
{
	//	Depth-First search();
	//		•	This function is here to help you understand this concept.
	//		•	It is somewhat separate from the rest of the project.
	//		•	Start with the first node and simply print each node as you reach it.
	//		•	You may use the code from pages 748-752 to start with, or you may start from scratch (but use recursion or a stack if you do).
	//		•	You may make a set class with an iterator as shown on page 762 from one of your previous projects, such as iterator-list.
	//			o	Or you can simply make the Depth-First-Search a member-function of your graph class.
	//			o	This allows you to iterate on the edges array directly, with - out the need of a set class or iterator.
	//			o	This is easier, once you understand it.
}




/*	Purpose
		o	to familiarize you with graphs 
		o	to help you understand depth-first search 
		o	to aid in understanding shortest-path algorithms

	Tasks
		•	Create a Graph Class
			o	This class is similar to the one in the book, however in this graph you need to use weighted edges.
				*	You do not need to use templates

			o	Include
				*	Constructor();
				*	Destructor();
				*	add_edge();
				*	add_vertex();
				*	is_edge();
				*	Depth-First search();
					•	This function is here to help you understand this concept.
					•	It is somewhat separate from the rest of the project.
					•	Start with the first node and simply print each node as you reach it.
					•	You may use the code from pages 748-752 to start with
						>	Or you may start from scratch. But use recursion or a stack.
					•	You may make a set class with an iterator as shown on page 762 from one of your previous projects, such as iterator-list
						o	Or you can simply make the Depth-First-Search a member-function of your graph class
						>	This allows you to iterate on the edges array directly, with-out the need of a set class or iterator.
						>	This is easier, once you understand it.

		•	Implement Dijkstra’s Shortest-Distance Algorithm
			o	Pseudo-code is on page 772.
	 
		•	Create a Driver
			o	Create a non-interactive driver
				*	No menu
				*	Initialize your graph using
					•	add_edge and add_vertex
				*	Do a depth-first search and display the order of the vertices traversed
					•	Display the order in which dfs is executed.
					•	Use the sample graph that is in the book on page 754.
				*	Perform Dijkstra’s Algorithm  on all vertices in the graph
					•	Display a vertex pair and the shortest path cost.
					•	Use the sample graph that is in the book on page 766.
*/