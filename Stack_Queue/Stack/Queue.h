#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

typedef int QDatatype;

typedef struct QueueNode
{
	struct QueueNode* next;
	QDatatype data;
}QNode;

typedef struct Queue
{
	QNode* head;
	QNode* tail;
	int size;
}Queue;


void QueueInit(Queue* pq);
void QueueDestroy(Queue* pq);

void QueuePush(Queue* pq,QDatatype x);
void QueuePop(Queue* pq);

QDatatype QueueSize(Queue* pq);

bool QueueEmpty(Queue* pq);

QDatatype QueueFront(Queue* pq);
QDatatype QueueBack(Queue* pq);




