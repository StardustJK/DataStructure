#pragma once
#include"SqList.h"

//将有序的SR[i...m] 和SR[m+1....n]归并成有序的TR[i...n]
void Merge(SqList SR, SqList &TR, int i, int m, int n) {
	int j, k;
	for ( j = m + 1, k = i;i <= m && j <= n;k++) {
		if (SR.data[i] < SR.data[j]) {
			TR.data[k] = SR.data[i];
			i++;
		}
		else {
			TR.data[k] = SR.data[j];
			j++;
		}
	}
	//后半部分先结束
	if (i <= m) {
		for (;k <= n;k++) {
			TR.data[k] = SR.data[i];
			i++;
		}
	}
	//前半部分先结束
	if (j <= n) {
		for (;k <= n;k++) {
			TR.data[k] = SR.data[j];
			j++;
		}
	}
}

void MSort(SqList SR, SqList &TR1, int s, int t) {
	SqList TR2;
	init_SqList(TR2);
	TR2.length = SR.length;
	for (int i = 1;i <= TR2.length;i++) {
		TR2.data[i] = -99999;
	}
	if (s == t)
		TR1.data[s] = SR.data[s];
	else {
		int m = (s + t) / 2;
		MSort(SR, TR2, s, m);
		MSort(SR, TR2, m + 1, t);
		Merge(TR2, TR1, s, m, t);
	}
		
}

void MergeSort(SqList &L) {
	MSort(L, L, 1, L.length);
}

