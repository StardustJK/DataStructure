/*
1.统计二叉树结点的个数
2.交换每个结点的左子树和右子树
3.在中序线索二叉树中求前驱结点和后驱结点
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

//先序生成树
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
//统计叶子的数量
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
//交换每个结点的左子树和右子树
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
//这是伪代码
//找前驱,左子树最右边
BiThrNode *prenode(BiThrNode *p){
    if(p->Ltag)
        return p->lchild;
    else
        pre=p->lchild;
    while(!pre->Rtag){//直到没有右孩子
        pre=pre->rchild;
    }
    return pre;
}
//找后继，右子树最左边
BiThrNode *nextnode(BiThrNode *p){
    if(p->Rtag)
        return p->rchild;
    else
        next=p->rchild;
        while(!next->Ltag){//直到没有左孩子
            next=next->lchild;
        }
    return next;
}
int main() {
	printf("先序输入\n没有左孩子或者没有右孩子都要分别输入一个空格\n");
	BiTree T;
	CreateBiTree(T);
	printf("创建的树为（先序）\n");
	PreOrderTraverse(T);
	printf("leaves:%d\n", leaves);
	printf("\n改变每个结点的左子树和右子树\n");
	changeTree(T);
	PreOrderTraverse(T);
	return 0;
}
