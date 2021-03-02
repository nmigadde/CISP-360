#include <iostream> 
#include <string>
using namespace std;

int main(){

	string product;
	double price,
		   number;
	char availability;


	cout << "Enter the name of the product" << endl;
	cin >> product;
	cout << "Is the item in stock? " << endl;
	cin >> availability;

	while (availability == 'Y' || availability == 'y')
	{
		cout << "How many numbers of items are there? " << endl;
		cin >> number;
		cout << "Enter the price of the item" << endl;
		cout << "$ ";
		cin >> price;

		availability = 'N';
	} 


	system("pause");
	return 0;
}

