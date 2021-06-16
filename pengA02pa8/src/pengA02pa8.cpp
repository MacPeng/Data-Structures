//============================================================================
// Name        : pengA02pa8.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
using namespace std;

void buildArray(int array[], int size, string s);
void displayArray(int array[], int low, int high);
bool checkIfHeap(int array[], int low, int high);
void heapify(int array[], int low, int high);
void buildHeap(int array[], int low, int high);
void heapSort(int array[], int low, int high);
int main() {
	    int low, high;
		low = 0; 			// low array index
		high = 99;			// high array index
		bool b;
		int list[100];
		string p ="./src/a81data.txt";
		cout << "main: building first array (from a81data.txt)" << endl;
		buildArray (list, 100, p);
		cout << "main: displaying first array" << endl << endl;
		displayArray (list, low, high);
		cout << endl;
		b=checkIfHeap (list, low, high);
		if (b)
			cout << "main: the first array is already a heap" << endl << endl;
		else
			cout << "main: the first array is not a heap" << endl << endl;
		cout << "main: now building heap" << endl;
		buildHeap (list, low, high);
		cout << "main: now displaying first array after heaping" << endl << endl;
		displayArray (list, low, high);
		b=checkIfHeap (list, low, high);
		if (b)
			cout << endl << "main: after heaping, the first array is a heap" << endl << endl;
		else
		{
			cout << endl << "main: after heaping, the first array is not a heap" << endl;
			return 4;
		}
		p ="./src/a82data.txt";
		cout << "main: building second array (from a82data.txt)" << endl;
		buildArray (list, 100, p);
		cout << "main: displaying second array" << endl << endl;
		displayArray (list, low, high);
		heapSort (list, low, high);
		cout << endl << "main: displaying second array, which should now be sorted" << endl << endl;
		displayArray (list, low, high);
		return 0;
}

void buildArray(int array[], int size, string s)
{
	int index = 0;
	ifstream file(s);
	string data;
	for(int i = 0; i < 100;i++)
	{
		array[i] = 0;
	}
	while(getline(file, data))
	{
		data.erase(remove(data.begin(),data.end(), ' '),data.end());
		for(int i = 0; i < data.length();i = i+3)
		{
			if(i < data.length())
			{
				array[index]=stoi(data.substr(i,3));
				index++;
			}else
			{
				array[index] = stoi(data.substr(i,1));
				index++;
			}
		}
	}
}

void displayArray(int array[], int low, int high)
{
	int i = 0;
	while(i != high + 1)
	{
		for(int j = 0;j < 10;j++)
		{
			cout << array[i] << " ";
			i++;
		}
		cout << endl;
	}
}
bool checkIfHeap(int array[], int low, int high)
{
	bool isHeap = true;
	for(int i = low; i < 100; i++)
	{
		int l = 2 * i + 1;
		int r = 2 * i + 2;
		if(l > high || r > high)
		{
			break;
		}
		if(array[l] > array[i] || array[r] > array[i])
		{
			isHeap = false;
			break;
		}
	}
	return isHeap;
}
void heapify(int array[], int low, int high)
{
	int largeIndex;
	int temp = array[low];//copy the root node of the subtree
	largeIndex = 2 * low + 1;//index of the left child
	while(largeIndex <= high)
	{
		if(largeIndex < high)
			if(array[largeIndex] < array[largeIndex + 1])
				largeIndex = largeIndex + 1;//index of the largest child
		if(temp > array[largeIndex])
			break;
		else
		{
			array[low] = array[largeIndex];//move the larger child to the root
			low = largeIndex;//go to the subtree to restore the heap
			largeIndex = 2 * low + 1;
		}
	}
	array[low] = temp;//insert temp into the tree, that's list

}
void buildHeap(int array[], int low, int high)
{
	for(int i = high / 2 - 1; i >= 0; i--)
	{
		heapify(array, i, high);
	}
}

void heapSort(int array[], int low, int high)
{
	int temp;
	buildHeap(array, low, high);
	for(int i = high - 1; i >= 0; i--)
	{
		temp = array[i];
		array[i] = array[0];
		array[0] = temp;
		heapify(array, 0, i - 1);
	}
}
