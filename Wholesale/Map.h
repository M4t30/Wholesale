#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

class Map
{
public:
	friend class DijkstrasAlgorithm;
	friend class Headquater;
	void readFile();
	//-------------------------------------------------------------------------------
	struct Node
	{
		int from, too, dist;
		Node* next;
		Node() : from(0), too(0), dist(0), next(0) {}
	};
	//-------------------------------------------------------------------------------
	~Map();

private:
	std::string createFileName();
	void addToListOfNeighbours(Node* &list, int dist, int too, Node *&tail);
	Node **_LN;
	int _LNSize;
};
