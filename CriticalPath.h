#pragma once
#include"GraphAdjacencyList.h"
#include"Topsort.h"

void CriticalPath(ALGraph G) {
	int i, j, k, e, l;
	int *ve, *vl;
	int *topo=Topsort(G);
	ArcNode *p;
	if (!topo) {
		printf("图有环，没有关键路径\n");
		return;
	}
	ve = (int *)malloc(sizeof(int)*G.vexnum);
	vl = (int *)malloc(sizeof(int)*G.vexnum);
	//ve初始化
	for (int i = 0;i < G.vexnum;i++) {
		ve[i] = 0;
	}
	for (int i = 0;i < G.vexnum;i++) {
		for (k = 0;k < G.vexnum;k++) {
			if (topo[k] == i+1)
				break;
		}
		if (k == G.vexnum)
			break;
		p = G.vertices[k].firstarc;
		while (p!=NULL) {
			j = p->adjvex;
			if (ve[j] < ve[k] + p->weight)
				ve[j] = ve[k] + p->weight;
			p = p->next;
		}
	}
	for (i = 0;i < G.vexnum;i++) {
		vl[i] = ve[G.vexnum - 1];
	}
	for (i = G.vexnum - 1;i >= 0;i--) {
		for (k = 0;k < G.vexnum;k++) {
			if (topo[k] == i)
				break;
		}
		if (k == G.vexnum)
			break;
		p = G.vertices[k].firstarc;
		while (p) {
			j = p->adjvex;
			if (vl[k] > vl[j] - p->weight)
				vl[k] = vl[j] - p->weight;
			p = p->next;
		}
	}
	for (i = 0;i < G.vexnum;i++) {
		p = G.vertices[i].firstarc;
		while (p!=NULL) {
			j = p->adjvex;
			e = ve[i];
			l = vl[j] - p->weight;
			if (e == l)
				printf("%c->%c  ", G.vertices[i].data, G.vertices[j].data);
			p = p->next;
		}
	}
	printf("\n");
 }
