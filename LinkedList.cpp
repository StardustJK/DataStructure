#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
typedef int ElemType;
typedef int Status;

//���嵥����洢�ṹ
typedef struct LNode {
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;

//��������(����
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
	//�Ƶ�i��λ�� 
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
	p = L;//��ʱp��head�����ǵ�һ��Ԫ�أ�
	//����i-1��λ��
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
	//��e����ɾ����ֵ
	LNode *p,*q;
	int j = 0;
	p = L;
	//����i-1��λ��
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
	printf("�б�Ϊ��\n");
	LinkedListShow(A);
	int a;
	int i;
	printf("��ȡ��i��λ�õ�ֵ��������i��\n");
	scanf_s("%d", &i);
	GetElem_L(A, i, a);
	printf("��%d��λ�õ�ֵΪ%d\n",i, a);
	printf("�ڵ�i��λ�ò���ֵ��������i�Ͳ����ֵ��\n");
	scanf_s("%d%d", &i,&a);
	ListInset_L(A, i, a);
	printf("�������б�\n");
	LinkedListShow(A);
	printf("ɾ����i��λ�õ�ֵ��������i��\n");
	scanf_s("%d", &i);
	ListDelete_L(A, i, a);
	printf("ɾ����ֵΪ��\n");
	printf("%d\n", a);
	printf("ɾ������б�\n");
	LinkedListShow(A);
	return 0;
}