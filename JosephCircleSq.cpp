#include<stdio.h>
#include<stdlib.h>

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef struct SqL {
	int *number;
	int *psw;
	int length;
	int listsize;
}SqL;

void init_Sq(SqL &L){
	L.number = (int *)malloc(LIST_INIT_SIZE * sizeof(int));
	L.psw = (int *)malloc(LIST_INIT_SIZE * sizeof(int));
	if (!L.number || !L.psw) {
		printf("overflow\n");
	}
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
}

void creat_Sq(SqL &L) {
	printf("请输入n的值：\n");
	int n;
	scanf_s("%d", &n);
	getchar();
	for (int i = 0;i <n;i++) {
		L.number[i] = i + 1;
		printf("请输入密码\n");
		scanf_s("%d", &L.psw[i]);
		L.length++;
	}

}
int getLocte(SqL L,int number) {
	for (int i = 0;i < L.length;i++) {
		if (number == L.number[i])
			return i+1;
	}
}
 int delete_Sq(SqL &L,int i) {
	 if (L.length == 1) {
		 exit(0);
		}


	else {
		int psw = L.psw[i-1];
		int number = L.number[i - 1];
		printf("%d\n",number);
		int loc = getLocte(L, number);
		for (int j = i - 1;j < L.length - 1;j++) {
			L.number[j] = L.number[j + 1];
			L.psw[j] = L.psw[j + 1];
		}
		L.length--;
		if ((psw%L.length) > (L.length +1-loc))//需要跨越列表最后一个元素
			return (psw%L.length) - (L.length+1 -loc);
		else                                  //不需要跨越列表最后一个元素
			return (psw % L.length)+loc-1;
	}

}
void show_Sq(SqL &L) {
	for (int j = 0;j < L.length;j++) {
		printf("编号：%d  ", L.number[j]);
		printf("密码：%d\n", L.psw[j]);
	}
}
void result(SqL &L, int m) {
	if (L.length == 1) {
		printf("%d\n", L.number[0]);
	}
	else
		result(L, delete_Sq(L, m));
}
int main() {
	SqL L;
	int m;
	init_Sq(L);
	creat_Sq(L);
	show_Sq(L);
	printf("请输入初始值m\n");
	scanf_s("%d", &m);
	printf("结果为：\n");
	result(L, m%L.length);
	getchar();

}