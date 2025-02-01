#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

#define INIT_CAPACITY 4


typedef int SLDataType;

//动态顺序表--按需申请
typedef struct Seqlist
{
	SLDataType *a;
	int capacity;
	int size;
}SL;

void SLInit(SL *ps);
void SLDestroy(SL* ps);
void SLPrint(SL* ps);
void SLCheckCapacity(SL* ps);
void SLPushBack(SL* ps, SLDataType x);
void SLPopBack(SL* ps);
void SLPushFront(SL* ps, SLDataType x);
void SLPopFront(SL* ps);
void SLInsert(SL* ps, int pos,SLDataType x);
void SLErase(SL* ps, int pos);





