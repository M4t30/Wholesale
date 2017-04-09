#pragma once
#include <string>
#include <iostream>
using namespace std;

class Item
{
public:
	void setName(string name) { _name = name; }
	void setBrand(string brand) { _brand = brand; }
	void setPrice(double price) { _price = price; }
	string getName(string name) { return _name; }
	string getBrand(string brand) { return _brand; }
	double getPrice(double price) { return _price; }

protected:
	string _name;
	string _brand;
	double _price;
	Item(std::string name_ = "", string brand_ = "", double price_ = 0) : _name(name_), _brand(brand_), _price(price_) {}
};