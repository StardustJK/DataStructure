#pragma once
#include<stdio.h>
#include<stdlib.h>
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define ElemType int

//sqstack
typedef struct {
	ElemType *base;
	ElemType *top;
	int stacksize;
}SqStack;

void InitSqStack(SqStack&S) {
	S.base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
	if (!S.base) {
		printf("overflow!\n");
		return;
	}
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
}

void GetTop(SqStack S, ElemType &e) {
	if (S.top == S.base) {
		printf("Õ»¿Õ\n");
		return;
	}
	e = *(S.top - 1);
}
void Push_SqS(SqStack &S, ElemType e) {
	if (S.top - S.base >= S.stacksize) {
		S.base = (ElemType*)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(ElemType));
		if (!S.base) {
			printf("overflow\n");
			return;
		}
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top = e;
	S.top++;

}

void Pop_SqS(SqStack&S, ElemType &e) {
	if (S.top == S.base) {
		printf("Õ»¿Õ\n");
		return;
	}
	S.top--;
	e = *S.top;
}
void showSqS(SqStack S) {
	S.top--;
	printf("Õ»Îª:\n");
	for (;S.top >= S.base;S.top--)
		printf("%d\n", *S.top);
}