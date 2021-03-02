#include <iostream>
using namespace std;
const int SIZE = 8;
void displayArray(int[], int);
void selectionSort(int[], int);
int main() {
	int values[SIZE] = { 23, 0, 45, -3, -78, 1, -1, 9 };
	cout << "The values before selection cort is performed:  " << endl;
	displayArray(values, SIZE);
	selectionSort(values, SIZE);
	cout << "The values after selection cort is performed:  " << endl;
	displayArray(values, SIZE);
	system("pause");
	return 0;
}
void displayArray(int array[], int elems)
{
	for (int count = 0; count < elems; count++)
		cout << array[count] << " ";
	cout << endl;
}

void selectionSort(int array[], int elems)
{
	int seek, minCount, minValue;
	for (seek = 0; seek < (elems - 1); seek++)
	{
		minCount = seek;
	    minValue = array[seek];
		for (int index = seek + 1; index < elems; index++)
		{
			if (array[index] > minValue)
			{
				minValue = array[index];
			    minCount = index;
			}
		}
		array[minCount] = array[seek];
		array[seek] = minValue;
		cout << "Selection is in progress . . . " << endl;
		displayArray(array, SIZE);
	}
}
