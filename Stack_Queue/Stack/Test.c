#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"
#include"Queue.h"

//int main()
//{
//	ST st;
//	STInit(&st);
//	STPush(&st, 1);
//	STPop(&st);
//	STPush(&st, 2);
//	STPush(&st, 3);
//	STPush(&st, 4);
//	STPush(&st, 5);
//	STPush(&st, 6);
//	while (!STEmpty(&st))
//	{
//		printf("%d ", STTop(&st));
//		STPop(&st);
//	}
//	STDestroy(&st);
//
//	return 0;
//}


void TestQueue()
{
    Queue q;
    QueueInit(&q);

    printf("测试队列初始化完成\n");
    printf("队列是否为空（1-是，0-否）：%d\n", QueueEmpty(&q));
    printf("队列大小：%zu\n", QueueSize(&q));

    printf("\n===== 开始入队 =====\n");
    QueuePush(&q, 10);
    QueuePush(&q, 20);
    QueuePush(&q, 30);
    QueuePush(&q, 40);

    printf("入队完成\n");
    printf("队列是否为空（1-是，0-否）：%d\n", QueueEmpty(&q));
    printf("队列大小：%zu\n", QueueSize(&q));
    printf("队头元素：%d\n", QueueFront(&q));
    printf("队尾元素：%d\n", QueueBack(&q));

    printf("\n===== 开始出队 =====\n");
    while (!QueueEmpty(&q))
    {
        printf("当前队头元素：%d\n", QueueFront(&q));
        QueuePop(&q);
        printf("队列大小：%zu\n", QueueSize(&q));
    }

    printf("队列已清空\n");
    printf("队列是否为空（1-是，0-否）：%d\n", QueueEmpty(&q));

    printf("\n===== 重新入队并销毁测试 =====\n");
    QueuePush(&q, 100);
    QueuePush(&q, 200);
    QueuePush(&q, 300);
    printf("重新入队完成，队列大小：%zu\n", QueueSize(&q));

    QueueDestroy(&q);
    printf("队列销毁完成\n");
    printf("队列是否为空（1-是，0-否）：%d\n", QueueEmpty(&q));

    printf("测试结束\n");
}

int main()
{
    TestQueue();
    return 0;
}