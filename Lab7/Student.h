#pragma once
#include<time.h>
#include<stdlib.h>
#include<string>
#include<stdio.h>
#define STUDENT_NUM 10
struct Student
{
	int number;
	char name[20];
	int Math;
	int English;
	int CLanguage;
	int Chemistry;
	int total;
	int rank;
};

void initStu(Student *stu) {
	char name_[STUDENT_NUM][20] = {
		"hecai",
		"liuyifan",
		"wangke",
		"zhangshan",
		"lisi",
		"wangxiaoming",
		"lixiaogong",
		"tangbaoyu",
		"jiangyue",
		"liyanjie"
	};
	//srand((int)time(NULL));
	for (int i = 1;i <= STUDENT_NUM;i++) {
		stu[i].number = i;
		stu[i].Math = rand() % 100;
		stu[i].English = rand() % 100;
		stu[i].CLanguage = rand() % 100;
		stu[i].Chemistry = rand() % 100;
		stu[i].total = stu[i].Math + stu[i].English + stu[i].CLanguage + stu[i].Chemistry;
		strcpy_s(stu[i].name, name_[i-1]);
	}
}

void showStu(Student *stu) {
	printf("学号 姓名               数学 英语   C语言  化学  总分\n");
	for (int i = 1;i <= STUDENT_NUM;i++) {
		printf("%2d   %-15s   %3d   %3d    %3d    %3d    %3d\n", stu[i].number, stu[i].name, stu[i].Math, stu[i].English, stu[i].CLanguage, stu[i].Chemistry,stu[i].total);
	}

}
void showRank(Student *stu) {
	printf("名次 学号 姓名               数学 英语   C语言  化学  总分\n");
	stu[1].total = 150;
	int rank = 1;
	for (int i = 1;i <= STUDENT_NUM;i++) {
		printf("%2d  ", rank);
		if (stu[i].total != stu[i + 1].total)
			rank++;
		printf("%2d   %-15s   %3d   %3d    %3d    %3d    %3d\n", stu[i].number, stu[i].name, stu[i].Math, stu[i].English, stu[i].CLanguage, stu[i].Chemistry, stu[i].total);
	}

}