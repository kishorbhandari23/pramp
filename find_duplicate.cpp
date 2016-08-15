// pramp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

void find_duplicate1(int*arr1, int size_arr1, int* arr2, int size_arr2, int* array_duplicate, int size_duplicate)
{
	int index1 = 0, index2 = 0, index = 0;
	while ((index1 < size_arr1) && (index2 < size_arr2))
	{
		if (arr1[index1] == arr2[index2])
		{
			array_duplicate[index] = arr1[index1];
			index++;
			index1++;
			index2++;
		}
		else if (arr1[index1] < arr2[index2])
			index1++;
		else
			index2++;
	}
}

int binary_search(int arr[], int size,int key)
{
	int begin = 0;
	int end = size - 1;
	int mid;
	while (begin <= end)
	{
		mid = (begin + end) / 2;
		if  (key>arr[mid])
		{
			begin = mid + 1;
		}
		else if (key < arr[mid])
		{
			end = mid - 1;
		}
		else
		{
			return mid;
		}
		return -1;

	}
}

void find_duplicate2(int*arr1, int size_arr1, int* arr2, int size_arr2, int* array_duplicate, int size_duplicate)
{
	int index = 0;
	//assuming the array1 is very big and array2 is small
	for(int i=0;i<size_arr2;i++)
		if (binary_search(arr1, size_arr1, arr2[i]))
		{
			array_duplicate[index++] = arr2[i];
		}
}


void print_array(int arr[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << arr[i] << " ";
		//printf("%d  ", arr[i]);
	}

}


int main()
{
	int arr1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int arr2[] = { 1,2,3,4,5 };

	int size_arr1 = sizeof(arr1) / sizeof(arr1[0]);
	int size_arr2 = sizeof(arr2) / sizeof(arr2[0]);

	int size_duplicate = (size_arr1 < size_arr2) ? size_arr1 : size_arr2;
	int* array_duplicate = new int[size_duplicate];

	find_duplicate1(arr1, size_arr1, arr2, size_arr2, array_duplicate, size_duplicate);
	print_array(array_duplicate, size_duplicate);

	find_duplicate2(arr1, size_arr1, arr2, size_arr2, array_duplicate, size_duplicate);
	print_array(array_duplicate, size_duplicate);


	
	return 0;
}

