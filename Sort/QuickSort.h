#pragma once
#include"SqList.h"
int Partition(SqList& L, int low, int high) {
	L.data[0] = L.data[low];
	int priotkey = L.data[low];
	while (low < high) {
		while (low < high && (L.data[high] >= priotkey))
			high--;
		L.data[low] = L.data[high];
		while (low < high && (L.data[low] <= priotkey))
			low++;
		L.data[high] = L.data[low];
	}
	L.data[low] = L.data[0];
	return low;
}

void QSort(SqList &L,int low,int high) {
	if (low < high) {
		int pivotloc = Partition(L, low, high);
		QSort(L, low, pivotloc - 1);
		QSort(L, pivotloc + 1, high);
	}
}
void QuickSort(SqList &L) {
	QSort(L, 1, L.length);
}