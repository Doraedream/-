#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"

int main()
{
	SListNode* n1=NULL;
	SListPushFront(&n1, 1);
	SListPushBack(&n1,1);
	SListPushBack(&n1, 2);
	SListPushBack(&n1, 3);
	
	
	SListPushFront(&n1, 1);
	SListPushFront(&n1, 2);
	SListPushFront(&n1, 3);
	SListPrint(n1);
	SListEraseAfter(n1);
	SListEraseAfter(n1);
	SListPrint(n1);
	SListDestroy(n1);
	SListPrint(n1);
	
	
	return 0;
	
}







	