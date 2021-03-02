/*
12/03/2017

Nabir Migadde/Melanie Sou/Shay Hameed/Dan Blumenschein
1648223/1606508/1596688/1612052
CISP 360 - M/W 1:30pm - 2:50pm
Spring 2017
Final Project
Product Inventory System for ABC's Store
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~ABC's Store Real Time Product Inventory System~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

This program allows a ABC's Store Employee to input information about a certain item such as if its in stock, the price, 
and the location. The program then stores this information in a offline database (file), and sorts the information in th
ree different options. The program later displays the final list to the user. 

*/

//Function Prototypes
int inputProduct(int &);
/*
What it does: Prompts the user if they would like to user the program, and checks for incorrect entries
Passed: Default Answer
Return: Their Answer
*/
void numberOfItems(int &);
/*
What it does: Asks the user how many items they will be entering today
Passed: Default Number of Items - 0
Return: The Number of Items they are entering
*/
void itemInformation(int &, vector<int> &, vector<double> &, vector<string> &, vector<string> &, ofstream &outputFile);
/*
What it does: Prompts user to put in the various information about the item
Passed: Numbers of Items, Name of the Item, The amount of that item in stock, The price of the item, The location of that item, and the file to record all this information
Return: Nothing
*/
void sort(vector<double> &, vector<string> &, vector<int> &, vector<string> &, ofstream &outputFile);
/*
What it does: Sorts the information in various ways - Increasing Price, Decreasing Price, Alphabetical Order
Passed: Name of the Item, The amount of that item in stock, The price of the item, The location of that item, and the file to record all this information
Return: Nothing
*/
void coutinue(int &);
/*
What it does: Ask the user if they would like to add more items to the database(file)
Passed: Their Answer
Return: Nothing
*/
void farewell(int &);
/*
What it does: Once the user is done with the program they are greeted with a farewell message
Passed: Their Answer
Return: Nothing
*/


int main (){
	//Declaration of Variables and Vectors
	vector<int> amount;
	vector<double> price;
	vector<string> location;
	vector<string> productNam;
	int inputAns = 0;
	int numTotalItem;
	int numItem=0;
	 
	 //Open file for writing
	ofstream outputFile;
	outputFile.open("Items.txt"); 
	
	//Function will return the user's answer
	inputAns = inputProduct(inputAns);
	
	//Main Loop
	while(inputAns == 1){
		
		numberOfItems(numItem); //Ask user how many item they are entering
		
		numItem = numItem; //Reset
		
		numTotalItem = numTotalItem + numItem; //Set the amount of total items inputted for every loop
		
		itemInformation(numItem, amount, price, location, productNam, outputFile); //Prompt user of information about the item
			
		sort(price, location, amount, productNam, outputFile); //Sort the information in lists for the user
		
		coutinue(inputAns); //Ask user if they would like to add more items
		
		}
	
	farewell(inputAns); //Farewell message
	
	outputFile.close(); //Close file for writing
	
	system("pause");
	return 0;
}

int inputProduct(int & answer){
	//Title of the Program
	cout << "********************ABC's Store Real Time Product Inventory System********************" << endl << endl;
	cout << "Do you have an item to input to the system? (1 = yes, 0 = no)  "; //Ask user if they would like to use program
	cin >> answer; 
		//Check for invalid answer and prompt user to try again
		while (answer != 1 && answer != 0) {
		cout << "Invalid answer. Please try again." << endl;
		cout << endl << "Do you have an item to input to the system? (1 = yes, 0 = no)  ";
		cin >> answer;
	}
	
	return answer;
}

void numberOfItems(int & items){
	cout << endl << "How many items do you want to input (Number)?  "; //Ask user how many items they are entering
	cin >> items;
	cout << " " << endl;
	//Check for invalid answer and prompt user to try again. Value has to be between 0 and 20.
	if(items >= 21 || items <= 0){
			cout << "Invalid answer. Please try again." << endl;
			cout << endl << "How many items do you want to input (Number)?  ";
			cin >> items;
			cout << " " << endl;
		}
}

