/*#include"Generate.h"
#include"InsertionSort.h"
#include"ShellSort.h"
#include"BubbleSort.h"
#include"QuickSort.h"
#include"SelectionSort.h"
#include"HeapSort.h"
#include"MergeSort.h"
#define LENGTH 110

//#define LENGTH 8
int main() {
	int a[LENGTH+1];
	Generate(a, LENGTH);
	printf("��ʼ����\n");
	showList(a, LENGTH);
	
	//InsertionSort(a, LENGTH);
	//ShellSort(a, LENGTH);
//	BubbleSort(a, LENGTH);
//	QuickSort(a, LENGTH);
//	SelectionSort(a, LENGTH);
	//HeapSort(a, LENGTH);
	MergeSort(a, LENGTH);
	printf("����������\n");
	showList(a, LENGTH);
	return 0;
}*/
#include"ShellSort.h"
#include"Student.h"
int main() {
	Student stu[STUDENT_NUM+1];
	initStu(stu);
	printf("��ʼ����\n");
	showStu(stu);
	ShellSort(stu, STUDENT_NUM);
	printf("�ɼ���\n");
	showRank(stu);
	return 0;
}