#pragma once
#include"SqList.h"


//��L.data[s]��L.data[m]�����ɴ󶥶�
void HeapAdjust(SqList &L, int s, int m) {
	int rc = L.data[s];

	for (int j = s * 2;j <= m;j = j * 2) {
		if (j < m && (L.data[j] <= L.data[j + 1]))//��¼s�����������нϴ���Ǹ����ӵ�����
			j++;
		if (rc > L.data[j])//rc������������Ͳ��û��ˣ��˳�
			break;
		L.data[s] = L.data[j];
		s = j;	
	}
	L.data[s] = rc;
}

void HeapSort(SqList &L) {
	for (int i = L.length / 2;i > 0;i--) {
		HeapAdjust(L, i, L.length);//��L���ɴ󶥶�
	}
	for (int i = L.length;i > 1;i--) {
		int temp = L.data[1];//������һ�������һ��������
		L.data[1] = L.data[i];
		L.data[i] = temp;
		HeapAdjust(L, 1, i - 1);//��1--i-1��������
	}
}