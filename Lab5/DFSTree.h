/*
DFS������
*/


#pragma once
#include"GraphAdjacencyList.h"
#include"CSTree.h"
//Ҫ��ʼ��visitedŶ(ִ����֮ǰ
void DFSTree(ALGraph G, int v, CSTree &T) {
	visited[v] = true;;
	CSTree q=T;//��qȥ����T�������������������ָ��
	bool first = true;//��һ��δ�����ʵ��ڽӶ���
	for (int w = FirstAdjVex(G, v);w >= 0;w = NextAdjVex(G, v, w)) {
		if (!visited[w]) {
			CSTree p = (CSTree)malloc(sizeof(CSNode));
			p->data = GetVex(G, w);
			p->firstchild = NULL;
			p->rightsib = NULL;
			if (first) {
				q->firstchild = p;
				first = false;//���first�ǻ������forѭ���������õģ�����������ı�first
			}
			else {
				q->rightsib = p;
			}
			q = p;
			DFSTree(G, w, q);
		}

	}
}
void CreateDFSTree(ALGraph G) {
	printf("�����������㣺\n");
	CSTree T;
	initTree(T);
	ElemType v;
	scanf_s("%c", &v);
	getchar();
	T->data = v;
	v = LocateVex(G, v);
	for (int i = 0;i < G.vexnum;i++) {
		visited[i] = 0;
	}
	DFSTree(G, v, T);
	printf("DFS���������������Ϊ��\n");
	PreOrderTraverse(T);
}