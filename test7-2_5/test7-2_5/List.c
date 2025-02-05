#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"

//�����½ڵ�
LTNode* BuyListNode(x)
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		return NULL;
	}
	newnode->next = NULL;
	newnode->prev = NULL;
	newnode->data = x;
	return newnode;
}

//�ж������Ƿ�Ϊ��
bool LTEmpty(LTNode* phead)
{
	return phead->next == phead;//����true ��ʾ����Ϊ��
}

//�����ڱ�λ
LTNode* LTInit()
{
	LTNode* phead = BuyListNode(-1);
	phead->prev = phead;
	phead->next = phead;
	return phead;
}


//β��
void LTPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);
	/*LTNode* newnode = BuyListNode(x);
	LTNode* tail = phead->prev;
	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;*/
	LTInsert(phead, x);

}


//βɾ
void LTPopBack(LTNode* phead)
{
	assert(phead);
	assert(!LTEmpty(phead));//��ʾ�������գ�û��ɾ��
	LTNode* tail = phead->prev;
	LTNode* tailprev = tail->prev;
	tailprev->next = phead;
	phead->prev = tailprev;
	free(tail);
	tail = NULL;
}

//��ӡ����
void LTPrint(LTNode* phead)
{
	assert(phead);
	LTNode* cur = phead->next;
	printf("-head->");
	while (cur != phead)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
}

//ͷ��
void LTPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);
	/*LTNode* newnode = BuyListNode(x);
	LTNode* start = phead->next;
	phead->next = newnode;
	newnode->prev = phead;
	newnode->next = start;
	start->prev = newnode;*/
	LTInsert(phead->next,x);
}

//ͷɾ
void LTPopFront(LTNode* phead)
{
	assert(phead);
	assert(!LTEmpty(phead));
	LTNode*front= phead->next;
	phead->next = front->next;
	front->next->prev = phead;
	free(front);
	front = NULL;
}

//����
LTNode* LTFind(LTNode* phead, LTDataType x)
{
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data ==x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

//��posǰ����
void LTInsert(LTNode* pos, LTDataType x)
{
	assert(pos);
	LTNode* prev = pos->prev;
	LTNode* newnode = BuyListNode(x);
	prev->next = newnode;
	newnode->next = pos;
	newnode->prev = prev;
	pos->prev = newnode;
}

//����
void LTDestroy(LTNode* phead)
{
	assert(phead);
	// �����ͷ����С���Ч�ڵ㡱
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		LTNode* next = cur->next;
		free(cur);
		cur = next;
	}
	// ����ͷ��ڱ��ڵ㱾��
	free(phead);
}