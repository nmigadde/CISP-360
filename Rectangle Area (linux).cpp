/*
10/22/2017

Nabir Migadde/Melanie Sou
1648223/1606508
CISP 360 - M/W 1:30pm - 2:50pm
Spring 2017
Assignment #8 Rectangle Area
Calculate an area of a rectangle
*/

#include <iostream>
using namespace std;

//Function Prototypes
double getLength (double &);
double getWidth (double &);
double getArea (double &, double &, double &);
void displayData (double , double , double);

//Rectangle Area Calculator
int main(){
	//Initialization of Variables
	double length;
	double width;
	double area;
	
	getLength(length); //Get Length of Rectangle
	getWidth(width); //Get Width of Rectangle
	getArea(length, width, area); //Calculate Area of Rectangle
	displayData(length, width, area); //Show Results to User
	
	return 0;
}

//getWidth Function
double getLength (double &len)
{
	cout << "Enter the length: "; //Input Length
	cin >> len;
	return len;
}

//getLength Function
double getWidth (double &wid)
{
	cout << "Enter the width: "; //Input Width
	cin >> wid;
	return wid;
}

//getArea Function
double getArea (double &len, double &wid, double &areas)
{
	areas = len * wid; //Multiply Length by Width
	return areas;
}

//displayData Function
void displayData (double len, double wid, double areas)
{
	//Display Results and Calculations to Console
	cout << endl;
	cout << "Rectangle Data" << endl;
	cout << "--------------" << endl;
	cout << "Length: " << len << endl;
	cout << "Width:  " << wid << endl;
	cout << "Area:   " << areas << endl;
}
