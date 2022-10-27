#define _CRT_SECURE_NO_WARNINGS 1
#include"sort.h"

void TestInsertSort()
{
	int a[] = { 34,56,25,65,86,99,72,66 };
	InsertSort(a, sizeof(a) / sizeof(int));
}

void TestShellSort()
{
	//int a[] = { 9,8,7,6,5,4,3,2,1,0 };
	int a[] = { 34, 56, 25, 65, 86, 99, 72, 66 };
	ShellSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

void TestSelectSort()
{
	int a[] = { 100, 56, 25, 65, 86, 99, 72, 66 };
	SelectSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

void TestBubbleSort()
{
	//int a[] = { 9,8,7,6,5,4,3,2,1,0 };
	int a[] = { 34, 56, 25, 65, 86, 99, 72, 66 };
	BubbleSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

void TestPartSort()
{
	//int a[] = { 9,8,7,6,5,4,3,2,1,0 };
	int a[] = { 8,7,6,5,4,3,2,1 };
	PartSort(a,0, sizeof(a) / sizeof(int)-1);
	PrintArray(a, sizeof(a) / sizeof(int));
}

void TestQuickSort()
{
	//int a[] = { 9,8,7,6,5,4,3,2,1,0 };
	//int a[] = { 9,8,7,6,5,4,3,2,1,0 };
	//int a[] = { 1,1,2,2,3,3,3,3,3,3,2,2,2 };
	int a[] = { 30,21,21,21,32,32,32,32 };
	QuickSort(a, 0, sizeof(a) / sizeof(int) - 1);
	PrintArray(a, sizeof(a) / sizeof(int));
}


int main()
{
	//TestInsertSort();
	//TestShellSort();
	//TestSelectSort();
	//TestBubbleSort();
	//TestPartSort();
	TestQuickSort();
	return 0;
}