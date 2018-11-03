#include<stdio.h>
#include<stdlib.h>

#define MAXQSIZE 4
#define ElemType int
typedef struct {
	ElemType *base;
	int front;
	int rear;
	int length;
}SqQueue;

void init(SqQueue &Q) {
	Q.base = (ElemType *)malloc(sizeof(ElemType));
	if (!Q.base) {
		printf("overflow\n");
		return;
	}
	Q.front = Q.rear = 0;
	Q.length = 0;
}
void EnQueue(SqQueue &Q, ElemType e) {
	if (Q.length >= MAXQSIZE) {
		printf("队列满\n");
		return;
	}
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXQSIZE;
	Q.length++;
}
void DeQueue(SqQueue &Q) {
	if (Q.length == 0) {
		printf("队列空\n");
		return;
	}
	Q.front = (Q.front + 1) % MAXQSIZE;
	Q.length--;
}

void show(SqQueue Q) {
	if (Q.length == MAXQSIZE) {
		for (int i = 0;i < Q.length;i++) {
			printf("(%d)  %d\n", i + 1, Q.base[i]);
		}
		return;
	}
	if (Q.front < Q.rear) {
		for (int i = Q.front;i < Q.rear;i++) {
			printf("(%d)  %d\n", i - Q.front + 1, Q.base[i - Q.front]);
		}
		return;
	}
	if (Q.front > Q.rear) {
		for (int i = Q.front,j=0;j<Q.length;j++,i++) {
			i = i % MAXQSIZE;
			printf("(%d)  %d\n", j + 1, Q.base[i]);
		}
		return;
	}
}
void create(SqQueue &Q) {
	printf("请输入要创建的长度n,n小于等于%d：\n",MAXQSIZE);
	int n;
	ElemType e;
	scanf_s("%d",&n);
	getchar();
	if (n > MAXQSIZE) {
		printf("输入长度需小于等于%d", MAXQSIZE);
		return;
	}
	for (int i = 0;i < n;i++) {
		printf("请输入第%d个值：\n",i+1);
		scanf_s("%d", &e);
		EnQueue(Q, e);
	}
	printf("队列为：\n");
	show(Q);
}
int main() {
	SqQueue Q;
	init(Q);
	create(Q);
	printf("删除后：\n");
	DeQueue(Q);
	show(Q);
	printf("插入后:\n");
	EnQueue(Q, 5);
	show(Q);
	printf("删除后：\n");
	DeQueue(Q);
	show(Q);
}