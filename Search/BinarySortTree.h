#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"SSTable.h"
#define OVERFLOW -2


typedef struct BiTNode {
	KeyType data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;
void initBiTree(BiTree &T) {
	T = (BiTree)malloc(sizeof(BiTNode));
	T->lchild = NULL;
	T->rchild = NULL;
}

//创建排序树
void CreateBiSortTree(BiTree& T,int a[]) {//a[0]存长度
	T->data = a[1];
	BiTNode *p = T;
	for (int i = 2;i < a[0];i++) {
		p = T;
		BiTNode *s = (BiTNode *)malloc(sizeof(BiTNode));
		s->data = a[i];
		s->lchild = NULL;
		s->rchild = NULL;
		while (p) {
			if (a[i] <= p->data) {
				if(p->lchild)
					p = p->lchild;
				else {
					p->lchild = s;
					break;
				}
			}
			else {
				if(p->rchild)
					p = p->rchild;
				else {
					p->rchild = s;
					break;
				}
			}
		}
	}
}


void InOrderTraverse(BiTree T) {
	if (T) {
		InOrderTraverse(T->lchild);
		printf("%d ", T->data);
		InOrderTraverse(T->rchild);
	}
}


BiTree SearchBST(BiTree T, KeyType e) {
	if (!T || e == T->data) {
		return T;
	}
	else if (e <= T->data) {
		return SearchBST(T->lchild, e);
	}
	else
		return SearchBST(T->rchild, e);
}



