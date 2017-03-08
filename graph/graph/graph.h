#pragma once

class graph
{
	public:
		graph(); // Constructor
		virtual ~graph(); // Destructor

		void add_edge();
		void add_vertex();
		void is_edge();
		void depth_first_search();

	private:
		// N/A
};

/*	Graphs (95 pts)

	Documentation (10 pts)
		Student name, Section and Disclaimer	______/5
		Proper function and class headers		______/5

	Graph Class (45 pts)
		Appropriate private data members		______/5
		Class Functions:						
			Constructor/Destructor/				______/5
			Add_edge							______/5
			Add_vertex							______/5
			Is_edge								______/5
			Depth-First Search					______/10

	Dijkstra’s Algorithm(20 pts)
		Correctly computes shortest paths for all vertex pairs	______/20

	Driver (20 pts)
		Non-Interactive driver						
			Output displayed correctly			______/10
			All functions used					______/10 */