#pragma once
/*
������ȱ���
*/
#include "GraphAdjacencyList.h"
#include"Stack.h"
Arc DSet[MAX_VERTEX_NUM];
int d;

//�ݹ��㷨
void DFS(ALGraph G, int v) {
	visited[v] = true;
	printf("%c ", G.vertices[v].data);
	for (int w = FirstAdjVex(G, v);w >= 0;w = NextAdjVex(G, v, w)) {
		if (!visited[w]) {
			DSet[d].start = v;
			DSet[d].end = w;
			d++;
			DFS(G, w);
		}
	}
}
void DFSTraverse(ALGraph G) {
	printf("\n�ݹ��㷨������ȱ���\n");
	d = 0;
	//��ʼ��visited
	for (int i = 0;i < G.vexnum;i++) {
		visited[i] = false;
	}
	for (int v = 0;v < G.vexnum;v++) {
		if (!visited[v]) {
			DFS(G, v);
		}
	}
}
void PrintDFSTree(ALGraph G) {
	printf("\n������ȱ����������ı߼���\n");
	for (int i = 0;i < G.vexnum-1;i++) {
		printf("[%c,%c]  ", GetVex(G, DSet[i].start), GetVex(G, DSet[i].end));
	}
}
//����ջ�ķǵݹ��㷨

void DFSStack(ALGraph G,char r) {
	for (int i = 0;i < G.vexnum;i++) {
		visited[i] = 0;
	}
	int v;
	LinkStack S;
	InitLinkS(S);
	v = LocateVex(G, r);
	Push_LS(S, v);
	visited[v] = true;
	ArcNode *p;
	p = G.vertices[v].firstarc;
	printf("\n����ջ��������ȱ���\n");
	printf("%c ", GetVex(G, v));
	while (!isEmpty(S))
	{
		p = G.vertices[getTop(S)].firstarc;
		while (p) {
			if (!visited[p->adjvex]) {
				visited[p->adjvex] = 1;
				printf("%c ", G.vertices[p->adjvex].data);
				Push_LS(S, p->adjvex);
				p = G.vertices[p->adjvex].firstarc;
			}
			else
				p = p->next;
		}
		if (p == NULL) {
			Pop_LS(S);
		}

	}
}
