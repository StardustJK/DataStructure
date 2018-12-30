#pragma once
#include<stdlib.h>
#include<stdio.h>
#define ElemType int


//����������
typedef struct BiNode{
	ElemType data;
	struct BiNode *lchild,*rchild;
}Binode, *BiTree;

void initTree(BiTree &T) {
	T = (BiTree)malloc(sizeof(BiNode));
	T->lchild = NULL;
	T->rchild = NULL;
}

//�������
void inOrderTraverse(BiTree T) {
	if (!T)
		return;
	inOrderTraverse(T->lchild);
	printf("%d ", T->data);
	inOrderTraverse(T->rchild);
}
