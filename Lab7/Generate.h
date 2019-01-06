#pragma once
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
void Generate(int  a[], int length) {
	srand((int)time(NULL));
	for (int i = 1;i <= length;i++) {
		a[i] = rand()%1000;
	}
}

void showList(int a[], int length) {
	for (int i = 1;i <= length;i++) {
		printf("(%d)%d  ",i, a[i]);
		if (i % 10 == 0)
			printf("\n");
	}
}