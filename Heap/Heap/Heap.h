#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int HPDataType;

//´ó¶Ñ
typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}Heap;

void HeapInit(Heap* php);

void Heappush(Heap* php,HPDataType x);
HPDataType HeapTop(Heap* php);

void Heappop(Heap* php);

bool HeapEmpty(Heap* php);

int HeapSize(Heap* php);

void HeapDestroy(Heap* php);

void ADjustDown(HPDataType* a, int n, int parent);
void AdjustUp(HPDataType* a, int child);

void swap(HPDataType* p1, HPDataType* p2);

void HeapInitArray(Heap* php, int* a, int n);