void itemInformation(int & items, vector<int> &amou, vector<double> &cost, vector<string> &place, vector<string> &name, ofstream &outputFile){
	for (int n = 0; n < items; n++){
			//Declaration of temporary variables 
			int stock;
			int tempAmou;
			double tempCost;
			string tempPlace;
			string tempName;
			
			cout << "~~~~~~~~~~~~ Item #" << n+1 << " ~~~~~~~~~~~~~~~~" << endl; //Item Number
			cout << "What is the name of the item (No-Spaces)?  - "; //Ask for the name of the item
			cin >> tempName;
			name.push_back(tempName); //Place the information in a vector
			
			cout << "Is that item in stock? (1 = yes, 0 = no)  - "; //Ask for availablity
			cin >> stock;
			
			//Check for invalid answer and prompt user to try again
			if (stock != 1 && stock != 0){
				cout << "Invalid answer. Please try again." << endl;
				cout << "Is that item in stock? (1 = yes, 0 = no)  - ";
				cin >> stock;
			}
			
			//If item is available
			if (stock == 1){
				cout << "How many are in stock (Number)?  - "; //Ask user how many are in stock
				cin >> tempAmou;
				amou.push_back(tempAmou);
			} else 
			{
				if (stock == 0) {
					tempAmou = 0;
					amou.push_back(tempAmou);//Place that information in another vector
				}
			}
			
			cout << "How much does that item cost?   $"; //Ask user how much the item costs
			cin >> tempCost;
			
			//Check for invalid answer and prompt user to try again
			if (tempCost < 0 || tempCost > 1000){
				cout << "Invalid answer. Please try again."; 
				cout << "How much does that item cost?   $";
				cin >> tempCost;
			}
			cost.push_back(tempCost); //Place that information in another vector
			
			cout << "Where is that item located (No-Spaces)?  - "; //Ask user where that item is located
			cin >> tempPlace;
			place.push_back(tempPlace); //Place that information in another vector
			
			cout << " " << endl;
	}
	
	//Declaration of Pointers and Arrays
	int size = cost.size();
	int amounts[size];
	int *amouPtr = nullptr;
	double *costPtr = nullptr;
	double costs[size];
	string *namPtr = nullptr;
	string *placePtr = nullptr;
	string names[size];
	string places[size];
	
	//Transfer the Values of the Vectors to Corresponding Arrays
	for(int q = 0; q < size; q++){
		amounts[q] = amou[q];
		names[q] = name[q];
		places[q] = place[q];
		costs[q] = cost[q];
	}
	
	//Unsorted List
	
	//Set pointers to point at the arrays
	namPtr = names;
	amouPtr = amounts;
	costPtr = costs;
	placePtr = places;
	
	//Display information to user in an unsorted list
	cout << "************** Unsorted **************" << endl;
	cout << "   Name " << "Amount " << "Price " << "Location " << endl; // Different coloumns
	for (int p = 0; p < size; p++){
		cout << p+1 << ". "; //Number of Item
		cout << *namPtr << " | "; //Name of Item
		cout << *amouPtr << "  | $"; //Amount of that Item available
		cout << *costPtr << "  | "; //Price of that Item
		cout << *placePtr << endl; //Location of the Item
		//Increment Pointers
		namPtr++;
		amouPtr++;
		costPtr++;
		placePtr++;
	}
	
	//Input the information to database (file)
	for (int z = 0; z < size; z++){
			outputFile << name[z] << " ";
			outputFile << amou[z] << " ";
			outputFile << cost[z] << " ";
			outputFile << place[z] << endl;
		}
	
	cout << " " << endl;
}

