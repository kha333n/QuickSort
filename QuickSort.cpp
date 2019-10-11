// QuickSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//



//Quick sort algorithm for sorting elements in an array.
//Refferance to the concept.    https://www.youtube.com/watch?v=8isAsDxcXPo



#include<iostream>
using namespace std;

int partition (int *array, int starting_point, int ending_point)
{
	//Take two pointers
	int i = starting_point - 1;
	int j = starting_point;
	int pivot = array[ending_point];
	
	for (; j <= ending_point; j++)
	{
		if (array[j] <= pivot) //IF the element is <= pivot element add it to first region.
		{
			i++;
			swap(array[i], array[j]);
		}
	}
	//Bring the pivot element to its sorted position.

	swap(array[i+1], array[ending_point]);
	//Return the current position of pivot point which is i+1

	return i+1;
}

void quickSort (int *array, int starting_point, int ending_point)
{
	if ( starting_point >= ending_point) //If there is only one element just return. No need to sort.
	{
		return;
	}

	//To avoid STACK OVERFLOW we use tail recursion.
	//For this to work, you have to make sure that the smaller of the two partitions is sorted first.
	//Reffer    https://en.wikipedia.org/wiki/Quicksort#Optimizations


TailRecurse:	
	if (starting_point < ending_point)
	{
	//Find out pivot point using partition function.
	int pivot = partition (array, starting_point, ending_point);
	//After partitioning the array.
		
	if (pivot < (starting_point + ending_point) / 2)
	{ //First partition is smaller.
		quickSort(array, starting_point, pivot-1); // Sort first partition.     //quickSort on left part.
		starting_point = pivot + 1;
		goto TailRecurse;	//Sort second partition.
	}
	else
	{  //Second partition is smaller.
		quickSort(array, pivot+1, ending_point); //Sort second partition.       //quickSort on right part.
		ending_point = pivot - 1;
		goto TailRecurse; // Sort first partition.
	}
		
	}
}

int main()
{
	int a[] = {3,1,4,81,32,13,42,12};
	int n = sizeof(a)/sizeof(n);
	quickSort(a,0,n-1);

	for (int i=0; i<n; i++)
	{
		cout << a[i] << endl;
	}
	return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
