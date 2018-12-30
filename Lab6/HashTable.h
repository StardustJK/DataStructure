#pragma once
//哈希表相关
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#define KeyType  char*
#define TABLESIZE 50

int hashsize[] = { 41,43,53 };
int all = 0;//记录平均查找
typedef struct ElemType {
	char key[15] = " ";
};
typedef struct {
	ElemType *elem;
	int count;//当前元素个数
	int sizeindex;//当前容量
}HashTable;

void initHash(HashTable *H) {
	all = 0;
	(*H).count = 0;
	(*H).sizeindex = 0;
	int m = hashsize[0];
	(*H).elem = (ElemType*)malloc(sizeof(ElemType)*hashsize[0]);
	for (int i = 0;i < m;i++) {
		strcpy_s((*H).elem[i].key, " ");
	}


	if (!(*H).elem) {
		printf("overflow\n");
	}

}

//取第一个字母,倒数第二个和最后一个字母对应的ASCII码相加再取余
int Hash(KeyType key) {
	int f, s, t;
	f = key[0];
	s = key[strlen(key) - 2];
	t = key[strlen(key) - 3];
	return (f + s + t) % 41;

}

//冲突处理方式1
int collision(int add, int count) {
	return (add + count) % TABLESIZE;

}
int d2[] = { 1,-1,4,-4,9,-9,16,-16,25,-25 };
int collision2(int add, int count) {
	return(add + d2[count - 1]) % TABLESIZE;
}

int collision3(int add, int count) {
	srand(time(NULL));
	//printf("%d\n", (add + rand())% TABLESIZE);
	return (add + rand()) % TABLESIZE;
}
void insertHash(HashTable *H, KeyType key) {
	int countnow = 1;
	int p = Hash(key);
	if (strcmp((*H).elem[p].key, " ") == 0) {
		strcpy_s((*H).elem[p].key, key);
	}
	else {
		p = collision(p, countnow);
		countnow++;
		while (strcmp((*H).elem[p].key, " ") != 0) {
			p = collision(p, countnow);
			countnow++;
		}
		strcpy_s((*H).elem[p].key, key);

	}
	H->count++;
	all = all + countnow;
	printf("%d ", countnow);

}
void searchHash(HashTable H, KeyType key) {
	int count = 1;
	int p;
	p = Hash(key);
	if (strcmp(H.elem[p].key, key) == 0) {
		printf("成功找到,地址：%d\n", p + 1);
		return;
	}
	while (strcmp(H.elem[p].key, " ") != 0 && (strcmp(H.elem[p].key, key) != 0)) {
		p = collision(p, count);

		count++;
	}
	if (strcmp(H.elem[p].key, key) == 0) {
		printf("成功找到,地址：%d\n", p);
		return;
	}
	else {
		printf("查找失败，不存在\n");
	}

}

void showTable(HashTable H) {
	for (int i = 0;i < hashsize[H.sizeindex];i++) {
		printf("%d.%s\n", i + 1, H.elem[i].key);
	}
}



