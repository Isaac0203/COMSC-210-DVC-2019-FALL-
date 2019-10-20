#include <iostream>

// Hyunwook Jung
// 20 Oct 2019
// Lab Merge Sort
// Diablo Valley College COMSC 210
using namespace std;

/*
Objectives:
1. Identify a problem that can efficiently be solved with merge sort.
2. Implement the merge sort algorithm
3. Determine and summarize the algorithmic run-time of the merge sort algorithm.
*/

/*
Specifications:

As you saw from your readings and exercises, Merge Sort is based upon the idea of divide-and-conquer.
If implemented correctly, your merge sort algorithm should have a time complexity of O(n*log(n)).

Your task for this lab is to write a program that utilizes the merge sort algorithm.
You can identify any problem that you wish (or make up a hypothetical problem),
but the sorting algorithm that you must use to sort the data is merge sort.

It is up to you ( your choice ) as to how you want to utilize merge sort within your program.

Once you have finished, write a small summary to describe the algorithmic time complexity of merge sort.*/

// Pseudo Code Base: zyBooks - 13.6 Merge Sort
// https://learn.zybooks.com/zybook/DVCCOMSC210KolenFall2019/chapter/13/section/6

int timeCounter = 0; // Time complexity Counter, global int

void Merge(double* numbers, int i, int j, int k) {
	int mergedSize = k - i + 1; // Size of merged partition
	int mergePos = 0;   // Position to insert merged number
	int leftPos = 0; // Position of elements in left partition
	int rightPos = 0; // Position of elements in right partition
	double* mergedNumbers = new double[mergedSize]; // Dynamically allocates temporary array for merged numbers

	leftPos = i;
	rightPos = j + 1;

	// Add smallest element from left or right partition to merged numbers
	while (leftPos <= j && rightPos <= k)
	{
		if (numbers[leftPos] <= numbers[rightPos]) {
			mergedNumbers[mergePos] = numbers[leftPos];
			++leftPos;
		}
		else {
			mergedNumbers[mergePos] = numbers[rightPos];
			++rightPos;
		}
		++mergePos;
		++timeCounter;
	}

	// If left partition is not empty, add remaining elemets to merged numbers
	while (leftPos <= j) {
		mergedNumbers[mergePos] = numbers[leftPos];
		++leftPos;
		++mergePos;
		++timeCounter;
	}

	// If right partition is not empty, add remaining elements to merged numbers
	while (rightPos <= k) {
		mergedNumbers[mergePos] = numbers[rightPos];
		++rightPos;
		++mergePos;
		++timeCounter;
	}

	// Copty merge number back to numbers
	for (mergePos = 0; mergePos < mergedSize; ++mergePos)
	{
		numbers[i + mergePos] = mergedNumbers[mergePos];
	}

	delete[] mergedNumbers;

}

void MergeSort(double* numbers, int i, int k) {
	int j = 0;

	if (i < k) {
		j = (i + k) / 2; // Find the midpoint in the partition

		// Recursively sort left and right partitions
		MergeSort(numbers, i, j);
		MergeSort(numbers, j + 1, k);

		// Merge left and right partition in sorted order
		Merge(numbers, i, j, k);
	}
}
int main()
{
	int i = 0;

	const int NUMBER_SIZE = 31;
	double numbers[NUMBER_SIZE];
	cout << "Please enter 31 scores separated by a space." << endl;

	for (i = 0; i < NUMBER_SIZE; i++) {
		cin >> numbers[i];
	}

	cout << "UNSORTED: ";
	for (i = 0; i < NUMBER_SIZE; i++) {
		cout << numbers[i] << " ";
	}
	cout << endl;

	MergeSort(numbers, 0, NUMBER_SIZE - 1);

	cout << "SORTED: ";
	for (i = 0; i < NUMBER_SIZE; i++) {
		cout << numbers[i] << " ";
	}
	cout << endl;

	cout << "TIME COMPLEXITY: " << timeCounter << endl;
	cout << "The number of time complexity of merge sort is fixed as the number of elements times the level of division by two." << endl;
	cout << "Which is equal to N*logN" << endl;
	return 0;
}
