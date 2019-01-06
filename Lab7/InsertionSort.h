#pragma once
#include<stdio.h>
void InsertionSort(int a[],int length) {
	int compare = 0,change=0;
	for (int i = 2;i <=length;i++) {
		compare++;
		if (a[i] < a[i - 1]) {
			a[0] = a[i];
			change++;
			int j;
			for ( j = i-1;a[0]<a[j] ;j--) {
				a[j + 1] = a[j];
				change++;
				compare++;
			}
			a[j+1] = a[0];
			change++;
		}
		
	}
	printf("比较次数：%d,交换次数：%d\n", compare, change);
}