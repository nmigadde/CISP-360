/***************************************************************************************
10/15/17

Melanie Sou/ Nabir Miggade
1606508/ 1648223
CISP 360 - M/W 1:30-2:50pm
Spring 2017
Assignment #7 Pattern Display
This program uses a loop to display Pattern A followed by another loop that displays pattern B
****************************************************************************************/

#include <iostream>
using namespace std;

int main()
{
	//int column = 10,
	//row = 10;

	// For loop for pattern A
	for (int row=0; row<=10; row++) //outer
	{
		for (int column=0; column<row; column++) // inner
		{
			cout << "+";
		}
		
		cout << endl;
	}
	
	cout << endl;

	// For loop for pattern B
	for (int row = 10; row > 0; row--) // outer
	{
		for (int column=0; column < row; column++) //inner
		{
			cout << "+";
		}
		
		cout << endl;
	}

	cout << endl;

	system("pause");
	return 0;
}
