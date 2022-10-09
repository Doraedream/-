#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int SLDatatype;
typedef struct SeqList {
	SLDatatype* a;
	size_t size;
	size_t capacity;
}SeqList;

void SeqListInit(SeqList* ps);
void SeqListDestroy(SeqList* ps);

void SeqListPrint(SeqList* ps);
void SeqListPushBack(SeqList* ps, SLDatatype x);
void SeqListPushFront(SeqList* ps, SLDatatype x);
void SeqListPopFront(SeqList* ps);
void SeqListPopBack(SeqList* ps);

// ˳������
int SeqListFind(SeqList* ps, SLDatatype x);
// ˳�����posλ�ò���x
void SeqListInsert(SeqList* ps, size_t pos, SLDatatype x);
// ˳���ɾ��posλ�õ�ֵ
void SeqListErase(SeqList* ps, size_t pos);
void CheckCacpity(SeqList* ps);