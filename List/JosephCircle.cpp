#include<stdio.h>
#include<stdlib.h>
/*
约瑟夫（Joeph）问题的一种描述是：编号为1,2,…,n的n个人按顺时针方向围坐一圈，
每人持有一个密码（正整数）。一开始任选一个正整数作为报数上限值m，从第一个人开始按顺时针方向自1开始顺序报数，报到m时停止报数。
报m的人出列，将他的密码作为新的m值，从他在顺时针方向上的下一个人开始重新从1报数，如此下去，直至所有人全部出列为止。
试设计一个程序求出出列顺序。
*/
typedef struct JC{
	int number;
	int psw;
	struct JC *next;

}JCnode,*JCList;

//没有头结点
void create_JC(JCList &L,int n) {
	JCList p, q;
	L = (JCList)malloc(sizeof(JCnode));
	L->next = NULL;
	L->number = 1;
	printf("请输入密码：\n");
	scanf_s("%d", &L->psw);
	p = L;
	for (int j = 2;j <= n;j++) {
		q = (JCList)malloc(sizeof(JCnode));
		printf("请输入密码：\n");
		q->number = j;
		scanf_s("%d", &q->psw);
		q->next = p->next;
		p->next = q;
		p = q;
	}
	p->next = L;//指向第一个数，形成环
}
int getLen(JCList L) {
	JCList p;
	p = L;
	if (p == NULL) {
		return 0;
	}
	int e = L->number;
	p = p->next;
	int i = 1;
	for (;p!=NULL;i++,p=p->next) {
		if (e==p->number)
			break;
	}
	return i;
}
int delete_JC(JCList &L,int i) {
	int psw;
	for (int j = getLen(L);j > 1;j--) {
		L = L->next;
	}
	JCList q;
	q = L->next;//标记删除点
	psw = q->psw;
	L->next = L->next->next;
	free(q);
	return psw;

}

void showCircle(JCList L) {
	JCList p;
	p = L;
	for (int j = 1;j <= getLen(L);j++) {
		
		printf("(%d)number:%d  password:%d\n", j, p->number, p->psw);
		p = p->next;
	}

}

void result(JCList L, int m) {
	if (getLen(L) == 1) {
		printf("%d", L->number);
		exit(0);
	}
	for (;m > 0;m--) {
		L = L->next;
	}
	printf("%d\n", L->number);
	result(L, delete_JC(L, 1));
	
}

int main() {
	JCList L;
	int n,m;
	printf("请输入n：\n");
	scanf_s("%d", &n);
	create_JC(L,n);
	showCircle(L);
	printf("请输入初始值m\n");
	scanf_s("%d", &m);
	printf("结果为：\n");
	result(L, m-1);
}