// ENMMultiOmics.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include "innerGraph.h"

using namespace std;


int main()
{
	innerGraph<int> g;
	g.addVertice(1);
	g.addVertice(11);
	g.addVertice(19);
	g.addVertice(2);
	g.addVertice(23);
	g.addVertice(24);
	g.addVertice(1165);
	g.addVertice(1100);
	g.addEdge(1, 11);
	g.addEdge(1, 19);
	g.addEdge(2, 23);
	g.addEdge(2, 24);
	g.addEdge(11, 1165);
	g.addEdge(11, 1100);
	g.printVerticesFrom(1);
	g.printVerticesFrom(2);
	g.printVerticesFrom(11);
	g.printAllVertices();

	return 0;
}