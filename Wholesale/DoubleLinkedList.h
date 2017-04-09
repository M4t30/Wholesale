#pragma once
#include <iostream>
#include <sstream>
using namespace std;

template <class Type>
class DoubleLinkedList
{
public:
	static int _storageSize;
	bool isEmpty()
	{
		if (_first == NULL)
			return true;

		else
			return false;
	}
	string shortSpecification(int &amount)
	{
		Node *tmp = _first;
		string specificationStream;
		for (int i = 0; tmp; i++, tmp = tmp->next)
		{
			amount++;
			specificationStream += tmp->value.print() + "\n";
		}
		return specificationStream;
	}

	friend ostream& operator<<(ostream &outStream, DoubleLinkedList<Type> &object)
	{
		Node *tmp = object._first;

		for (int i = 0; tmp; i++, tmp = tmp->next)
			outStream << "[" << i << "]" << endl << tmp->value << endl;

		return outStream;
	}
	//-------------------------------------------------------------------------------
	struct Node
	{
		Type value;
		Node *prev;
		Node *next;
		Node() :prev(NULL), next(NULL) {}
	};
	//-------------------------------------------------------------------------------
	DoubleLinkedList() : _first(NULL), _last(NULL), _chosen(NULL) {}
	~DoubleLinkedList()
	{
		for (_chosen = _first; _chosen;)
		{
			Node *tmp;
			tmp = _chosen->next;

			delete _chosen;
			_chosen = tmp;
		}
	}

	void insert(Type &object)
	{
		Node *tmp = new Node;
		tmp->value = object;

		if (_first != NULL)
		{
			tmp->next = _first;
			_first->prev = tmp;
		}
		_first = tmp;

		if (_last == NULL)
			_last = tmp;


		_chosen = NULL;
	}
	bool remove(Type &object)
	{
		_chosen = find(object);

		if (!_chosen)
			return false;

		if (_chosen == _first)
		{
			removeFirst();
			return true;
		}
		else
		{
			if (_chosen == _last)
			{
				removeLast();
				return true;
			}

			else
			{
				removeFromTheMiddle();
				return true;
			}

			return false;
		}
	}
	static void changeSizeOfStorage(int size)
	{
		_storageSize = size;
	}

private:
	Node *_first, *_last, *_chosen;
	Node* find(Type &object)
	{
		DoubleLinkedList<Type>::Node *tmp = _first;
		while (tmp->value != object)
		{
			tmp = tmp->next;
			if (tmp == NULL)
				break;
		}
		return tmp;
	}
	void removeFirst()
	{
		_first = _first->next;
		delete _chosen;
		_chosen = _first;
		if (_first)
			_first->prev = 0;

		else
			_last = 0;
	}
	void removeLast()
	{
		Node *tmp = _chosen->prev;

		tmp->next = 0;
		_last = tmp;
		delete _chosen;
		_chosen = 0;
	}
	void removeFromTheMiddle()
	{
		Node *tmp = _chosen->prev;

		tmp->next = _chosen->next;
		_chosen->next->prev = tmp;
		delete _chosen;
		_chosen = tmp;
	}
};

template <class Type> int DoubleLinkedList<Type>::_storageSize = 100;