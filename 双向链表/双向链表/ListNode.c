#define _CRT_SECURE_NO_WARNINGS 1
#include"ListNode.h"

ListNode* BuyListNode(LTDataType x)
{
	ListNode* new = (ListNode*)malloc(sizeof(ListNode));
	new->_data = x;
	new->_next = new->_prev = NULL;
	return new;
}

ListNode* ListCreate()
{
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	head->_next = head;
	head->_prev = head;
	return head;
}

void ListDestroy(ListNode* pHead)
{
	assert(pHead);
	ListNode* cur = pHead->_next;
	while (cur !=pHead)
	{
		ListNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	free(pHead);
}

void ListPrint(ListNode* pHead)
{
	assert(pHead);
	ListNode* cur = pHead->_next;
	while (cur != pHead)
	{
		printf("%d<=>", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}

void ListInsert(ListNode* pos, LTDataType x) 
{
	assert(pos);
	ListNode* Node = BuyListNode(x);
	ListNode* tail = pos->_prev;
	tail->_next = Node;
	Node->_prev = tail;
	Node->_next = pos;
	pos->_prev = Node;
}

void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* prev = pos->_prev;
	prev->_next = pos->_next;
	pos->_next->_prev = prev;
	free(pos);
	pos = NULL;
}

void ListPushBack(ListNode* pHead, LTDataType x)
{
	ListNode* cur = BuyListNode(x);
	cur->_next = pHead;
	cur->_prev = pHead->_prev;
	pHead->_prev->_next = cur;
	pHead->_prev = cur;
}

void ListPopBack(ListNode* pHead)
{
	assert(pHead);

	ListErase(pHead->_prev);
}

void ListPushFront(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListInsert(pHead->_next, x);
}

void ListPopFront(ListNode* pHead)
{
	assert(pHead);
	ListErase(pHead->_next);
}

ListNode* ListFind(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* cur = pHead->_next;
	while (cur != pHead)
	{
		if (cur->_data = x)
		{
			return cur;
		}
		else {
			cur = cur->_next;
		}
	}
	return NULL;
}