#pragma once
#include "Item.h"

class Cpu :public Item
{
public:
	Cpu(string name_ = "", string brand_ = "", int frequency_ = 0, int numberOfCores_ = 0, int numberOfThreads_ = 0, string socket_ = "",
		int l1Cache_ = 0, int l2Cache_ = 0, int l3Cache_ = 0, int manufacturingTechnology_ = 0, int tdp_ = 0, double price_ = 0)
		:Item(name_, brand_, price_), _frequency(frequency_), _numberOfCores(numberOfCores_), _numberOfThreads(numberOfThreads_),
		_socket(socket_), _l1Cache(l1Cache_), _l2Cache(l2Cache_), _l3Cache(l3Cache_), _manufacturingTechnology(manufacturingTechnology_), _tdp(tdp_) {}

	friend ostream& operator<<(ostream &outStream, Cpu &object);
	bool operator!=(Cpu &object);
	string print();

	void setFrequency(int frequency) { _frequency = frequency; }
	void setNumberOfCores(int numberOfCores) { _numberOfCores = numberOfCores; }
	void setNumberOfThreads(int numberOfThreads) { _numberOfThreads = numberOfThreads; }
	void setSocket(int socket) { _socket = socket; }
	void setL1Chache(int l1Cache) { _l1Cache = l1Cache; }
	void setL2Chache(int l2Cache) { _l2Cache = l2Cache; }
	void setL3Chache(int l3Cache) { _l3Cache = l3Cache; }
	void setManufactoringTechnology(int manufacturingTechnology) { _manufacturingTechnology = manufacturingTechnology; }
	void setTdp(int tdp) { _tdp = tdp; }
	int getFrequency() { return _frequency; }
	int getNumberOfCores() { return _numberOfCores; }
	int getNumberOfThreads() { return _numberOfThreads; }
	string getSocket() { return _socket; }
	int getL1Chache() { return _l1Cache; }
	int getL2Chache() { return _l2Cache; }
	int getL3Chache() { return _l3Cache; }
	int getManufactoringTechnology() { return _manufacturingTechnology; }
	int getTdp() { return _tdp; }

private:
	int _frequency;
	int _numberOfCores;
	int _numberOfThreads;
	string _socket;
	int _l1Cache;
	int _l2Cache;
	int _l3Cache;
	int _manufacturingTechnology;
	int _tdp;
};
