#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"
TestList1()
{
	LTNode* plist = LTInit();
	LTPushBack(plist, 1);
	LTPushBack(plist, 2);
	LTPushBack(plist, 3);
	LTPushBack(plist, 4);
	LTPushBack(plist, 5);
	LTPopBack(plist);
	LTPopBack(plist);//1 2 3
	LTPushFront(plist, 0);//0 1 2 3
	LTPushFront(plist, -1);//-1 0 1 2 3
	LTPopFront(plist);//0 1 2 3
	LTNode* ret = LTFind(plist,2);
	LTInsert(ret, 7);//0 1 
	LTPrint(plist);

}
int main()
{
	TestList1();
	return 0;
}