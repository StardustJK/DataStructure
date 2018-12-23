#pragma once
/*
直接插入排序
*/
#include"SqList.h"

void InserSort(SqList &L) {

	for (int i = 2;i <= L.length;i++) {
		if (L.data[i] < L.data[i - 1]) {
			L.data[0] = L.data[i];
			L.data[i] = L.data[i - 1];
			int j;
			for (j = i - 2;L.data[j] > L.data[0];j--) {//右移
				L.data[j + 1] = L.data[j];
			}
			//插入正确位置
			L.data[j + 1] = L.data[0];
	
		}
		
	}
}

