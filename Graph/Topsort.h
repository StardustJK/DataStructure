#pragma once
/*
	拓扑排序
	用队列实现
*/
#include"GraphAdjacencyList.h"
#include "Queue.h"
int* Topsort(ALGraph G) {
	LinkQueue Q;
	init_Queue(Q);
	int *TopNum = (int*)malloc(sizeof(int)*MAX_VERTEX_NUM);//输出顺序
	int counter = 0;
	int i=0;
	for (;i < G.vexnum;i++) {//用i来遍历表头
		if (G.vertices[i].degree == 0) {
			EnQueue(Q, i);
		}
	}
	while (!isEmpty(Q))
	{
		i = DeQueue(Q);//j接收的是表头
		counter++;
		TopNum[i] = counter;
		for (ArcNode *s = G.vertices[i].firstarc;s != NULL;s = s->next) {
			int j = s->adjvex;
			G.vertices[j].degree--;
			if (G.vertices[j].degree == 0)
				EnQueue(Q, j);
		}
	}
	if (counter != G.vexnum) {
		printf("图有环，不存在拓扑排序\n");
		return NULL;
	}
	else
		return TopNum;
}
