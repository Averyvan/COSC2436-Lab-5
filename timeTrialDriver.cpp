//Author:               Avery Vanausdal
//Assignment Number:    Lab 5
//File Name:		timeTrialDriver.cpp
//Course/Selection:     COSC 2436 Section 003
//Due Date:             11/12/18
//Instructor:           Ku, Bernard
//Description:			

#include <iostream>
#include <iomanip>
#include <ctime>
#include <fstream>
#include <limits>
#include <algorithm>

#include "bubbleSort.cpp"
#include "HeapSort.cpp" //ints only
#include "insertionSort.cpp"
#include "mergesort.cpp"
#include "quicksort.cpp"
#include "RadixSort.cpp" //ints only
#include "RadixSort4String.cpp" //strings only
#include "selectionSort.cpp"
#include "shellSort.cpp"

using namespace std;

void fillIntArray(int array[], int size)
{
	for(int i = 0; i < size; i++)
	{
		array[i] = rand();
	}
}

void fillStrArray(string array[], int size)
{
	ifstream inFile("LastName2010.txt");
	for(int i = 0; i < size; i++)
	{
		getline(inFile, array[i]);
	}
}

template<class T>
void trialRuns(int trials, ofstream &outFile, string sortName, void (*sortAlg)(T[], int), int size, void fillArray(T[], int))
{
	T **array = new T*[trials];
	for(int i=0; i < trials; i++)
		array[i] = new T[size];
	for(int j = 0; j < trials; j++)
	{
		fillArray(&array[j][0], size);
	}

	double start = double(clock()) / CLOCKS_PER_SEC; //starts timer

	for (int i=1; i<=trials; i++)
	{
		sortAlg(&array[i-1][0], size);
	}
	outFile << fixed << showpoint << setprecision (5) << "Algorithm: "<<sortName<<endl;
	double finish = double(clock()) / CLOCKS_PER_SEC;														   
	double elapsed = (finish - start);  //Takes final time - beginning time, to get time to complete all iterative trials
	double average = (finish - start)/trials;//finds average time to complete each trial
	outFile << "Time Elapsed: " << setw(5) << elapsed << " seconds" << endl; //displays elapsed time
	outFile << "Average time trial over " << trials << " times: " << setw(5) << average << " seconds with "<<size<< " elements\n" <<endl; //displays average time
	for(int i=0; i < trials; i++)
		delete[] array[i];
	delete[] array;
}

template<class T>
void trialRuns2(int trials, ofstream &outFile, string sortName, void (*sortAlg)(T[], int, int), int size, void fillArray(T[], int))
{
	T **array = new T*[trials];
	for(int i=0; i < trials; i++)
		array[i] = new T[size];
	for(int j = 0; j < trials; j++)
	{
		fillArray(&array[j][0], size);
	}
	double start = double(clock()) / CLOCKS_PER_SEC; //starts timer

	for (int i=1; i<=trials; i++)
	{
		sortAlg(&array[i-1][0], 0, size-1);
	}
	
	outFile << fixed << showpoint << setprecision (5) << "Algorithm: "<<sortName<<endl;
	double finish = double(clock()) / CLOCKS_PER_SEC;														   
	double elapsed = (finish - start);  //Takes final time - beginning time, to get time to complete all iterative trials
	double average = (finish - start)/trials;//finds average time to complete each trial
	outFile << "Time Elapsed: " << setw(5) << elapsed << " seconds" << endl; //displays elapsed time
	outFile << "Average time trial over " << trials << " times: " << setw(5) << average << " seconds with "<<size<< " elements\n" <<endl; //displays average time
	for(int i=0; i < trials; i++)
		delete[] array[i];
	delete[] array;
}

template<class T>
void trialSTLsort(int trials, ofstream &outFile, int size, void fillArray(T[], int))
{
	T **array = new T*[trials];
	for(int i=0; i < trials; i++)
		array[i] = new T[size];
	for(int j = 0; j < trials; j++)
	{
		fillArray(&array[j][0], size);
	}

	
	double start = double(clock()) / CLOCKS_PER_SEC; //starts timer

	for (int i=1; i<=trials; i++)
	{
		sort(&array[i-1][0], &array[i-1][size-1]);
	}
	outFile << fixed << showpoint << setprecision (5) << "Algorithm: STL Sort"<<endl;
	double finish = double(clock()) / CLOCKS_PER_SEC;														   
	double elapsed = (finish - start);  //Takes final time - beginning time, to get time to complete all iterative trials
	double average = (finish - start)/trials;//finds average time to complete each trial
	outFile << "Time Elapsed: " << setw(5) << elapsed << " seconds" << endl; //displays elapsed time
	outFile << "Average time trial over " << trials << " times: " << setw(5) << average << " seconds with "<<size<< " elements\n" <<endl; //displays average time
	for(int i=0; i < trials; i++)
		delete[] array[i];
	delete[] array;
}

