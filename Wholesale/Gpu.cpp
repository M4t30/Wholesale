#include "Gpu.h"

//*******************************************************************************************************************
ostream& operator<<(ostream &outStream, Gpu &object)
{
	outStream << "Name: " << object._name << endl
		<< "Brand: " << object._brand << endl
		<< "Core Frequency: " << object._coreFrequency << endl
		<< "Memory Frequency: " << object._memoryFrequency << endl
		<< "Number of Cores: " << object._numberOfCores << endl
		<< "Size of video memory: " << object._sizeOfVideoMemory << endl
		<< "Memory interface: " << object._memoryInterface << endl
		<< "DirectX: " << object._directX << endl
		<< "OpenGL: " << object._openGL << endl
		<< "Max resolution: " << object._maxResolution << endl
		<< "Slot width: " << object._slotWidth << endl
		<< "TDP: " << object._tdp << endl
		<< "Price: " << object._price << endl;
	return outStream;
}
//*******************************************************************************************************************
bool Gpu::operator!=(Gpu &object)
{
	if (this->_name != object._name || this->_brand != object._brand || this->_price != object._price
		|| this->_coreFrequency != object._coreFrequency || this->_numberOfCores != object._numberOfCores
		|| this->_memoryFrequency != object._memoryFrequency || this->_sizeOfVideoMemory != object._sizeOfVideoMemory
		|| this->_memoryInterface != object._memoryInterface || this->_directX != object._directX || this->_openGL != object._openGL
		|| this->_maxResolution != object._maxResolution || this->_tdp != object._tdp || this->_slotWidth || object._slotWidth)

		return true;

	else
		return false;
}
//*******************************************************************************************************************
string Gpu::print() 
{
	string specification;
	specification = this->_name + ";" + this->_brand + ";" + std::to_string(this->_coreFrequency) + ";" +
		std::to_string(this->_memoryFrequency) + ";" + std::to_string(this->_numberOfCores) + ";" + 
		std::to_string(this->_sizeOfVideoMemory) + ";" + std::to_string(this->_memoryInterface) + ";" +
		std::to_string(this->_directX) + ";" + std::to_string(this->_openGL) + ";" +
		this->_maxResolution + ";" + std::to_string(this->_slotWidth) + ";" + 
		std::to_string(this->_tdp) + ";" + std::to_string(this->_price) + ";";

	return specification;
}
//*******************************************************************************************************************
