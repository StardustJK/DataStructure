#pragma once
/*
广度优先遍历
*/
#include "Queue.h"
#include "GraphAdjacencyList.h"
#include "DFSTraverse.h"
//extern bool visited[MAX_VERTEX_NUM];
void BFSTraverse(ALGraph G) {
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
					}
				}
			}
		}
	}
}