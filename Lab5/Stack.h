#pragma once
#include<stdio.h>
#include<stdlib.h>
#define ElemType int

typedef struct Snode {
	ElemType data;
	struct Snode *next;
}Snode, *LinkStack;

void InitLinkS(LinkStack &S) {
	S = (LinkStack)malloc(sizeof(Snode));//有头结点
	S->next = NULL;
}
void creatLinkS(LinkStack &S, int n)

{
	LinkStack q;
	printf("please input the data of LinkStack \n");
	for (int i = 0;i<n;i++)
	{
		q = (LinkStack)malloc(sizeof(Snode));
		scanf_s("%d", &q->data);
		q->next = S->next;
		S->next = q;
	}
}

void Push_LS(LinkStack &S, ElemType e) {
	LinkStack q;
	q = (LinkStack)malloc(sizeof(Snode));
	q->data = e;
	q->next = S->next;
	S->next = q;
	
}
ElemType Pop_LS(LinkStack &S) {
	ElemType e;
	e = S->next->data;
	LinkStack p;
	p = S;
	S = S->next;
	free(p);
	return e;
}

void showLS(LinkStack S) {
	S = S->next;
	printf("the stack is:\n");
	while (S != NULL) {
		printf("%d\n", S->data);
		S = S->next;
	}
}
bool isEmpty(LinkStack S) {
	if (S->next == NULL) {
		return 1;
	}
	else
		return 0;
}
ElemType getTop(LinkStack S) {
	return S->next->data;
}