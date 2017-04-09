#include "Ram.h"

//*******************************************************************************************************************
ostream& operator<<(ostream &outStream, Ram &object)
{
	outStream << "Name: " << object._name << endl
		<< "Brand: " << object._brand << endl
		<< "Type: " << object._type << endl
		<< "Size: " << object._size << endl
		<< "Cas Latency: " << object._casLatency << endl
		<< "Voltage: " << object._voltage << endl
		<< "Price: " << object._price << endl;
	return outStream;
}
//*******************************************************************************************************************
bool Ram::operator!=(Ram &object)
{
	if (this->_name != object._name || this->_brand != object._brand || this->_price != object._price
		|| this->_size != object._size || this->_voltage != object._voltage
		|| this->_type != object._type || this->_casLatency != object._casLatency)

		return true;

	else
		return false;
}
//*******************************************************************************************************************
string Ram::print()
{
	string specification;
	specification = this->_name + ";" + this->_brand + ";" + std::to_string(this->_size) + ";" +
		std::to_string(this->_voltage) + ";" + this->_type + ";" + std::to_string(this->_casLatency) + ";" + 
		std::to_string(this->_price) + ";";

	return specification;
}
//*******************************************************************************************************************