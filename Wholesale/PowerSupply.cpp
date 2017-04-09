#include "PowerSupply.h"

//*******************************************************************************************************************
ostream& operator<<(ostream &outStream, PowerSupply &object)
{
	outStream << "Name: " << object._name << endl
		<< "Brand: " << object._brand << endl
		<< "Power: " << object._power << endl
		<< "Efficiency: " << object._efficiency << endl
		<< "Price: " << object._price << endl;
	return outStream;
}
//*******************************************************************************************************************
bool PowerSupply::operator!=(PowerSupply &object)
{
	if (this->_name != object._name || this->_brand != object._brand || this->_price != object._price
		|| this->_power != object._power || this->_efficiency != object._efficiency)

		return true;

	else
		return false;
}
//*******************************************************************************************************************
string PowerSupply::print()
{
	string specification;
	specification = this->_name + ";" + this->_brand + ";" + std::to_string(this->_power) + ";" +
		this->_efficiency + ";" + std::to_string(this->_price) + ";";

	return specification;
}
//*******************************************************************************************************************