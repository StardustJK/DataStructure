/*
DFS生成树
*/


#pragma once
#include"GraphAdjacencyList.h"
#include"CSTree.h"
//要初始化visited哦(执行它之前
void DFSTree(ALGraph G, int v, CSTree &T) {
	visited[v] = true;;
	CSTree q=T;//用q去遍历T不会打乱最终生成树的指针
	bool first = true;//第一个未被访问的邻接顶点
	for (int w = FirstAdjVex(G, v);w >= 0;w = NextAdjVex(G, v, w)) {
		if (!visited[w]) {
			CSTree p = (CSTree)malloc(sizeof(CSNode));
			p->data = GetVex(G, w);
			p->firstchild = NULL;
			p->rightsib = NULL;
			if (first) {
				q->firstchild = p;
				first = false;//这个first是会在这个for循环里面运用的，就这种情况改变first
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
	printf("请输入遍历起点：\n");
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
	printf("DFS生成树的先序遍历为：\n");
	PreOrderTraverse(T);
}