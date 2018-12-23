/*
	数组表示法 之无权无向图   （matrix)
*/

#pragma once
#include<stdio.h>
#include<stdlib.h>

#define INFINITY INT_MAX   //无穷
#define MAX_VERTEX_NUM 20  //顶点最大个数
#define VRType bool
#define VertexType int //顶点类型
typedef enum { DG, DN, UDG, UDN }GraphKind;//有向图，有向网（有权），无向图，无向网（有权）
//邻接矩阵的类型
typedef struct ArcCell {
	VRType adj;//无权图 0，1表示
	//InfoType *info
}ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

//图类型
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

//无向图
void createUDG(MGraph &G) {
	printf("请依次输入顶点个数、弧的条数\n");
	scanf_s("%d%d", &G.vexnum, &G.arcnum);
	getchar();
	printf("请依次输入顶点\n");
	for (int i = 0;i < G.vexnum;i++) {
		scanf_s("%d", &G.vexs[i]);
	}
	getchar();
	//初始化矩阵
	for (int i = 0;i < G.vexnum;i++) {
		for (int j = 0;j < G.vexnum;j++) {
				G.arcs[i][j].adj = 0;
		}
	}
	//构造邻接矩阵
	for (int k = 0;k < G.arcnum;k++) {
		printf("请按照顶点1 顶点2的顺序输入第%d组\n",k+1);
		int i, j;
		scanf_s("%d%d", &i, &j);
		i = LocateVex(G, i);
		j = LocateVex(G, j);
		if (i == -1 || j == -1) {
			printf("输入错误请重新输入\n");
			k--;
			continue;
		}
		if (isExist(G, i, j)) {
			printf("重复输入,请重新输入\n");
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