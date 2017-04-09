#include "Motherboard.h"

//*******************************************************************************************************************
ostream& operator<<(ostream &outStream, Motherboard &object)
{
	outStream << "Name: " << object._name << endl
		<< "Brand: " << object._brand << endl
		<< "SocketName: " << object._socketName << endl
		<< "ChipsetName: " << object._chipsetName << endl
		<< "Form Factor: " << object._formFactor << endl
		<< "Maximum supported memory: " << object._maximumMemorySupported << endl
		<< "Multi GPU support: " << object._multiGpuSupport << endl
		<< "Price: " << object._price << endl;
	return outStream;
}
//*******************************************************************************************************************
bool Motherboard::operator!=(Motherboard &object)
{
	if (this->_name != object._name || this->_brand != object._brand || this->_price != object._price
		|| this->_socketName != object._socketName || this->_chipsetName != object._chipsetName
		|| this->_formFactor != object._formFactor || this->_maximumMemorySupported != object._maximumMemorySupported
		|| this->_multiGpuSupport != object._multiGpuSupport)

		return true;

	else
		return false;
}
//*******************************************************************************************************************
string Motherboard::print()
{
	string specification;
	specification = this->_name + ";" + this->_brand + ";" + (this->_socketName) + ";" +
		(this->_chipsetName) + ";" + (this->_formFactor) + ";" + std::to_string(this->_maximumMemorySupported) + ";" + 
		this->_multiGpuSupport + ";" + std::to_string(this->_price) + ";";

	return specification;
}
//*******************************************************************************************************************