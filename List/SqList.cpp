// SqList.cpp: 定义控制台应用程序的入口点。
//

#include <stdio.h>
#include<stdlib.h>

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

//deletion
Status ListDele_Sq(SqList &L, int i, ElemType &e) {
	if (i<1 || i>L.length)
		return ERROR;
	ElemType*p = &L.elem[i-1];
	e = *p;
	ElemType*q = &L.elem[L.length - 1];
	for (;p<=q;p++) {
		*p = *(p + 1);
	}
	L.length--;
	return OK;
}
void showList(SqList L) {
	ElemType* p = &L.elem[0];
	ElemType *q = &L.elem[L.length - 1];
	for (;p <= q;p++) {
		printf("%d  ",*p);
	}
	printf("\n");
}

int LocateElem_Sq(SqList L, ElemType e) {
	ElemType *p = &L.elem[0];
	for (int i = 1;i <=L.length;i++) {
		if (*p == e)
			return i;
		p++;
	}
	return 0;
}
int main()
{
	SqList A;
	int i;
	ElemType a;
	printf("创建列表\n");
	initList_Sq(A);
	for (int j = 0;j < 5;j++) {
		ListInsertion_Sq(A, j+1, j);
	}
	showList(A);
	printf("在第i个位置插入值：请输入i和对应的值\n");
	scanf_s("%d%d", &i, &a);
	ListInsertion_Sq(A, i, a);
	printf("插入操作后的列表：\n");
	showList(A);
	printf("删除在第i个位置的元素,请输入i\n");
	scanf_s("%d", &i);
	ListDele_Sq(A, i, a);
	printf("删除的值为：%d\n", a);
	printf("删除操作后的列表为：\n");
	showList(A);
	printf("查找出现a元素的第一个位置，请输入a\n");
	scanf_s("%d", &a);
	ElemType b;
	b=LocateElem_Sq(A, a);
	if (b)
		printf("出现a元素的第一个位置为%d\n", b);
	else
		printf("元素不存在\n");
    return 0;
}

