/*
	双向链表的基础操作：获取某个位置的元素，插入，删除
*/

#include<stdio.h>
#include<stdlib.h>

#define ElemType int
#define Status int
#define ERROR -1
#define OK 1

//定义结构体
typedef struct DuLNode {
	ElemType data;
	struct DuLNode *prior;
	struct DuLNode *next;
}DuLNode,*DuLinkList;

//insertion
Status ListInsert_DuL(DuLinkList &L, int i, ElemType a) {
	//到达i的位置
	DuLinkList p=L;
	for (int j = 0;j < i;j++) {
		p = p->next;
	}
	//位置不合理
	if (!p)
		return ERROR;
	//创建节点
	DuLinkList s;
	s = (DuLinkList)malloc(sizeof(DuLNode));
	if (!s)
		return ERROR;
	s->data = a;
	s->prior = p->prior;
	p->prior->next = s;
	s->next = p;
	p->prior = s;
	return OK;
}

//deletion
Status ListDelete_DuL(DuLinkList &L, int i, ElemType&e) {
	DuLinkList p = L;
	for (int j = 0;j < i;j++) {
		p = p->next;
	}
	//位置不合理
	if (!p)
		return ERROR;
	//增添i是最后一个位置的情况
	if (p->next == NULL) {
		e = p->data;
		p->prior->next = NULL;
		free(p);
		return OK;
	}
	p->prior->next = p->next;
	p->next->prior = p->prior;
	e = p->data;
	free(p);
	return OK;
}

//创建链表,尾插法

void createList_DuL(DuLinkList& L, int n) {
	L = (DuLinkList)malloc(sizeof(DuLNode));//头结点
	L->next = NULL;
	L->prior = NULL;
	DuLNode* p,*q;
	q = L;
	//printf("请输入数据\n");
	printf("请按照指数的升序输入 系数 指数\n");
	for (int i = 0;i < n;i++) {
		p = (DuLNode*)malloc(sizeof(DuLNode));
		scanf_s("%d", &p->data);
	

		p->next = q->next;
		//q->next->prior= p;   //千万不能有这个！！   q->next 是NULL
		q->next = p;
		p->prior = q;
		q = p;
	}
}

void ListShow(DuLinkList L)
{
	DuLinkList temp;
	int i = 0;
	for (i = 1, temp = L->next; temp != NULL; i++, temp = temp->next)
		printf("(%d)->系数：%d  指数：%d ", i, temp->data,temp->e);
	printf("\n");

}


//getelem
ElemType Getelem_DuL(DuLinkList L, int i) {
	
	for (int j = 0;j < i;j++) {
		L = L->next;
	}
	return L->data;
}

int getLocate_DuL(DuLinkList L, int a) {
	DuLinkList p;
	p = L->next;
	for (int i = 1;p != NULL;i++) {
		if (p->e == a) {
			return i;
		}
		p = p->next;
	}
	return ERROR;
}


int main() {
	//create the List
	int i;
	printf("输入列表长度");
	scanf_s("%d,&i);
	DuLinkList A;
	createList_DuL(A, i);
	printf("列表为：\n");
	ListShow(A);

	ElemType e;
	//test for insertion

	printf("在第i个位置插入元素e,请输入i 和e:\n");
	scanf_s("%d%d", &i, &e);
	ListInsert_DuL(A, i, e);
	printf("插入后的列表为：\n");
	ListShow(A);
	//test for deletion
	printf("删除在第i个的位置元素,请输入i \n");
	scanf_s("%d", &i);
	ListDelete_DuL(A, i, e);
	printf("删除的值为%d", e);
	printf("删除后的列表为：\n");
	ListShow(A);
}