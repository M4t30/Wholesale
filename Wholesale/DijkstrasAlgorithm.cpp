#include "DijkstrasAlgorithm.h"
#include <iostream>

//*******************************************************************************************************************
int** DijkstrasAlgorithm::dijkstrasAlgorithm(Map &minimap, int vertex, int **&distanceArray)
{
	distanceArray = new int *[minimap._LNSize];//tworzenie macierzy odleglosci do wierzcholkow
	for (int i = 0; i < minimap._LNSize; i++)
		distanceArray[i] = new int[3];

	for (int i = 0; i < minimap._LNSize; i++) //nadawanie poczatkowych wartosci macierzy
	{
		distanceArray[i][0] = 0;
		distanceArray[i][1] = -1;
		distanceArray[i][2] = -1;
	}

	distanceArray[vertex][0] = 1; //ustawiam jako szary wierzcholek od ktorego liczona bedzie odleglosc
	distanceArray[vertex][1] = 0; //ustawiam odlegosc do tego wierzcholka jako 0
	distanceArray[vertex][2] = -1;//ustawiam ze jego poprzednik nie istnieje

	bool stop = false;

	while (stop == false)
	{
		Map::Node *tmpLN = minimap._LN[vertex];

		while (tmpLN != 0) //uwaga na to bo bylo tu null
		{
			if (distanceArray[tmpLN->too][0] != 2)
			{
				if (distanceArray[tmpLN->too][0] == 0)
					addValuesToArray(distanceArray, tmpLN->too, (distanceArray[vertex][1] + tmpLN->dist), vertex, 1, false);

				else if (distanceArray[tmpLN->too][1] > (distanceArray[vertex][1] + tmpLN->dist))//relaksacja
					addValuesToArray(distanceArray, tmpLN->too, distanceArray[vertex][1] + tmpLN->dist, vertex, 1, true);
			}

			tmpLN = tmpLN->next;
		}

		addValuesToArray(distanceArray, vertex, 0, -1, 2, false);//ustawianie wierzcholka jako czarnego

		vertex = findClosest(distanceArray, minimap._LNSize);//znajdowanie najblizszego wierzcholka sposrod szarych

		stop = allBlackDijkstra(distanceArray, minimap._LNSize);
	}

	return distanceArray;
}
//***********************************************************************************************
bool DijkstrasAlgorithm::allBlackDijkstra(int **array, int size)
{
	for (int i = 0; i < size; i++)
		if (array[i][0] != 2)
			return false;

	return true;
}
//***********************************************************************************************
int DijkstrasAlgorithm::findClosest(int **array, int size)
{
	int index = -1;
	int dist = -1;

	for (int i = 0; i < size; i++)
	{
		if (array[i][0] == 1)
		{
			if (index == -1)
			{
				index = i;
				dist = array[i][1];
			}
			else if (dist > array[i][1])
			{
				index = i;
				dist = array[i][1];
			}
		}
	}

	return index;
}
//***********************************************************************************************
void DijkstrasAlgorithm::addValuesToArray(int **array, int too, int dist, int prev, int color, bool relaxation)
{
	array[too][0] = color;

	if (array[too][1] == -1)
		array[too][1] = 0;

	if (relaxation == false)
		array[too][1] += dist;

	else
		array[too][1] = dist;

	if (prev != -1)
		array[too][2] = prev;
}
//*******************************************************************************************************************
void DijkstrasAlgorithm::showTheWayFromXtoY(int from, int too, int** Dijkstras_array, Map &minimap)
{
	int distance = 0;
	printRoute(too, Dijkstras_array, distance);
	std::cout << " Distance: " << distance << std::endl;
}
//***********************************************************************************************
void DijkstrasAlgorithm::printRoute(int indeks, int ** Dijkstras_array, int &distance)
{
	if (Dijkstras_array[indeks][2] != -1)
	{
		printRoute(Dijkstras_array[indeks][2], Dijkstras_array, distance);
		std::cout << "->";
	}

	distance += Dijkstras_array[indeks][1];
	if (indeks == 0)
		std::cout << "Krakow";
	else if (indeks == 1)
		std::cout << "Wroclaw";
	else if (indeks == 2)
		std::cout << "Warszawa";
	else if (indeks == 3)
		std::cout << "Szczecin";
	else
		std::cout << "Gdansk";
}
//*******************************************************************************************************************