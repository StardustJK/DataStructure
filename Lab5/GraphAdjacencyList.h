#pragma once
#include<stdio.h>
#include<stdlib.h>

#define MAX_VERTEX_NUM 30 //���������
#define VertexType char
#define InfoType int
typedef enum { DG, DN, UDG, UDN }GraphKind;//����ͼ������������Ȩ��������ͼ������������Ȩ��

bool visited[MAX_VERTEX_NUM];

										   //����
typedef struct ArcNode {
	int adjvex;//�û�ָ��Ķ����λ��
	struct ArcNode *next;
}ArcNode;

//ͷ���
typedef struct VNode {
	VertexType data;
	ArcNode *firstarc;
}VNode, AdjList[MAX_VERTEX_NUM];

//ͼ�ṹ
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
//����ͼ
void createUDG(ALGraph &G) {
	printf("���������붥���������������\n");
	scanf_s("%d%d", &G.vexnum, &G.arcnum);
	getchar();
	printf("���������붥��\n");
	for (int i = 0;i < G.vexnum;i++) {
		scanf_s("%c", &G.vertices[i].data);
		G.vertices[i].firstarc = NULL;
	}
	getchar();

	//����
	for (int k = 0;k < G.arcnum;k++) {
		printf("�밴�ն���1 ����2 ��˳�������%d��\n", k + 1);
		int i, j;
		scanf_s("%c %c", &i, 1, &j, 1);
		getchar();
		i = LocateVex(G, i);
		j = LocateVex(G, j);
		if (i == -1 || j == -1) {
			printf("�����������������\n");
			k--;
			continue;
		}
		if (isExistUDG(G, i, j)) {
			printf("�ظ�����,����������\n");
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
	printf("�ڽ�����Ϊ��\n");
	showGraph(G);
}


//����ͼ
void createDG(ALGraph &G) {
	printf("���������붥���������������\n");
	scanf_s("%d%d", &G.vexnum, &G.arcnum);
	getchar();
	printf("���������붥�㣺\n");//�޿ո�����
	for (int i = 0;i < G.vexnum;i++) {
		scanf_s("%c", &G.vertices[i].data);
		G.vertices[i].firstarc = NULL;
	}
	getchar();

	for (int k = 0;k < G.arcnum;k++) {
		printf("�밴�ն���1 ����2 ��˳�������%d��\n", k + 1);
		int i, j;
		scanf_s("%c %c", &i, 1, &j, 1);
		getchar();
		i = LocateVex(G, i);
		j = LocateVex(G, j);
		if (i == -1 || j == -1) {
			printf("�����������������\n");
			k--;
			continue;
		}
		if (isExistDG(G, i, j)) {
			printf("�ظ����룬����������\n");
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
		while (p&&p->adjvex != w)//�ҵ�w
			p = p->next;
		if (p->adjvex == w && p->next)
			return p->next->adjvex;//�ҵ���w�Ҵ����ڽӵ�
		else
			return -1;
	}
	return -1;

}
