#include<stdio.h>
#include<stdlib.h>
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define OVERFLOW -2
#define OK 1
#define ERROR -1
#define ElemType int
#define Status int

//sqstack
typedef struct {
	ElemType *base;
	ElemType *top;
	int stacksize;
}SqStack;

Status InitSqStack(SqStack&S) {
	S.base = (ElemType *)malloc(STACK_INIT_SIZE*sizeof(ElemType));
	if (!S.base)
		return OVERFLOW;
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return OK;
}

Status GetTop(SqStack S,ElemType &e) {
	if (S.top == S.base)
		return ERROR;
	e = *(S.top - 1);
	return OK;
}
Status Push_SqS(SqStack &S, ElemType e) {
	if (S.top - S.base >= S.stacksize) {
		S.base = (ElemType*)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(ElemType));
		if (!S.base)
			return OVERFLOW;
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top= e;
	S.top++;
	
	return OK;
}

Status Pop_SqS(SqStack&S, ElemType &e) {
	if (S.top == S.base)
		return ERROR;
	S.top--;
	e = *S.top;
	return OK;
}
typedef struct Snode{
	ElemType data;
	struct Snode *next;
}Snode,*LinkStack;

void InitLinkS(LinkStack &S) {
	S = (LinkStack)malloc(sizeof(Snode));
	S->next= NULL;
}
void creatLinkS(LinkStack &S, int n)

{
	LinkStack q;
	printf("输入LinkStack数据\n");
	for (int i = 0;i<n;i++)
	{
		q = (LinkStack)malloc(sizeof(Snode));
		scanf_s("%d", &q->data);
		q->next = S->next;
		S->next = q;
	}
}

Status Push_LS(LinkStack &S, ElemType e) {
	LinkStack q;
	q = (LinkStack)malloc(sizeof(Snode));
	q->data = e;
	q->next = S->next;
	S->next = q;
	return OK;
}
Status Pop_LS(LinkStack &S, ElemType &e) {
	e = S->data;
	LinkStack p;
	p = S;
	S = S->next;
	free(p);
	return OK;
}
void showSqS(SqStack S) {
	S.top--;
	printf("栈为:\n");
	for(;S.top >= S.base;S.top--) 
		printf("%d\n", *S.top);
}
void showLS(LinkStack S) {
	S = S->next;
	printf("栈为:\n");
	while (S != NULL) {
		printf("%d\n", S->data);
		S = S->next;
	}
}
int main() {
	SqStack A;
	ElemType a;
	InitSqStack(A);
	Push_SqS(A, 1);
	Push_SqS(A, 3);
	Push_SqS(A, 5);
	showSqS(A);
	Pop_SqS(A, a);
	printf("pop出的元素为：%d\n",a);
	showSqS(A);
	Pop_SqS(A, a);

	printf("pop出的元素为：%d\n", a);
	showSqS(A);
	LinkStack B;
	InitLinkS(B);
	creatLinkS(B,3);
	showLS(B);

	Push_LS(B, 6);
	showLS(B);

	Pop_LS(B, a);
	showLS(B);
	return 0;
}