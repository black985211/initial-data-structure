#define _CRT_SECURE_NO_WARNINGS 1
#include"seqlist.h"


void SLInit(SL *ps)
{
	assert(ps);

	ps->a = (SLDataType*)malloc(INIT_CAPACITY * sizeof(SLDataType));
	if (ps->a == NULL)
	{
		perror("malloc fail");
		return;

	}
	ps->capacity = INIT_CAPACITY;
	ps->size = 0;
}
void SLDestroy(SL* ps)
{
	assert(ps);

	free(ps->a);
	ps->a = NULL;
	ps->capacity = 0;
	ps->size = 0;
}

void SLPrint(SL* ps)
{
	assert(ps);

	for (int i = 0;i < ps->size;i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}
void SLCheckCapacity(SL* ps)
{
	assert(ps);
	if (ps->size == ps->capacity)
	{
		SLDataType* ptr = (SLDataType*)realloc(ps->a, 2 * ps->capacity * sizeof(SLDataType));
		if (ptr == NULL)
		{
			perror("realloc fail");
			return;
		}
		ps->a = ptr;
		ps->capacity *= 2;

	}
}


void SLPushBack(SL* ps, SLDataType x)
{
	assert(ps);

	SLInsert(ps, ps->size, x);
}
void SLPopBack(SL* ps)
{
	assert(ps);

	assert(ps->size > 0);
	//if (ps->capacity == 0)
	//{
	//	
	//	return 0;
	//}
	ps->size--;
}

void SLPushFront(SL* ps, SLDataType x)
{
	assert(ps);
	SLCheckCapacity(ps);
	//int end = ps->size-1;
	//while (end>=0)
	//{
	//	ps->a[end + 1] = ps->a[end];
	//	end--;
	//}
	//ps->a[0] = x;
	//ps->size++;
	SLInsert(ps, 0, x);
}
void SLPopFront(SL* ps)
{
	assert(ps);
	assert(ps->size > 0);
	int begin = 1;
	while(begin < ps->size)
	{
		ps->a[begin - 1] = ps->a[begin];
		begin++;
	}
	ps->size--;

}
void SLInsert(SL* ps, int pos, SLDataType x)// 0 0  1 1
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);//size=1
	SLCheckCapacity(ps);
	int end = ps->size - 1;//end = 0
	while (end>=pos)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[pos] = x;
	ps->size++;
}
void SLErase(SL* ps, int pos)
{
	assert(ps);
	assert(pos >= 0 && pos < ps->size);
	int begin = pos;
	while (begin + 1 < ps->size)
	{
		ps->a[begin] = ps->a[begin + 1];
		begin++;
	}
	ps->size--;
}







