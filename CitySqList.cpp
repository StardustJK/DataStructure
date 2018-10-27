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
	int length;//当前长度
	int listsize;//容量
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
	printf("请输入创建的城市数量：\n");
	int n;
	scanf_s("%d", &n);
	getchar();
	for (int i = 0;i < n;i++) {
		printf("请输入城市名字（单字母）：\n");
		scanf_s("%c",&L.name[i],1);
		getchar();
		printf("请输入城市坐标：\n");
		scanf_s("%d%d", &L.x[i],&L.y[i]);
		getchar();
		L.length++;
	}
}

void insert(SqList &L) {
	int i;
	printf("请输入插入的位置：\n");
	scanf_s("%d", &i);
	getchar();
	if (i<1 || i>L.length + 1)
		printf("输入位置有错\n");
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
	printf("请输入城市名字（单字母）：\n");
	scanf_s("%c",&L.name[i-1], 1);
	getchar();
	printf("请输入城市坐标：\n");
	scanf_s("%d%d",&L.x[i-1],&L.y[i-1]);
	getchar();
	L.length++;
}

void delete_SqL(SqList &L) {
	int i;
	printf("请输入删除的位置：\n");
	scanf_s("%d", &i);
	getchar();
	if (i<1 || i>L.length)
		printf("输入位置有错!\n");
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
		printf("城市名字：%c\n", *pname);
		printf("城市坐标：（%d,%d)\n", *px, *py);
		pname++;
		px++;
		py++;
	}
}

//根据城市名给出坐标
void getPos(SqList L) {
	char e;
	int i = 0;
	printf("请输入城市名：\n");
	scanf_s("%c", &e, 1);
	getchar();
	for (;;i++) {
		if (e == L.name[i]) {
			break;
		}
		if (i >= L.length) {
			printf("该城市不存在\n");
			break;
		}
	}
	if(i<L.length)
		printf("该城市坐标为：（%d,%d)\n", L.x[i], L.y[i]);

}
//根据坐标给出城市名
void getCity(SqList L) {
	int x, y;
	printf("请输入坐标：\n");
	scanf_s("%d%d", &x, &y);
	getchar();
	int i=0;
	for (;;i++) {
		if ((x == L.x[i]) && (y == L.y[i]))
			break;
		if (i >= L.length) {
			printf("该城市不存在\n");
			break;
		}
	}
	if (i < L.length)
		printf("该城市名字为：%c\n", L.name[i]);

}

void update(SqList &L) {
	int i;
	printf("请输入要更新的城市序号：\n");
	scanf_s("%d", &i);
	getchar();
	if (i<1 || i>L.length) {
		printf("该城市不存在\n");
	}
	if (i <= L.length) {
		printf("请输入新的城市名：\n");
		scanf_s("%c", &L.name[i - 1], 1);
		printf("输入新的坐标：\n");
		scanf_s("%d%d", &L.x[i - 1], &L.y[i - 1]);
		getchar();
	}
}

void distance(SqList &L) {
	printf("请输入城市坐标：\n");
	int x, y, d;
	scanf_s("%d%d", &x, &y);
	printf("请输入距离：\n");
	scanf_s("%d", &d);
	getchar();
	int dis;
	for (int i = 0;i < L.length;i++) {
		dis = (x - L.x[i])*(x - L.x[i]) + (y - L.y[i])*(y - L.y[i]);
		if (dis <= d * d) {
			printf("城市名字:  %c\n", L.name[i]);
			printf("城市坐标:(%d,%d)\n", L.x[i], L.y[i]);
		}
		
	}
	if (dis > d*d) {
		printf("不存在这样的城市\n");
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
		printf("|1.展示各城市信息           |\n");
		printf("|2.根据坐标查找城市         |\n");
		printf("|3.根据城市名查找其坐标     |\n");
		printf("|4.插入城市                |\n");
		printf("|5.删除城市                |\n");
		printf("|6.更新城市信息             |\n");
		printf("|7.查找与P市距离<=D的城市   |\n");
		printf("|8.退出                    |\n");
		printf("---------------------------\n");
		printf("请输入你的操作：\n");
		scanf_s("%d", &c);
		system("cls");
		getchar();
		if (1 == c) {
			showList(p);
			printf("按下回车键返回主菜单\n");
			getchar();
			system("cls");
		}
		if (2 == c) {
			getCity(p);
			printf("按下回车键返回主菜单\n");
			getchar();
			system("cls");
		}
		if (3 == c) {
			getPos(p);
			printf("按下回车键返回主菜单\n");
			getchar();
			system("cls");
		}
		if (4 == c) {
			insert(p);
			printf("按下回车键返回主菜单\n");
			getchar();
			system("cls");
		}
		if (5 == c) {
			delete_SqL(p);
			printf("按下回车键返回主菜单\n");
			getchar();
			system("cls");
		}
		if (6 == c) {
			update(p);
			printf("按下回车键返回主菜单\n");
			getchar();
			system("cls");
		}
		if (7 == c) {
			distance(p);
			printf("按下回车键返回主菜单\n");
			getchar();
			system("cls");
		}
		if (8 == c) {
			exit(0);
		}
	}
	return 0;
}

