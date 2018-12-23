#pragma once
/*
删除二叉排序树上的结点
*/

#include"BinarySortTree.h"


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
void DeleteBST(BiTree &T, KeyType key) {
	if (!T) {
		printf("\n不存在关键字为%d的结点\n",key);
		return;
	}//不存在关键字为key的
	else {
		if (T->data == key) {
			Delete(T);
		}
		else if(T->data > key){
			DeleteBST(T->lchild, key);
		}
		else {
			DeleteBST(T->rchild, key);
		}
		
	}
}
