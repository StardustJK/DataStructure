#pragma once
/*
	��������
	�ö���ʵ��
*/
#include"GraphAdjacencyList.h"
#include "Queue.h"
int* Topsort(ALGraph G) {
	LinkQueue Q;
	init_Queue(Q);
	int *TopNum = (int*)malloc(sizeof(int)*MAX_VERTEX_NUM);//���˳��
	int counter = 0;
	int i=0;
	for (;i < G.vexnum;i++) {//��i��������ͷ
		if (G.vertices[i].degree == 0) {
			EnQueue(Q, i);
		}
	}
	while (!isEmpty(Q))
	{
		i = DeQueue(Q);//j���յ��Ǳ�ͷ
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
		printf("ͼ�л�����������������\n");
		return NULL;
	}
	else
		return TopNum;
}
