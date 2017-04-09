#pragma once
#include "Item.h"

class Motherboard :public Item
{
public:
	Motherboard(string name_ = "", string brand_ = "", string socketName_ = "", string chipsetName_ = "", string formFactor_ = "",
		int maximumMemorySupported_ = 0, string multiGpuSupport_ = "", double price_ = 0) :Item(name_, brand_, price_), _socketName(socketName_),
		_chipsetName(chipsetName_), _formFactor(formFactor_), _maximumMemorySupported(maximumMemorySupported_), _multiGpuSupport(multiGpuSupport_) {}

	friend ostream& operator<<(ostream &outStream, Motherboard &object);
	bool operator!=(Motherboard &object);
	string print();

	void setSocketName(string socketName) { _socketName = socketName; }
	void setChipsetName(string chipsetName) { _chipsetName = chipsetName; }
	void setFormFactor(string formfactor) { _formFactor = formfactor; }
	void setMaximumMemorySupported(int maximumMemorySupported) { _maximumMemorySupported = maximumMemorySupported; }
	void setMultiGpuSupport(string multiGpuSupport) { _multiGpuSupport = multiGpuSupport; }
	string getSocketName() { return _socketName; }
	string getChipsetName() { return _chipsetName; }
	string getFormFactor() { return _formFactor; }
	int getMaximumMemorySupported() { return _maximumMemorySupported; }
	string getMultiGpuSupport() { return _multiGpuSupport; }


private:
	string _socketName;
	string _chipsetName;
	string _formFactor;
	int _maximumMemorySupported;
	string _multiGpuSupport;
};
