#include <iostream>
#include <exception>
using namespace std;

int count1 = 0;
int count2 = 0;

int search(int* arr, int size ,int item)
{
	for (int i = 0; i < size; i++)
	{
		count1++; 
		if (arr[i] == item)
			return i;
	}
	return -1;
}

int BinarySearch(int* arr, int size, int item)   
{
	int first = 0; 
	int last = size - 1;
	while (first <= last) 
	{
		int mid = (last + first) / 2; 
		count2++;
		if (arr[mid] == item)  
			return mid;
		else if (arr[mid] > item) 
			last = mid - 1;
		else 
			first = mid + 1;
	}
}

void main()
{
	int* arr = new int[1000000];
	for (int i = 0; i < 1000000; i++)
	{
		arr[i] = i;
	}

	cout << "Linear search result: " << search(arr, 1000000, 999999) << ", took " << count1 << " iterations" << endl;
	cout << "Binary search result: " << BinarySearch(arr, 1000000, 999999) << ", took " << count2 << " iterations" << endl;
	delete[] arr;
}