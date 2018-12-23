/*
	作业1.后缀表达式的计算
	运用栈的知识
	算法分析：
		如果是数，则压入栈
		如果是运算符，则弹出栈中的两个数，进行运算。并将运算结果放入栈中
	
	作业2：将中缀表达式变成后缀表达式
		+,-,*,/,(),

	算法分析：
			数字不进栈
			符号进栈。新的优先级高，就让它进栈。遇见级别低的，就弹出前面级别高和同级的,压入这一个
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
bool isprior(int e,int pre) {//1是级别高
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
		printf("栈空\n");
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
			// ）
			if (a[j] == ')') {
				while (*(S.top - 1) != '(') {
					e = pop_SqS(S);
				}
				if (e != '(')
				printf("%c", e);
				pop_SqS(S);//弹出（
				continue;
			}
			if (isprior(a[j],*(S.top-1 ))){//级别高直接压入栈中
					push_SqS(S, a[j]);
					continue;

			}
			if (!isprior(a[j],*(S.top-1))) {//级别低，弹出级别高的和同级的
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
	！！这是错误的，数组作为形参后，降为指针，sizeof(a)的长度就变成了4；
	int i = sizeof(a)/sizeof(a[0]);//a[]的长度
	*/

	for (int j = 0;j < n;j++) {
		if (!isOperator(a[j])) {//是数
			push_SqS(S, a[j]);
		}
		else {//是操作符
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
	
	//test for 作业1
	printf("作业1：\n");
	int a[] = {6,5,2,3,'+',8,'*','+',3,'+','*'};
	int n = sizeof(a)/sizeof(int);
	result1(a,n);
	printf("\n");
	//test for 作业2
	printf("作业2：\n");
	int b[] = { 'A','+','B','*','C','+','(','D','*','E','+','F',')','*','G' };
	//int b[] = { '(','A','+','B',')','*','C' };
	//int b[] = { 'A','+','B','*','C','-','(','D','+','E',')' };
	n = sizeof(b) / sizeof(int);
	result2(b, n);
	printf("\n");
	return 0;
}