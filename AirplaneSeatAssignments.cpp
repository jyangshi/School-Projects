#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <cstring>
using namespace std;
const int rows = 14;
const int columns = 6;
void initPlane(char plane[rows][columns]);
void printPlane(const char msg[], char plane[rows][columns]);
void  checkType(char &ticketType);
void typeCheck(char ticketType, int &row, char &seat);
int main()
{
	int seatsTaken = 0;
	int seats = (rows - 1) * (columns - 1);
	char plane[rows][columns];
	char keepGoing = 'y' || 'Y';
	int row = 0;
	char seat;
	int rowIndex, columnIndex;
	char ticketType = 1;
	initPlane(plane);
	cout << "Please choose an unoccupied seat..." << endl;
	while (seatsTaken < seats && keepGoing == 'y' || 'Y')
	{

		printPlane("Cabin layout: X = Occupied Seats, * = Available Seats", plane);
		cout << endl;

		ticketType = toupper(ticketType);
		checkType(ticketType);
		typeCheck(ticketType, row, seat);
		rowIndex = row;

		columnIndex = toupper(seat) - 'A' + 1;

		if (seat == 'A' || seat == 'a')
			columnIndex = 0;
		else if (seat == 'B' || seat == 'b')
			columnIndex = 1;
		else if (seat == 'C' || seat == 'c')
			columnIndex = 2;
		else if (seat == 'D' || seat == 'd')
			columnIndex = 3;
		else if (seat == 'E' || seat == 'e')
			columnIndex = 4;
		else if (seat == 'F' || seat == 'f')
			columnIndex = 5;

		if (plane[rowIndex][columnIndex] == 'X')
			cout << "Sorry, " << row << seat << " is already taken." << endl;
		else
		{
			cout << "You've confirmed seat:  " << row << seat << endl;
			plane[rowIndex][columnIndex] = 'X';
			seatsTaken++;
		}
		if (seatsTaken < seats)
		{
			cout << "Choose another seat? (Y/N) ";
			cin >> keepGoing;
		}
		else
			cout << "There are no longer any seats available!" << endl;

	}
	printPlane("Final seating chart", plane);

	return 0;

}
void initPlane(char plane[rows][columns])
{
	int x, y;
	plane[0][0] = ' ';
	for (x = 0; x < rows; x++)
	{
		plane[0][x] = 'A' + (x - 1);
	}
	for (x = 0; x < rows; x++)
	{
		for (y = 0; y <= 13; y++)
			plane[x][y] = ' ';
	}

	for (x = 0; x < rows; x++)
	{
		for (y = 0; y < columns; y++)
			plane[x][y] = '*';
	}
}
void printPlane(const char msg[], char plane[rows][columns])
{
	cout << msg << endl;
	int Row, col;
	for (Row = 1; Row < rows; Row++)
	{
		if (Row == 0)
			cout << "     ";
		else if (Row != 0)
			cout << "Row " << Row;
		if (Row < 10)
			cout << " ";
		for (col = 0; col < columns; col++)
			cout << setw(2) << plane[Row][col] << " ";
		cout << endl;

	}
}
void checkType(char &ticketType)
{
	bool needInput = true;
	while (needInput)
	{
		cout << "Rows 1 and 2  = First class. " << endl;
		cout << "Rows 3 - 7 = Business class. " << endl;
		cout << "Rows 8 - 13 = Economy class. " << endl;
		cout << "Enter ticket type " << endl
			<< "Enter 'F'  for First class" << endl
			<< "Enter 'B' for Business class " << endl
			<< "Enter 'E' Economy class" << endl;
		cin >> ticketType;
		cout << endl;;
		ticketType = toupper(ticketType);
		if (ticketType == 'F' || 'f')
			needInput = false;
		else if (ticketType == 'B' || 'b')
			needInput = false;
		else if (ticketType == 'E' || 'e')
			needInput = false;
		else
		{
			needInput = true;
			cout << "Invalid input. Please try again " << endl;
			cout << endl;;
		}
	}
}
void typeCheck(char ticketType, int &row, char &seat)
{
	bool needInput;
	if (ticketType == 'F')
	{
		needInput = true;
		while (needInput)
		{
			cout << "Enter row 1 or 2 and then seat choice (A-F) you would like (e.g., 1D): ";
			cin >> row >> seat;
			cout << endl;
			seat = toupper(seat);
			if ((row >= 1) && (row <= 2))
			{
				if (seat == 'A' || 'a')
					needInput = false;
				else if (seat == 'B' || 'b')
					needInput = false;
				else if (seat == 'C' || 'c')
					needInput = false;
				else if (seat == 'D' || 'd')
					needInput = false;
				else if (seat == 'E' || 'e')
					needInput = false;
				else if (seat == 'F' || 'f')
					needInput = false;
				else
				{
					needInput = true;
					cout << "Invalid input, please try again " << endl;
				}
				cout << endl;
			}
			else
			{
				cout << "Invalid input. try again " << endl;
				cout << endl;
			}
		}
	}
	else if (ticketType == 'B')
	{
		needInput = true;
		while (needInput)
		{
			cout << "Enter row number between 3 - 7, then seat choice (A - F) you would like (e.g., 3D): ";
			cin >> row >> seat;
			cout << endl;;
			seat = toupper(seat);
			if ((row >= 3) && (row <= 7))
			{
				if (seat == 'A' || 'a')
					needInput = false;
				else if (seat == 'B' || 'b')
					needInput = false;
				else if (seat == 'C' || 'c')
					needInput = false;
				else if (seat == 'D' || 'd')
					needInput = false;
				else if (seat == 'E' || 'e')
					needInput = false;
				else if (seat == 'F' || 'f')
					needInput = false;
				else
				{
					needInput = true;
					cout << "Invalid input, please try again " << endl;
				}
				cout << endl;
			}
			else
			{
				cout << "Invalid input. try again " << endl;
				cout << endl;;
			}
		}
	}
	else if (ticketType == 'E')
	{
		needInput = true;
		while (needInput)
		{
			cout << "Enter a row number between 8 - 13 and seat choice (A - F) you would like (e.g., 8D): ";
			cin >> row >> seat;
			cout << endl;;
			seat = toupper(seat);
			if ((row >= 8) && (row <= 13))
			{
				if (seat == 'A' || 'a')
					needInput = false;
				else if (seat == 'B' || 'b')
					needInput = false;
				else if (seat == 'C' || 'c')
					needInput = false;
				else if (seat == 'D' || 'd')
					needInput = false;
				else if (seat == 'E' || 'e')
					needInput = false;
				else if (seat == 'F' || 'f')
					needInput = false;
				else
				{
					needInput = true;
					cout << "Invalid input, please try again " << endl;
				}
				cout << endl;;
			}
			else
			{
				cout << "Invalid input. try again " << endl;
				cout << endl;;
			}
		}
	}

}
