#pragma once
/*
ɾ�������������ϵĽ��
*/

#include"BinarySortTree.h"


void Delete(BiTree &p) {
	if (p->rchild == NULL) {//�Һ���Ϊ�յ����
		BiTree q = p;
		p = p->lchild;
		free(q);
	}
	else if (p->lchild == NULL) {//����Ϊ��
		BiTree q = p;
		p = p->rchild;
		free(q);
	}
	else {//���Ҷ��к���
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
		printf("\n�����ڹؼ���Ϊ%d�Ľ��\n",key);
		return;
	}//�����ڹؼ���Ϊkey��
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