void sort(vector<double> &cost, vector<string> &place, vector<int> &amou, vector<string> &name, ofstream &outputFile){
	//Declaration of Temporary Variables
	bool swap;
	int choose;
	int temp3;
	int size = cost.size();
	double temp1;
	string temp2;
	string temp4;
	
	//Prompts user of methods of sorting
	cout << "How do you want you results sorted?" << endl;
	cout << "1 = Highest Price First" << endl;
	cout << "2 = Lowest Price First" << endl;
	cout << "3 = Alphabetical Order" << endl;
	cout << " " << endl;
	cin >> choose;
	cout << " " << endl;
	
	//Case stucture of different choices
	switch(choose){
		case 1:
			do //Bubble Sort of Highest Price First
			{	
			swap = false;
			for (int count = 0; count < (size-1); count++){
				if (cost[count] < cost[count+1]){
					temp1 = cost[count];
					cost[count] = cost[count + 1];
					cost[count + 1] = temp1;
				
					temp2 = place[count];
					place[count] = place[count + 1];
					place[count + 1] = temp2;
				
					temp3 = amou[count];
					amou[count] = amou[count + 1];
					amou[count + 1] = temp3;
				
					temp4 = name[count];
					name[count] = name[count + 1];
					name[count + 1] = temp4;
					swap = true;
				}
			}	
			} while (swap);
			break;
		case 2:
			do //Bubble Sort of Lowest Price First
			{
			swap = false;
			for (int count = 0; count < (size-1); count++){
				if (cost[count] > cost[count+1]){
					temp1 = cost[count];
					cost[count] = cost[count + 1];
					cost[count + 1] = temp1;
				
					temp2 = place[count];
					place[count] = place[count + 1];
					place[count + 1] = temp2;
				
					temp3 = amou[count];
					amou[count] = amou[count + 1];
					amou[count + 1] = temp3;
				
					temp4 = name[count];
					name[count] = name[count + 1];
					name[count + 1] = temp4;
				swap = true;
				}
			}
			} while (swap); 
			break;
		case 3:
			do //Bubble Sort of Alphabetical Order
			{
			swap = false;
			for (int count = 0; count < (size-1); count++){
				if (name[count] > name[count+1]){
					temp1 = cost[count];
					cost[count] = cost[count + 1];
					cost[count + 1] = temp1;
				
					temp2 = place[count];
					place[count] = place[count + 1];
					place[count + 1] = temp2;
				
					temp3 = amou[count];
					amou[count] = amou[count + 1];
					amou[count + 1] = temp3;
				
					temp4 = name[count];
					name[count] = name[count + 1];
					name[count + 1] = temp4;
				swap = true;
				}
			}
		
			} while (swap);
			break;
		default:
			cout << "Invaild. Please try again";
			cout << endl << endl;
			break;	
	}
	
	//Declaration of Pointers and Arrays
	int amounts[size];
	int *amouPtr = nullptr;
	double *costPtr = nullptr;
	double costs[size];
	string *namPtr = nullptr;
	string *placePtr = nullptr;
	string names[size];
	string places[size];
	
	//Transfer the Values of the Vectors to Corresponding Arrays
	for(int q = 0; q < size; q++){
		amounts[q] = amou[q];
		names[q] = name[q];
		places[q] = place[q];
		costs[q] = cost[q];
	}
	
	//Sorted List
	
	//Set pointers to point at the arrays
	namPtr = names;
	amouPtr = amounts;
	costPtr = costs;
	placePtr = places;
	
	//Display information to user in an unsorted list
	cout << "************** Sorted **************" << endl;
	cout << "   Name " << "Amount " << "Price " << "Location " << endl; //Coloumns
	for (int p = 0; p < size; p++){
		cout << p+1 << ". "; //Same
		cout << *namPtr << " | "; //Same
		cout << *amouPtr << "  | $"; //Same
		cout << *costPtr << "  | "; //Same
		cout << *placePtr << endl; //Same
		namPtr++;
		amouPtr++;
		costPtr++;
		placePtr++;
	}
	//Input the information to database (file)
	for (int c = 0; c < size; c++){
			outputFile << name[c] << " ";
			outputFile << amou[c] << " ";
			outputFile << cost[c] << " ";
			outputFile << place[c] << endl;
		}
		
}

void coutinue(int & ans){
cout << endl << "Would you like to input any more items? (1 = yes, 0 = no)  "; //Ask user if they would like to add more items
		cin >> ans;
		//Check for invalid answer and prompt user to try again 
		while (ans != 0 && ans != 1) {
			cout << "Invalid answer. Please try again." << endl;
			cout << endl << "Would you like to input any more items? (1 = yes, 0 = no)  ";
			cin >> ans;
		}
}

void farewell(int & ans){
	//If answer is NO
	if (ans == 0) {
	//Farewell Message
	cout << endl << "Good Bye!!!" << endl; 
	cout << "Thanks for using ABC's Store Real Time Product Inventory System!" << endl;
	}
}
