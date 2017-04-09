#pragma once
#include "Item.h"

class Gpu :public Item
{
public:
	Gpu(string name_ = "", string brand_ = "", int coreFrequency_ = 0, int memoryFrequency_ = 0, int numberOfCores_ = 0,
		int sizeOfVideoMemory_ = 0, int memoryInterface_ = 0, int directX_ = 0, double openGL_ = 0, string maxResolution_ = "",
		int slotWidth_ = 0, int tdp_ = 0, double price_ = 0) :Item(name_, brand_, price_), _coreFrequency(coreFrequency_), _memoryFrequency(memoryFrequency_),
		_numberOfCores(numberOfCores_), _sizeOfVideoMemory(sizeOfVideoMemory_), _memoryInterface(memoryInterface_), _directX(directX_),
		_openGL(openGL_), _maxResolution(maxResolution_), _slotWidth(slotWidth_), _tdp(tdp_) {}

	friend ostream& operator<<(ostream &outStream, Gpu &object);
	bool operator!=(Gpu &object);
	string print();

	void setCoreFrequency(int coreFrequency) { _coreFrequency = coreFrequency; }
	void setMemoryFrequency(int memoryFrequency) { _memoryFrequency = memoryFrequency; }
	void setNumberOfCores(int numberOfCores) { _numberOfCores = numberOfCores; }
	void setSizeOfVideoMemory(int sizeOfVideoMemory) { _sizeOfVideoMemory = sizeOfVideoMemory; }
	void setDirectX(int directX) { _directX = directX; }
	void setOpenGL(double openGL) { _openGL = openGL; }
	void setMaxResolution(string maxResolution) { _maxResolution = maxResolution; }
	void setSlotWidth(int slotWidth) { _slotWidth = slotWidth; }
	void setTdp(int tdp) { _tdp = tdp; }
	int getCoreFrequency(int coreFrequency) { _coreFrequency = coreFrequency; }
	int getMemoryFrequency() { return _memoryFrequency; }
	int getNumberOfCores() { return _numberOfCores; }
	int getSizeOfVideoMemory() { return _sizeOfVideoMemory; }
	int getDirectX() { return _directX; }
	double getOpenGL() { return _openGL; }
	string getMaxResolution() { return _maxResolution; }
	int getSlotWidth() { return _slotWidth; }
	int getTdp() { return _tdp; }

private:
	int _coreFrequency;
	int _memoryFrequency;
	int _numberOfCores;
	int _sizeOfVideoMemory;
	int _memoryInterface;
	int _directX;
	double _openGL;
	string _maxResolution;
	int _slotWidth;
	int _tdp;
};
