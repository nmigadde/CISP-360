/*
09/17/2017

Nabir Migadde/Melanie Sou
1648223/1606508
CISP 360 - M/W 1:30pm - 2:50pm
Spring 2017
Assignment #4 Box Office
Display the gross profit and net profit of a movie
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//Box Office
int main() {
	//Initialization of Variables
	string movieNam;
	int numAduTic;
	int numChiTic;
	double gProfit;
	double nProfit;
	double amouDistri;

	//Ask user for information
	cout << "Enter the name of the movie: "; // Name of Movie
	getline(cin, movieNam);
	cout << "Enter the number of adult tickets sold: "; // Number of Adult Tickets 
	cin >> numAduTic;
	cout << "Enter the number of child tickets sold: "; // Number of Child Tickets
	cin >> numChiTic;
	cout << endl;

	//Calculations
	gProfit = (10 * numAduTic) + (6 * numChiTic); //Gross Profit
	nProfit = .2 * gProfit; // Net Profit
	amouDistri = gProfit - nProfit; //Amount Paid to Distributor

	//Display the Results to the user
	cout << "Revenue Report" << endl;
	cout << "==============" << endl;
	cout << setprecision(2) << fixed;
	cout << "Movie Name:" << setw(18) << '"' << movieNam << '"' << setw(1) << endl;
	cout << "Adult Tickets Sold:" << setw(17) << numAduTic << setw(1) <<endl;
	cout << "Child Tickets Sold:" << setw(17) << numChiTic << setw(1) <<endl;
	cout << "Gross Box Office Profit:    $ " << setw(1) << gProfit << endl;
	cout << "Net Box Office Profit:      $  " << setw(1) <<nProfit << endl;
	cout << "Amount Paid to Distributor: $ " << setw(1) <<amouDistri << endl;


	system("pause");
	return 0;
}