/*
	作业1：LA=LA U LB  A,B无序
	作业2：LC=LA U LB  其中A,B为升序，要求C是非降序

*/

#include<stdio.h>
#include<stdlib.h>

//列表的创造及基本操作函数
#define ERROR -1
#define OK 1
#define OVERFLOW -2
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define ElemType int 
#define Status int

typedef struct {
	ElemType *elem;
	int length;//当前长度
	int listsize;//容量
}SqList;


//init SqList
Status initList_Sq(SqList &L) {
	L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));//给elem划空间
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
	if (L.length >= L.listsize) {//当前空间已满
		ElemType *newbase;
		newbase = (ElemType*)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
		if (!newbase)
			exit(OVERFLOW);
		L.elem = newbase;
		L.listsize = L.listsize + LISTINCREMENT;
	}
	ElemType* q = &(L.elem[i - 1]);//这里用指针相当于是数组的操作，所以要-1
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

//LA=LA U LB  A,B无序
void mergeList_Sq1(SqList &A, SqList B) {
	for (int i = 0;i < B.length;i++) {
		int j = 0;
		while((A.elem[j]!=B.elem[i])&&(j<A.length)){
			j++;
		}
		if (j >=A.length) {//说明遍历完了都没有一样的
			ListInsertion_Sq(A, A.length+1, B.elem[i]);
		}
	}
}

//LC = LA U LB  其中A, B为升序，要求C是非降序
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
	//剩余的加入C

	//A遍历完了 B还没完
	if ((i >= A.length) &&(j<B.length)){
		for (;j<B.length;j++) {
			ListInsertion_Sq(C, k, B.elem[j]);
			k++;
		}
	}
	//B遍历完了 A还没完
	if ((j>= B.length ) && (i<A.length) ){
		for (;i<A.length;i++) {
			ListInsertion_Sq(C, k, A.elem[i]);
			k++;
		}
	}
	

}
int main() {


	//创造列表A,B
	SqList A, B;
	initList_Sq(A);
	initList_Sq(B);
	ElemType e;
	int i;
	printf("请输入A的长度i 以及A的元素\n");
	scanf_s("%d",&i);
	for (int j = 0;j < i;j++) {
		scanf_s("%d", &e);
		ListInsertion_Sq(A, j + 1, e);
	}
	showList(A);
	printf("请输入B的长度i 以及B的元素\n");
	scanf_s("%d", &i);
	for (int j = 0;j < i;j++) {
		scanf_s("%d", &e);
		ListInsertion_Sq(B, j + 1, e);
	}
	showList(B);
	

	//此处测试作业1

	/*
	printf("合并后的列表A\n");
	mergeList_Sq1(A, B);
	showList(A);
	*/

	//此处测试作业2   输入A，B时需按升序输入

	/*
	SqList C;
	initList_Sq(C);
	printf("合并后的C\n");
	mergeList_Sq2(C, A, B);
	showList(C);
	*/
	return 0;
}