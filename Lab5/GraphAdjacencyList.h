#pragma once
#include<stdio.h>
#include<stdlib.h>

#define MAX_VERTEX_NUM 30 //顶点最大数
#define VertexType char
#define InfoType int
typedef enum { DG, DN, UDG, UDN }GraphKind;//有向图，有向网（有权），无向图，无向网（有权）

bool visited[MAX_VERTEX_NUM];

										   //表结点
typedef struct ArcNode {
	int adjvex;//该弧指向的顶点的位置
	struct ArcNode *next;
}ArcNode;

//头结点
typedef struct VNode {
	VertexType data;
	ArcNode *firstarc;
}VNode, AdjList[MAX_VERTEX_NUM];

//图结构
typedef struct {
	AdjList vertices;
	int vexnum, arcnum;
	GraphKind kind;
}ALGraph;

typedef struct {
	int start;
	int end;
}Arc;
int LocateVex(ALGraph G, VertexType v) {
	for (int i = 0;i < G.vexnum;i++) {
		if (G.vertices[i].data == v)
			return i;
	}
	return -1;
}
ElemType GetVex(ALGraph G, int w) {
	return G.vertices[w].data;
}

bool isExistDG(ALGraph G, int i, int j) {
	ArcNode *p = G.vertices[i].firstarc;
	for (;p != NULL;p = p->next) {
		if (p->adjvex == j)
			return 1;
	}
	return 0;
}
bool isExistUDG(ALGraph G, int i, int j) {
	ArcNode *p = G.vertices[i].firstarc;
	for (;p != NULL;p = p->next) {
		if (p->adjvex == j)
			return 1;
	}
	p = G.vertices[j].firstarc;
	for (;p != NULL;p = p->next) {
		if (p->adjvex == i)
			return 1;
	}
	return 0;
}

void showGraph(ALGraph G) {
	for (int i = 0;i < G.vexnum;i++) {
		printf("%c ->", G.vertices[i].data);
		ArcNode *p = G.vertices[i].firstarc;
		while (p != NULL) {
			printf("%d ->", p->adjvex);
			p = p->next;
		}
		printf("\n");
	}
}
//无向图
void createUDG(ALGraph &G) {
	printf("请依次输入顶点个数、弧的条数\n");
	scanf_s("%d%d", &G.vexnum, &G.arcnum);
	getchar();
	printf("请依次输入顶点\n");
	for (int i = 0;i < G.vexnum;i++) {
		scanf_s("%c", &G.vertices[i].data);
		G.vertices[i].firstarc = NULL;
	}
	getchar();

	//构造
	for (int k = 0;k < G.arcnum;k++) {
		printf("请按照顶点1 顶点2 的顺序输入第%d组\n", k + 1);
		int i, j;
		scanf_s("%c %c", &i, 1, &j, 1);
		getchar();
		i = LocateVex(G, i);
		j = LocateVex(G, j);
		if (i == -1 || j == -1) {
			printf("输入错误请重新输入\n");
			k--;
			continue;
		}
		if (isExistUDG(G, i, j)) {
			printf("重复输入,请重新输入\n");
			k--;
			continue;
		}
		ArcNode *s1;
		s1 = (ArcNode*)malloc(sizeof(ArcNode));
		s1->next = G.vertices[i].firstarc;
		G.vertices[i].firstarc = s1;
		s1->adjvex = j;
		ArcNode *s2;
		s2 = (ArcNode*)malloc(sizeof(ArcNode));
		s2->next = G.vertices[j].firstarc;
		G.vertices[j].firstarc = s2;
		s2->adjvex = i;
	}
	printf("邻接链表为：\n");
	showGraph(G);
}


//有向图
void createDG(ALGraph &G) {
	printf("请依次输入顶点个数、弧的条数\n");
	scanf_s("%d%d", &G.vexnum, &G.arcnum);
	getchar();
	printf("请依次输入顶点：\n");//无空格输入
	for (int i = 0;i < G.vexnum;i++) {
		scanf_s("%c", &G.vertices[i].data);
		G.vertices[i].firstarc = NULL;
	}
	getchar();

	for (int k = 0;k < G.arcnum;k++) {
		printf("请按照顶点1 顶点2 的顺序输入第%d组\n", k + 1);
		int i, j;
		scanf_s("%c %c", &i, 1, &j, 1);
		getchar();
		i = LocateVex(G, i);
		j = LocateVex(G, j);
		if (i == -1 || j == -1) {
			printf("输入错误请重新输入\n");
			k--;
			continue;
		}
		if (isExistDG(G, i, j)) {
			printf("重复输入，请重新输入\n");
			k--;
			continue;
		}
		ArcNode *s;
		s = (ArcNode*)malloc(sizeof(ArcNode));
		s->next = G.vertices[i].firstarc;
		G.vertices[i].firstarc = s;
		s->adjvex = j;
	}
	showGraph(G);
}

int FirstAdjVex(ALGraph G, int v) {
	if (!G.vertices[v].firstarc)
		return -1;
	else
		return (G.vertices[v].firstarc->adjvex);
}
int NextAdjVex(ALGraph G, int v, int w) {
	ArcNode *p;
	p = G.vertices[v].firstarc;
	if (p) {
		while (p&&p->adjvex != w)//找到w
			p = p->next;
		if (p->adjvex == w && p->next)
			return p->next->adjvex;//找到了w且存在邻接点
		else
			return -1;
	}
	return -1;

}
