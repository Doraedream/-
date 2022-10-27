#define _CRT_SECURE_NO_WARNINGS 1
#include"sort.h"

void swap(int* p, int* q)
{
	int i = *p;
	*p = *q;
	*q = i;
}
void PrintArray(int* a, int n)
{
	for (int i = 0;i < n;i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void InsertSort(int* a, int n)
{
	for (int i = 1;i < n;i++)
	{
		for(int j=i;j>0;j--)
		{
			if (a[j] < a[j - 1])
			{
				swap(&a[j], &a[j - 1]);
			}
			else {
				break;
			}
		}
	}
}

void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap /= 2;
		for (int i = 0;i < n - gap;i++)
		{
			int end = i + gap;
			while (end >= gap)
			{
				if (a[end] < a[i])
				{
					swap(&a[end], &a[i]);
				}
				else
				{
					break;
				}
			}
		}
	}
}

void AdjustDown(int* a, int n, int parent)
{
	int minchild = parent * 2 + 1;
	while (minchild < n)
	{
		if (minchild + 1 < n && a[minchild] < a[minchild + 1])
		{
			minchild++;
		}

		if (a[parent] < a[minchild])
		{
			swap(&a[parent], &a[minchild]);
			parent = minchild;
			minchild = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapSort(int* a, int n)
{
	for (int i = (n - 2) / 2;i >= 0;i--)
	{
		AdjustDown(a, n, i);
	}
	int i = 1;
	while (i < n)
	{
		swap(&a[0], &a[n - i]);
		AdjustDown(a, n, 0);
		i++;
	}
}

void SelectSort(int* a, int n)
{
	int begin = 0, end = n - 1;
	while (begin < end)
	{
		int max = begin;
		int min = begin;
		for (int i = begin + 1;i <= end;i++)
		{
			if (a[i] > a[max])
			{
				max = i;
			}
			if (a[i] < a[min])
			{
				min = i;
			}
		}
		swap(&a[begin], &a[min]);
		if (begin == max)
		{
			swap(&a[min], &a[end]);
		}
		else
		{
			swap(&a[max], &a[end]);
		}
		begin++;
		end--;

	}
}

void BubbleSort(int* a, int n)
{
	for (int i = 0;i < n;i++)
	{
		int exchange = 0;
		for (int j = 0;j < n - i - 1;j++)
		{
			if (a[j] > a[j + 1])
			{
				swap(&a[j], &a[j + 1]);
				exchange = 1;
			}
		}
		if (exchange == 0)
		{
			break;
		}
	}
}

int PartSort(int* a, int left, int right)
{
	int keyi = left;
	while (right > left)
	{
		while (right > left && a[right] >= a[keyi])
		{
			right--;
		}
		while (right > left && a[left] <= a[keyi])
		{
			left++;
		}
		if(right > left)
		swap(&a[left], &a[right]);
	}
	int meet = left;
	swap(&a[keyi], &a[meet]);
	return meet;
}

void QuickSort(int* a, int begin, int end)
{
	if (begin >= end)
	{
		return;
	}
	int i = PartSort(a, begin, end);
	QuickSort(a, begin, i - 1);
	QuickSort(a, i+1, end);
}