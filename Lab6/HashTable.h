#pragma once
//��ϣ�����
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#define KeyType  char*
#define TABLESIZE 50

int hashsize[] = { 41,43,53 };
int all = 0;//��¼ƽ������
typedef struct ElemType {
	char key[15] = " ";
};
typedef struct {
	ElemType *elem;
	int count;//��ǰԪ�ظ���
	int sizeindex;//��ǰ����
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

//ȡ��һ����ĸ,�����ڶ��������һ����ĸ��Ӧ��ASCII�������ȡ��
int Hash(KeyType key) {
	int f, s, t;
	f = key[0];
	s = key[strlen(key) - 2];
	t = key[strlen(key) - 3];
	return (f + s + t) % 41;

}

//��ͻ����ʽ1
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
		printf("�ɹ��ҵ�,��ַ��%d\n", p + 1);
		return;
	}
	while (strcmp(H.elem[p].key, " ") != 0 && (strcmp(H.elem[p].key, key) != 0)) {
		p = collision(p, count);

		count++;
	}
	if (strcmp(H.elem[p].key, key) == 0) {
		printf("�ɹ��ҵ�,��ַ��%d\n", p);
		return;
	}
	else {
		printf("����ʧ�ܣ�������\n");
	}

}

void showTable(HashTable H) {
	for (int i = 0;i < hashsize[H.sizeindex];i++) {
		printf("%d.%s\n", i + 1, H.elem[i].key);
	}
}