template <typename T>
T get_input(const string& prompt="", const string& error_msg="", 
T min=-numeric_limits<T>::max(), T max=numeric_limits<T>::max()) {
	T value{};
	while (not(cout<<prompt && cin>>value && value>=min && value<=max)) {
		cout<<error_msg;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
	}
	return value;
}

void intTesting(ofstream &outFile, int size)
{
	int input = get_input<int>("Which integer sorting method do you want to use:\n1. Bubble\n2. Heap\n3. Insertion\n4. Merge\n5. Quick\n6. Radix\n7. Selection\n8. Shell\n9. STL\n10. Exit\n", 
	"Please enter the number of an option 1-10.\n\n", 1, 10);
	switch (input)
	{
		case 1: {
			cout<<"\nBubble sorting...\n";
			trialRuns<int>(1, outFile, "bubbleSort", bubbleSort, size, fillIntArray);
			cout<<"Done!\n\n";
			break;
		}
		case 2: {
			cout<<"\nHeap sorting...\n";
			trialRuns<int>(1, outFile, "HEAPSORT", HEAPSORT, size, fillIntArray);
			cout<<"Done!\n\n";
			break;
		}
		case 3: {
			cout<<"\nInsertion sorting...\n";
			trialRuns<int>(1, outFile, "insertionSort", insertionSort, size, fillIntArray);
			cout<<"Done!\n\n";
			break;
		}
		case 4: {
			cout<<"\nMerge sorting...\n";
			trialRuns2<int>(1, outFile, "mergeSort", mergeSort, size, fillIntArray);
			cout<<"Done!\n\n";
			break;
		}
		case 5: {
			cout<<"\nQuick sorting...\n";
			trialRuns2<int>(1, outFile, "quickSort", quickSort, size, fillIntArray);
			cout<<"Done!\n\n";
			break;
		}
		case 6: {
			cout<<"\nRadix sorting...\n";
			trialRuns<int>(1, outFile, "radixsort", radixsort, size, fillIntArray);
			cout<<"Done!\n\n";
			break;
		}
		case 7: {
			cout<<"\nSelection sorting...\n";
			trialRuns<int>(1, outFile, "selectionSort", selectionSort, size, fillIntArray);
			cout<<"Done!\n\n";
			break;
		}
		case 8: {
			cout<<"\nShell sorting...\n";
			trialRuns<int>(1, outFile, "shellSort", shellSort, size, fillIntArray);
			cout<<"Done!\n\n";
			break;
		}
		case 9: {
			cout<<"\nSTL sorting...\n";
			trialSTLsort(1, outFile, size, fillIntArray);
			cout<<"Done!\n\n";
			break;
		}
		case 10: cout<<endl;
	}
}

void strTesting(ofstream &outFile, int size)
{
	int input = get_input<int>("Which string sorting method do you want to use:\n1. Bubble\n2. Insertion\n3. Merge\n4. Quick\n5. Radix\n6. Selection\n7. Shell\n8. STL\n9. Exit\n", 
	"Please enter the number of an option 1-10.\n\n", 1, 9);
	switch (input)
	{
		case 1: {
			cout<<"\nBubble sorting...\n";
			trialRuns<string>(1, outFile, "bubbleSort", bubbleSort, size, fillStrArray);
			cout<<"Done!\n\n";
			break;
		}
		case 2: {
			cout<<"\nInsertion sorting...\n";
			trialRuns<string>(1, outFile, "insertionSort", insertionSort, size, fillStrArray);
			cout<<"Done!\n\n";
			break;
		}
		case 3: {
			cout<<"\nMerge sorting...\n";
			trialRuns2<string>(1, outFile, "mergeSort", mergeSort, size, fillStrArray);
			cout<<"Done!\n\n";
			break;
		}
		case 4: {
			cout<<"\nQuick sorting...\n";
			trialRuns2<string>(1, outFile, "quickSort", quickSort, size, fillStrArray);
			cout<<"Done!\n\n";
			break;
		}
		case 5: {
			cout<<"\nRadix sorting...\n";
			trialRuns<string>(1, outFile, "radixSort", radixSort, size, fillStrArray);
			cout<<"Done!\n\n";
			break;
		}
		case 6: {
			cout<<"\nSelection sorting...\n";
			trialRuns<string>(1, outFile, "selectionSort", selectionSort, size, fillStrArray);
			cout<<"Done!\n\n";
			break;
		}
		case 7: {
			cout<<"\nShell sorting...\n";
			trialRuns<string>(1, outFile, "shellSort", shellSort, size, fillStrArray);
			cout<<"Done!\n\n";
			break;
		}
		case 8: {
			cout<<"\nSTL sorting...\n";
			trialSTLsort(1, outFile, size, fillStrArray);
			cout<<"Done!\n\n";
			break;
		}
		case 9: cout<<endl;
	}
}

