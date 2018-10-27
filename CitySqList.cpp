#include <stdio.h>
#include<stdlib.h>

#define ERROR -1
#define OK 1
#define OVERFLOW -2
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef struct {
	char *name;
	int *x;
	int *y;
	int length;//��ǰ����
	int listsize;//����
}SqList;

void init_SqL(SqList & L) {
	L.name = (char*)malloc(LIST_INIT_SIZE * sizeof(char));
	L.x = (int *)malloc(LIST_INIT_SIZE * sizeof(int));
	L.y = (int *)malloc(LIST_INIT_SIZE * sizeof(int));
	if (!L.name || !L.x || !L.y) {
		printf("overflow\n");
	}
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
}
void create_City(SqList &L) {
	printf("�����봴���ĳ���������\n");
	int n;
	scanf_s("%d", &n);
	getchar();
	for (int i = 0;i < n;i++) {
		printf("������������֣�����ĸ����\n");
		scanf_s("%c",&L.name[i],1);
		getchar();
		printf("������������꣺\n");
		scanf_s("%d%d", &L.x[i],&L.y[i]);
		getchar();
		L.length++;
	}
}

void insert(SqList &L) {
	int i;
	printf("����������λ�ã�\n");
	scanf_s("%d", &i);
	getchar();
	if (i<1 || i>L.length + 1)
		printf("����λ���д�\n");
	if (L.length >= L.listsize) {
		char *newname;
		newname = (char*)realloc(L.name, (L.listsize + LISTINCREMENT) * sizeof(char));
		int *newx;
		int *newy;
		newx = (int *)realloc(L.x, (L.listsize + LISTINCREMENT) * sizeof(int));
		newy = (int *)realloc(L.y, (L.listsize + LISTINCREMENT) * sizeof(int));
	}
	int j = L.length - 1;
	for (;j >= i-1;j--) {
		L.name[j + 1] = L.name[j];
		L.x[j + 1] = L.x[j];
		L.y[j + 1] = L.y[j];
	}
	printf("������������֣�����ĸ����\n");
	scanf_s("%c",&L.name[i-1], 1);
	getchar();
	printf("������������꣺\n");
	scanf_s("%d%d",&L.x[i-1],&L.y[i-1]);
	getchar();
	L.length++;
}

void delete_SqL(SqList &L) {
	int i;
	printf("������ɾ����λ�ã�\n");
	scanf_s("%d", &i);
	getchar();
	if (i<1 || i>L.length)
		printf("����λ���д�!\n");
	for (int j = i - 1;j < L.length-1;j++) {
		L.name[j] = L.name[j + 1];
		L.x[j] = L.x[j + 1];
		L.y[j] = L.y[j + 1];
	}
	L.length--;
}

void showList(SqList L) {
	char *pname = &L.name[0];
	int *px = &L.x[0];
	int *py = &L.y[0];
	for (int j = 0;j < L.length;j++) {
		printf("%d\n", j + 1);
		printf("�������֣�%c\n", *pname);
		printf("�������꣺��%d,%d)\n", *px, *py);
		pname++;
		px++;
		py++;
	}
}

//���ݳ�������������
void getPos(SqList L) {
	char e;
	int i = 0;
	printf("�������������\n");
	scanf_s("%c", &e, 1);
	getchar();
	for (;;i++) {
		if (e == L.name[i]) {
			break;
		}
		if (i >= L.length) {
			printf("�ó��в�����\n");
			break;
		}
	}
	if(i<L.length)
		printf("�ó�������Ϊ����%d,%d)\n", L.x[i], L.y[i]);

}
//�����������������
void getCity(SqList L) {
	int x, y;
	printf("���������꣺\n");
	scanf_s("%d%d", &x, &y);
	getchar();
	int i=0;
	for (;;i++) {
		if ((x == L.x[i]) && (y == L.y[i]))
			break;
		if (i >= L.length) {
			printf("�ó��в�����\n");
			break;
		}
	}
	if (i < L.length)
		printf("�ó�������Ϊ��%c\n", L.name[i]);

}

void update(SqList &L) {
	int i;
	printf("������Ҫ���µĳ�����ţ�\n");
	scanf_s("%d", &i);
	getchar();
	if (i<1 || i>L.length) {
		printf("�ó��в�����\n");
	}
	if (i <= L.length) {
		printf("�������µĳ�������\n");
		scanf_s("%c", &L.name[i - 1], 1);
		printf("�����µ����꣺\n");
		scanf_s("%d%d", &L.x[i - 1], &L.y[i - 1]);
		getchar();
	}
}

void distance(SqList &L) {
	printf("������������꣺\n");
	int x, y, d;
	scanf_s("%d%d", &x, &y);
	printf("��������룺\n");
	scanf_s("%d", &d);
	getchar();
	int dis;
	for (int i = 0;i < L.length;i++) {
		dis = (x - L.x[i])*(x - L.x[i]) + (y - L.y[i])*(y - L.y[i]);
		if (dis <= d * d) {
			printf("��������:  %c\n", L.name[i]);
			printf("��������:(%d,%d)\n", L.x[i], L.y[i]);
		}
		
	}
	if (dis > d*d) {
		printf("�����������ĳ���\n");
	}
}
int main() {
	SqList p;
	int c;
	init_SqL(p);
	create_City(p);
	system("cls");
	while (1) {
		printf("---------------------------\n");
		printf("|1.չʾ��������Ϣ           |\n");
		printf("|2.����������ҳ���         |\n");
		printf("|3.���ݳ���������������     |\n");
		printf("|4.�������                |\n");
		printf("|5.ɾ������                |\n");
		printf("|6.���³�����Ϣ             |\n");
		printf("|7.������P�о���<=D�ĳ���   |\n");
		printf("|8.�˳�                    |\n");
		printf("---------------------------\n");
		printf("��������Ĳ�����\n");
		scanf_s("%d", &c);
		system("cls");
		getchar();
		if (1 == c) {
			showList(p);
			printf("���»س����������˵�\n");
			getchar();
			system("cls");
		}
		if (2 == c) {
			getCity(p);
			printf("���»س����������˵�\n");
			getchar();
			system("cls");
		}
		if (3 == c) {
			getPos(p);
			printf("���»س����������˵�\n");
			getchar();
			system("cls");
		}
		if (4 == c) {
			insert(p);
			printf("���»س����������˵�\n");
			getchar();
			system("cls");
		}
		if (5 == c) {
			delete_SqL(p);
			printf("���»س����������˵�\n");
			getchar();
			system("cls");
		}
		if (6 == c) {
			update(p);
			printf("���»س����������˵�\n");
			getchar();
			system("cls");
		}
		if (7 == c) {
			distance(p);
			printf("���»س����������˵�\n");
			getchar();
			system("cls");
		}
		if (8 == c) {
			exit(0);
		}
	}
	return 0;
}

