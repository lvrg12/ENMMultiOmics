#pragma once
#include <iostream>
#include "stdio.h"
#include "DLL.h"

using namespace std;

//directed graph using adjacency list representation
class innerGraph
{
	public:
		innerGraph(int V);
		void addEdge(int v, int w);
		void printVerticesFrom(int v);

	protected:
		int V; //number of vertices
		DoublyLinkedList<int> *adj; //pointer to array containing adjacency lists
};

innerGraph::innerGraph(int V)
{
	this->V = V;
	adj = new DoublyLinkedList<int>[V];
	int i = 0;
	for (; i < V; i++)
	{
		adj[i] = *(new DoublyLinkedList<int>());
	}
}

void innerGraph::addEdge(int v, int w)
{
	adj[v].addToDLLTail(w); //Add w to v's list
}

void innerGraph::printVerticesFrom(int v)
{
	cout << v << endl;
	cout << "vvvvvvv" << endl;
	adj[v].printDLL();
	cout << endl;
}