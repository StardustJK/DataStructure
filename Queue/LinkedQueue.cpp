#include<stdio.h>
#include<stdlib.h>

//��������
#define ElemType int
typedef struct QNode {
	ElemType data;
	struct  QNode *next;	
}QNode,*QNodePtr;
typedef struct LinkQueue {
	QNodePtr front;
	QNodePtr rear;
}LinkQueue;
void init_Queue(LinkQueue & Q) {
	Q.front = Q.rear = (QNodePtr)malloc(sizeof(QNode));
	if (!Q.front)
		printf("overflow\n");
	Q.front->next = NULL;
}
//�Ӷ�β����
void EnQueue(LinkQueue &Q,ElemType e) {
	QNodePtr p;
	p = (QNodePtr)malloc(sizeof(QNode));
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
}
//�Ӷ�ͷɾ��
void DeQueue(LinkQueue &Q) {
	if (Q.rear == Q.front) {
		printf("ջ��\n");
		exit(0);
	}
	QNodePtr p;
	p = Q.front->next;
	Q.front->next = p->next;
	if (Q.rear == p) {
		Q.rear = Q.front;
	}
	free(p);
}
void show(LinkQueue Q) {
	int i = 1;
	QNodePtr p = Q.front;
	while (p!= Q.rear) {
		p = p->next;
		printf("(%d)   %d\n", i, p->data);
		
		i++;
	}
}
void create(LinkQueue &Q) {
	printf("��������еĳ���\n");
	int n;
	ElemType e;
	scanf_s("%d", &n);//
	getchar();
	for (int i = 0;i < n;i++) {
		printf("�������%d�����ݣ�\n",i+1);
		scanf_s("%d", &e);
		EnQueue(Q, e);
	}
	printf("�������б�Ϊ��\n");
	show(Q);
}

int main() {
	LinkQueue Q;
	init_Queue(Q);
	create(Q);
	printf("�Ӷ�ͷɾ����\n");
	DeQueue(Q);
	show(Q);
	printf("�Ӷ�β���룺\n");
	EnQueue(Q, 6);
	show(Q);
	return 0;
}