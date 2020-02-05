#include <iostream> //allows usage of cin and cout
#include <iomanip> //

using namespace std;
int main()
{
	int acctNumber, minUsed, premDayMin, premNightMin; //declaring variables
	double minUsedBill, premTotal, dayBill, nightBill = 0; //declaring variables
	char serviceCode; //declaring variables (letters)

	const float regFee = 10.00; //assigning value to variable
	const float regRate = 0.20; //assigning value to variable
	const float premFee = 25.00; //assigning value to variable
	const float premDay = 0.10; //assigning value to variable
	const float premNight = 0.05; //assigning value to variable

	cout << "Enter an account number: "; //tells user to input account number
	cin >> acctNumber; //stores account number in variable acctNumber
	cout << "Enter service code: "; //tells user to input service code
	cin >> serviceCode; //stores service code in variable serviceCode

	switch (serviceCode) { //compares user input for serviceCode to following letters
	case 'r': //compares serviceCode to r
	case 'R': //compares serviceCode to R
		cout << "Enter number of minutes used: "; //asks user for number of minutes used
		cin >> minUsed; //stores minutes used into variable minUsed
		if (minUsed > 50) { 
			minUsedBill = ((minUsed - 50) * regRate) + regFee;
		}
		else {
			minUsedBill = regFee;
		}
		cout << "Account Number: " << acctNumber << endl;
		cout << "Account Type: Regular" << endl;
		cout << "Minutes Used: " << minUsed << endl;
		cout << "Payment Due: $" << minUsedBill << endl;
		break;
	case 'p':
	case 'P':
		cout << "Enter number of day minutes used: ";
		cin >> premDayMin;
		cout << "Enter number of night minutes used: ";
		cin >> premNightMin;
		if (premDayMin > 75) {
			dayBill = (premDayMin - 75) * premDay;
		}
		else {
			dayBill = 0;
		}
		if (premNightMin > 100) {
			nightBill = (premNightMin - 100) * premNight;
		}
		else {
			nightBill = 0;
		}
		premTotal = dayBill + nightBill + premFee;
		cout << "Account Number: " << acctNumber << endl;
		cout << "Account Type: Premium" << endl;
		cout << "Daytime Minutes: " << premDayMin << endl;
		cout << "Nighttime Minutes: " << premNightMin << endl;
		cout << "Payment Due: $" << premTotal << endl;
		break;
	default:
		cout << "Invalid service code" << endl;
		return 1;
		break;
	}
	system("pause");

	return 0;
}
