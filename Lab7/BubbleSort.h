#pragma once
#include<stdio.h>
void BubbleSort(int a[], int length) {
	int compare = 0, change = 0;
	for (int i = 1;i <= length;i++) {
		for (int j = 1;j <= length - i;j++) {
			compare++;
			if (a[j] > a[j + 1]) {
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
				change = change + 3;
			}
		}
	}
	printf("�Ƚϴ�����%d,����������%d\n",compare,change);
}
