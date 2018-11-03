#include<stdio.h>
#include<stdlib.h>
#define STACK_INIT_SIZE 2
#define STACKINCREMENT 10
#define ElemType Data



//stack
typedef struct Data{
	int carnumber;
	int time;
};
typedef struct {
	Data *base;
	Data *top;
	int stacksize;
	int length;
}SqStack;

void init_SqS(SqStack &S) {
	S.base = (Data *)malloc(STACK_INIT_SIZE * sizeof(Data));
	if (!S.base)
		printf("overflow\n");
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	S.length = 0;
}
Data pop_SqS(SqStack &S) {
	if (S.base == S.top) {
		printf("ջ��\n");
		exit(0);
	}
	S.top--;
	S.length--;
	return *S.top;
}
void push_SqS(SqStack &S, Data e) {
	if (S.top - S.base >= S.stacksize) {
		printf("ͣ����������\n");
		return;
	}
	*S.top = e;
	S.top++;
	S.length++;
}

int getLoc_SqS(SqStack S,int e) {
	for (int i=1;S.base <= S.top;S.base++,i++) {
		if (e == S.base->carnumber) {
			return i;
		}
	}
	return 0;//������
}
//queue

typedef struct QNode {
	ElemType data;
	struct  QNode *next;
}QNode, *QNodePtr;
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
void EnQueue(LinkQueue &Q, ElemType e) {
	QNodePtr p;
	p = (QNodePtr)malloc(sizeof(QNode));
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
}
//�Ӷ�ͷɾ��
Data DeQueue(LinkQueue &Q) {
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
	Data e = p->data;
	free(p);
	return e;

}

int getLoc_Que(LinkQueue Q, int e) {
	QNodePtr p = Q.front->next;
	for (int i = 1;p <= Q.rear;p=p->next,i++) {
		if (p->data.carnumber == e) {
			return i;
		}
	}
	return 0;
}

int main() {
	SqStack park;
	SqStack left;
	LinkQueue wait;
	init_Queue(wait);
	init_SqS(park);
	init_SqS(left);
	Data data;
	char oper;
	while (1) {
		printf("���������ݣ�\n");
		scanf_s("%c%d%d", &oper, 1, &data.carnumber, &data.time);
		getchar();
		if (oper == 'A') {
			if (park.length < STACK_INIT_SIZE) {//��ͣ����
				push_SqS(park, data);
				printf("����ͣ�����ɱ����ϵĵ�%d��λ\n", getLoc_SqS(park, data.carnumber));
			}
			else {//�����
				EnQueue(wait, data);
				printf("���ڱ���ĵ�%d��λ\n", getLoc_Que(wait, data.carnumber));
			}
			continue;
		}
		if (oper == 'D') {
			if (getLoc_SqS(park, data.carnumber) == 2) {//�ڿ����ŵ�λ�ã�ֱ�ӳ���
				int parktime = data.time - park.base[1].time;
				printf("parking time:%d\n", parktime);
				pop_SqS(park);
				push_SqS(park, DeQueue(wait));
				park.base[1].time = data.time;


			}
			if (getLoc_SqS(park, data.carnumber) == 1) {//��Ų�������ٰѱ���ϵ�Ū��ȥ
				push_SqS(left, pop_SqS(park));
				int parktime = data.time - park.base[0].time;
				printf("parking time:%d\n", parktime);
				pop_SqS(park);
				push_SqS(park, pop_SqS(left));
				if (wait.front != wait.rear) {
					push_SqS(park, DeQueue(wait));
					park.base[1].time = data.time;
				}
			}
			continue;
		}
		if (oper == 'E') {
			break;
		}

	}

}