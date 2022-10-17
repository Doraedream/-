#define _CRT_SECURE_NO_WARNINGS 1
#include"ListNode.h"

int main()
{
	ListNode* head = ListCreate();
	ListPushBack(head, 1);
	ListPushBack(head, 2);
	ListPushBack(head, 3);
	ListPushBack(head, 4);
	ListPushBack(head, 5);
	ListPrint(head);
    ListPopBack(head);
	ListPopBack(head);
	ListPrint(head);
	ListPushFront(head, 1);
	// Ë«ÏòÁ´±íÍ·É¾
	ListPrint(head);

	return 0;
}