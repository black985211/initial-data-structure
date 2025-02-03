#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

typedef int SLTDataType;

struct SListNode
{
	SLTDataType Data;
	struct SListNode * next;
};
typedef struct SListNode SLTNode;

void SLTPrint(SLTNode* phead);
void SLTPushBack(SLTNode** pphead, SLTDataType x);
void SLTPushFront(SLTNode** pphead, SLTDataType x);
void SLTPopBack(SLTNode** pphead);
void SLTPopfront(SLTNode** pphead);

SLTNode* SLTFind(SLTNode* phead, SLTDataType x);
void SLTInsert(SLTNode** phead, SLTNode* pos, SLTDataType x);
void SLTErase(SLTNode** phead, SLTNode* pos);
void SLTInsertAfter(SLTNode* pos, SLTDataType x);
void SLTEraseAfter(SLTNode* pos);


