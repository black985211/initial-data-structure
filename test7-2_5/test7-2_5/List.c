#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"

//创建新节点
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

//判断链表是否为空
bool LTEmpty(LTNode* phead)
{
	return phead->next == phead;//返回true 表示链表为空
}

//设置哨兵位
LTNode* LTInit()
{
	LTNode* phead = BuyListNode(-1);
	phead->prev = phead;
	phead->next = phead;
	return phead;
}


//尾插
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


//尾删
void LTPopBack(LTNode* phead)
{
	assert(phead);
	assert(!LTEmpty(phead));//表示链表若空，没得删除
	LTNode* tail = phead->prev;
	LTNode* tailprev = tail->prev;
	tailprev->next = phead;
	phead->prev = tailprev;
	free(tail);
	tail = NULL;
}

//打印链表
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

//头插
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

//头删
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

//查找
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

//在pos前插入
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

//销毁
void LTDestroy(LTNode* phead)
{
	assert(phead);
	// 遍历释放所有“有效节点”
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		LTNode* next = cur->next;
		free(cur);
		cur = next;
	}
	// 最后释放哨兵节点本身
	free(phead);
}