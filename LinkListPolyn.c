#include <stdio.h>
#include <stdlib.h>
#include<memory>
#define OK 1
#define ERROR 0
typedef int ElemType;
typedef int Status;

//定义单链表存储结构
typedef struct LNode {
	ElemType data;
	ElemType e;
	struct LNode *next;
}LNode, *LinkList;

//创建链表
void createList_L(LinkList& L,int n) {
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	LinkList p,q;
	q = L;
	
	for (int i = 0;i < n;i++) {
		p = (LinkList)malloc(sizeof(LNode));
		scanf_s("%d%d",&p->data,&p->e);
		p->next = q->next;
		q->next= p;
		q = p;
	}
	
}

//getelem
Status GetElem_L(LinkList L, int i, ElemType &e) {
	LNode *p;
	p = L->next;int j = 1;
	//移到i的位置 
	while (p&&j<i) {
		p = p->next;
		j++;
	}
	if (!p || j>i)
		return ERROR;
	e = p->data;
	return OK;
}
//insertion
Status ListInsert_L(LinkList &L, int i, ElemType e,ElemType a) {
	LNode *p;
	LNode *s;
	int j = 0;
	p = L;//此时p是head而不是第一个元素！
	//到达i-1的位置
	while (p&&j<i - 1) {
		p = p->next;
		j++;
	}
	if (!p || j>i)
		return ERROR;
	s = (LNode *)malloc(sizeof(LNode));
	s->data = e;
	s->e = a;
	s->next = p->next;
	p->next = s;
	return OK;
}

//deletion
Status ListDelete_L(LinkList &L, int i, ElemType &e) {
	//由e返回删除的值
	LNode *p,*q;
	int j = 0;
	p = L;
	//到达i-1的位置
	while ((p->next)&&(j<i-1)){
		p = p->next;
		++j;
	}
	if (!(p->next)&&(j > i - 1))
		return ERROR;
	q = p->next;

	p->next = q->next;
	e = q->data;
	free(q);
	return OK;

	return OK;
}
void ListShow(LinkList L)
{
	LinkList temp;
	int i = 0;
	for (i = 1, temp = L->next; temp != NULL; i++, temp = temp->next)
		printf("(%d)->系数：%d  指数：%d ", i, temp->data, temp->e);
	printf("\n");
	//
	printf("多项式为：\nf(x)=");
	for (i = 1, temp = L->next; temp != NULL; i++, temp = temp->next)
	{
		if (temp->data == 0)
			continue;
		printf("%dx^%d", temp->data, temp->e);
		if ((temp->next != NULL) && (temp->next->data != 0))
			printf("+");
	}
	printf("\n");
}
int getLocate_L(LinkList L,ElemType a) {
	LinkList p;
	p = L->next;
	p = L;
	for (int i = 1;p != NULL;i++) {
		if (p->e == a) {
			return i;
		}
		p = p->next;
	}
	return ERROR;
}
void AddPolyn(LinkList&A, LinkList&B) {
	LinkList p, q;
	p = A->next, q = B->next;
	
	while (q != NULL&&p!=NULL) {
		if (p->e == q->e) {
			p->data = p->data + q->data;
			p = p->next;
			q = q->next;
			continue;
		}
		if (p->e < q->e) {
			ListInsert_L(A, getLocate_L(A, p->e) , q->data, q->e);
			q = q->next;
			p = p->next->next;
			continue;
			//break;
		}
		if (p->e > q->e) {
			ListInsert_L(A, getLocate_L(A, p->e) - 1, q->data, q->e);
			q = q->next;
			continue;
		}
	}
	while (p==NULL&&q!=NULL)
	{
		p = A->next;
		while (p->next != NULL)
		{
			p = p->next;
		}
		while(q != NULL) {
			ListInsert_L(A, getLocate_L(A, p->e), q->data, q->e);
			q = q->next;
			p = p->next;
		}
	}
	/*
	p = A->next;
	while (p != NULL)
	{
		if (p->data == 0) {
			int a;
			ListDelete_L(A, getLocate_L(A, p->data), a);
			break;
		}
		p = p->next;
	}
*/
}
int getMaxE(LinkList A) {
	LinkList p;
	p = A->next;
	int i = 0;
	for (;p->next != NULL;)
		p = p->next;
	i = p->e;
	return i;
}
LinkList MultiplyPloyn(LinkList&A, LinkList&B) {
	LinkList p, q, temp, C, Temp, r;
	int i;
	i = getMaxE(A);
	if (i <getMaxE(B))
		i = getMaxE(B);
	Temp = (LinkList)malloc(i*sizeof(LNode));
	C = (LinkList)malloc(i*sizeof(LNode));
	memset(Temp, 0, sizeof(LNode) * i);
	memset(C, 0, sizeof(LNode) * i);
	//初始化C
	ListInsert_L(C, 1, 0, 0);
	ListInsert_L(C, 2, 0, 0);
	p = A->next, q = B->next;
	temp = Temp;
	for (;p != NULL;) {
		for (q=B->next;q != NULL;) {
			r = (LinkList)malloc(sizeof(LNode));
			r->data = p->data * q->data;
			r->e = q->e + p->e;
			r->next = temp->next;
			temp->next = r;
			temp = r;
			q = q->next;
		}

		AddPolyn(C, Temp);
		p = p->next;

	}
	return C;
}
int main() {
	LinkList A;
	createList_L(A, 1);
	printf("列表为：\n");
	ListShow(A);
	LinkList B;
	createList_L(B, 2);
	printf("列表为：\n");
	ListShow(B);
	LinkList C;

	AddPolyn(A, B);
	ListShow(A);
	/*
	C = MultiplyPloyn(A, B);
	ListShow(C);*/
	getchar();
}