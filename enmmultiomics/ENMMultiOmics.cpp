// ENMMultiOmics.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include "innerGraph.h"

using namespace std;


int main()
{
	innerGraph g(5);
	g.addEdge(1, 10);
	g.addEdge(1, 11);
	g.addEdge(1, 19);
	g.addEdge(2, 23);
	g.addEdge(2, 24);
	g.addEdge(2, 27);
	g.addEdge(2, 29);
	g.printVerticesFrom(1);
	g.printVerticesFrom(2);

	return 0;
}