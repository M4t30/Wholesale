#include "Headquater.h"

int main()
{
	Headquater mainHeadquater;
	void (Headquater::*funGoodsReleasePointer)() = &Headquater::goodsRelease;
	void (Headquater::*funGoodsAcceptancePointer)() = &Headquater::goodsAcceptance;
	void (Headquater::*funPrintPointer)() = &Headquater::print;
	void (Headquater::*funBackupPointer)() = &Headquater::createGoodsBackupFile;
	int choice = 0;
	do
	{
		cout << "What would you like to do:" << endl
			<< "1. Accept Goods" << endl
			<< "2. Release Goods" << endl
			<< "3. Print all Goods" << endl
			<< "4. Create backup files with all Goods" << endl
			<< "0. Close programme" << endl;
		cin >> choice;

		if (choice == 1)
			(mainHeadquater.*funGoodsAcceptancePointer)();

		if (choice == 2)
			(mainHeadquater.*funGoodsReleasePointer)();

		if (choice == 3)
			(mainHeadquater.*funPrintPointer)();

		if (choice == 4)
			(mainHeadquater.*funBackupPointer)();

	} while (choice);

	system("PAUSE");
}