/*#pragma once
#include<stdio.h>

void ShellSort(int a[], int length) {
	int compare = 0,change=0;
	int d = length;
	for (d = d / 2;d>=1;d = d / 2) {
		for (int i = d + 1;i <= length;i++) {
			compare++;
			if (a[i] < a[i - d]) {
				a[0] = a[i];
				change++;
				int j;
				for (j = i - d;j > 0 && (a[j] > a[0]);j=j-d) {
					a[j + d] = a[j];
					change++;
					compare++;
				}
				a[j + d] = a[0];
				change++;
			}
		}
	}
	printf("比较次数：%d,交换次数：%d\n", compare, change);
}*/
#pragma once
#include<stdio.h>
#include"Student.h"
void ShellSort(Student a[], int length) {
	int d = length;
	for (d = d / 2;d >= 1;d = d / 2) {
		for (int i = d + 1;i <= length;i++) {
			if (a[i].total < a[i - d].total) {
				a[0] = a[i];
				int j;
				for (j = i - d;j > 0 && (a[j].total > a[0].total);j = j - d) {
					a[j + d] = a[j];
				}
				a[j + d] = a[0];
			}
		}
	}
}