/*
	1.����������
	2.�������򡢺������
	3.�������������ӡ
	4.�ǵݹ�ʵ�ֱ���
*/

#include<stdio.h>
#include<stdlib.h>
#define OVERFLOW -2



//������
typedef struct BiTNode {
	char data;
	BiTNode *lchild, *rchild;
}BiTNode,*BiTree;

//ջ���
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
//��������
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

//����ݹ����
void PreOrderReTraverse(BiTree T) {
	if (T) {
		printf("%c", T->data);
		PreOrderReTraverse(T->lchild);
		PreOrderReTraverse(T->rchild);
	}
}

//����ݹ����
void InOrderReTraverse(BiTree T) {
	if (T) {
		InOrderReTraverse(T->lchild);
		printf("%c", T->data);
		InOrderReTraverse(T->rchild);
	}
}

//����ݹ����
void PostOrderReTraverse(BiTree T) {
	if (T) {
		PostOrderReTraverse(T->lchild);
		PostOrderReTraverse(T->rchild);
		printf("%c", T->data);
	}
}


//�����ӡ������
//�Ҹ���
void PrintBiT(BiTree T,int i) {
	if (T) {
		PrintBiT(T->rchild,i+1);
		for (int j = 0;j < i;j++)
			printf(" |");
		printf("%c\n", T->data);
		PrintBiT(T->lchild,i+1);
	}
}

//�ǵݹ����
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
			//top����ǵ�ǰ�ĸ��ڵ㣬��top��������Ϊ�ջ���top��������Ϊpos��˵���������Ѿ���������
			//��ʱ�Ϳ��Է��ʵ�ǰ�ĸ��ڵ���
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
	printf("�밴��������������Ԫ�أ��ո��ʾ���������\n");
	BiTree T;
	createBiTree(T);
	printf("��������Ľ��\n");
	PreOrderReTraverse(T);
	printf("\n��������Ľ��\n");
	InOrderReTraverse(T);
	printf("\n��������Ľ��\n");
	PostOrderReTraverse(T);
	printf("\n�����ӡ\n");
	PrintBiT(T,1);
	printf("\n");

	printf("�ǵݹ����������\n");
	printf("��������Ľ��\n");
	PreTraverse(T);
	printf("\n��������Ľ��\n");
	InTraverse(T);
	printf("\n��������Ľ��\n");
	PostOrder(T);
	printf("\n");



	
	return 0;
}