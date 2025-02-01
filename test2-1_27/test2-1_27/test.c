#define _CRT_SECURE_NO_WARNINGS 1
#include"seqlist.h"
#include<assert.h>
void TestSeqlist1()
{
	SL s;
	SLInit(&s);
	SLPushBack(&s, 1);
	SLPushBack(&s, 2);
	SLPushBack(&s, 3);
	SLPushBack(&s, 4);
	SLPushBack(&s, 5);
	SLPrint(&s);
	SLPopBack(&s);
	SLPopBack(&s);


	SLPushBack(&s, 5);

	SLPrint(&s);




}
TestSeqlist2()
{
	SL s;
	SLInit(&s);
	SLPushFront(&s,1);
	SLPushFront(&s, 2);
	SLPushFront(&s, 3);
	SLPushFront(&s, 4);
	SLPushFront(&s, 5);
	SLPrint(&s);
	/*SLPopFront(&s);
	SLPopFront(&s);
	SLPopFront(&s);
	SLPopFront(&s);
	SLPrint(&s);*/

}
TestSeqlist3()
{
	SL s;
	SLInit(&s);
	SLPushBack(&s, 1);
	SLPushBack(&s, 2);
	SLPushBack(&s, 3);
	SLPushBack(&s, 4);
	SLPushBack(&s, 5);
	SLInsert(&s, 1, 6);
	SLPrint(&s);
	SLErase(&s, 3);
	SLPrint(&s);


}


int main()
{
	//TestSeqlist1();
	//TestSeqlist2();
	TestSeqlist3();


	return 0;
}