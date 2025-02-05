#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include<stdbool.h>


typedef int LTDataType;

typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;
	LTDataType data;
}LTNode;

LTNode* LTInit();
bool LTEmpty(LTNode* phead);
void LTPushBack(LTNode*phead,LTDataType x);
void LTPopBack(LTNode* phead);
void LTPushFront(LTNode* phead, LTDataType x);
void LTPopFront(LTNode* phead);
LTNode* LTFind(LTNode* phead, LTDataType x);
void LTInsert(LTNode* pos, LTDataType x);
void LTPrint(LTNode* phead);
void LTDestroy(LTNode* phead);
