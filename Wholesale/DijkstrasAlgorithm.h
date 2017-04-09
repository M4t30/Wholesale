#pragma once
#include "Map.h"
#include <iostream>

class DijkstrasAlgorithm
{
public:
	static int** dijkstrasAlgorithm(Map &minimap, int vertex, int **&distanceArray);
	static void showTheWayFromXtoY(int from, int too, int** Dijkstras_array, Map &minimap);

private:
	static void printRoute(int indeks, int **Dijkstras_array, int &distance);
	static bool allBlackDijkstra(int **array, int size);
	static int findClosest(int **array, int size);
	static void addValuesToArray(int **array, int too, int dist, int prev, int color, bool relaxation);
};