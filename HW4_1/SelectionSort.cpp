////////////////////////////////////////////////////////////////////////////////////////
// SelectionSort.cpp
// -----------------------------------------------------------------------------------
// Course: CIS554
// HomeWork 4
// Author: Wei Liu
// Date: 3/1/2015
// -----------------------------------------------------------------------------------
// Class descriptinon: 
// The class can ascendingly or descendingly sort a C-style or STL vector with recursive
// or iterative selection sort method. 
// Input 1 for ascending sort, 2 for descending sort. The default is ascending sorting.
////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include "SelectionSort.h"

using namespace std;
//constructor of class SelectionSort
SelectionSort::SelectionSort()
{
	ascending = true; //set ascending as default true;
	choice(); //ask the user to select
}
//promopt the use choose ascending or descending sort
void SelectionSort::choice()
{
	int input;
	cout << "Input 1 for ascending sort, 2 for descending sort: ";
	cin >> input;
	while ( 1 )
	{
		switch (input)
		{
		case 1:
			ascending = true;
			break;
		case 2:
			ascending = false;
			break;
		default:
			cout << "/[ERROR] Invalid input!";
			break;
		}
		break;
	}
	cout << endl;
}
//method of recursive sort for C-style array
void SelectionSort::recursiveSort(int arr[], size_t arrSize)
{
	recursiveSort(arr, 0, arrSize);
}
//method of recursive sort for C-style array, which does the actual work
void SelectionSort::recursiveSort(int arr[], size_t left, size_t right)
{
	if (left < right)
	{
		size_t temp = left;
		if (ascending)
			temp = findMinIndex(arr, left, right);
		else
			temp = findMaxIndex(arr, left, right);
		swap(arr[temp], arr[left]);
		recursiveSort(arr, left + 1, right);
	}
}
//iterative sort method for C-style array
void SelectionSort::iterativeSort(int arr[], size_t arrSize)
{
	for (size_t i = 0; i < arrSize - 1; i++)
	{
		size_t temp = i;
		if (ascending)
			temp = findMinIndex(arr, i, arrSize);	
		else
			temp = findMaxIndex(arr, i, arrSize);		
		swap(arr[temp], arr[i]);
	}
}
//recursive sort method for STL vector
void SelectionSort::recursiveSort(vector<int> &vec)
{
	recursiveSort(vec, 0, vec.size());
}
//recursive sort method for STL vector, which dose the actual work
void SelectionSort::recursiveSort(vector<int> &vec, size_t left, size_t right)
{
	if (left < right)
	{
		size_t temp = left;
		if (ascending)
			temp = findMinIndex(vec, left, right);		
		else
			temp = findMaxIndex(vec, left, right);		
		swap(vec[temp], vec[left]);
		recursiveSort(vec, left + 1, right);
	}
}
//iterative sort method for STL vector
void SelectionSort::iterativeSort(vector<int> &vec)// recursive
{
	for (size_t i = 0; i < vec.size() - 1; i++)
	{
		size_t temp = i;
		if (ascending)
			temp = findMinIndex(vec, i, vec.size());

		else
			temp = findMaxIndex(vec, i, vec.size());
		swap(vec[temp], vec[i]);
	}
}
//method to swap two variables
void SelectionSort::swap(int &num1, int &num2)
{
	int temp = num1;
	num1 = num2;
	num2 = temp;
}

//method to return the min index in a data(C-style array or a STL vector) in the range of lo and hi
template <class T>
size_t SelectionSort::findMinIndex(const T &data, size_t lo, size_t hi)
{
	size_t min = lo;
	for (size_t i = lo + 1; i < hi; i++)
	{
		if (data[i] < data[min])
			min = i;
	}
	return min;
}
//method to return the max index in a data(C-style array or a STL vector) in the range of lo and hi
template <class T>
size_t SelectionSort::findMaxIndex(const T &data, size_t lo, size_t hi)
{
	size_t max = lo;
	for (size_t i = lo + 1; i < hi; i++)
	{
		if (data[i] > data[max])
			max = i;
	}
	return max;
}

