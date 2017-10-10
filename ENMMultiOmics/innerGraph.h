#pragma once
#include <iostream>
#include <map>
#include "stdio.h"
#include "DLL.h"

using namespace std;

//directed graph using adjacency list representation
template<class T>
class innerGraph
{
	public:
		innerGraph();
		void addEdge(const T& a, const T& b);
		void addVertice(const T& a);
		void printVerticesFrom(const T& a);
		void printAllVertices();

	protected:
		int V; //number of vertices
		map<T, DoublyLinkedList<T>> adj;
};

template<class T>
innerGraph<T>::innerGraph()
{
	this->V = NULL;
}

template<class T>
void innerGraph<T>::addVertice(const T& a)
{
	adj[a];
}

template<class T>
void innerGraph<T>::addEdge(const T& a, const T& b)
{
	if (adj.find(b) == adj.end())
	{
		//do not do anything
		cout << "destination vertice has not been added to graph" << endl;
	}
	else
	{
		adj[a].addToDLLTail(b); //Add b to a's list
	}
}

template<class T>
void innerGraph<T>::printVerticesFrom(const T& a)
{
	cout << a << endl;
	cout << "vvvvvvv" << endl;
	adj[a].printDLL();
	cout << endl;
}

template<class T>
void innerGraph<T>::printAllVertices()
{
	for (map<T, DoublyLinkedList<T>>::iterator it = adj.begin(); it != adj.end(); ++it)
	{
		cout << it->first << endl;
		cout << "vvvvvvv" << endl;
		it->second.printDLL();
		cout << endl;
	}
	//prints repeated vectors and its connections
	//fix bug
}