#define _CRT_SECURE_NO_WARNINGS 1
#include"stack.h"

int main()
{
	Stack* st=(Stack*)malloc(sizeof(Stack));
	StackInit(st);
	StackPush(st, 1);
	StackPush(st, 2);
	StackPush(st, 3);
	StackPush(st, 4);
	StackPush(st, 5);
	print(st);



	return 0;
}