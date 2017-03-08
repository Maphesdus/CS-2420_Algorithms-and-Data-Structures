#pragma once

#ifndef INCLUDES
#define INCLUDES
	#include <string>
	#include <iostream>
	using namespace std;
#endif


class Node
{
	private:
		Node* _frontNode;
		Node* _rearNode;
		int _nodeNumber;

	public:
		Node(int);
		virtual ~Node();
		void LinkFront(Node*);
		void LinkRear(Node*);
};

class DLink_List
{
	private:
		Node* _headPtr;
		Node* _endPtr;
		static int count;

	public:
		DLink_List(void);
		virtual ~DLink_List(void);
		void Link_Front(Node*);
		void Link_End(Node*);
};