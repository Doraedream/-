#include"SeqList.h"
void SeqListInit(SeqList* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}

void SeqListDestroy(SeqList* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}

void SeqListPrint(SeqList* ps)
{
	assert(ps);
	for (size_t i = 0;i < ps->size;i++)
	{
		printf("%d ", ps->a[i]);
	}
}
void CheckCacpity(SeqList* ps)
{
	assert(ps);
	if (ps->capacity == ps->size)
	{
		size_t newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDatatype* tmp = (SLDatatype*)realloc(ps->a, newcapacity * sizeof(SLDatatype));
		if (tmp == NULL)
		{
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity = newcapacity;
	}
}

void SeqListPushFront(SeqList* ps, SLDatatype x)
{
	assert(ps);
	CheckCacpity(ps);
	for (size_t i = ps->size;i > 0;i--)
	{
		ps->a[i] = ps->a[i - 1];
		ps->a[0] = x;
		ps->size++;
	}
}

void SeqListPushBack(SeqList* ps, SLDatatype x)
{
	assert(ps);
	CheckCacpity(ps);
	ps->a[ps->size] = x;
	ps->size++;
}

void SeqListPopFront(SeqList* ps)
{
	assert(ps);
	for (size_t i = 0;i < ps->size - 1;i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}

void SeqListPopBack(SeqList* ps)
{
	assert(ps);
	ps->size--;
}

int SeqListFind(SeqList* ps, SLDatatype x)
{
	assert(ps);
	for (size_t i = 0;i < ps->size;i++)
	{
		if (ps->a[i] == x)
		{
			return i;
		}
	}
	return -1;
}

void SeqListInsert(SeqList* ps, size_t pos, SLDatatype x)
{
	assert(ps);
	assert(pos <= ps->size&&pos>=0);
	CheckCacpity(ps);
	size_t end = ps->size;
	while (end > pos)
	{
		ps->a[end] = ps->a[end - 1];
		end--;
	}
	ps->a[pos] = x;
	ps->size++;
}

void SeqListErase(SeqList* ps, size_t pos)
{
	assert(ps&&pos<ps->size);
	int i = pos;
	while (i < ps->size-1)
	{
		ps->a[i] = ps->a[i + 1];
		i++;
	}
	ps->size--;
}