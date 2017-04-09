#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include "DijkstrasAlgorithm.h"
#include "DoubleLinkedList.h"
#include "Gpu.h"
#include "Cpu.h"
#include "Ram.h"
#include "Motherboard.h"
#include "PowerSupply.h"
using namespace std;

class Headquater
{
public:
	Headquater();
	void createGoodsBackupFile();
	void goodsAcceptance();
	void goodsRelease();
	void print();
	void printRoute();
private:
	DoubleLinkedList<Cpu> _cpuWarehouse;
	DoubleLinkedList<Gpu> _gpuWarehouse;
	DoubleLinkedList<Ram> _ramWarehouse;
	DoubleLinkedList<PowerSupply> _psWarehouse;
	DoubleLinkedList<Motherboard> _moboWarehouse;
	int **_distanceArray;
	Map _deliveryMap;
	int _ammountOfGoods;
	string createFileName();
	string** readFile();
	string *_whereToDeliver;
	void changeCityNames();
	int eraseSameCities();
};

