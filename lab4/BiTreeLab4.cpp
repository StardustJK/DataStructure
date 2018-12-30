/*
	1.建立二叉树
	2.先序、中序、后序遍历
	3.将二叉树横向打印
	4.非递归实现遍历
*/

#include<stdio.h>
#include<stdlib.h>
#define OVERFLOW -2



//二叉树
typedef struct BiTNode {
	char data;
	BiTNode *lchild, *rchild;
}BiTNode,*BiTree;

//栈相关
typedef struct Snode {
	BiTree data;
	struct Snode *next;
}Snode, *LinkStack;

void InitLinkS(LinkStack &S) {
	S = (LinkStack)malloc(sizeof(Snode));
	S->data = NULL;
	S->next = NULL;
}

void Push_LS(LinkStack &S, BiTree e) {
	LinkStack q;
	q = (LinkStack)malloc(sizeof(Snode));
	q->data = e;
	q->next = S->next;
	S->next = q;

}
BiTree Pop_LS(LinkStack &S) {

	BiTree e = S->next->data;
	LinkStack p;
	p = S->next;
	S->next = S->next->next;
	free(p);
	return e;
}
bool IsEmptyStack(LinkStack S) {
	if (S ->next== NULL)
		return true;
	else
		return false;
}

BiTree GetTop(LinkStack S) {
	return S->next->data;
}
//先序建立树
void createBiTree(BiTree &T) {
	char a;
	scanf_s("%c", &a);
	if (a == ' ') 
		T = NULL;
	else {
		if (!(T = (BiTree)malloc(sizeof(BiTNode))))
			exit(OVERFLOW);
		T->data = a;
		createBiTree(T->lchild);
		createBiTree(T->rchild);
	}
}

//先序递归遍历
void PreOrderReTraverse(BiTree T) {
	if (T) {
		printf("%c", T->data);
		PreOrderReTraverse(T->lchild);
		PreOrderReTraverse(T->rchild);
	}
}

//中序递归遍历
void InOrderReTraverse(BiTree T) {
	if (T) {
		InOrderReTraverse(T->lchild);
		printf("%c", T->data);
		InOrderReTraverse(T->rchild);
	}
}

//后序递归遍历
void PostOrderReTraverse(BiTree T) {
	if (T) {
		PostOrderReTraverse(T->lchild);
		PostOrderReTraverse(T->rchild);
		printf("%c", T->data);
	}
}


//横向打印二叉树
//右根左
void PrintBiT(BiTree T,int i) {
	if (T) {
		PrintBiT(T->rchild,i+1);
		for (int j = 0;j < i;j++)
			printf(" |");
		printf("%c\n", T->data);
		PrintBiT(T->lchild,i+1);
	}
}

//非递归遍历
void PreTraverse(BiTree T) {
	LinkStack S;
	InitLinkS(S);
	Push_LS(S, T);
	BiTree p = NULL;
	while (!IsEmptyStack(S))
	{
		p= Pop_LS(S);
		printf("%c", p->data);
		if (p->rchild)
			Push_LS(S, p->rchild);
		if (p->lchild)
			Push_LS(S, p->lchild);

	}
}

void InTraverse(BiTree T) {
	LinkStack S;
	InitLinkS(S);
	//Push_LS(S, T);
	BiTree p = T;
	do
	{
		while (p)
		{
			Push_LS(S, p);
			p = p->lchild;
		}
		p = Pop_LS(S);
		printf("%c", p->data);
		if (p->rchild)
			p = p->rchild;
		else
			p = NULL;
	} while (!IsEmptyStack(S)||p!=NULL);
}

void PostOrder(BiTree T) {
	LinkStack S;
	InitLinkS(S);
	BiTree cur = T;
	BiTree pos = T;
	while (cur || !IsEmptyStack(S))
	{
		while (cur)
		{
			Push_LS(S, cur);
			cur = cur->lchild;
		}

		BiTree top = GetTop(S);

		if (top->rchild == NULL || top->rchild == pos)
			//top存的是当前的根节点，当top的右子树为空或者top的右子树为pos，说明右子树已经遍历过，
			//这时就可以访问当前的根节点了
		{
			printf("%c", top->data);
			pos = top;
			Pop_LS(S);
		}
		else
		{
			cur = top->rchild;
		}
	}

}



int main() {
	printf("请按照先序输入树的元素，空格表示不建立结点\n");
	BiTree T;
	createBiTree(T);
	printf("先序遍历的结果\n");
	PreOrderReTraverse(T);
	printf("\n中序遍历的结果\n");
	InOrderReTraverse(T);
	printf("\n后序遍历的结果\n");
	PostOrderReTraverse(T);
	printf("\n横向打印\n");
	PrintBiT(T,1);
	printf("\n");

	printf("非递归遍历二叉树\n");
	printf("先序遍历的结果\n");
	PreTraverse(T);
	printf("\n中序遍历的结果\n");
	InTraverse(T);
	printf("\n后序遍历的结果\n");
	PostOrder(T);
	printf("\n");



	
	return 0;
}