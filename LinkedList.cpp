#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
typedef int ElemType;
typedef int Status;

//定义单链表存储结构
typedef struct LNode {
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;

//创建链表(逆序）
void createList_L(LinkList& L,int n) {
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	LNode* p;
	for (int i = 0;i < n;i++) {
		p = (LNode*)malloc(sizeof(LNode));
		scanf_s("%d",&p->data);
		p->next = L->next;
		L->next= p;
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
Status ListInset_L(LinkList &L, int i, ElemType e) {
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
void LinkedListShow(LinkList L)
{
	LinkList temp;
	int i = 0;
	for (i = 1, temp = L->next; temp != NULL; i++, temp = temp->next)
		printf("(%d)->%d ", i, temp->data);
	printf("\n");
}

int main(int argc, char *argv[]) {
	
	LinkList A;
	createList_L(A, 5);
	printf("列表为：\n");
	LinkedListShow(A);
	int a;
	int i;
	printf("获取第i个位置的值，请输入i：\n");
	scanf_s("%d", &i);
	GetElem_L(A, i, a);
	printf("第%d个位置的值为%d\n",i, a);
	printf("在第i个位置插入值，请输入i和插入的值：\n");
	scanf_s("%d%d", &i,&a);
	ListInset_L(A, i, a);
	printf("插入后的列表：\n");
	LinkedListShow(A);
	printf("删除第i个位置的值，请输入i：\n");
	scanf_s("%d", &i);
	ListDelete_L(A, i, a);
	printf("删除的值为：\n");
	printf("%d\n", a);
	printf("删除后的列表：\n");
	LinkedListShow(A);
	return 0;
}