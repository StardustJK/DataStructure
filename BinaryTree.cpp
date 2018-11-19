/*
	������
	�ݹ���������
	����Ҷ�ӵ���Ŀ
	�����������
*/


#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define ElemType char
#define OVERFLOW -2

int leaves = 0;
int flag = 0;

typedef struct BiTNode {
	ElemType data;
	struct BiTNode *lchild, *rchild;
}BiTNode,*BiTree;


//����������,���ҵõ�Ҷ�ӵ�����
void CreateBiTree(BiTree& T) {
	ElemType ch;
	scanf_s("%c", &ch,1);
	//getchar();
	if (ch == '0')
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
	printf("%c\n", e);
	return 1;
}
void PreOrderTraverse(BiTree T){
	if (T) {
		if (!T->lchild && !T->rchild) {
			leaves++;
		}
		
		PrintElement(T->data);
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);

	}
	
}

//�õ����
void getdepth(BiTree T, int depth) {
	if (!T)
		return;
	else
	{
		if (depth > flag)
			flag = depth;
		if (T->lchild != NULL)
			getdepth(T->lchild, depth + 1);
		if (T->rchild != NULL)
			getdepth(T->rchild, depth + 1);
	}

}



int main() {
	printf("��������\nû�����ӻ���û���Һ��Ӷ�Ҫ�ֱ�����һ��0\n");
	BiTree T;
	CreateBiTree(T);
	printf("��������Ϊ������\n");
	PreOrderTraverse(T);
	printf("leaves:%d\n", leaves);
	getdepth(T, 1);
	printf("depth:%d\n", flag);
	return 0;
}
