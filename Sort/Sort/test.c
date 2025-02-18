#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"
#include"Stack.h"

void InsertSortTest()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	InsertSort(arr, sz);
	PrintSort(arr, sz);
}

void ShellSortTest()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	PrintSort(arr, sz);
	ShellSort(arr, sz);
	PrintSort(arr, sz);
}

void SelectSortTest()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	PrintSort(arr, sz);
	SelectSort(arr, sz);
	PrintSort(arr, sz);
}

void HeapSortTest()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	PrintSort(arr, sz);
	HeapSort(arr, sz);
	PrintSort(arr, sz);
}

void BubbleSortTest()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	PrintSort(arr, sz);
	BubbleSort(arr, sz);
	PrintSort(arr, sz);
}

void QuickSort1Test()
{
	int arr[] = { 6,1,2,7,9,3,4,5,10,8 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	PrintSort(arr, sz);
	QuickSort(arr, 0,sz-1);
	PrintSort(arr, sz);
}

QuickSortNonRTest()
{
	int arr[] = { 6,1,2,7,9,3,4,5,10,8 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	PrintSort(arr, sz);
	QuickSortNonR(arr, 0, sz - 1);
	PrintSort(arr, sz);
}

MergeSortTest()
{
	int arr[] = { 6,1,2,7,9,3,4,5,10,8 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	PrintSort(arr, sz);
	MergeSort(arr,  sz);
	PrintSort(arr, sz);
}

MergeSortNonRTest()
{
	int arr[] = { 6,1,2,7,9,3,4,5,10,8 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	PrintSort(arr, sz);
	MergeSortNonR(arr, sz);
	PrintSort(arr, sz);
}

CountSortTest()
{
	int arr[] = { 6,1,2,7,9,3,4,5,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	PrintSort(arr, sz);
	CountSort(arr, sz);
	PrintSort(arr, sz);
}
int main()
{
	//InsertSortTest();
	//ShellSortTest();
	//SelectSortTest();
	//HeapSortTest();
	//BubbleSortTest();
	//QuickSort1Test();
	//QuickSortNonRTest();
	//MergeSortTest();
	//MergeSortNonRTest();
	CountSortTest();

	return 0;
}