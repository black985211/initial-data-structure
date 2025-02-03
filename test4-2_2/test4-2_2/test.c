#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"
void test1()
{
	SLTNode* plist = NULL;
	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPushBack(&plist, 4);
	SLTPushBack(&plist, 5);
	SLTPushFront(&plist, 0);
	SLTPushFront(&plist, -1);//-1 0 1 2 3 4 5
	SLTPopBack(&plist);
	SLTPopBack(&plist);
	SLTPopBack(&plist);//-1 0 1 2
	/*SLTPopBack(&plist);
	SLTPopBack(&plist);
	SLTPopBack(&plist);
	SLTPopBack(&plist);*/
	SLTPopfront(&plist);//0 1 2
	SLTNode *ret = SLTFind(plist, 2);
	ret->Data *= 2;//0 1 4
	SLTNode* NewRet1 = SLTFind(plist, 4);
	SLTInsert(&plist, NewRet1, 3);//0 1 3 4

	SLTNode* NewRet2 = SLTFind(plist, 3);
	SLTErase(&plist, NewRet2);
	NewRet2 = NULL;//0 1 4
	SLTPrint(plist);

}
int main()
{
	test1();
	return 0;
}





