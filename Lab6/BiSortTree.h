#pragma once
//二叉排序树的建立、遍历
#include"BiTree.h"
void createBST(BiTree &T,int a[]) {//a[0]放长度
	initTree(T);
	BiTree p = T;
	p->data = a[1];
	//插入结点
	for (int i = 2;i <= a[0];i++) {
		p = T;
		BiTree s = (BiTree)malloc(sizeof(BiNode));
		s->data = a[i];
		s->lchild = NULL;
		s->rchild = NULL;
		while (p) {
			if (a[i] <= p->data) {
				if (p->lchild) {//p有左孩子的时候
					p = p->lchild;
				}
				else {//p左孩子为空
					p->lchild = s;
					break;
				}
			}
			else {//a[i]的值比p->data大
				if (p->rchild) {
					p = p->rchild;
				}
				else {
					p->rchild = s;
					break;
				}
			}
		}

	}
}
void insertBST(BiTree &T, ElemType a) {
	BiTree p = T;
	BiTree s = (BiTree)malloc(sizeof(BiNode));
	s->data = a;
	s->lchild = NULL;
	s->rchild = NULL;
	while (p) {
		if (a <= p->data) {
			if (p->lchild) {//p有左孩子的时候
				p = p->lchild;
			}
			else {//p左孩子为空
				p->lchild = s;
				break;
			}
		}
		else {//a[i]的值比p->data大
			if (p->rchild) {
				p = p->rchild;
			}
			else {
				p->rchild = s;
				break;
			}
		}
	}
}
BiTree searchBST(BiTree T,ElemType key,int length) {
	BiTree p = T;
	if (p == NULL) {
		printf("不存在%d\n",key);
		return NULL;
	}
	if (p->data == key) {
		printf("成功查找到%d，已返回树结点,查找长度为：%d\n",key, length);
		return p;
	}
	if (key < p->data) {
		searchBST(p->lchild, key, length + 1);
	}
	else {
		searchBST(p->rchild, key, length + 1);
	}
}


/*
删除二叉排序树上的结点
*/

void Delete(BiTree &p) {
	if (p->rchild == NULL) {//右孩子为空的情况
		BiTree q = p;
		p = p->lchild;
		free(q);
	}
	else if (p->lchild == NULL) {//左孩子为空
		BiTree q = p;
		p = p->rchild;
		free(q);
	}
	else {//左右都有孩子
		BiTree q = p;
		BiTree s = p->lchild;
		while (s->rchild != NULL) {
			q = s;
			s = s->rchild;
		}
		p->data = s->data;
		if (q != p) {
			q->rchild = s->lchild;
		}
		else {
			p->lchild = s->lchild;
			free(s);
		}

	}

}
void DeleteBST(BiTree &T, ElemType key) {
	if (!T) {
		printf("\n不存在关键字为%d的结点\n", key);
		return;
	}//不存在关键字为key的
	else {
		if (T->data == key) {
			Delete(T);
		}
		else if (T->data > key) {
			DeleteBST(T->lchild, key);
		}
		else {
			DeleteBST(T->rchild, key);
		}

	}
}


//横向打印
void PrintBiT(BiTree T, int i) {
	if (T) {
		PrintBiT(T->rchild, i + 1);
		for (int j = 0;j < i;j++)
			printf(" |");
		printf("%d\n", T->data);
		PrintBiT(T->lchild, i + 1);
	}
}