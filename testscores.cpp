// 11/17/17
// Melanie Sou / Nabir Migadde
// 1606508 / 1648223
// CISP 360 M/W 1:30-2:50 pm
//Spring 2017
// This program displays the total and average of test scores and sorts them in ascending order.

#include <iostream>
#include <iomanip>
using namespace std;

//Fumction prototypes
void arrSelectSort(double [], int);
double arrAvgScore(double, int);
void showArrPtr(double [], int);

int main()
{
	double * scores, // to dynamically allocate an array
		total = 0.0, // accumulator
		average; // hold the averaage scores 
	int numScores, // hold the number of test scores
		count; // counter variable

	// Get number of test scores 
	cout << "How many test scores will you enter?  ";
	cin >> numScores;

	//Dynamically allocate an array large enough to hold that many test scores
	scores = new double[numScores];

	//Get the test scores
	for (count = 0; count < numScores; count++)
	{
		//Display test scores
		cout << " Enter test score " << (count + 1) << ": ";
		cin >> scores[count];
	}

	//Input Vaidation
	while (numScores<0)
	{
		cout << "Invalid. Please enter a non-negative score" << endl;
		cin >> scores[count];
	}
	
	arrSelectSort(scores, numScores);
	showArrPtr(scores, numScores);
	

	//Calculate total test scores
	for (count = 0; count < numScores; count++)
	{
		total += scores[count];
	}
	
	arrAvgScore(total, numScores);
	
	//Calculate the average test score
	average = total / numScores;

	//Display results
	cout << fixed << showpoint << setprecision(2);
	cout << "The test scores in ascending order, and their average, are: " << endl;
	cout << "Score" << endl;
	cout << "-----" << endl;

	// Free dynamially allocated memory
	delete[] scores;
	//scores = nullptr; //makes scores a null pointer

	//system("pause");
	return 0;

}

//Ascending order selection sort
void arrSelectSort(double *array[], int size)
{
	int startScan, minIndex;
	double *minElem;

	for (startScan = 0; startScan < (size - 1); startScan++)
	{
		minIndex = startScan;
		minElem = array[startScan];

		for (int index = startScan + 1; index<size; index++)
		{
			if (array[index] < minElem)
			{
				minElem = array[index];
				minIndex = index;
			}
		}
		array[minIndex] = array[startScan];
		array[startScan] = minElem;
	}
}

void showArrPtr(double *array[], int size)
{
	for (int count = 0; count< size; count++)
		cout << *(array[count]) << " ";
	cout << endl;
}

double arrAvgScore(double total, int numScores)
{
	double average;
	//Calculate the average
	average = total / numScores;
	return average;

	//Display the results.
	cout << fixed << showpoint << setprecision(2);
	cout << "Average Score: " << average << endl;
}
