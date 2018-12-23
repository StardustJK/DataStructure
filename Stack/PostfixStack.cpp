/*
	��ҵ1.��׺���ʽ�ļ���
	����ջ��֪ʶ
	�㷨������
		�����������ѹ��ջ
		�������������򵯳�ջ�е����������������㡣��������������ջ��
	
	��ҵ2������׺���ʽ��ɺ�׺���ʽ
		+,-,*,/,(),

	�㷨������
			���ֲ���ջ
			���Ž�ջ���µ����ȼ��ߣ���������ջ����������͵ģ��͵���ǰ�漶��ߺ�ͬ����,ѹ����һ��
*/
#include<stdio.h>
#include<stdlib.h>
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef struct {
	int *base;
	int *top;
	int stacksize;
}SqStack;

void init_SqS(SqStack &S) {
	S.base = (int *)malloc(STACK_INIT_SIZE * sizeof(int));
	if (!S.base)
		printf("overflow\n");
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
}

void push_SqS(SqStack &S, char e) {
	if (S.top - S.base >= S.stacksize) {
		S.base = (int*)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(int));
		if (!S.base)
			printf("overflow\n");
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top = e;
	S.top++;
}
bool isprior(int e,int pre) {//1�Ǽ����
	if (pre == '(')
		return 1;
	if (e == '(')
		return 1;
	if (e == '+')
	{
		if (pre == '#')
			return 1;
		if (pre == '-' || pre == '*' || pre == '/'|| e == '+')
			return 0;
	}
	if (e == '-')
	{
		if (pre == '#')
			return 1;
		if (pre == '+' || pre == '*' || pre == '/'|| e == '-')
			return 0;
	}
	if (e == '*')
	{
		if (pre == '-' || pre == '+'||pre=='#')
			return 1;
		if(pre == '/'||e == '*')
			return 0;
	}
	if (e == '/')
	{
		if (pre == '-' || pre == '+' || pre == '#')
			return 1;
		if (pre == '*'|| e == '/')
			return 0;
	}

}

int pop_SqS(SqStack &S) {
	if (S.base == S.top) {
		printf("ջ��\n");
		exit(0);
	}
	S.top--;
	return *S.top;
}
bool isOperator(int e) {
	if (e == '-' || e == '+' || e == '*' || e == '/'|| e == '('||
		e == ')' || e == '{' || e == '}' || e == '['|| e == ']') {
		return 1;
	}
	else
		return 0;
}
void result2(int a[], int n) {
	SqStack S;
	init_SqS(S);
	push_SqS(S, '#');
	int e;
	for (int j = 0;j < n;j++) {

		if (!isOperator(a[j])) {
			printf("%c", a[j]);
			continue;
		}
		if (isOperator(a[j])) {
			// ��
			if (a[j] == ')') {
				while (*(S.top - 1) != '(') {
					e = pop_SqS(S);
				}
				if (e != '(')
				printf("%c", e);
				pop_SqS(S);//������
				continue;
			}
			if (isprior(a[j],*(S.top-1 ))){//�����ֱ��ѹ��ջ��
					push_SqS(S, a[j]);
					continue;

			}
			if (!isprior(a[j],*(S.top-1))) {//����ͣ���������ߵĺ�ͬ����
				while(!isprior(a[j], *(S.top - 1))) {
					e = pop_SqS(S);
					printf("%c", e);
					}
				
				push_SqS(S, a[j]);
				continue;
			}

		}
	}
	while (S.base != S.top) {
		e = pop_SqS(S);
		if(e!='#')
		printf("%c", e);
	}
}
void result1(int a[],int n) {
	//init stack
	SqStack S;
	init_SqS(S);
	int c, b,e;
	
	/*
	�������Ǵ���ģ�������Ϊ�βκ󣬽�Ϊָ�룬sizeof(a)�ĳ��Ⱦͱ����4��
	int i = sizeof(a)/sizeof(a[0]);//a[]�ĳ���
	*/

	for (int j = 0;j < n;j++) {
		if (!isOperator(a[j])) {//����
			push_SqS(S, a[j]);
		}
		else {//�ǲ�����
			c = pop_SqS(S);
			b = pop_SqS(S);
			if (a[j] == '+')
				e = b + c;
			if (a[j] == '-')
				e = b - c;
			if (a[j] == '*')
				e = b * c;
			if (a[j] == '/')
				e = b / c;
			push_SqS(S, e);
		}
	}
		printf("%d\n", e);
}
int main() {
	
	//test for ��ҵ1
	printf("��ҵ1��\n");
	int a[] = {6,5,2,3,'+',8,'*','+',3,'+','*'};
	int n = sizeof(a)/sizeof(int);
	result1(a,n);
	printf("\n");
	//test for ��ҵ2
	printf("��ҵ2��\n");
	int b[] = { 'A','+','B','*','C','+','(','D','*','E','+','F',')','*','G' };
	//int b[] = { '(','A','+','B',')','*','C' };
	//int b[] = { 'A','+','B','*','C','-','(','D','+','E',')' };
	n = sizeof(b) / sizeof(int);
	result2(b, n);
	printf("\n");
	return 0;
}