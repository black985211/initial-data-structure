#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"


// ��ӡ����
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
//�����µĽڵ�
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
//β��
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

//ͷ��
void SLTPushFront(SLTNode** pphead, SLTDataType x)
{
	assert(pphead != NULL);
	SLTNode* NewNode = BuyNode(x);
	NewNode->next = *pphead;
	*pphead = NewNode;

}

//βɾ
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

//ͷɾ
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

//����
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

//posλ��ǰ����
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

//posλ��ǰɾ��
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
//pos����λ�ò���
void SLTInsertAfter(SLTNode* pos, SLTDataType x)
{
	assert(pos);
	SLTNode* newnode = BuyNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

//pos����λ��ɾ��
void SLTEraseAfter(SLTNode* pos)
{
	assert(pos);
	assert(pos->next);
	SLTNode* Del = pos->next;
	pos->next = Del->next;
	free(Del);
}
