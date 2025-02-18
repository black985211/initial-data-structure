#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"
#include"Stack.h"


//打印排序后的数组
void PrintSort(int* a, int n)
{
	for (int i = 0;i < n;i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

//升序

//插入排序
void InsertSort(int* a, int n)
{
	for(int i  = 1;i<n;i++)
	{
		int end=i-1;
		int tmp=a[end+1];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
			a[end + 1] = tmp;
		}
	}
	
}

//希尔排序
void ShellSort(int* a, int n)
{
	int gap = n;
	/*for (int j = 0;j < gap;j++)
	{
		for (int i = j;i < n - gap;i += gap)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
				a[end + gap] = tmp;
			}
		}
	}*/

	while (gap > 1)
	{
		gap /= 2;
		for (int i = 0;i < n - gap;i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
				a[end + gap] = tmp;
			}
		}
	}
}

//选择排序
void Swap(int * p1, int * p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void SelectSort(int* a, int n)
{
	int left = 0;
	int right = n - 1;
	
	while (left < right)
	{
		int mini = left;
		int maxi = left;
		for (int i = left + 1;i <= right;i++)
		{
			if (a[i] < a[mini])
			{
				mini = i;
			}
			if (a[i] > a[maxi])
			{
				maxi = i;
			}
		}
		Swap(&a[left], &a[mini]);
		if (left == maxi)
		{
			maxi = mini;
		}
		Swap(&a[left], &a[maxi]);
		++left;
		--right;

	}
}

//堆排序
typedef int HPDataType;
void AdjustUp(HPDataType* a, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
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

void ADjustDown(HPDataType* a, int n, int parent)
{
	int child = 2 * parent + 1; //n-1
	while (child < n)
	{

		if (child + 1 < n && a[child] < a[child + 1])
		{
			child++;
		}
		if (a[parent] < a[child])
		{
			Swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;

		}
		else
		{
			break;
		}


	}
}

void HeapSort(int* a, int n)
{
	////向上调整建堆 时间复杂度O(n*logn)
	//for (int i = 0;i < n;i++)
	//{
	//    AdjustUp(a, i);
	//}

	//向下调整建堆 时间复杂度O(logn)
	for (int i = (n - 1 - 1) / 2;i >= 0;i--)
	{
		ADjustDown(a, n, i);
	}

	
	while (n > 1)
	{
		Swap(&a[0], &a[n - 1]);
		n--;
		ADjustDown(a, n, 0);
	}

}

//冒泡排序
void BubbleSort(int* a, int n)  
{
	for (int j = 0;j < n-1 ;j++)
	{
		for (int i = 1;i < n - j;i++)
		{
			if (a[i - 1] > a[i])
			{
				Swap(&a[i - 1], &a[i]);
			}
		}

	}
}

//快速排序
int GetMidNumi(int a[], int left, int right)
{
	int mid = (left + right) / 2; 
	if (a[left] < a[mid]) 
	{
		if (a[mid] < a[right])
		{
			return mid;
		}
		else if (a[left] > a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
	else
	{
		if (a[mid] > a[right])
		{
			return mid;
		}
		else if (a[left] < a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
}

//hoare法
int PartSort_Hoare(int a[], int left, int right)
{
	////随机选key
	//int randomIndex = left + rand() % (right - left + 1);
	//Swap(&a[left], &a[randomIndex]);

	////中间值为key
	//int midi = GetMidNumi(a, left, right);
	//Swap(&a[left], &a[midi]);

	int key = left;
	while (left < right)
	{
		while (left < right && a[right] >= a[key])
		{
			right--;
		}
		while (left < right && a[left] <= a[key])
		{
			left++;
		}
		Swap(&a[left], &a[right]);
	}
	Swap(&a[key], &a[right]);
	key = left;
	return key;
}

//用挖坑法
int PartSort_Hole(int a[], int left, int right)
{
	////随机选key
	//int randomIndex = left + rand() % (right - left + 1);
	//Swap(&a[left], &a[randomIndex]);

	////中间值为key
	//int midi = GetMidNumi(a, left, right);
	//Swap(&a[left], &a[midi]);

	int key = a[left];
	int hole = left;
	while (left < right)
	{
		while (left < right && a[right] >= key)
		{
			right--;
		}
		a[hole] = a[right];
		hole = right;
		while (left < right && a[left] <= key)
		{
			left++;
		}
		a[hole] = a[left];
		hole = left;
	}
	a[hole] = key;
	return hole;
}

////前后指针版本快排
int PartSort_TwoPointers(int a[], int left, int right)
{
	int key = left;
	int prev, cur;
	prev = left;
	cur = left + 1;
	while (cur <= right )
	{
		if (a[cur] < a[key]&&++prev!=cur)
		{
			Swap(&a[cur], &a[prev]);
		}
		cur++;
	}

	Swap(&a[key], &a[prev]);
	key = prev;
	return key;
}
void QuickSort(int a[], int left, int right)
{
	
	if (left >= right) {
		return;  
	}

	////用hoare法快排
	//int key_hoare = PartSort_Hoare(a, left, right);
	//QuickSort(a, left, key_hoare - 1);
	//QuickSort(a, key_hoare + 1, right);
	
	////用挖坑法快排
	//int key_hole = PartSort_Hole(a, left, right);
	//QuickSort(a, left, key_hole - 1);
	//QuickSort(a, key_hole + 1, right);

	//前后指针版本快排
	/*int key_TwoPointers = PartSort_TwoPointers(a, left, right);
	QuickSort(a, left, key_TwoPointers- 1);
	QuickSort(a, key_TwoPointers+ 1, right);*/

	//小区间优化--小区间直接使用插入排序
	if ((right - left + 1) > 10)
	{
		int key = PartSort_TwoPointers(a, left, right);
		QuickSort(a, left, key - 1);
		QuickSort(a, key +1,right );

	}
	else
	{
		InsertSort(a + left, right - left + 1);
	}
}

//非递归进行快排
void QuickSortNonR(int a[], int left, int right)
{
	ST s;
	STInit(&s);
	STPush(&s, right);
	STPush(&s, left);
	while (!STEmpty(&s))
	{
		int begin = STTop(&s);
		STPop(&s);
		int end = STTop(&s);
		STPop(&s);
		int keyi = PartSort_TwoPointers(a, begin, end);
		if (keyi+1 < end)
		{
			STPush(&s, end);
			STPush(&s, keyi + 1);
		}
		if (begin < keyi-1)
		{
			STPush(&s, keyi - 1);
			STPush(&s, begin);
		}

	}
	STDestroy(&s);
}

//归并排序
#include<string.h>
void _MergeSort(int* a, int begin, int end, int* tmp)
{
	if (begin == end) 
	{
		return;
	}
	int mid = (begin + end) / 2;
	_MergeSort(a, begin, mid, tmp);
	_MergeSort(a, mid + 1, end, tmp);

	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;
	int i = begin;

	// 合并两个有序子数组
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[i++] = a[begin1++];
		}
		else
		{
			tmp[i++] = a[begin2++];
		}
	}

	// 处理剩余元素
	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}

	// 将临时数组的内容复制回原数组
	memcpy(a + begin, tmp + begin, sizeof(int) * (end - begin + 1)); // 修复：长度计算错误
}

void MergeSort(int* a, int n)
{

	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc fail");
		return;
	}

	_MergeSort(a, 0, n - 1, tmp);

	free(tmp);
	tmp = NULL; 
}

//归并排序非递归
void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc fail");
		return;
	}

	int gap = 1;
	while (gap < n)
	{
		for (int i = 0;i < n;i += 2 * gap)
		{
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;
			int j = i;
			if (end1 >= n )
			{
				end1 = n - 1;
				begin2 = n;
				end2 = n - 1;
			}
			else if (begin2 >= n)
			{
				begin2 = n;
				end2 = n - 1;
			}
			else if (end2 >= n)
			{
				end2 = n - 1;
			}
			// 合并两个有序子数组
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
				{
					tmp[j++] = a[begin1++];
				}
				else
				{
					tmp[j++] = a[begin2++];
				}
			}

			// 处理剩余元素
			while (begin1 <= end1)
			{
				tmp[j++] = a[begin1++];
			}
			while (begin2 <= end2)
			{
				tmp[j++] = a[begin2++];
			}
			memcpy(a + i, tmp + i, sizeof(int) * (end2 - i + 1));

		}

		gap *= 2;
	}
	
	
	free(tmp);
	tmp = NULL;
}

//计数排序
void CountSort(int* a, int n)   
{
	int max = a[0];
	int min = a[0];
	for (int i = 1;i < n;i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
		if (a[i] < min)
		{
			min = a[i];
		}
	}
	int range = max - min + 1;
	int* count = (int*)malloc(sizeof(int) * range);
	if (count == NULL)
	{
		perror("malloc fail");
		return;
	}
	memset(count, 0, sizeof(int) * range);
	//计数
	for (int i = 0;i < n;i++)
	{
		count[a[i] - min]++;
	}
	//排序
	int j = 0;
	for (int i = 0;i < range;i++)
	{
		while (count[i]--)
		{
			a[j++] = min + i;
		}
	}
	free(count);
	count = NULL;
}





