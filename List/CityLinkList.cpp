#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

typedef struct City {
	char name;
	int x;
	int y;
	struct City *next;
}City;


void init_City(City * city) {
	city->name = {' '};
	city->x = 0;
	city->y = 0;
	city->next = NULL;
}

void create_City(City * city,int n) {
	City *p,*q;
	p = city;
	for (int i = 0;i < n;i++) {
		q = (City*)malloc(sizeof(City));
		printf("请输入城市名（单字母）\n");
		scanf_s("%c",&q->name,1);
		printf("请分别输入x y坐标\n");
		scanf_s("%d%d", &q->x,&q->y);
		getchar();
		q->next = p->next;
		p->next = q;
		p = q;
	}
}
void print_City(City* city) {
	City *p;
	p = city->next;
	for (int i=1;p!=NULL;i++)
	{
		printf("(%d)\n", i);
		printf("city name:     %c\n", p->name);
		printf("city position:(%d,%d)\n", p->x, p->y);
		p = p->next;
	}
}

void insert(City* city) {
	City *p;
	p = city->next;
	printf("请输入插入位置：\n");
	int i;
	scanf_s("%d", &i);
	getchar();
	int j = 1;
	for (;j < i - 1;j++) {
		p = p->next;
	}
	if (!p || j > i) {
		printf("error\n");
	}
	City *s;
	s = (City*)malloc(sizeof(City));
	printf("请输入插入城市名：\n");
	scanf_s("%c", &s->name,1);
	printf("请输入城市的x y坐标：\n");
	scanf_s("%d%d", &s->x, &s->y);
	getchar();
	s->next = p->next;
	p->next = s;

}
void deletion(City* city) {
	City *p;
	p = city->next;
	printf("请输入删除位置：\n");
	int i;
	scanf_s("%d",&i);
	getchar();
	int j = 1;
	for (;j < i-1;j++) {
		p = p->next;
	}
	if (!p || j > i) {
		printf("error\n");
	}
	City* s;
	s = p->next;
	p->next = p->next->next;
	char e;
	e = s->name;
	printf("删除的城市名为：%c\n",e);
	free(s);
}
void update(City* city) {
	City *p;
	p = city->next;
	int i;
	printf("请输入要更新的城市序号:\n");
	scanf_s("%d",&i);
	getchar();
	for (int j = 0;j < i - 1;j++) {
		p = p->next;
		if (p == NULL) {
			printf("the city doesn't exist\n");
			break;
		}
	}
	if (p != NULL) {
		printf("输入新的城市名：\n");
		scanf_s("%c", &p->name, 1);
		printf("输入新的坐标：\n");
		scanf_s("%d%d", &p->x, &p->y);
		getchar();
	}

}
//根据坐标查找城市
void getCity(City *city) {
	City *p;
	p = city->next;
	printf("city position:\n");
	int x_, y_;
	scanf_s("%d%d", &x_, &y_);
	while (p != NULL)
	{
		if ((p->x==x_)&&(p->y==y_) ){
			printf("city name:%c\n", p->name);
			break;
		}
		else
			p = p->next;
	}
	if(p==NULL)
	printf("the city dosen't exist\n");
	getchar();

}
//根据城市查找坐标
void getPos(City *city) {
	City *p;
	p = city->next;
	printf("city name:\n");
	char n;
	scanf_s("%c", &n,1);
	getchar();
	while (p!=NULL)
	{
		if (p->name == n) {
			printf("city position:(%d,%d)\n", p->x, p->y);
			break;
		}
		else
			p = p->next;
	}
	if(p==NULL)
	printf("the city dosen't exist\n");
}
//给城市的坐标p和距离D，返回与p距离小于D的城市
void distance(City*city) {
	City*p;
	p = city->next;
	printf("请输入城市坐标：\n");
	int px, py, d;
	scanf_s("%d%d", &px, &py);
	printf("请输入距离：\n");
	scanf_s("%d", &d);
	getchar();
	int dis;
	while (p!=NULL)
	{
		dis = (px - p->x)*(px - p->x) + (py - p->y)*(py - p->y);
		if (dis < d*d) {
			printf("city name:     %c\n", p->name);
			printf("city position:(%d,%d)\n", p->x, p->y);
		}
			
		p = p->next;
	}
}
int main() {
	City *p;
	p = (City *)malloc(sizeof(City));
	init_City(p);
	int n, c;
	printf("请输入创建的城市数量：\n");
	scanf_s("%d", &n);
	getchar();
	create_City(p, n);
	system("cls");
	while (1) {
		printf("---------------------------\n");
		printf("|1.展示各城市信息           |\n");
		printf("|2.根据坐标查找城市         |\n");
		printf("|3.根据城市名查找其坐标     |\n");
		printf("|4.插入城市                |\n");
		printf("|5.删除城市                |\n");
		printf("|6.更新城市信息             |\n");
		printf("|7.查找与P市距离小于D的城市  |\n");
		printf("|8.退出                    |\n");
		printf("---------------------------\n");
		printf("请输入你的操作：\n");
		scanf_s("%d", &c);
		system("cls");
		getchar();
		if (1 == c) {
			print_City(p);
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
			deletion(p);
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