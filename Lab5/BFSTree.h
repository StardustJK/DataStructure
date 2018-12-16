/*
BFS生成树
*/
#pragma once
#include"CSTree.h"
#include"GraphAdjacencyList.h"
#include"Queue.h"
void BFSTree(ALGraph G, int v, CSTree &T) {
	CSTree q = T;
	LinkQueue Q;
	init_Queue(Q);
	//根节点入队
	EnQueue(Q, v);
	while(!isEmpty(Q))
	{
		bool first = true;
		ElemType data=DeQueue(Q);
		q = FindNode(T, data);
		int v = LocateVex(G, q->data);
		visited[v] = true;
		for (int w = FirstAdjVex(G, v);w > 0;w = NextAdjVex(G, v, w)) {
			if (!visited[w]) {
				CSTree p = (CSTree)malloc(sizeof(CSNode));
				p->data = GetVex(G, w);
				p->firstchild = NULL;
				p->rightsib = NULL;

				EnQueue(Q, p->data);
				visited[w] = true;
				if (first) {
					printf("%c", p->data);
					q->firstchild = p;
					first = false;
				}
				else {
					printf("%c", p->data);
					q->rightsib = p;
				}
				q = p;
			}
		}
	}
}

void CreateBFSTree(ALGraph G) {
	printf("请输入起点\n");
	CSTree T;
	initTree(T);
	ElemType v;
	scanf_s("%c", &v);
	getchar();
//	v = LocateVex(G, v);
	for (int i = 0;i < G.vexnum;i++) {
		visited[i] = 0;
	}
	T->data = v;
	BFSTree(G, v, T);
	printf("DFS生成树的先序遍历为：\n");
	PreOrderTraverse(T);
}