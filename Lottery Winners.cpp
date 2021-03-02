/*
11/12/2017

Nabir Migadde/Melanie Sou
1648223/1606508
CISP 360 - M/W 1:30pm - 2:50pm
Spring 2017
Assignment #11 Lottery Winners
Find the winning lottery numbers
*/

#include <iostream>
using namespace std;

//Lottery Winning Number Finder
int main (){
	//Initialization of Variables
	int winningNums[10] = {13579, 26791, 26792, 33445, 55555, 62483, 77777, 79422, 85647, 93121}; //Array of Winning Numbers
	int searchNum;
	int index = 0;
	int position = -1;
	int numElems = 10;
	bool found = false;

	
	cout << "Please enter this week's 5-digit winning lottery number: "; //Prompt user for their number
	cin >> searchNum; //Variable that holds the user's number and searches it in the list 
	
	//Linear Searching for the Winning Numbers
	while (index < numElems && !found) // Flag will be used
	{
		if(winningNums[index] == searchNum){ // If number is found then set flag to true
			found = true;
			position = index;
		}
		
		index++; //Increment index for the loop
	}
	
	if(found){
		cout << "You have a winning ticket." << endl; //If the number is in the list, prompt user of winning number
	} else {
		cout << "You did not win this week." << endl; //If not then prompt the user that they didnt win
	}
	
	return 0;
}
