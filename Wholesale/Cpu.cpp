#include "Cpu.h"
#include <string>

//*******************************************************************************************************************
ostream& operator<<(ostream &outStream, Cpu &object)
{
	outStream << "Name: " << object._name << endl
		<< "Brand: " << object._brand << endl
		<< "Core Frequency: " << object._frequency << endl
		<< "Number of Cores: " << object._numberOfCores << endl
		<< "Number of Threads: " << object._numberOfThreads << endl
		<< "Socket: " << object._socket << endl
		<< "L1 Cache: " << object._l1Cache << endl
		<< "L2 Cache: " << object._l2Cache << endl
		<< "L3 Cache: " << object._l3Cache << endl
		<< "Manufacturing technology: " << object._manufacturingTechnology << endl
		<< "TDP: " << object._tdp << endl
		<< "Price: " << object._price << endl;
	return outStream;
}
//*******************************************************************************************************************
bool Cpu::operator!=(Cpu &object)
{
	if (this->_name != object._name || this->_brand != object._brand || this->_price != object._price
		|| this->_frequency != object._frequency || this->_numberOfCores != object._numberOfCores
		|| this->_numberOfThreads != object._numberOfThreads || this->_socket != object._socket
		|| this->_l1Cache != object._l1Cache || this->_l2Cache != object._l2Cache || this->_l3Cache != object._l3Cache
		|| this->_manufacturingTechnology != object._manufacturingTechnology || this->_tdp != object._tdp)

		return true;

	else
		return false;
}
//*******************************************************************************************************************
string Cpu::print()
{
	string specification;
	specification = this->_name + ";" + this->_brand + ";" + std::to_string(this->_frequency) + ";" +
		std::to_string(this->_numberOfCores) + ";" + std::to_string(this->_numberOfThreads) + ";" +
		this->_socket + ";" + std::to_string(this->_l1Cache) + ";" + std::to_string(this->_l2Cache) + ";" +
		std::to_string(this->_l3Cache) + ";" + std::to_string(this->_manufacturingTechnology) + ";" +
		std::to_string(this->_tdp) + ";" + std::to_string(this->_price) + ";";

	return specification;
}
//*******************************************************************************************************************