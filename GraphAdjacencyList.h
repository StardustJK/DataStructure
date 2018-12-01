#pragma once
#include<stdio.h>
#include<stdlib.h>

#define MAX_VERTEX_NUM 20 //���������
#define VertexType char
typedef enum { DG, DN, UDG, UDN }GraphKind;//����ͼ������������Ȩ��������ͼ������������Ȩ��

//����
typedef struct ArcNode {
	int adjvex;//�û�ָ��Ķ����λ��
	struct ArcNode *next;
	//InfoType *info;
}ArcNode;

//ͷ���
typedef struct VNode {
	VertexType data;
	ArcNode *firstarc;
}VNode,AdjList[MAX_VERTEX_NUM];

//ͼ�ṹ
typedef struct {
	AdjList vertices;
	int vexnum, arcnum;
	GraphKind kind;
}ALGraph;

int LocateVex(ALGraph G, VertexType v) {
	for (int i = 0;i < G.vexnum;i++) {
		if (G.vertices[i].data == v)
			return i;
	}
	return -1;
}

bool isExist(ALGraph G,int i,int j) {
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
		scanf_s("%c %c", &i,1, &j,1);
		getchar();
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
		ArcNode *s;
		s = (ArcNode*)malloc(sizeof(ArcNode));
		s->next = G.vertices[i].firstarc;
		G.vertices[i].firstarc = s;
		s->adjvex = j;
	}
}

void showGraph(ALGraph G) {
	for (int i = 0;i < G.vexnum;i++) {
		printf("%c ->", G.vertices[i].data);
		ArcNode *p = G.vertices[i].firstarc;
		while(p!=NULL){
			printf("%d ", p->adjvex);
			p = p->next;
		}
		printf("\n");
	}
}