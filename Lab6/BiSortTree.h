#pragma once
//�����������Ľ���������
#include"BiTree.h"
void createBST(BiTree &T,int a[]) {//a[0]�ų���
	initTree(T);
	BiTree p = T;
	p->data = a[1];
	//������
	for (int i = 2;i <= a[0];i++) {
		p = T;
		BiTree s = (BiTree)malloc(sizeof(BiNode));
		s->data = a[i];
		s->lchild = NULL;
		s->rchild = NULL;
		while (p) {
			if (a[i] <= p->data) {
				if (p->lchild) {//p�����ӵ�ʱ��
					p = p->lchild;
				}
				else {//p����Ϊ��
					p->lchild = s;
					break;
				}
			}
			else {//a[i]��ֵ��p->data��
				if (p->rchild) {
					p = p->rchild;
				}
				else {
					p->rchild = s;
					break;
				}
			}
		}

	}
}
void insertBST(BiTree &T, ElemType a) {
	BiTree p = T;
	BiTree s = (BiTree)malloc(sizeof(BiNode));
	s->data = a;
	s->lchild = NULL;
	s->rchild = NULL;
	while (p) {
		if (a <= p->data) {
			if (p->lchild) {//p�����ӵ�ʱ��
				p = p->lchild;
			}
			else {//p����Ϊ��
				p->lchild = s;
				break;
			}
		}
		else {//a[i]��ֵ��p->data��
			if (p->rchild) {
				p = p->rchild;
			}
			else {
				p->rchild = s;
				break;
			}
		}
	}
}
BiTree searchBST(BiTree T,ElemType key,int length) {
	BiTree p = T;
	if (p == NULL) {
		printf("������%d\n",key);
		return NULL;
	}
	if (p->data == key) {
		printf("�ɹ����ҵ�%d���ѷ��������,���ҳ���Ϊ��%d\n",key, length);
		return p;
	}
	if (key < p->data) {
		searchBST(p->lchild, key, length + 1);
	}
	else {
		searchBST(p->rchild, key, length + 1);
	}
}


/*
ɾ�������������ϵĽ��
*/

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
void DeleteBST(BiTree &T, ElemType key) {
	if (!T) {
		printf("\n�����ڹؼ���Ϊ%d�Ľ��\n", key);
		return;
	}//�����ڹؼ���Ϊkey��
	else {
		if (T->data == key) {
			Delete(T);
		}
		else if (T->data > key) {
			DeleteBST(T->lchild, key);
		}
		else {
			DeleteBST(T->rchild, key);
		}

	}
}


//�����ӡ
void PrintBiT(BiTree T, int i) {
	if (T) {
		PrintBiT(T->rchild, i + 1);
		for (int j = 0;j < i;j++)
			printf(" |");
		printf("%d\n", T->data);
		PrintBiT(T->lchild, i + 1);
	}
}