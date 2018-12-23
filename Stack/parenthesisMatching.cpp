/*
	ʵ�����
		2.����ƥ���жϣ����������ȼ�
*/
#include<stdio.h>  
#include<stdlib.h>  

#define STACK_INIT_SIZE 100  
#define STACKINCREMENT 10  
#define ElemType char

typedef struct {
	ElemType *base;
	ElemType *top;
	int stacksize;
}SqStack;

void initStack(SqStack &S) {
	S.base = (ElemType*)malloc(sizeof(ElemType));
	if (!S.base) {
		printf("overflow\n");
		exit(0);
	}
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
}

void push(SqStack &S, ElemType e) {
	if (S.top - S.base >= S.stacksize) {
		S.base = (ElemType*)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(ElemType));
		if (!S.base)
		{
			printf("overflow\n");
			exit(0);
		}
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top = e;
	S.top++;

}

ElemType pop(SqStack &S) {
	if (S.top == S.base) {
		printf("ջ��\n");
		exit(0);
	}
	S.top--;
	return *S.top;
}

ElemType getTop(SqStack &S){
	return *(S.top - 1);
}
//1 ��ȷ
//0 ����
int matching(char a[],int n) {
	if (a[0] == ')' || a[0] == ']' || a[0] == '}') {
		return 0;
	}
	SqStack S;
	initStack(S);
	for (int i = 0;i < n;i++) {
		if (
			a[i] == '(' || a[i] == '[' || a[i] == '{'
			)
		{
			push(S, a[i]);
			continue;
		}
		else if( (a[i]==')' &&'('== getTop(S))|| (a[i] == ']' &&'[' == getTop(S))|| (a[i] == '}' &&'{' == getTop(S))) {
			pop(S);
			continue;
		}
		else
			return 0;
	}
	if (S.top != S.base)
		return 0;
	else
		return 1;
}

int main() {
	int n;
	char a[100];
	while (1) {
		printf("�����볤��n(1--100):\n");
		scanf_s("%d", &n);
		getchar();
		printf("������Ҫ��������:\n");
		for (int i = 0;i < n;i++) {
			scanf_s("%c", &a[i], 1);
		}
		getchar();
		printf("�������\n");
		int b;
		b = matching(a, n);
		if (b == 1) {
			printf("���ƥ��\n");
		}
		if (b == 0) {
			printf("��ƥ��\n");
		}
		printf("\n\n");
		printf("����0�˳�\n");
		printf("�����������ּ�������\n");
		int c;
		scanf_s("%d", &c);
		if (c == 0) {
			break;
		}
		else {
			system("cls");
			continue;
		}
	}
	return 0;
}