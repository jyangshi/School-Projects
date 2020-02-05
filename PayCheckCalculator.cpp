#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	ifstream inFile;
	ofstream outFile;

	inFile.open("inData.txt");
	outFile.open("outData.txt");

	if (!inFile) {
		cout << "File did not open" << endl;
		system("pause");
		return 0;
	}
	string fName, lName, name, department;
	double mSalary, mBonus, aBonus, tIncome, taxes, tRate, pCheck, dTraveled, tTime, aSpeed, cCost, cSales;
	int cSold;
	outFile << fixed << showpoint << setprecision(2);
	inFile >> fName >> lName >> department;
	name = fName + lName;
	outFile << "Name: " << name << ", Department: " << department << endl;

	inFile >> mSalary >> mBonus >> taxes;
	aBonus = (mSalary) * (mBonus / 100);
	tIncome = mSalary + aBonus;
	tRate = (tIncome) * (taxes / 100);
	pCheck = tIncome - tRate;
	outFile << "Monthly Gross Salary: " << mSalary << ", Monthly Bonus: " << mBonus << "%" << ", Taxes: " << taxes << "%" << endl;
	outFile << "Paycheck: $" << pCheck << endl;

	inFile >> dTraveled >> tTime;
	aSpeed = dTraveled / tTime;
	outFile << "Distance Traveled: " << dTraveled << " miles" << ", Traveling time: " << tTime << " hours" << endl;
	outFile << "Average Speed: " << aSpeed << " mph" << endl;

	inFile >> cSold >> cCost;
	cSales = cSold * cCost;
	outFile << "Number of coffee cups sold: " << cSold << ", Cost: $" << 1.50 << " per cup" << endl;
	outFile << "Sales Amount: $" << cSales << endl;

	inFile.close();
	outFile.close();
	cout << "End of program" << endl;
	system("pause");

	return 0;
}
