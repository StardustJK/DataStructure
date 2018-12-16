#pragma once
#include<stdio.h>
//树的孩子兄弟表示法child sibling
//有头结点
#define ElemType char
typedef struct CSNode{
	ElemType data;
	CSNode *firstchild;
	CSNode *rightsib;//该结点的兄弟
}CSNode,*CSTree;

void initTree(CSTree &t) {
	t = (CSTree)malloc(sizeof(CSNode));//这个结点在后面是存东西了的
	t->firstchild = NULL;
	t->rightsib =NULL;
}

void PreOrderTraverse(CSTree t) {//TODO 生成树的边集
	if (t != NULL) {
		printf("%c ", t->data);
		PreOrderTraverse(t->firstchild);
		PreOrderTraverse(t->rightsib);
	}

}

CSTree FindNode(CSTree T,ElemType e) {
	if (T == NULL)
		return NULL;
	if (T->data == e)
		return T;
	//左子树查找
	CSTree curNode = FindNode(T->firstchild, e);
	if (curNode != NULL)
		return curNode;
	else
		return FindNode(T->rightsib, e);
}