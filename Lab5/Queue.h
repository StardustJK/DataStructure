#pragma once
/*
队列操作
*/
#include<stdio.h>
#include<stdlib.h>

//单链队列
#define ElemType int
typedef struct QNode {
	ElemType data;
	struct  QNode *next;
}QNode, *QNodePtr;
typedef struct LinkQueue {
	QNodePtr front;
	QNodePtr rear;
}LinkQueue;
void init_Queue(LinkQueue & Q) {
	Q.front = Q.rear = (QNodePtr)malloc(sizeof(QNode));//头结点
	if (!Q.front)
		printf("overflow\n");
	Q.front->next = NULL;
}
//从队尾插入
void EnQueue(LinkQueue &Q, ElemType e) {
	QNodePtr p;
	p = (QNodePtr)malloc(sizeof(QNode));
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
}
//从队头删除
ElemType DeQueue(LinkQueue &Q) {
	if (Q.rear == Q.front) {
		printf("栈空\n");
		exit(0);
	}
	QNodePtr p;
	p = Q.front->next;
	Q.front->next = p->next;
	if (Q.rear == p) {
		Q.rear = Q.front;
	}
	ElemType data = p->data;
	free(p);
	return data;
}
void show(LinkQueue Q) {
	int i = 1;
	QNodePtr p = Q.front;
	while (p != Q.rear) {
		p = p->next;
		printf("(%d)   %d\n", i, p->data);

		i++;
	}
}
bool isEmpty(LinkQueue Q) {
	if (Q.rear == Q.front) {
		return 1;
	}
	else
		return 0;
}
