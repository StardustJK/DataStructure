/*
	�����ʾ�� ֮��Ȩ����ͼ   ��matrix)
*/

#pragma once
#include<stdio.h>
#include<stdlib.h>

#define INFINITY INT_MAX   //����
#define MAX_VERTEX_NUM 20  //����������
#define VRType bool
#define VertexType int //��������
typedef enum { DG, DN, UDG, UDN }GraphKind;//����ͼ������������Ȩ��������ͼ������������Ȩ��
//�ڽӾ��������
typedef struct ArcCell {
	VRType adj;//��Ȩͼ 0��1��ʾ
	//InfoType *info
}ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

//ͼ����
typedef struct{
	VertexType vexs[MAX_VERTEX_NUM];
	AdjMatrix arcs;
	int vexnum, arcnum;
	GraphKind kind;
}MGraph;

int LocateVex(MGraph G, VertexType v) {
	for (int i = 0;i < G.vexnum;i++) {
		if (G.vexs[i] == v)
			return i;
		
	}
	return -1;
}

bool isExist(MGraph G,int i,int j) {
	if (G.arcs[i][j].adj == 1)
		return 1;
	return 0;
}

//����ͼ
void createUDG(MGraph &G) {
	printf("���������붥���������������\n");
	scanf_s("%d%d", &G.vexnum, &G.arcnum);
	getchar();
	printf("���������붥��\n");
	for (int i = 0;i < G.vexnum;i++) {
		scanf_s("%d", &G.vexs[i]);
	}
	getchar();
	//��ʼ������
	for (int i = 0;i < G.vexnum;i++) {
		for (int j = 0;j < G.vexnum;j++) {
				G.arcs[i][j].adj = 0;
		}
	}
	//�����ڽӾ���
	for (int k = 0;k < G.arcnum;k++) {
		printf("�밴�ն���1 ����2��˳�������%d��\n",k+1);
		int i, j;
		scanf_s("%d%d", &i, &j);
		i = LocateVex(G, i);
		j = LocateVex(G, j);
		if (i == -1 || j == -1) {
			printf("�����������������\n");
			k--;
			continue;
		}
		if (isExist(G, i, j)) {
			printf("�ظ�����,����������\n");
			k--;
			continue;
		}
		G.arcs[i][j].adj = 1;
		G.arcs[j][i].adj = 1;
	}

}

void showGraph(MGraph G) {
	for (int i = 0;i < G.vexnum;i++) {
		for (int j = 0;j < G.vexnum;j++) {
			printf("%d ", G.arcs[i][j]);
		}
		printf("\n");
	}
}