////////////////////////////////////////////////////////////////////////////////////////
// SelectionSort.h
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

#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include <iostream>
#include <vector>
using std::vector;

class SelectionSort
{
public:
	SelectionSort(); //class constructor
	void recursiveSort(int arr[], size_t arrSize); //recursive method to sort C-style arrays
	void recursiveSort(vector<int> &vec); //recursive method to sort STL vectors

	void iterativeSort(int arr[], size_t arrSize); //iterative method to sort C-style arrays
	void iterativeSort(vector<int> &vec); //iterative method to sort STL vectors

private:
	bool ascending; // a helper bool variable, which decide a ascending or descending sort

	void choice();//promopt the use choose ascending or descending sort
	void swap(int &num1, int &num2);//swap the value of two variables

	//the recursive sort method which do the actual work
	void recursiveSort(int arr[], size_t left, size_t right);
	void recursiveSort(vector<int> &vec, size_t left, size_t right);


	template <class T> //method to return the min index in a data(C-style array or a STL vector) in the range of lo and hi
	size_t findMinIndex(const T &data, size_t lo, size_t hi);

	template <class T> //method to return the max index in a data(C-style array or a STL vector) in the range of lo and hi
	size_t findMaxIndex(const T &data, size_t lo, size_t hi);

};

#endif