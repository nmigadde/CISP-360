// 10/28/17
// Melanie Sou / Nabir Migadde
// 1606508 / 1648223
// CISP 360 M/W 1:30-2:50 pm
//Spring 2017
//Assignment #9
//This program passes values to a function named futureValue and display's the account future value 


#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

float futureValue(float, float, int);

int main()
{
float presentValue;
float monthlyinterestRate;
int numMonths;
char answer;
float totalFutureValue;

cout << "What is the present value of the account? ";
cin >> presentValue; 

while (presentValue<0) // input validation
{
	cout << "\nInvalid input. Enter the account's present value: "; 
	cin >> presentValue;
}

cout << "What is the monthly interest rate? ";
cin >> monthlyinterestRate;

while (monthlyinterestRate <0) // input validation
{
	cout << "\nInvalid inpit. Enter the account's monthly interest rate :";
	cin >> monthlyinterestRate;
}

cout << "For how many months will the money will be left in the account? ";
cin >> numMonths;

while (numMonths<0)
{
	cout <<"\nInvalid input. Enter the number of months that the money will be left in the account: ";
	cin >> numMonths;
}

totalFutureValue= futureValue(presentValue, monthlyinterestRate, numMonths);

cout << "The account's future value will be $" << setprecision(2) << fixed << totalFutureValue << endl;

cout << "Want to try another set of values? (y = yes) : ";
cin >> answer;


// prompt to try another set of values
while (answer=='y' || answer =='y')
{
	cout << "\nWhat is the present value of the account? ";
cin >> presentValue; 

while (presentValue<0) // input validation
{
	cout << "\nInvalid input. Enter the account's present value: "; 
	cin >> presentValue;
}

cout << "What is the monthly interest rate? ";
cin >> monthlyinterestRate;

while (monthlyinterestRate <0) // input validation
{
	cout << "\nInvalid inpit. Enter the account's monthly interest rate :";
	cin >> monthlyinterestRate;
}

cout << "For how many months will the money will be left in the account? ";
cin >> numMonths;

while (numMonths<0)
{
	cout <<"\nInvalid input. Enter the number of months that the money will be left in the account: ";
	cin >> numMonths;
}

totalFutureValue= futureValue(presentValue, monthlyinterestRate, numMonths);

cout << "The account's future value will be $" << setprecision(2) << fixed << totalFutureValue << endl;
cout << "Want to try another set of values? (y = yes) : ";
cin >> answer;
}

system("pause");
return 0;	
}

float futureValue(float P, float i, int t) 
{
float fValue=0; // future value of account	
fValue= P*pow(1+i,t); // future value formula
return fValue;
}


