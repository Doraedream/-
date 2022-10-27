#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* p, int* q);
void PrintArray(int* a, int n);

void InsertSort(int* a, int n);
void ShellSort(int* a, int n);
void AdjustDown(int* a, int n, int parent);
void HeapSort(int* a, int n);
void SelectSort(int* a, int n);
void BubbleSort(int* a, int n);
int PartSort(int* a, int left, int right);
void QuickSort(int* a, int begin, int end);