#pragma once
#include"SqList.h"


//将L.data[s]到L.data[m]调整成大顶堆
void HeapAdjust(SqList &L, int s, int m) {
	int rc = L.data[s];

	for (int j = s * 2;j <= m;j = j * 2) {
		if (j < m && (L.data[j] <= L.data[j + 1]))//记录s的两个孩子中较大的那个孩子的坐标
			j++;
		if (rc > L.data[j])//rc已是最大的情况就不用换了，退出
			break;
		L.data[s] = L.data[j];
		s = j;	
	}
	L.data[s] = rc;
}

void HeapSort(SqList &L) {
	for (int i = L.length / 2;i > 0;i--) {
		HeapAdjust(L, i, L.length);//把L建成大顶堆
	}
	for (int i = L.length;i > 1;i--) {
		int temp = L.data[1];//交换第一个和最后一个的数据
		L.data[1] = L.data[i];
		L.data[i] = temp;
		HeapAdjust(L, 1, i - 1);//把1--i-1建成最大堆
	}
}