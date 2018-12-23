/*
	��ҵ1��LA=LA U LB  A,B����
	��ҵ2��LC=LA U LB  ����A,BΪ����Ҫ��C�Ƿǽ���

*/

#include<stdio.h>
#include<stdlib.h>

//�б�Ĵ��켰������������
#define ERROR -1
#define OK 1
#define OVERFLOW -2
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define ElemType int 
#define Status int

typedef struct {
	ElemType *elem;
	int length;//��ǰ����
	int listsize;//����
}SqList;


//init SqList
Status initList_Sq(SqList &L) {
	L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));//��elem���ռ�
	if (!L.elem)
		exit(OVERFLOW);
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return OK;
}


//insertion
Status ListInsertion_Sq(SqList &L, int i, ElemType e) {
	if (i<1 || i>L.length + 1)
		return ERROR;
	if (L.length >= L.listsize) {//��ǰ�ռ�����
		ElemType *newbase;
		newbase = (ElemType*)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
		if (!newbase)
			exit(OVERFLOW);
		L.elem = newbase;
		L.listsize = L.listsize + LISTINCREMENT;
	}
	ElemType* q = &(L.elem[i - 1]);//������ָ���൱��������Ĳ���������Ҫ-1
	ElemType* p = &(L.elem[L.length - 1]);
	for (;p >= q;p--) {
		*(p + 1) = *p;
	}
	*q = e;
	L.length++;
	return OK;
}

void showList(SqList L) {
	ElemType* p = &L.elem[0];
	ElemType *q = &L.elem[L.length - 1];
	for (;p <= q;p++) {
		printf("%d  ", *p);
	}
	printf("\n");
}

//LA=LA U LB  A,B����
void mergeList_Sq1(SqList &A, SqList B) {
	for (int i = 0;i < B.length;i++) {
		int j = 0;
		while((A.elem[j]!=B.elem[i])&&(j<A.length)){
			j++;
		}
		if (j >=A.length) {//˵���������˶�û��һ����
			ListInsertion_Sq(A, A.length+1, B.elem[i]);
		}
	}
}

//LC = LA U LB  ����A, BΪ����Ҫ��C�Ƿǽ���
void mergeList_Sq2(SqList&C, SqList A, SqList B) {
	int i=0, j=0, k = 1;
	while ((i < A.length) && (j < B.length)) {
		if (A.elem[i] <B.elem[j]) {
			ListInsertion_Sq(C, k, A.elem[i]);
			i++;
			k++;
			continue;
		}
		if (A.elem[i] > B.elem[j]) {
			ListInsertion_Sq(C, k, B.elem[j]);
			j++;
			k++;
			continue;
		}
		if (A.elem[i] == B.elem[j]) {
			ListInsertion_Sq(C, k, A.elem[i]);
			i++;
			j++;
			k++;
			continue;
		}
	}
	//ʣ��ļ���C

	//A�������� B��û��
	if ((i >= A.length) &&(j<B.length)){
		for (;j<B.length;j++) {
			ListInsertion_Sq(C, k, B.elem[j]);
			k++;
		}
	}
	//B�������� A��û��
	if ((j>= B.length ) && (i<A.length) ){
		for (;i<A.length;i++) {
			ListInsertion_Sq(C, k, A.elem[i]);
			k++;
		}
	}
	

}
int main() {


	//�����б�A,B
	SqList A, B;
	initList_Sq(A);
	initList_Sq(B);
	ElemType e;
	int i;
	printf("������A�ĳ���i �Լ�A��Ԫ��\n");
	scanf_s("%d",&i);
	for (int j = 0;j < i;j++) {
		scanf_s("%d", &e);
		ListInsertion_Sq(A, j + 1, e);
	}
	showList(A);
	printf("������B�ĳ���i �Լ�B��Ԫ��\n");
	scanf_s("%d", &i);
	for (int j = 0;j < i;j++) {
		scanf_s("%d", &e);
		ListInsertion_Sq(B, j + 1, e);
	}
	showList(B);
	

	//�˴�������ҵ1

	/*
	printf("�ϲ�����б�A\n");
	mergeList_Sq1(A, B);
	showList(A);
	*/

	//�˴�������ҵ2   ����A��Bʱ�谴��������

	/*
	SqList C;
	initList_Sq(C);
	printf("�ϲ����C\n");
	mergeList_Sq2(C, A, B);
	showList(C);
	*/
	return 0;
}