#include <iostream>
#include <string>
using namespace std;

void prompt(char&choice)
{
	cout << "\n\nIs time in 12-HR format?" <<
		"\nY/N (not case sensitive): ";
	cin >> choice;
}

void input(int&hour, int&min, char&choice, bool&amORpm)
{
	char c;
	if (choice == 'Y' || choice == 'y')
	{
		cout << "Hours: ";
		cin >> hour;

		cout << "Minutes: ";
		cin >> min;

		cout << "Is it AM?" <<
			"\nY/N (not case sensitive): ";
		cin >> c;

		if (c == 'Y' || c == 'y')
			amORpm = true;
		else
			amORpm = false;
	}
	else
	{
		cout << "Hours: ";
		cin >> hour;

		cout << "Minutes: ";
		cin >> min;

		if (hour < 12)
			amORpm = true;
		else
			amORpm = false;
	}
}

void format24(int&hour, bool&amORpm)
{
	if (!amORpm)
		hour = 12 + hour;
}

void format12(int&hour, bool&amORpm)
{
	if (hour > 12)
	{
		hour = hour - 12;
		amORpm = false;
	}
	else
		amORpm = true;
}

void display(int&hour, int&min, char&choice, bool&amORpm)
{
	cout << "Converted time is: " << hour << ":" << min;
	if (!(choice == 'Y' || choice == 'y'))
		if (amORpm)
			cout << "AM";
		else
			cout << "PM";
	cout << endl;
}

int main()
{
	int hour;
	int min;
	char choice;
	bool amORpm;

	prompt(choice);
	input(hour, min, choice, amORpm);

	if (choice == 'Y' || choice == 'y')
	{
		format24(hour, amORpm);
	}
	else
	{
		format12(hour, amORpm);
	}

	display(hour, min, choice, amORpm);

	system("PAUSE");
	return 0;
}
