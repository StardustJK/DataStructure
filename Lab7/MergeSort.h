#pragma once
#include<stdio.h>
#define MAXLENGTH 101

int Mcompare, Mchange;
void Merge(int a[], int b[], int i, int m, int n) {
	int j, k;
	for (j = m + 1, k = i;i <= m && j <= n;k++) {
		Mcompare++;
		if (a[i] < a[j]) {
			b[k] = a[i];
			Mchange++;
			i++;
		}
		else {
			b[k] = a[j];
			Mchange++;
			j++;
		}
	}
	if (i <= m) {
		for (;k <= n;k++) {
			b[k] = a[i];
			Mchange++;
			i++;
		}
	}
	if (j <= n) {
		for (;k <= n;k++) {
			b[k] = a[j];
			Mchange++;
			j++;
		}
	}
}

void MSort(int a[],int b[], int s, int t) {
	int c[MAXLENGTH];
	/*for (int i = 1;i <= alength;i++) {

	}*/
	if (s == t) {
		b[s] = a[s];
		Mchange++;
	}
	else {
		int m = (s + t) / 2;
		MSort(a, c, s, m);
		MSort(a, c, m + 1, t);
		Merge(c, b, s, m, t);
	}
}

void MergeSort(int a[],int length) {
	Mcompare = 0;
	Mchange = 0;
	MSort(a, a, 1, length);
	printf("比较次数：%d,交换次数：%d\n", Mcompare, Mchange);
}