#pragma once
#include<stdio.h>
int Hcompare, Hchange;

void HeapAdjust(int a[], int s, int m) {
	int rc = a[s];
	Hchange++;
	for (int j = 2 * s;j <= m;j = j * 2) {
		Hcompare++;
		if (j < m &&a[j] < a[j + 1]) {//要加上j<m不然就越界了
			j++;
		}
		Hcompare++;
		if (rc > a[j])
			break;
		Hchange++;
		a[s] = a[j];
		s = j;
	}
	a[s] = rc;
	Hchange++;
}

void HeapSort(int a[], int length) {
	Hcompare = 0, Hchange = 0;
	for (int i = length / 2;i > 0;i--) {
		HeapAdjust(a, i, length);
	}
	for (int i = length;i > 0;i--) {
		a[0] = a[1];
		a[1] = a[i];
		a[i] = a[0];
		Hchange = Hchange + 3;
		HeapAdjust(a, 1, i-1);
	}
	printf("比较次数：%d,交换次数：%d\n", Hcompare, Hchange);

}