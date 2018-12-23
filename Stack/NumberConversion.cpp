/*
	实验二：
		1.用顺序栈实现的数制转换
			
*/

#include<stdio.h>
#include<stdlib.h>

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define ElemType int

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

void push(SqStack &S,ElemType e) {
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
		printf("栈空\n");
		exit(0);
	}
	S.top--;
	return *S.top;
}

void conversion(int N, int d) {
	if (d == 0) {
		printf("输入错误\n");
		exit(0);
	}
	printf("%d转换成%d进制为：\n", N, d);
	SqStack S;
	initStack(S);
	int e;
	while (N > 0) {
		push(S, N%d);
		N = N / d;
	}
	while (S.base != S.top) {
		e = pop(S);
		if (e < 10) {
			printf("%d", e);
		}
		else {
			printf("%c", e + 55);
		}
	}
}

int main() {
	int N, d;
	while (1) {
		printf("请输入要转换的数字(十进制):\n");
		scanf_s("%d", &N);
		printf("请输入要转换的进制:\n");
		scanf_s("%d", &d);
		getchar();
		conversion(N, d);
		printf("\n\n");
		printf("输入0退出\n");
		printf("输入任意数字继续操作\n");
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