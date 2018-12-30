/*#include"BiSortTree.h"


//建立二叉排序树
int main() {
	printf("请输入长度(<100)\n");
	int a[100];
	int length;
	scanf_s("%d", &length);
	getchar();
	a[0] = length;	//a[0]放数组的大小
	printf("请输入数据，空格隔开\n");
	for (int i = 1;i <= length;i++) {
		scanf_s("%d", &a[i]);
	}

	BiTree T;
	createBST(T, a);
	printf("中序遍历\n");
	inOrderTraverse(T);
	printf("\n横向打印\n");
	PrintBiT(T, 1);
	searchBST(T, 3, 1);
	searchBST(T, 10, 1);
	searchBST(T, 100, 1);


	printf("\n删除10\n");
	DeleteBST(T, 10);
	printf("横向打印\n");
	PrintBiT(T, 1);
	printf("\n删除100\n");
	DeleteBST(T, 100);

	printf("插入10\n");
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
	printf("平均查找次数：%f\n", all / 30.0);
	printf("哈希表为：\n");
	showTable(H);
	while (true) {
		printf("请输入查找人名\n");
		char s[15];
		scanf_s("%s", s, 15);
		searchHash(H, s);
	}

	return 0;
}