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

    printf("���Զ��г�ʼ�����\n");
    printf("�����Ƿ�Ϊ�գ�1-�ǣ�0-�񣩣�%d\n", QueueEmpty(&q));
    printf("���д�С��%zu\n", QueueSize(&q));

    printf("\n===== ��ʼ��� =====\n");
    QueuePush(&q, 10);
    QueuePush(&q, 20);
    QueuePush(&q, 30);
    QueuePush(&q, 40);

    printf("������\n");
    printf("�����Ƿ�Ϊ�գ�1-�ǣ�0-�񣩣�%d\n", QueueEmpty(&q));
    printf("���д�С��%zu\n", QueueSize(&q));
    printf("��ͷԪ�أ�%d\n", QueueFront(&q));
    printf("��βԪ�أ�%d\n", QueueBack(&q));

    printf("\n===== ��ʼ���� =====\n");
    while (!QueueEmpty(&q))
    {
        printf("��ǰ��ͷԪ�أ�%d\n", QueueFront(&q));
        QueuePop(&q);
        printf("���д�С��%zu\n", QueueSize(&q));
    }

    printf("���������\n");
    printf("�����Ƿ�Ϊ�գ�1-�ǣ�0-�񣩣�%d\n", QueueEmpty(&q));

    printf("\n===== ������Ӳ����ٲ��� =====\n");
    QueuePush(&q, 100);
    QueuePush(&q, 200);
    QueuePush(&q, 300);
    printf("���������ɣ����д�С��%zu\n", QueueSize(&q));

    QueueDestroy(&q);
    printf("�����������\n");
    printf("�����Ƿ�Ϊ�գ�1-�ǣ�0-�񣩣�%d\n", QueueEmpty(&q));

    printf("���Խ���\n");
}

int main()
{
    TestQueue();
    return 0;
}