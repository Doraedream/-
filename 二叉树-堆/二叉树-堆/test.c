#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"
int main()
{
	int a[] = { 65, 100, 60, 32, 50, 70 };
	//int a[10] = { 15, 1, 19, 25, 8, 34, 65, 4, 27, 7 };
	HeapSort(a, sizeof(a) / sizeof(int));

	for (size_t i = 0; i < sizeof(a) / sizeof(int); ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");


	return 0;
}