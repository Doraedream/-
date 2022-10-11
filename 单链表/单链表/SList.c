#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"

SListNode* BuySListNode(SLTDateType x)
{
	SListNode* p = (SListNode*)malloc(sizeof(SListNode));
	p->data = x;
	p->next = NULL;
	return p;
}

void SListPrint(SListNode* plist)
{
	SListNode* cur = plist;
	while (cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

void SListPushBack(SListNode** pplist, SLTDateType x)
{
	SListNode* ps = BuySListNode(x);
	if (*pplist == NULL)
	{
		*pplist = ps;
	}
	else
	{
		SListNode* tail = *pplist;
		while (tail->next!=NULL)
		{
			tail = tail->next;
		} 
		tail->next = ps;
	}
}

void SListPushFront(SListNode** pplist, SLTDateType x)
{

	assert(pplist);
	SListNode* newnode = BuySListNode(x);
	if (*pplist == NULL)
	{
		*pplist = newnode;
	}
	else
	{
		newnode->next = *pplist;
		*pplist = newnode;
	}
	
}

void SListPopBack(SListNode** pplist)
{
	SListNode* prev = NULL, * tail = *pplist;
	if ((tail == NULL) || (tail->next == NULL))
	{
		free(tail);
		tail = NULL;
		*pplist = NULL;
	}
	else {
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		tail = NULL;
		prev->next = NULL;
	}
}

void SListPopFront(SListNode** pplist)
{
	SListNode* ps = *pplist;
	if (ps == NULL)
	{
		return;
	 }
	else {
		*pplist = ps->next;
		free(ps);
		ps = NULL;

	}

}

SListNode* SListFind(SListNode* plist, SLTDateType x)
{
	SListNode* ps = plist;
	while (ps)
	{
		if (ps->data == x)
			return ps;

		ps = ps->next;
	}
	return NULL;
}

void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	assert(pos);
	SListNode* next = pos->next;
	SListNode* ps = BuySListNode(x);
	ps->next = next;
	pos->next = ps;
}

void SListEraseAfter(SListNode* pos)
{
	assert(pos);
	// pos next nextnext
	SListNode* next = pos->next;

	if (next != NULL)
	{
		SListNode* nextnext = next->next;
		free(next);
		pos->next = nextnext;
	}
	}

void SListDestroy(SListNode* plist)
{
	SListNode* r = NULL,*l=plist;
	while (l != NULL)
	{
		r = l;
		l = l->next;
		free(r);
		r = NULL;
	}
	plist = NULL;

}
