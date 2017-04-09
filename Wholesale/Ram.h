#pragma once
#include "Item.h"

class Ram :public Item
{
public:
	Ram(string name_ = "", string brand_ = "", int size_ = 0, double voltage_ = 0, string type_ = "", int casLatency_ = 0, double price_ = 0) :
		Item(name_, brand_, price_), _size(size_), _voltage(voltage_), _type(type_), _casLatency(casLatency_) {}

	friend ostream& operator<<(ostream &outStream, Ram &object);
	bool operator!=(Ram &object);
	string print();

	void setSize(int size) { _size = size; }
	void setVoltage(double voltage) { _voltage = voltage; }
	void setType(string type) { _type = type; }
	void setCasLatency(int casLatency) { _casLatency = casLatency; }
	int getSize() { return _size; }
	double getVoltage() { return _voltage; }
	string getType() { return _type; }
	int getCasLatency() { return _casLatency; }

private:
	int _size;
	double _voltage;
	string _type;
	int _casLatency;
};
