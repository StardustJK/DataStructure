#pragma once
#include"SqList.h"
void ShellSort(SqList &L) {
	int dk;
	int j;
	for (dk = L.length / 2;dk > 0;dk = dk / 2) {
		for (int i = dk + 1;i <= L.length;i++) {
			if (L.data[i] < L.data[i - dk]) {
				L.data[0] = L.data[i];
				for (j = i - dk;j > 0 && (L.data[0] < L.data[j]);j = j - dk)
					L.data[j + dk] = L.data[j];
				L.data[j + dk] = L.data[0];
			}
		}
	}
}


