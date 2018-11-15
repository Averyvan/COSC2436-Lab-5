//Author:               Avery Vanausdal
//Assignment Number:    Lab 5
//File Name:			AveryVanAusdalLab5Part1Driver.cpp
//Course/Selection:     COSC 2436 Section 003
//Due Date:             11/12/18
//Instructor:           Ku, Bernard
//Description:			Menu testing different sorting algorithms

#include <iostream>
#include <algorithm>
#include <array>

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

template<class T>
void displayArray(T array[], int size)
{
	for (int i = 0; i< size; i++)
		cout<<array[i]<<" ";
	cout<<endl;
}

template<class T>
void displaySorted(T array[], int size)
{
	cout<<"Sorted Array: ";
	displayArray(array, size);
	cout<<endl;
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

void intTesting()
{
	int intArray[10] = {654, 18, 81, 4, 92, 68, 145, 8, 99, 36};
	cout<<"Original Array: ";
	displayArray(intArray, 10);
	cout<<endl;
	int input = get_input<int>("Which integer sorting method do you want to use:\n1. Bubble\n2. Heap\n3. Insertion\n4. Merge\n5. Quick\n6. Radix\n7. Selection\n8. Shell\n9. STL\n10. Exit\n", 
	"Please enter the number of an option 1-10.\n\n", 1, 10);
	switch (input)
	{
		case 1: {
			cout<<"\nBubble sorting...\n";
			bubbleSort(intArray, 10);
			displaySorted(intArray, 10);
			break;
		}
		case 2: {
			int intHeapArray[11] = {0, 654, 18, 81, 4, 92, 68, 145, 8, 99, 36};
			cout<<"\nHeap sorting...\n";
			HEAPSORT(intHeapArray, 10);
			displaySorted(intHeapArray+1, 10);
			break;
		}
		case 3: {
			cout<<"\nInsertion sorting...\n";
			insertionSort(intArray, 10);
			displaySorted(intArray, 10);
			break;
		}
		case 4: {
			cout<<"\nMerge sorting...\n";
			mergeSort(intArray, 0, 10);
			displaySorted(intArray, 10);
			break;
		}
		case 5: {
			cout<<"\nQuick sorting...\n";
			quickSort(intArray, 0, 10);
			displaySorted(intArray, 10);
			break;
		}
		case 6: {
			cout<<"\nRadix sorting...\n";
			radixsort(intArray, 10);
			displaySorted(intArray, 10);
			break;
		}
		case 7: {
			cout<<"\nSelection sorting...\n";
			selectionSort(intArray, 10);
			displaySorted(intArray, 10);
			break;
		}
		case 8: {
			cout<<"\nShell sorting...\n";
			shellSort(intArray, 10);
			displaySorted(intArray, 10);
			break;
		}
		case 9: {
			cout<<"\nSTL sorting...\n";
			sort(intArray, intArray+10);
			displaySorted(intArray, 10);
			break;
		}
		case 10: cout<<endl;
	}
}

void strTesting()
{
	string strArray[6] = {"Z", "X", "R", "K", "F", "B"};
	cout<<"Original Array: ";
	displayArray(strArray, 6);
	cout<<endl;
	int input = get_input<int>("Which string sorting method do you want to use:\n1. Bubble\n2. Insertion\n3. Merge\n4. Quick\n5. Radix\n6. Selection\n7. Shell\n8. STL\n9. Exit\n", 
	"Please enter the number of an option 1-9.\n\n", 1, 9);
	switch (input)
	{
		case 1: {
			cout<<"\nBubble sorting...\n";
			bubbleSort(strArray, 6);
			displaySorted(strArray, 6);
			break;
		}
		case 2: {
			cout<<"\nInsertion sorting...\n";
			insertionSort(strArray, 6);
			displaySorted(strArray, 6);
			break;
		}
		case 3: {
			cout<<"\nMerge sorting...\n";
			mergeSort(strArray, 0, 5);
			displaySorted(strArray, 6);
			break;
		}
		case 4: {
			cout<<"\nQuick sorting...\n";
			quickSort(strArray, 0, 5);
			displaySorted(strArray, 6);
			break;
		}
		case 5: {
			cout<<"\nRadix sorting...\n";
			radixSort(strArray, 6);
			displaySorted(strArray, 6);
			break;
		}
		case 6: {
			cout<<"\nSelection sorting...\n";
			selectionSort(strArray, 6);
			displaySorted(strArray, 6);
			break;
		}
		case 7: {
			cout<<"\nShell sorting...\n";
			shellSort(strArray, 6);
			displaySorted(strArray, 6);
			break;
		}
		case 8: {
			cout<<"\nSTL sorting...\n";
			sort(strArray, strArray+6);
			displaySorted(strArray, 6);
			break;
		}
		case 9: cout<<endl;
	}
}

int main()
{
	string choice;
	size_t size = 0;
	while (true)
	{
		cout<<"Which type of array do you want to sort:\n1. Integer\n2. String\n3. Exit\n";
		cin>>choice;
		cout<<endl;
		switch (choice[0])
		{
			case '1': {
				intTesting();
				break;
			}
			case '2': {
				strTesting();
				break;
			}
			case '3': {
				cout<<"Thank you, goodbye!";
				return 0;
			}
		}
		
	}
}

/* Sample output:
Which type of array do you want to sort:
1. Integer
2. String
3. Exit
1

Original Array: 654 18 81 4 92 68 145 8 99 36

Which integer sorting method do you want to use:
1. Bubble
2. Heap
3. Insertion
4. Merge
5. Quick
6. Radix
7. Selection
8. Shell
9. STL
10. Exit
2

Heap sorting...
Sorted Array: 4 8 18 36 68 81 92 99 145 654

Which type of array do you want to sort:
1. Integer
2. String
3. Exit
1

Original Array: 654 18 81 4 92 68 145 8 99 36

Which integer sorting method do you want to use:
1. Bubble
2. Heap
3. Insertion
4. Merge
5. Quick
6. Radix
7. Selection
8. Shell
9. STL
10. Exit
3

Insertion sorting...
Sorted Array: 4 8 18 36 68 81 92 99 145 654

Which type of array do you want to sort:
1. Integer
2. String
3. Exit
1

Original Array: 654 18 81 4 92 68 145 8 99 36

Which integer sorting method do you want to use:
1. Bubble
2. Heap
3. Insertion
4. Merge
5. Quick
6. Radix
7. Selection
8. Shell
9. STL
10. Exit
4

Merge sorting...
Sorted Array: 4 8 18 36 68 81 92 99 145 654

Which type of array do you want to sort:
1. Integer
2. String
3. Exit
1

Original Array: 654 18 81 4 92 68 145 8 99 36

Which integer sorting method do you want to use:
1. Bubble
2. Heap
3. Insertion
4. Merge
5. Quick
6. Radix
7. Selection
8. Shell
9. STL
10. Exit
5

Quick sorting...
Sorted Array: 4 8 18 36 68 81 92 99 145 654

Which type of array do you want to sort:
1. Integer
2. String
3. Exit
1

Original Array: 654 18 81 4 92 68 145 8 99 36

Which integer sorting method do you want to use:
1. Bubble
2. Heap
3. Insertion
4. Merge
5. Quick
6. Radix
7. Selection
8. Shell
9. STL
10. Exit
6

Radix sorting...
Sorted Array: 4 8 18 36 68 81 92 99 145 654

Which type of array do you want to sort:
1. Integer
2. String
3. Exit
1

Original Array: 654 18 81 4 92 68 145 8 99 36

Which integer sorting method do you want to use:
1. Bubble
2. Heap
3. Insertion
4. Merge
5. Quick
6. Radix
7. Selection
8. Shell
9. STL
10. Exit
7

Selection sorting...
Sorted Array: 4 8 18 36 68 81 92 99 145 654

Which type of array do you want to sort:
1. Integer
2. String
3. Exit
1

Original Array: 654 18 81 4 92 68 145 8 99 36

Which integer sorting method do you want to use:
1. Bubble
2. Heap
3. Insertion
4. Merge
5. Quick
6. Radix
7. Selection
8. Shell
9. STL
10. Exit
8

Shell sorting...
Sorted Array: 4 8 18 36 68 81 92 99 145 654

Which type of array do you want to sort:
1. Integer
2. String
3. Exit
1

Original Array: 654 18 81 4 92 68 145 8 99 36

Which integer sorting method do you want to use:
1. Bubble
2. Heap
3. Insertion
4. Merge
5. Quick
6. Radix
7. Selection
8. Shell
9. STL
10. Exit
9

STL sorting...
Sorted Array: 4 8 18 36 68 81 92 99 145 654

Which type of array do you want to sort:
1. Integer
2. String
3. Exit
2

Original Array: Z X R K F B

Which string sorting method do you want to use:
1. Bubble
2. Insertion
3. Merge
4. Quick
5. Radix
6. Selection
7. Shell
8. STL
9. Exit
1

Bubble sorting...
Sorted Array: B F K R X Z

Which type of array do you want to sort:
1. Integer
2. String
3. Exit
2

Original Array: Z X R K F B

Which string sorting method do you want to use:
1. Bubble
2. Insertion
3. Merge
4. Quick
5. Radix
6. Selection
7. Shell
8. STL
9. Exit
2

Insertion sorting...
Sorted Array: B F K R X Z

Which type of array do you want to sort:
1. Integer
2. String
3. Exit
2

Original Array: Z X R K F B

Which string sorting method do you want to use:
1. Bubble
2. Insertion
3. Merge
4. Quick
5. Radix
6. Selection
7. Shell
8. STL
9. Exit
3

Merge sorting...
Sorted Array: B F K R X Z

Which type of array do you want to sort:
1. Integer
2. String
3. Exit
2

Original Array: Z X R K F B

Which string sorting method do you want to use:
1. Bubble
2. Insertion
3. Merge
4. Quick
5. Radix
6. Selection
7. Shell
8. STL
9. Exit
4

Quick sorting...
Sorted Array: B F K R X Z

Which type of array do you want to sort:
1. Integer
2. String
3. Exit
2

Original Array: Z X R K F B

Which string sorting method do you want to use:
1. Bubble
2. Insertion
3. Merge
4. Quick
5. Radix
6. Selection
7. Shell
8. STL
9. Exit
5

Radix sorting...
Sorted Array: B F K R X Z

Which type of array do you want to sort:
1. Integer
2. String
3. Exit
2

Original Array: Z X R K F B

Which string sorting method do you want to use:
1. Bubble
2. Insertion
3. Merge
4. Quick
5. Radix
6. Selection
7. Shell
8. STL
9. Exit
6

Selection sorting...
Sorted Array: B F K R X Z

Which type of array do you want to sort:
1. Integer
2. String
3. Exit
2

Original Array: Z X R K F B

Which string sorting method do you want to use:
1. Bubble
2. Insertion
3. Merge
4. Quick
5. Radix
6. Selection
7. Shell
8. STL
9. Exit
7

Shell sorting...
Sorted Array: B F K R X Z

Which type of array do you want to sort:
1. Integer
2. String
3. Exit
2

Original Array: Z X R K F B

Which string sorting method do you want to use:
1. Bubble
2. Insertion
3. Merge
4. Quick
5. Radix
6. Selection
7. Shell
8. STL
9. Exit
8

STL sorting...
Sorted Array: B F K R X Z

Which type of array do you want to sort:
1. Integer
2. String
3. Exit
2

Original Array: Z X R K F B

Which string sorting method do you want to use:
1. Bubble
2. Insertion
3. Merge
4. Quick
5. Radix
6. Selection
7. Shell
8. STL
9. Exit
9

Which type of array do you want to sort:
1. Integer
2. String
3. Exit
3

Thank you, goodbye!
--------------------------------
Process exited after 44.21 seconds with return value 0
Press any key to continue . . .
*/
