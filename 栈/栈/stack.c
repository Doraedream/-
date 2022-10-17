#define _CRT_SECURE_NO_WARNINGS 1
#include"stack.h"

void CheckCapacity(Stack* ps)
{
	assert(ps);
	if (ps->_capacity = ps->_top)
	{
		int newcapacity = (ps->_capacity == 0) ? 4 : (ps->_capacity) * 2;
		STDataType* b = (STDataType*)realloc(ps->_a, sizeof(STDataType) * newcapacity);
		assert(b);
		ps->_a = b;
		ps->_capacity = newcapacity;
	}
}

void StackInit(Stack* ps)
{
	ps->_a = (STDataType*)malloc(sizeof(STDataType)*4);
	ps->_capacity = 4;
	ps->_top = 0;
}

void StackPush(Stack* ps, STDataType data)
{
	CheckCapacity(ps);
	ps->_a[ps->_top] = data;
	ps->_top++;
}

void StackPop(Stack* ps)
{
	if (ps->_top == 0)
	{
		return;
	}
	ps->_top--;
}

STDataType StackTop(Stack* ps)
{
	if (ps->_top == 0)
	{
		return (STDataType)0;
   }
	return ps->_a[ps->_top - 1];
}

int StackSize(Stack* ps)
{
	return ps->_top;
}

bool StackEmpty(Stack* ps)
{
	return ps->_top == 0;
}

void StackDestroy(Stack* ps)
{
	if (ps->_a)
	{
		free(ps->_a);
		ps->_a = NULL;
		ps->_capacity = ps->_top = 0;
	}
}

void print(Stack* ps)
{
	int i = ps->_top;
	while (i)
	{
		printf("%d=", ps->_a[i - 1]);
		i--;
	}
}