int main()
{
	ofstream outFile("Test Results.txt", ios::app);
	int numTrials = 0;
	string choice;
	while (true)
	{
		cout<<"Which type of array do you want to sort:\n1. Integer\n2. String\n3. Full Testing Run (Will take hours)\n4. Exit\n";
		cin>>choice;
		cout<<endl;
		switch (choice[0])
		{
			case '1': {
				int size = get_input<int>("Enter how many elements in the array: ");
				intTesting(outFile, size);
				break;
			}
			case '2': {
				int size = get_input<int>("Enter how many elements in the array: ");
				strTesting(outFile, size);
				break;
			}
			case '3': {
				cout<<"Bulk testing:\n Integer runs...\n";
				int intRuns[5] = {1000, 50000, 75000, 100000, 250000};
				int strRuns[3] = {100000, 250000, 440000};
				int trials = 5;
				for (int size:intRuns) trialRuns<int>(trials, outFile, "bubbleSort", bubbleSort, size, fillIntArray);
				for (int size:intRuns) trialRuns<int>(trials, outFile, "HEAPSORT", HEAPSORT, size, fillIntArray);
				for (int size:intRuns) trialRuns<int>(trials, outFile, "insertionSort", insertionSort, size, fillIntArray);
				for (int size:intRuns) trialRuns2<int>(trials, outFile, "mergeSort", mergeSort, size, fillIntArray);
				for (int size:intRuns) trialRuns2<int>(trials, outFile, "quickSort", quickSort, size, fillIntArray);
				for (int size:intRuns) trialRuns<int>(trials, outFile, "radixsort", radixsort, size, fillIntArray);
				for (int size:intRuns) trialRuns<int>(trials, outFile, "selectionSort", selectionSort, size, fillIntArray);
				for (int size:intRuns) trialRuns<int>(trials, outFile, "shellSort", shellSort, size, fillIntArray);
				for (int size:intRuns) trialSTLsort(trials, outFile, size, fillIntArray);
				cout<<"String runs...\n";
				outFile<<"String Testing\n";
				for (int size:strRuns) trialRuns<string>(trials, outFile, "bubbleSort", bubbleSort, size, fillStrArray);
				for (int size:strRuns) trialRuns<string>(trials, outFile, "insertionSort", insertionSort, size, fillStrArray);
				for (int size:strRuns) trialRuns2<string>(trials, outFile, "mergeSort", mergeSort, size, fillStrArray);
				for (int size:strRuns) trialRuns2<string>(trials, outFile, "quickSort", quickSort, size, fillStrArray);
				for (int size:strRuns) trialRuns<string>(trials, outFile, "radixSort", radixSort, size, fillStrArray);
				for (int size:strRuns) trialRuns<string>(1, outFile, "selectionSort", selectionSort, size, fillStrArray);
				for (int size:strRuns) trialRuns<string>(1, outFile, "shellSort", shellSort, size, fillStrArray);
				for (int size:strRuns) trialSTLsort(trials, outFile, size, fillStrArray);
				cout<<"We're done!\n";
				break;
			}
			case '4': {
				cout<<"Thank you, goodbye!";
				return 0;
			}
		}
	}
	
//	intTrialRuns(10, outFile, "bubbleSort", bubbleSort, 10000);
	outFile.close();
	return 0;
}

