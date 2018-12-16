#pragma once
#include<stdio.h>
//���ĺ����ֵܱ�ʾ��child sibling
//��ͷ���
#define ElemType char
typedef struct CSNode{
	ElemType data;
	CSNode *firstchild;
	CSNode *rightsib;//�ý����ֵ�
}CSNode,*CSTree;

void initTree(CSTree &t) {
	t = (CSTree)malloc(sizeof(CSNode));//�������ں����Ǵ涫���˵�
	t->firstchild = NULL;
	t->rightsib =NULL;
}

void PreOrderTraverse(CSTree t) {//TODO �������ı߼�
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
	//����������
	CSTree curNode = FindNode(T->firstchild, e);
	if (curNode != NULL)
		return curNode;
	else
		return FindNode(T->rightsib, e);
}