#pragma once
#include<stdlib.h>
#include<stdio.h>
#define ElemType int
#define MAXLISTSIZE 20
typedef struct SqList{
	ElemType *data;
	int length;
	int listsize=MAXLISTSIZE;
}SqList;

void init_SqList(SqList &L) {
	L.data = (ElemType *)malloc(sizeof(ElemType)*MAXLISTSIZE);
	L.length = 0;
}

void create_SqList(SqList &L,int a[]) {//´Ó1¿ªÊ¼
	for (int i = 1;i <= a[0];i++) {
		L.data[i] = a[i];
		L.length++;
	}
}

void show_SqList(SqList L) {
	for (int i = 1;i <= L.length;i++) {
		printf("%d ", L.data[i]);
	}
}
