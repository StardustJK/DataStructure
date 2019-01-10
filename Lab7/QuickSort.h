#pragma once
#include<stdio.h>
int compare = 0, change = 0;
int Partition(int a[], int low, int high) {
	a[0] = a[low];
	change++;
	while (low < high) {
		compare++;
		while (low < high&&a[high] >= a[0]) {
			high--;
			compare++;
		}
		a[low] = a[high];
		change++;
		while (low < high&&a[low]<=a[0]) {
			low++;
			compare++;
		}
		a[high] = a[low];
		change++;
	}
	a[low] = a[0];
	change++;
	return low;
}

void QSort(int a[], int s, int t) {
	if (s < t) {
		int pivotloc = Partition(a, s, t);
		QSort(a, s, pivotloc - 1);
		QSort(a, pivotloc + 1, t);
	}
}

void QuickSort(int a[], int length) {
	compare = 0;
	change = 0;
	QSort(a, 1, length);
	printf("比较次数：%d,交换次数:%d\n", compare, change);
}