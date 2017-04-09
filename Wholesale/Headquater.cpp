#include "Headquater.h"

//*******************************************************************************************************************
Headquater::Headquater()
{
	_deliveryMap.readFile();
}
//*******************************************************************************************************************
void Headquater::print()
{
	cout << "All Cpus:" << endl;
	(this->_cpuWarehouse.isEmpty()) ? cout << "CPU WAREHOUSE IS EMPTY\n" : cout << this->_cpuWarehouse;
	cout << "All Gpus:" << endl;
	(this->_gpuWarehouse.isEmpty()) ? cout << "GPU WAREHOUSE IS EMPTY\n" : cout << this->_gpuWarehouse;
	cout << "All Motherboards:" << endl;
	(this->_moboWarehouse.isEmpty()) ? cout << "MOTHERBOARD WAREHOUSE IS EMPTY\n" : cout << this->_moboWarehouse;
	cout << "All Power Supplies:" << endl;
	(this->_psWarehouse.isEmpty()) ? cout << "POWER SUPPLY WAREHOUSE IS EMPTY\n" : cout << this->_psWarehouse;
	cout << "All Rams:" << endl;
	(this->_ramWarehouse.isEmpty()) ? cout << "RAM WAREHOUSE IS EMPTY\n" : cout << this->_ramWarehouse;
}
//*******************************************************************************************************************
void Headquater::createGoodsBackupFile()
{
	int amountOfGoods = 0;
	string everything;
	everything += this->_cpuWarehouse.shortSpecification(amountOfGoods);
	everything += this->_gpuWarehouse.shortSpecification(amountOfGoods);
	everything += this->_moboWarehouse.shortSpecification(amountOfGoods);
	everything += this->_psWarehouse.shortSpecification(amountOfGoods);
	everything += this->_ramWarehouse.shortSpecification(amountOfGoods);

	fstream fileWithAllGoods("D:\\AGH University of science and technology\\Rok II Semestr I\\Programowanie Obiektowe\\Laboratoria\\Wholesale\\Goods\\backup.csv", ios::out);
	if (fileWithAllGoods.good())
	{
		fileWithAllGoods << amountOfGoods << ";" << endl;
		fileWithAllGoods << everything;
		fileWithAllGoods.close();
	}
}
//*******************************************************************************************************************
string Headquater::createFileName()
{
	string fileName;
	string filePath = "D:\\AGH University of science and technology\\Rok II Semestr I\\Programowanie Obiektowe\\Laboratoria\\Wholesale\\Goods\\";
	cout << "Enter file name: (Pattern: filename_dd.mm.yy): ";
	cin >> fileName;
	filePath += fileName + ".csv";
	return filePath;
}
//*******************************************************************************************************************
string** Headquater::readFile()
{
	fstream fileStream;
	string line = "";
	stringstream seter;
	bool fileOpen = false;
	string **fileData = NULL;
	do
	{
		fileStream.open(createFileName().c_str(), ios::in);

		if (fileStream.good())
		{
			getline(fileStream, line, '\n');
			_ammountOfGoods = stoi(line);
			fileData = new string *[_ammountOfGoods];
			for (int j = 0; j < _ammountOfGoods; j++)
				fileData[j] = new string[14];

			for (int i = 0; i < _ammountOfGoods; i++)
			{
				for (int j = 0; j < 14; j++)
				{
					if (fileStream.peek() == '\n')
					{
						fileStream.ignore(1);
						break;
					}
					getline(fileStream, fileData[i][j], ';');
				}
			}
			fileOpen = true;
		}

		else
		{
			fileStream.clear();
			fileOpen = false;
			cout << "Error opening file" << endl;
		}

	} while (!fileOpen);

	fileStream.close();
	return fileData;
}
//*******************************************************************************************************************
void Headquater::goodsAcceptance()
{
	string** cargo = readFile();

	for (int i = 0; i < _ammountOfGoods; i++)
	{
		if (cargo[i][0] == "cpu")
		{
			_cpuWarehouse.insert(Cpu(cargo[i][0], cargo[i][1], stoi(cargo[i][2]), stoi(cargo[i][3]), stoi(cargo[i][4]),
				cargo[i][5], stoi(cargo[i][6]), stoi(cargo[i][7]), stoi(cargo[i][8]), stoi(cargo[i][9]),
				stoi(cargo[i][10]), stod(cargo[i][11])));
		}

		if (cargo[i][0] == "gpu")
		{
			_gpuWarehouse.insert(Gpu(cargo[i][0], cargo[i][1], stoi(cargo[i][2]), stoi(cargo[i][3]), stoi(cargo[i][4]),
				stoi(cargo[i][5]), stoi(cargo[i][6]), stoi(cargo[i][7]), stod(cargo[i][8]), cargo[i][9],
				stoi(cargo[i][10]), stoi(cargo[i][11]), stod(cargo[i][12])));
		}

		if (cargo[i][0] == "motherboard")
		{
			_moboWarehouse.insert(Motherboard(cargo[i][0], cargo[i][1], cargo[i][2], cargo[i][3], cargo[i][4],
				stoi(cargo[i][5]), cargo[i][6], stod(cargo[i][7])));
		}

		if (cargo[i][0] == "powersupply")
		{
			_psWarehouse.insert(PowerSupply(cargo[i][0], cargo[i][1], stoi(cargo[i][2]), cargo[i][3], stod(cargo[i][4])));
		}

		if (cargo[i][0] == "ram")
		{
			_ramWarehouse.insert(Ram(cargo[i][0], cargo[i][1], stoi(cargo[i][2]), stod(cargo[i][3]), cargo[i][4],
				stoi(cargo[i][5]), stod(cargo[i][6])));
		}
	}

	for (int i = 0; i < _ammountOfGoods; i++)
		delete[] cargo[i];

	delete[] cargo;
}
//*******************************************************************************************************************
void Headquater::goodsRelease()
{
	string **cargo = readFile();
	_whereToDeliver = new string[_ammountOfGoods+1];
	
	_whereToDeliver[0] = "Warszawa";
	bool found = false;

	for (int i = 0; i < _ammountOfGoods; i++)
	{
		if (cargo[i][0] == "cpu")
		{
			found = _cpuWarehouse.remove(Cpu(cargo[i][0], cargo[i][1], stoi(cargo[i][2]), stoi(cargo[i][3]), stoi(cargo[i][4]),
				cargo[i][5], stoi(cargo[i][6]), stoi(cargo[i][7]), stoi(cargo[i][8]), stoi(cargo[i][9]),
				stoi(cargo[i][10]), stod(cargo[i][11])));

			if (found)
				_whereToDeliver[i + 1] = cargo[i][12];
		}

		if (cargo[i][0] == "gpu")
		{
			found = _gpuWarehouse.remove(Gpu(cargo[i][0], cargo[i][1], stoi(cargo[i][2]), stoi(cargo[i][3]), stoi(cargo[i][4]),
				stoi(cargo[i][5]), stoi(cargo[i][6]), stoi(cargo[i][7]), stod(cargo[i][8]), cargo[i][9],
				stoi(cargo[i][10]), stoi(cargo[i][11]), stod(cargo[i][12])));

			if (found)
				_whereToDeliver[i + 1] = cargo[i][13];
		}

		if (cargo[i][0] == "motherboard")
		{
			found = _moboWarehouse.remove(Motherboard(cargo[i][0], cargo[i][1], cargo[i][2], cargo[i][3], cargo[i][4],
				stoi(cargo[i][5]), cargo[i][6], stod(cargo[i][7])));

			if(found)
				_whereToDeliver[i + 1] = cargo[i][8];
		}

		if (cargo[i][0] == "powersupply")
		{
			found = _psWarehouse.remove(PowerSupply(cargo[i][0], cargo[i][1], stoi(cargo[i][2]), cargo[i][3], stod(cargo[i][4])));

			if(found)
				_whereToDeliver[i + 1] = cargo[i][5];
		}

		if (cargo[i][0] == "ram")
		{
			found = _ramWarehouse.remove(Ram(cargo[i][0], cargo[i][1], stoi(cargo[i][2]), stod(cargo[i][3]), cargo[i][4],
				stoi(cargo[i][5]), stod(cargo[i][6])));

			if(found)
				_whereToDeliver[i + 1] = cargo[i][7];
		}
	}

	for (int i = 0; i < _ammountOfGoods; i++)
		delete[] cargo[i];

	delete[] cargo;

	printRoute();
}
//*******************************************************************************************************************
void Headquater::printRoute()
{
	changeCityNames();
	int counter = eraseSameCities();
	_ammountOfGoods -= counter;
	for (int i = 0; i < _ammountOfGoods - 1; i++)
	{
		DijkstrasAlgorithm::dijkstrasAlgorithm(_deliveryMap, stoi(_whereToDeliver[i]), _distanceArray);
		DijkstrasAlgorithm::showTheWayFromXtoY(stoi(_whereToDeliver[i]), stoi(_whereToDeliver[i+1]), _distanceArray, _deliveryMap);
	}

	delete[] _whereToDeliver;
}
//*******************************************************************************************************************
void Headquater::changeCityNames()
{
	for (int i = 0; i < _ammountOfGoods + 1; i++)
	{
		if (_whereToDeliver[i] == "Krakow")
			_whereToDeliver[i] = "0";
		else if (_whereToDeliver[i] == "Wroclaw")
			_whereToDeliver[i] = "1";
		else if (_whereToDeliver[i] == "Warszawa")
			_whereToDeliver[i] = "2";
		else if (_whereToDeliver[i] == "Szczecin")
			_whereToDeliver[i] = "3";
		else
			_whereToDeliver[i] = "4";
	}
}
//*******************************************************************************************************************
int Headquater::eraseSameCities()
{
	int counter = 0;
	for (int i = 0; i < _ammountOfGoods + 1; i++)
		for(int j = 0; j < _ammountOfGoods + 1; j++)
			if (_whereToDeliver[i] == _whereToDeliver[j] && _whereToDeliver[i] != "same" && i != j)
			{
				_whereToDeliver[j] = "same";
				counter++;
			}

	string *tmpArray = new string[_ammountOfGoods + 1 - counter];

	for (int i = 0, j = 0; i < _ammountOfGoods + 1; i++)
	{
		if (_whereToDeliver[i] != "same")
		{
			tmpArray[j] = _whereToDeliver[i];
			j++;
		}
	}

	delete[] _whereToDeliver;
	_whereToDeliver = tmpArray;

	return counter;
}
//*******************************************************************************************************************