#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void BubbleSort(int* arr, int size)
{
	for(int i = 0 ; i < size ; i++)
	{
		for (int j = i; j < size; j)
		{
			if (arr[i] > arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp; 
			}
	    }
	}
}

int partition(int arr[], int start, int end)
{
    int pivot = arr[start];

    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }

    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);

    // Sorting left and right parts of the pivot element
    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex) {

        while (arr[i] <= pivot) {
            i++;
        }

        while (arr[j] > pivot) {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

void quickSort(int arr[], int start, int end)
{

    // base case
    if (start >= end)
        return;

    // partitioning the array
    int p = partition(arr, start, end);

    // Sorting the left part
    quickSort(arr, start, p - 1);

    // Sorting the right part
    quickSort(arr, p + 1, end);
}

void Merge(int arr[], int low, int high, int mid)
{
	int i, j, k, c[50];
	i = low;
	k = low;
	j = mid + 1;
	while (i <= mid && j <= high) {
		if (arr[i] < arr[j]) {
			c[k] = arr[i];
			k++;
			i++;
		}
		else {
			c[k] = arr[j];
			k++;
			j++;
		}
	}
	while (i <= mid) {
		c[k] = arr[i];
		k++;
		i++;
	} 
	while (j <= high) {
		c[k] = arr[j];
		k++;
		j++;
	}
	for (i = low; i < k; i++) {
		arr[i] = c[i];
	}
}

void MergeSort(int arr[], int low, int high) {
	int mid;
	if (low < high) {
		//divide the array at mid and sort independently using merge sort
		mid = (low + high) / 2;
		MergeSort(arr, low, mid);
		MergeSort(arr, mid + 1, high);
		//merge or conquer sorted arrays
		Merge(arr, low, high, mid);
	}
}

void main()
{
	int arr[] = { 5,4,3,2,1,0 };
	for (int i = 0; i < 6; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	BubbleSort(arr, 6);
	for (int i = 0; i < 6; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}