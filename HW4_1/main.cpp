////////////////////////////////////////////////////////////////////////////////////////
// main.cpp
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
#include "TimeStamp.h"
using namespace std;

template<class T> //function template to display the array or vector
void printData(const T &data, const size_t dataSize);

template<class T> //function template to generate random integer data in the range of [LO, HI)
void dataGenerator(T &data, const size_t size, const int LO, const int HI);

int main()
{
	
	const int dataSizeSmall = 20; //the size of the small data set
	const int loSmall = 100; //the lower  bound for random number generation of the small data set
	const int hiSmall = 300; //the higher bound for random number generation of the small data set

	int arrSmall_1[dataSizeSmall]; //a C-style array with dataSize elements, arrSmall_1
	dataGenerator(arrSmall_1, dataSizeSmall, loSmall, hiSmall); //arr_1 was generated with random number between lo and hi

	int arrSmall_2[dataSizeSmall]; //another C-style array with dataSize elements, arrSmall_2
	copy(arrSmall_1, arrSmall_1 + dataSizeSmall, arrSmall_2); //helper function: std::copy, copy arrSmall_2 from arrSmall_1

	vector<int> vecSmall_1(arrSmall_1, arrSmall_1 + dataSizeSmall); //define a STL vector, copy vecSmall_1 from arrSmall_1
	vector<int> vecSmall_2 = vecSmall_1; //copy vecSmall_2 from vecSmall_1
	
	cout << "---------------- Now test selection sorting with " << dataSizeSmall << " elements ----------------" << endl;
	cout << endl;
	//display the arr_1, arr_2, and vec_1, vec_2
	cout << "Before the selection sort, arrSmall_1: " << endl;
	printData(arrSmall_1, dataSizeSmall);
	cout << "Before the selection sort, arrSmall_2: " << endl;
	printData(arrSmall_2, dataSizeSmall);
	cout << "Before the selection sort, vecSmall_1: " << endl;
	printData(vecSmall_1, dataSizeSmall);
	cout << "Before the selection sort, vecSmall_2: " << endl;
	printData(vecSmall_2, dataSizeSmall);


	SelectionSort ssSmall; //an instance of class SelectionSort

	ssSmall.recursiveSort(arrSmall_1, dataSizeSmall); //sort a C-style arrays with recursive method
	cout << "After the recursive selection sort, arrSmall_1: " << endl;
	printData(arrSmall_1, dataSizeSmall);

	ssSmall.iterativeSort(arrSmall_2, dataSizeSmall);//sort a C-style arrays with iterative method
	cout << "After the iterative selection sort, arrSmall_2: " << endl;
	printData(arrSmall_2, dataSizeSmall);

	ssSmall.recursiveSort(vecSmall_1); //sort a STL vector with recursive method
	cout << "After the recursive selection sort, vecSmall_1: " << endl;
	printData(vecSmall_1, dataSizeSmall);

	ssSmall.iterativeSort(vecSmall_2); //sort a STL vector with iterative method
	cout << "After the iterative selection sort, vecSmall_2: " << endl;
	printData(vecSmall_2, dataSizeSmall);
	cout << endl;

	/////////////////////////////////////////////////////////////////////////////////////////////////////
	// Analyze performance of selection algorithms using large arrays and large vectors.

	const int dataSizeLarge = 8000; //the size of the large data set
	const int loLarge = 0; //the lower  bound for random number generation
	const int hiLarge = 10000; //the higher bound for random number generation

	int arrLarge_1[dataSizeLarge]; //a C-style array with dataSizeLarge elements, arr_1
	dataGenerator(arrLarge_1, dataSizeLarge, loLarge, hiLarge); //arr_1 was generated with random number between lo and hi

	int arrLarge_2[dataSizeLarge]; //another C-style array with dataSizeLarge elements, arr_2
	copy(arrLarge_1, arrLarge_1 + dataSizeLarge, arrLarge_2); //helper function: std::copy, copy large arr_2 from large arr_1

	vector<int> vecLarge_1(arrLarge_1, arrLarge_1 + dataSizeLarge); //define a STL vector, copy vec_1 from arr_1
	vector<int> vecLarge_2(vecLarge_1); //copy large vec_2 from large vec_1

	cout << "---------------- Now test selection sorting with " << dataSizeLarge << " elements ----------------" << endl;
	cout << endl;
	SelectionSort ssLarge; //an instance of class SelectionSort

	TimeStamp ts; //an instance for class TimeStamp
	cout << "For recursively sorting large C-style array with " << dataSizeLarge << " elements: " << endl;
	cout << "Start time:  " << ts.GetTime() << endl; //print timestamp
	ssLarge.recursiveSort(arrLarge_1, dataSizeLarge); //sort a C-style arrays with recursive method
	cout << "Ending time: " << ts.GetTime() << endl; //print timestamp
	cout << endl;

	cout << "For iteratively sorting large C-style array with " << dataSizeLarge << " elements: " << endl;
	cout << "Start time:  " << ts.GetTime() << endl; //print timestamp
	ssLarge.iterativeSort(arrLarge_2, dataSizeLarge);//sort a C-style arrays with iterative method
	cout << "Ending time: " << ts.GetTime() << endl; //print timestamp
	cout << endl;

	cout << "For recursively sorting large STL vector with " << dataSizeLarge << " elements: " << endl;
	cout << "Start time:  " << ts.GetTime() << endl; //print timestamp
	ssLarge.recursiveSort(vecLarge_1); //sort a STL vector with recursive method
	cout << "Ending time: " << ts.GetTime() << endl; //print timestamp
	cout << endl;


	cout << "For iteratively sorting large STL vector with " << dataSizeLarge << " elements: " << endl;
	cout << "Start time:  " << ts.GetTime() << endl; //print timestamp
	ssLarge.iterativeSort(vecLarge_2); //sort a STL vector with iterative method
	cout << "Ending time: " << ts.GetTime() << endl; //print timestamp
	cout << endl;

}

//function template to display the array or vector
template<class T>
void printData(const T &data, const size_t dataSize)
{
	for (size_t i = 0; i != dataSize; ++i)
		cout << data[i] << " ";
	cout << endl;
}

//function template to generate random integer data in the range of [LO, HI)
template<class T>
void dataGenerator(T &data, const size_t dataSize, const int LO, const int HI)
{
	srand(static_cast<unsigned int>(time(0)));
	for (size_t i = 0; i != dataSize; ++i)
	{
		data[i] =  LO + rand() % (HI - LO);
	}
}
