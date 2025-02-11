#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"

void HeapInit(Heap* php)
{	
	assert(php);
	php->a = (HPDataType*)malloc(sizeof(HPDataType) * 4);
	if (php->a == NULL)
	{
		perror("malloc fail");
		return;
	}
	php->size = 0;
	php->capacity = 4;
}

void HeapInitArray(Heap* php, int* a, int n)
{
	assert(php);
	php->a = a;
	php->size = n;
	php->capacity = n;
	for (int i = (n - 2) / 2;i >= 0;i--)
	{
		ADjustDown(php->a, php->size, i);
	}
}

void swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
void AdjustUp(HPDataType* a, int child)
{
	int parent = (child - 1) / 2;
	while (child>0)
	{
		if (a[child] > a[parent])
		{
			swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
	/*while (child>0 && a[child] > a[parent])
	{
		swap(&a[child], &a[parent]);
		child = parent;
		parent = (child - 1) / 2;
	}*/
}
void Heappush(Heap* php, HPDataType x)
{
	assert(php);
	if (php->size == php->capacity)
	{
		HPDataType* ptr = (HPDataType*)realloc(php->a, sizeof(HPDataType) * php->capacity * 2);
		if (ptr == NULL)
		{
			perror("realloc fail");
			return;
		}
		php->a = ptr;
		php->capacity *= 2;
	}
	php->a[php->size] = x;
	php->size++;
	AdjustUp(php->a, php->size - 1);
}

void ADjustDown(HPDataType* a, int n, int parent)//{ 2,1,4,6,2,6,8,3,5 }; parent = (n-2)/2
{
	int child = 2 * parent + 1; //n-1
	while (child < n)
	{
		
		if (child+1<n && a[child] < a[child + 1])
		{
			child++;
		}
		if (a[parent] < a[child])
		{
			swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;

		}
		else
		{
			break;
		}
		
		
	}
}
void Heappop(Heap* php)
{
	assert(php);
	assert(!HeapEmpty(php));
	swap(&php->a[php->size - 1], &php->a[0]);
	php->size--;
	ADjustDown(php->a, php->size, 0);
	
}

HPDataType HeapTop(Heap* php)
{
	assert(php);
	assert(!HeapEmpty(php));
	return php->a[0];
}
bool HeapEmpty(Heap* php)
{
	assert(php);
	return php->size == 0;
}
int HeapSize(Heap* php)
{
	assert(php);
	return php->size;
}

void HeapDestroy(Heap* php)
{
	assert(php);

	if (php->a != NULL)
	{
		free(php->a);  // 释放动态分配的数组
		php->a = NULL; // 避免野指针
	}

	php->size = 0;
	php->capacity = 0; 

}





