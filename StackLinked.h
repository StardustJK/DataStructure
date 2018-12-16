#pragma once
#include<stdio.h>
#include<stdlib.h>
#define ElemType int

typedef struct Snode {
	ElemType data;
	struct Snode *next;
}Snode, *LinkStack;

void InitLinkS(LinkStack &S) {
	S = (LinkStack)malloc(sizeof(Snode));
	S->next = NULL;
}
void creatLinkS(LinkStack &S, int n)

{
	LinkStack q;
	printf("����LinkStack����\n");
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
void Pop_LS(LinkStack &S, ElemType &e) {
	e = S->data;
	LinkStack p;
	p = S;
	S = S->next;
	free(p);
}

void showLS(LinkStack S) {
	S = S->next;
	printf("ջΪ:\n");
	while (S != NULL) {
		printf("%d\n", S->data);
		S = S->next;
	}
}