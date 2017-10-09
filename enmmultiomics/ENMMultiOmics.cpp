// ENMMultiOmics.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include "DLL.h"

using namespace std;


int main()
{
	DoublyLinkedList<int> myList;
	cout << "Empty?" << myList.isEmpty() << endl;
	myList.addToDLLHead(1);
	myList.addToDLLHead(2);
	myList.addToDLLHead(4);
	myList.addToDLLTail(0);
	myList.deleteFromDLLHead();
	myList.deleteFromDLLTail();
	myList.addToDLLHead(3);
	cout << "Empty?" << myList.isEmpty() << endl;
	myList.printDLL();

	return 0;
}