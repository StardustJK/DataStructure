/*#include"BiSortTree.h"


//��������������
int main() {
	printf("�����볤��(<100)\n");
	int a[100];
	int length;
	scanf_s("%d", &length);
	getchar();
	a[0] = length;	//a[0]������Ĵ�С
	printf("���������ݣ��ո����\n");
	for (int i = 1;i <= length;i++) {
		scanf_s("%d", &a[i]);
	}

	BiTree T;
	createBST(T, a);
	printf("�������\n");
	inOrderTraverse(T);
	printf("\n�����ӡ\n");
	PrintBiT(T, 1);
	searchBST(T, 3, 1);
	searchBST(T, 10, 1);
	searchBST(T, 100, 1);


	printf("\nɾ��10\n");
	DeleteBST(T, 10);
	printf("�����ӡ\n");
	PrintBiT(T, 1);
	printf("\nɾ��100\n");
	DeleteBST(T, 100);

	printf("����10\n");
	insertBST(T, 10);
	PrintBiT(T, 1);
	return 0;
}*/

#include"HashTable.h"
#include<stdio.h>
#include<string.h>
int main() {
	HashTable H;
	initHash(&H);
	char s[30][15] = { "hecai",
		"tangli",
		"liuyifan",
		"tangbaoyu",
		"lixiaoman",
		"zhangyiqun",
		"xuwen",
		"jiangyue",
		"liyanjie",
		"linjunjie",
		"zhangjie",
		"chenjingqiao",
		"chensheng",
		"shenzhaocong",
		"zhoutingjiang",
		"panhang",
		"suixiaoyu",
		"chenyuanheng",
		"chenxiao",
		"chenyushi",
		"fengtianyou",
		"gaochenxi",
		"zhanghuahai",
		"zenghaonan",
		"yangke",
		"wangyao",
		"liuyueming",
		"liguohang",
		"songjiuxiao",
		"sukexin"
	};
	for (int i = 0;i < 30;i++) {
		insertHash(&H, s[i]);
	}
	printf("ƽ�����Ҵ�����%f\n", all / 30.0);
	printf("��ϣ��Ϊ��\n");
	showTable(H);
	while (true) {
		printf("�������������\n");
		char s[15];
		scanf_s("%s", s, 15);
		searchHash(H, s);
	}

	return 0;
}