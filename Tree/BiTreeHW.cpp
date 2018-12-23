/*
1.ͳ�ƶ��������ĸ���
2.����ÿ��������������������
3.��������������������ǰ�����ͺ������
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define ElemType char
#define OVERFLOW -2

int leaves = 0;

typedef struct BiTNode {
	ElemType data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

//����������
void CreateBiTree(BiTree& T) {
	ElemType ch;
	scanf_s("%c", &ch, 1);
	if (ch == ' ')
		T = NULL;
	else {
		if (!(T = (BiTree)malloc(sizeof(BiTNode))))
			exit(OVERFLOW);
		T->data = ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
}

int PrintElement(ElemType e) {
	printf("%c", e);
	return 1;
}
//ͳ��Ҷ�ӵ�����
void PreOrderTraverse(BiTree T) {
	if (T) {
		if (!T->lchild && !T->rchild) {
			leaves++;
		}
		PrintElement(T->data);
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);

	}

}
//����ÿ��������������������
void changeTree(BiTree & T) {
	if (T != NULL) {
		BiTree temp;
		temp = T->lchild;
		T->lchild = T->rchild;
		T->rchild = temp;
		changeTree(T->lchild);
		changeTree(T->rchild);
	}
}
//����α����
//��ǰ��,���������ұ�
BiThrNode *prenode(BiThrNode *p){
    if(p->Ltag)
        return p->lchild;
    else
        pre=p->lchild;
    while(!pre->Rtag){//ֱ��û���Һ���
        pre=pre->rchild;
    }
    return pre;
}
//�Һ�̣������������
BiThrNode *nextnode(BiThrNode *p){
    if(p->Rtag)
        return p->rchild;
    else
        next=p->rchild;
        while(!next->Ltag){//ֱ��û������
            next=next->lchild;
        }
    return next;
}
int main() {
	printf("��������\nû�����ӻ���û���Һ��Ӷ�Ҫ�ֱ�����һ���ո�\n");
	BiTree T;
	CreateBiTree(T);
	printf("��������Ϊ������\n");
	PreOrderTraverse(T);
	printf("leaves:%d\n", leaves);
	printf("\n�ı�ÿ��������������������\n");
	changeTree(T);
	PreOrderTraverse(T);
	return 0;
}
