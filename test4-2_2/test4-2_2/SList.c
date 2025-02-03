#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"


// 打印链表
void SLTPrint(SLTNode* phead)
{
	SLTNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->Data);
		cur = cur->next;
	}
	printf("NULL\n");
}
//创建新的节点
SLTNode* BuyNode(SLTDataType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		return NULL;
	}
	newnode->Data = x;
	newnode->next = NULL;
	return  newnode;
}
//尾插
void SLTPushBack(SLTNode** pphead, SLTDataType x)
{
	assert(pphead != NULL);
	SLTNode* NewNode = BuyNode(x);
	if (*pphead == NULL)
	{
		*pphead = NewNode;
		return;
	}
	SLTNode* cur = *pphead;
	while (cur->next != NULL)
	{
		cur = cur->next;
	}
	cur->next = NewNode;
}

//头插
void SLTPushFront(SLTNode** pphead, SLTDataType x)
{
	assert(pphead != NULL);
	SLTNode* NewNode = BuyNode(x);
	NewNode->next = *pphead;
	*pphead = NewNode;

}

//尾删
void SLTPopBack(SLTNode** pphead)
{
	assert(*pphead && pphead);
	/*if (*pphead == NULL)
	{
		return;

	}*/
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
		return;
	}
	SLTNode* cur = *pphead;
	while (cur->next->next != NULL)
	{
		cur = cur->next;
	}
	free(cur->next);
	cur->next = NULL;

}

//头删
void SLTPopfront(SLTNode** pphead)
{
	assert(pphead);
	if (*pphead == NULL)
	{
		return;

	}
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
		return;
	}
	SLTNode* first = *pphead;
	*pphead = first->next;
	free(first);
	first = NULL;
}

//查找
SLTNode* SLTFind(SLTNode* phead, SLTDataType x)
{
	SLTNode* cur = phead;
	while (cur)
	{
		if (cur->Data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

//pos位置前插入
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	assert(pos&&pphead);
	if (pos == *pphead)
	{
		SLTPushFront(pphead, x);
		return;
	}
	SLTNode* cur = *pphead;
	while (cur->next !=pos)
	{
		cur = cur->next;
	}
	SLTNode* newnode = BuyNode(x);
	newnode->next = pos;
	cur->next = newnode;

}

//pos位置前删除
void SLTErase(SLTNode** pphead, SLTNode* pos)
{
	assert(pos && pphead);
	if (pos == *pphead)
	{
		SLTPopfront(pphead);
		return;
	}
	SLTNode* cur = *pphead;
	while (cur->next != pos)
	{
		cur = cur->next;
	}
	cur->next = pos->next;
	free(pos);
}
//pos后面位置插入
void SLTInsertAfter(SLTNode* pos, SLTDataType x)
{
	assert(pos);
	SLTNode* newnode = BuyNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

//pos后面位置删除
void SLTEraseAfter(SLTNode* pos)
{
	assert(pos);
	assert(pos->next);
	SLTNode* Del = pos->next;
	pos->next = Del->next;
	free(Del);
}
