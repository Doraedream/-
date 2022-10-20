#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"
void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void HeapPrint(HP* php)
{
	assert(php);
	for (int i = 0;i < php->size;i++)
	{
		printf("%d ", php->a[i]);
	}
	printf("\n");
}

void AdjustUp(HPDataType* a, int child)
{
	assert(a);
	int parent = (child - 1) / 2;
	while (child>0)
	{
		if (a[parent] < a[child])
		{
			Swap(&a[parent], &a[child]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else {
			break;
		}
	}
}

void AdjustDown(HPDataType* a, int n, int parent)
{
	int minchild = parent * 2 +1;
	while (minchild < n)
	{
		if (minchild + 1 < n && a[minchild + 1] > a[minchild])
		{
			minchild++;
		}
		if (a[minchild] > a[parent])
		{
			Swap(&a[minchild], &a[parent]);
			parent = minchild;
			minchild = parent * 2 + 1;
		}
		else {
			break;
		}
	}


}

void HeapInit(HP* php)
{
	assert(php);
	php->a = NULL;
	php->capacity = php->size = 0;
}

void HeapDestroy(HP* php)
{
	free(php->a);
	free(php);
}

void HeapPush(HP* php, HPDataType x)
{
	assert(php);
	if (php->size == php->capacity)
	{
		int newcapacity = (php->capacity == 0) ? 4 : 2 * php->capacity;
		HPDataType* newa = (HPDataType*)realloc(php->a, sizeof(HPDataType) * newcapacity);
		if (newa == NULL)
		{
			perror("realloc fail");
			exit(-1);
		}
		php->a = newa;
		php->capacity = newcapacity;
	}
	php->a[php->size] = x;
	php->size++;
	AdjustUp(php->a, php->size - 1);
}

bool HeapEmpty(HP* php)
{
	assert(php);
	return php->size == 0;
}

void HeapPop(HP* php)
{
	assert(php);
	assert(!HeapEmpty(php));
	Swap(&php->a[0], &php->a[php->size - 1]);
	php->size--;
	AdjustDown(php->a, php->size, 0);

}

HPDataType HeapTop(HP* php)
{
	assert(php);
	return php->a[0];
}

int HeapSize(HP* php)
{
	return php->size;
}