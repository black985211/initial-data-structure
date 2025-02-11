#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"

void test1()
{
    Heap hp;
    HeapInit(&hp);

    printf("测试：插入元素到堆\n");
    Heappush(&hp, 10);
    Heappush(&hp, 20);
    Heappush(&hp, 15);
    Heappush(&hp, 30);
    Heappush(&hp, 25);

    printf("当前堆大小: %d\n", HeapSize(&hp));
    printf("当前堆顶: %d\n", HeapTop(&hp));

    assert(HeapTop(&hp) == 30);  // 30 是最大值，应在堆顶

    printf("测试：删除堆顶元素\n");
    Heappop(&hp); // 移除 30
    printf("新堆顶: %d\n", HeapTop(&hp));
    assert(HeapTop(&hp) == 25);  // 25 应成为新的堆顶

    Heappop(&hp); // 移除 25
    printf("新堆顶: %d\n", HeapTop(&hp));
    assert(HeapTop(&hp) == 20);  // 20 应成为新的堆顶

    printf("测试：删除所有元素\n");
    while (!HeapEmpty(&hp))
    {
        printf("弹出元素: %d\n", HeapTop(&hp));
        Heappop(&hp);
    }

    printf("测试：检查空堆\n");
    assert(HeapEmpty(&hp));
    printf("堆为空: %s\n", HeapEmpty(&hp) ? "true" : "false");

    HeapDestroy(&hp);
    printf("所有测试通过！\n");
}



void HeapSort(int* a, int n)
{
    ////向上调整建堆 时间复杂度O(n*logn)
    //for (int i = 0;i < n;i++)
    //{
    //    AdjustUp(a, i);
    //}
    
    //向下调整建堆 时间复杂度O(logn)
    for (int i = (n - 1-1) / 2;i >= 0;i--)// i是最后一个父亲节点，n-1是最后一个叶子节点  parent = (child-1)/2   i = (n-1-1)/2
    {
        ADjustDown(a, n, i);
    }
   
    //8 5 6 4 2 2 6 1 3  
    //建大堆排升序
    while (n>1)
    {
        swap(&a[0], &a[n - 1]);
        n--;
        ADjustDown(a, n, 0);
    }
    
}

void test2()
{
    int a[] = { 2,1,4,6,2,6,8,3,5 };
    int sz = sizeof(a) / sizeof(a[0]);
    HeapSort(a, sz);
    for (int i = 0;i < sz;i++)
    {
        printf("%d ", a[i]);
    }
}
void test3()
{
    Heap hp;
    int arr[] = { 2,33,7,4,2,8,4,5 };
    int sz = sizeof(arr) / sizeof(arr[0]);
    HeapInitArray(&hp, arr, sz);
    for (int i = 0;i < sz;i++)
    {
        printf("%d ", hp.a[i]);
    }
    printf("\n");
    while (!HeapEmpty(&hp))
    {
        printf("弹出元素: %d\n", HeapTop(&hp));
        Heappop(&hp);
    }
}

int main()
{
	//test1();
    //test2();
    //test3();
   
	return 0;
}