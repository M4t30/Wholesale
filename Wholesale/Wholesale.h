//#pragma once
//#include <iostream>
//#include <fstream>
//#include <sstream>
//#include "DijkstrasAlgorithm.h"
//#include "DoubleLinkedList.h"
//#include "Gpu.h"
//#include "Cpu.h"
//#include "Ram.h"
//#include "Motherboard.h"
//#include "PowerSupply.h"
//using namespace std;
//
//class Wholesale
//{
//protected:
//	DoubleLinkedList<Cpu> _cpuWarehouse;
//	DoubleLinkedList<Gpu> _gpuWarehouse;
//	DoubleLinkedList<Ram> _ramWarehouse;
//	DoubleLinkedList<PowerSupply> _psWarehouse;
//	DoubleLinkedList<Motherboard> _moboWarehouse;
//	int **_distanceArray;
//	Map _deliveryMap;
//	virtual void createGoodsBackupFile() = 0;
//	virtual string** readFile() = 0;
//	virtual string createFileName() = 0;
//	virtual void goodsAcceptance() = 0;
//	virtual void goodsRelease() = 0;
//	virtual void print() = 0;
//	//virtual void delivery() = 0; email function 
//};