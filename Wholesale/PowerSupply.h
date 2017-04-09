#pragma once
#include "Item.h"

class PowerSupply :public Item
{
public:
	PowerSupply(string name_ = "", string brand_ = "", int power_ = 0, string efficiency_ = "", double price_ = 0)
		:Item(name_, brand_, price_), _power(power_), _efficiency(_efficiency) {}

	friend ostream& operator<<(ostream &outStream, PowerSupply &object);
	bool operator!=(PowerSupply &object);
	string print();

	void setPower(int power) { _power = power; }
	void setEfficiency(string efficiency) { _efficiency = efficiency; }
	int setPower() { return _power; }
	string setEfficiency() { return _efficiency; }

private:
	int _power;
	string _efficiency;
};