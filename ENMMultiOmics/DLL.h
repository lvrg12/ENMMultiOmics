#pragma once
#include <iostream>
#include <string>

using namespace std;

template<class T>
class DLLNode
{
	public:
		DLLNode()
		{
			next = prev = NULL;
		}
		DLLNode(const T& element, DLLNode<T> *n = NULL, DLLNode<T> *p = NULL)
		{
			info = element;
			next = n;
			prev = p;
		}
		T info;
		DLLNode<T> *next, *prev;
};

template<class T>
class DoublyLinkedList
{
	public:
		DoublyLinkedList()
		{
			head = tail = NULL;
		}

		~DoublyLinkedList()
		{
			clear();
		}

		bool isEmpty() const
		{
			return head == NULL; // 1 if Empy
		}
		
		void setToNull()
		{
			head = tail = NULL;
		}

		DLLNode<T>* getHead()
		{
			return head;
		}

		void addToDLLTail(const T&);
		T deleteFromDLLTail();
		void clear();
		void addToDLLHead(const T&);
		T deleteFromDLLHead();
		T& firstElement();
		T& lastElement();
		DLLNode<T> *headNode();
		DLLNode<T> *tailNode();
		T* find(const T&) const;
		void printDLL();

	protected:

		DLLNode<T> *head, *tail;
		friend ostream& operator<<(ostream& out, const DoublyLinkedList<T>& dll)
		{
			for (DLLNode<T> *tmp = dll.headNode; tmp != NULL)
			{
				out << tmp->info << ' ';
			}

			return out;
		}
};

template<class T>
DLLNode<T> *DoublyLinkedList<T>::headNode()
{
	return head;
}

template<class T>
DLLNode<T> *DoublyLinkedList<T>::tailNode()
{
	return tail;
}

template<class T>
void DoublyLinkedList<T>::addToDLLHead(const T& el)
{
	if (head != NULL)
	{
		head = new DLLNode<T>(el, head, NULL);
		head->next->prev = head;
	}
	else
	{
		head = tail = new DLLNode<T>(el);
	}
}

template<class T>
void DoublyLinkedList<T>::addToDLLTail(const T& el)
{
	if (tail != NULL)
	{
		tail = new DLLNode<T>(el, NULL, tail);
		tail->prev->next = tail;
	}
	else
	{
		head = tail = new DLLNode<T>(el);
	}
}

template<class T>
T DoublyLinkedList<T>::deleteFromDLLHead()
{
	T el = head->info;
	if (head == tail)
	{
		delete head;
		head = tail = NULL;
	}
	else
	{
		head = head->next;
		delete head->prev;
		head->prev = NULL;
	}
	return el;
}

template<class T>
T DoublyLinkedList<T>::deleteFromDLLTail()
{
	T el = tail->info;
	if (head == tail)
	{
		delete tail;
		head = tail = NULL;
	}
	else
	{
		tail = tail->prev;
		delete tail->next;
		tail->next = NULL;
	}
	return el;
}

template<class T>
T* DoublyLinkedList<T>::find(const T& el) const
{
	DLLNode<T> *tmp = head;
	for (; tmp != NULL && !(tmp->info == el); tmp = tmp->next);
	if (tmp == NULL)
		return NULL;
	else return &tmp->info;
}

template<class T>
T& DoublyLinkedList<T>::firstElement()
{
	if (isEmpty())
	{
		throw string("The list is empty.");
	}
	return head->info;
}

template<class T>
T& DoublyLinkedList<T>::lastElement()
{
	if (isEmpty())
	{
		throw string("The list is empty.");
	}
	return tail->info;
}

template<class T>
void DoublyLinkedList<T>::clear()
{
	for (DLLNode<T> *tmp; head != NULL; )
	{
		tmp = head;
		head = head->next;
		delete tmp;
	}
}

template<class T>
void DoublyLinkedList<T>::printDLL()
{
	DLLNode<T> *tmp = head;

	if (tmp == NULL)
	{
		cout << "List is empty" << endl;
	}
	else
	{
		for (; tmp != NULL; tmp = tmp->next)
		{
			cout << to_string(tmp->info) << endl;
		}
	}
}