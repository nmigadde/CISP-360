#include <iostream>;
using namespace std;

void bubbleSort(int, int);
void selectionSort(int, int);

int main (){
	int array1[8] = {102, 105, 107, 103, 106, 100, 104, 101};
	int array2[8] = {102, 105, 107, 103, 106, 100, 104, 101};
	int size = 8;
	
	cout << "Now performing the bubble sort" << endl;
	cout << "------------------------------" << endl;
	bubbleSort(int array1, int size)
	cout << "Now performing the selection sort"
	cout << "---------------------------------" << endl;
	selectionSort(int array2[], int size)
	
	
	
	return 0;
}

void bubbleSort (int a1[], int elems)
{
	bool swap; 
	int temp;
	
	do 
	{
		swap = false;
		for (int count = 0; count < (elems - 1); count++)
		{
			if (a1[count] > array[count +1]
			{
				temp = a1[count];
				a1[count] = a1[count + 1];
				a1[count + 1] = temp;
				swap = true;
			}
		}
	} while (swap);
}

void selectionSort (int array[], int size)
{
	int startScan, mindIndex, minValue;
	
	for (startScan = 0; startScan < (size - 1); startScan++)
	{
		minIndex = startScan;
		minValue = array[startScan];
		for(int index = startScan + 1; index < size; index++)
		{
			if (array[index] <minValue)
			{ 
				minValue = array[index];
				minIndex = index;
			}
		}
		array[minIndex] = array[startScan];
		array[startScan] = minValue;
	}
}
