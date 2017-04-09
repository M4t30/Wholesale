#include "Map.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

//*******************************************************************************************************************
Map::~Map()
{
	for (int i = 0; i < _LNSize; i++)
		delete _LN[i];

	delete[] _LN;
}
//*******************************************************************************************************************
string Map::createFileName()
{
	string fileName;
	string filePath = "D:\\AGH University of science and technology\\Rok II Semestr I\\Programowanie Obiektowe\\Laboratoria\\Wholesale\\Map\\";
	cout << "Enter file map name, which you want to open: ";
	cin >> fileName;
	filePath += fileName + ".txt";
	return filePath;
}
//*******************************************************************************************************************
void Map::readFile()
{
	fstream fileStream;
	int value = 0;
	Node *tail = NULL;

	try
	{
		fileStream.open(createFileName().c_str(), ios::in);

		if (fileStream.good())
		{
			fileStream >> _LNSize;

			_LN = new Node *[_LNSize];

			for (int i = 0; i < _LNSize; i++)
				_LN[i] = NULL;

			for (int i = 0; i < _LNSize; i++)
			{
				tail = NULL;                        
				for (int j = 0; j < _LNSize; j++)
				{
					fileStream >> value;
					if (value != NULL)
						addToListOfNeighbours(_LN[i], value, j, tail);
				}
			}
			fileStream.close();
		}

		else
			throw 1;
	}

	catch (int)
	{
		cout << "Error loading map!\n!!Exiting programme!!" << endl;

		system("PAUSE");
		exit(1);
	}
}
//*******************************************************************************************************************
void Map::addToListOfNeighbours(Node *&list, int dist, int too, Node * &tail)
{
	Node *tmp = new Node;
	tmp->too = too;
	tmp->dist = dist;
	if (list == NULL)
	{
		tmp->next = list;
		list = tmp;
		tail = list;
	}

	else
	{
		tail->next = tmp;
		tail = tail->next;
		tmp->next = NULL;
	}
}
//*******************************************************************************************************************