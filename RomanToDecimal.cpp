#include"romanType.h"
using namespace std;

romanType::romanType(string romanNums)
{
	roman = romanNums;
	decimal = 0;
} //end romanType

void romanType::setRoman(string romanNums)
{
	roman = romanNums;
	decimal = 0;
} //end setRoman

void romanType::romanToDecimal()
{
	char romans[7] = { 'M', 'D', 'C', 'L', 'X', 'V', 'I' };
	int decimals[7] = { 1000, 500, 100, 50, 10, 5, 1 };
	int j, pos;

	size_t len = roman.length();

	//for to process the numeral
	for (unsigned int i = 0; i < len - 1; i++)
	{
		//finding correct roman letter
		for (pos = 0; pos < 7; pos++)
			if (roman.at(i) == romans[pos])
				break;

		//check position of the roman letter
		if (pos < 7)
		{
			//find the next roman letter's value
			for (j = 0; j < pos; j++)
				if (roman.at(i + 1) == romans[j])
					break;

			//add or subtract the dec. val according to the values of j and pos
			if (j == pos)
				decimal += decimals[pos];
			else
				decimal -= decimals[pos];
		}
	} //end for

	//process the last digit
	for (j = 0; j < 7; j++)
		if (roman.at(len - 1) == romans[j])
			break;
	decimal += decimals[j];

} //end romanToDecimal

void romanType::printRoman()
{
	cout << "\n\n\tRoman numeral: " << roman;
} //end function printRoman

void romanType::printDecimal()
{
	cout << "\n\tDecimal equivalent: " << decimal;
} //end function printDecimal

//main funtion
int main()
{
	//program title
	cout << "\n\n\tProgram that romanToDecimal Roman Numeral"
		<< " into decimal form.";

	romanType r;

	string rns[3] = { "CCCLIX", "MCXIV", "MDCLXVI" };

	for (int i = 0; i < 3; i++)
	{
		//set the roman numeral string
		r.setRoman(rns[i]);

		//romanToDecimal roman numeral to decimal
		r.romanToDecimal();

		//print roman numeral
		r.printRoman();

		//print decimal
		r.printDecimal();
	} //end for

	cout << "\n\n\t";
	system("pause");
	return 0;
}	//end program
