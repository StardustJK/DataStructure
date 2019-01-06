#pragma once
#include<stdio.h>
void SelectionSort(int a[], int length) {
	int compare = 0, change = 0;
	for (int i = 1;i < length;i++) {
		int min = a[i];
		int pos = i;
		int j;
		for (j = i+1;j <= length;j++) {
			compare++;
			if (a[j] < min) {
				min = a[j];
				pos = j;
			}
		}
		int temp = a[i];
		a[i] = a[pos];
		a[pos] = temp;
		change = change + 3;
	}
	printf("比较次数：%d,交换次数：%d", compare, change);
}