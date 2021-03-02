/*
09/02/2017

Nabir Migadde/Melanie Sou
1648223/1606508
CISP 360 - M/W 1:30pm - 2:50pm
Spring 2017
Assignment #2 Average of Values
Display the average of a series of values
*/

#include <iostream> 
using namespace std;

//Average
int main() {
	//Initialization of Variables
	double num1 = 28;
	double num2 = 32;
	double num3 = 37;
	double num4 = 24;
	double num5 = 33;
	double sum;
	double average;

	//Calculation to find the Sum
	sum = num1 + num2 + num3 + num4 + num5;

	//Calculation to find the Average
	average = sum / 5;

	//Display the results to the user
	cout << "Number 1: " << num1 << endl;
	cout << "Number 2: " << num2 << endl;
	cout << "Number 3: " << num3 << endl;
	cout << "Number 4: " << num4 << endl;
	cout << "Number 5: " << num5 << endl;
	cout << "Average: " << average << endl;

	//system("pause");
	return 0;
}