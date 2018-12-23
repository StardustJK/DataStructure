/*
	二叉树
	递归的先序遍历
	计算叶子的数目
	计算树的深度
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


//先序生成树,并且得到叶子的数量
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

//得到深度
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
	printf("先序输入\n没有左孩子或者没有右孩子都要分别输入一个0\n");
	BiTree T;
	CreateBiTree(T);
	printf("创建的树为（先序）\n");
	PreOrderTraverse(T);
	printf("leaves:%d\n", leaves);
	getdepth(T, 1);
	printf("depth:%d\n", flag);
	return 0;
}
