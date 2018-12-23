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
		printf("�����������������ĸ��\n");
		scanf_s("%c",&q->name,1);
		printf("��ֱ�����x y����\n");
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
	printf("���������λ�ã�\n");
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
	printf("����������������\n");
	scanf_s("%c", &s->name,1);
	printf("��������е�x y���꣺\n");
	scanf_s("%d%d", &s->x, &s->y);
	getchar();
	s->next = p->next;
	p->next = s;

}
void deletion(City* city) {
	City *p;
	p = city->next;
	printf("������ɾ��λ�ã�\n");
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
	printf("ɾ���ĳ�����Ϊ��%c\n",e);
	free(s);
}
void update(City* city) {
	City *p;
	p = city->next;
	int i;
	printf("������Ҫ���µĳ������:\n");
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
		printf("�����µĳ�������\n");
		scanf_s("%c", &p->name, 1);
		printf("�����µ����꣺\n");
		scanf_s("%d%d", &p->x, &p->y);
		getchar();
	}

}
//����������ҳ���
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
//���ݳ��в�������
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
//�����е�����p�;���D��������p����С��D�ĳ���
void distance(City*city) {
	City*p;
	p = city->next;
	printf("������������꣺\n");
	int px, py, d;
	scanf_s("%d%d", &px, &py);
	printf("��������룺\n");
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
	printf("�����봴���ĳ���������\n");
	scanf_s("%d", &n);
	getchar();
	create_City(p, n);
	system("cls");
	while (1) {
		printf("---------------------------\n");
		printf("|1.չʾ��������Ϣ           |\n");
		printf("|2.����������ҳ���         |\n");
		printf("|3.���ݳ���������������     |\n");
		printf("|4.�������                |\n");
		printf("|5.ɾ������                |\n");
		printf("|6.���³�����Ϣ             |\n");
		printf("|7.������P�о���С��D�ĳ���  |\n");
		printf("|8.�˳�                    |\n");
		printf("---------------------------\n");
		printf("��������Ĳ�����\n");
		scanf_s("%d", &c);
		system("cls");
		getchar();
		if (1 == c) {
			print_City(p);
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
			deletion(p);
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