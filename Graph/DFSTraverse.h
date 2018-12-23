#pragma once
/*
深度优先遍历
*/
#include "GraphAdjacencyList.h"

bool visited[MAX_VERTEX_NUM];

int FirstAdjVex(ALGraph G, int v) {
	if (!G.vertices[v].firstarc)
		return 0;
	else
		return (G.vertices[v].firstarc->adjvex);
}
int NextAdjVex(ALGraph G, int v, int w) {
	ArcNode *p;
	p = G.vertices[v].firstarc;
	while (p&&p->adjvex != w)//找到w
		p = p->next;
	if (p->adjvex == w && p->next)
		return p->next->adjvex;//找到了w且存在邻接点
	else
		return 0;

}
void DFS(ALGraph G, int v) {
	visited[v] = true;
	printf("%c ", G.vertices[v].data);
	for (int w = FirstAdjVex(G, v);w > 0;w = NextAdjVex(G, v, w)) {
		if (!visited[w])
			DFS(G, w);
	}
}
void DFSTraverse(ALGraph G) {
	//初始化visited
	for (int i = 0;i < G.vexnum;i++) {
		visited[i] = false;
	}
	for (int v = 0;v < G.vexnum;v++) {
		if (!visited[v]) {
			DFS(G, v);
		}
	}
}


