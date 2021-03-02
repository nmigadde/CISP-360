/*
10/1/2017

Nabir Migadde/Melanie Sou
1648223/1606508
CISP 360 - M/W 1:30pm - 2:50pm
Spring 2017
Assignment #6 Math Tutor
Help a student improve on their math skills
*/

#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <time.h>
using namespace std;

//Math Tutor
int main() {
	//Initialization of Variables
	int choice;
	double num1;
	double num2;
	double ans;
	double userAns;

	//Loop for Tutor
	do {

		//Seed randomization based off time 
		srand(time(NULL));

		//Set random numbers for calculations
		num1 = (rand() % 300) + 1;
		num2 = (rand() % 300) + 1;

		//Math Tutor Menu
		cout << "       Math Tutor Menu" << endl;
		cout << "-------------------------------" << endl;
		cout << "1. Addition problem" << endl;
		cout << "2. Subtraction problem" << endl;
		cout << "3. Multiplication problem" << endl;
		cout << "4. Division problem" << endl;
		cout << "5. Quit this program" << endl;
		cout << "-------------------------------" << endl;
		cout << "Enter your choice (1-5): ";
		cin >> choice; // User's choice

		//Do action based off User's choice
		switch (choice) {
		case 1: // Addition 
			ans = num1 + num2; //Calculations

			//Display Calculation to User
			cout << "  " << endl << endl;
			cout << "Number 1 is : " << num1 << endl;
			cout << "Number 2 is : " << num2 << endl << endl;
			cout << "What is the answer if you ADD them: "; // User answers the problem
			cin >> userAns;
			cout << " " << endl << endl;
			cout << "   " << num1 << endl;
			cout << " + " << num2 << endl;
			cout << "  ----" << endl;
			cout << "   " << ans << endl;
			cout << " " << endl << endl << endl;

			if (userAns == ans) { // If user is correct
				cout << "Congratulations! That's right." << endl << endl;
			}

			if (userAns != ans) { // If user is incorrect
				cout << "Sorry, the correct answer is " << ans << "." << endl << endl;
			}
			break;
		case 2: // Subtraction 
			ans = num1 - num2; // Calculations

			//Display Calculation to User
			cout << "  " << endl << endl;
			cout << "Number 1 is : " << num1 << endl;
			cout << "Number 2 is : " << num2 << endl << endl;
			cout << "What is the answer if you SUBTRACT them: "; // User answers the problem
			cin >> userAns;
			cout << " " << endl << endl;
			cout << "   " << num1 << endl;
			cout << " - " << num2 << endl;
			cout << "  ----" << endl;
			cout << "   " << ans << endl;
			cout << " " << endl << endl << endl;

			if (userAns == ans) {
				cout << "Congratulations! That's right." << endl << endl; // If user is correct
			}

			if (userAns != ans) {
				cout << "Sorry, the correct answer is " << ans << "." << endl << endl; // If user is incorrect
			}
			break;
		case 3: // Multiplication 
			ans = num1 * num2; // Calculations

			//Display Calculation to User
			cout << "  " << endl << endl;
			cout << "Number 1 is : " << num1 << endl;
			cout << "Number 2 is : " << num2 << endl << endl;
			cout << "What is the answer if you MULTIPLY them: "; // User answers the problem
			cin >> userAns;
			cout << " " << endl << endl;
			cout << "   " << num1 << endl;
			cout << " x " << num2 << endl;
			cout << "  ----" << endl;
			cout << "   " << ans << endl;
			cout << " " << endl << endl << endl;

			if (userAns == ans) {
				cout << "Congratulations! That's right." << endl << endl; // If user is correct
			}

			if (userAns != ans) {
				cout << "Sorry, the correct answer is " << ans << "." << endl << endl; // If user is incorrect
			}

			break;
		case 4: //Division 
			ans = num1 / num2;
			cout << "  " << endl << endl; //Calculations

			//Display Calculation to User
			cout << "Number 1 is : " << num1 << endl;
			cout << "Number 2 is : " << num2 << endl << endl;
			cout << "What is the answer if you DIVIDE them: "; // User answers the problem
			cin >> userAns;
			cout << " " << endl << endl;
			cout << "   " << num1 << " / " << num2 << " = " << ans << endl;
			cout << " " << endl << endl << endl;

			if (userAns == ans) {
				cout << "Congratulations! That's right." << endl << endl; // If user is correct
			}

			if (userAns != ans) {
				cout << "Sorry, the correct answer is " << ans << "." << endl << endl; // If user is incorrect
			}
			break;
		case 5: // Exit the program
			cout << " " << endl << endl; 
			break;
		default: // Invalid Entry
			cout << "The valid choices are 1, 2, 3, 4, and 5. Please choose: 5 ";
			cout << "Thank you for using Math Tutor." << endl << endl;
			break;
		}
	} while (choice != 5);

	//system("pause");
	return 0;
}