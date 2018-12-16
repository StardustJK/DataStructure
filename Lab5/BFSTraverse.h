#pragma once
/*
广度优先遍历
*/
#include "Queue.h"
#include "GraphAdjacencyList.h"
#include "DFSTraverse.h"
Arc BSet[MAX_VERTEX_NUM];
int b=0;
void BFSTraverse(ALGraph G) {
	printf("\n广度优先遍历\n");
	for (int i = 0;i < G.vexnum;i++) {
		visited[i] = false;
	}
	LinkQueue Q;
	init_Queue(Q);
	for (int v = 0;v < G.vexnum;v++) {
		if (!visited[v]) {
			visited[v] = true;
			printf("%c ", G.vertices[v].data);
			EnQueue(Q, v);
			while (!isEmpty(Q))
			{
				int u = DeQueue(Q);
				for (int w = FirstAdjVex(G, u);w > 0;w = NextAdjVex(G, u, w)) {
					if (!visited[w]) {
						visited[w] = true;
						printf("%c ", G.vertices[w].data);
						EnQueue(Q, w);
						BSet[b].start = u;
						BSet[b].end = w;
						b++;
					}
				}
			}
		}
	}
}

void PrintBFSTree(ALGraph G) {

	printf("\n广度优先遍历生成树的边集：\n");
	for (int i = 0;i < G.vexnum - 1;i++) {
		printf("[%c,%c]  ", GetVex(G, BSet[i].start), GetVex(G, BSet[i].end));
	}
}