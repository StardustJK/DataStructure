#include"Generate.h"
#include"InsertionSort.h"
#include"ShellSort.h"
#include"BubbleSort.h"
#include"QuickSort.h"
#include"SelectionSort.h"
#include"HeapSort.h"
#include"MergeSort.h"
#define LENGTH 100
//#define LENGTH 8
int main() {
	int a[LENGTH+1];
	Generate(a, LENGTH);
	showList(a, LENGTH);
	
	//int a[LENGTH+1] = { 0,5,3,6,12,34,12,3,1 };
//	InsertionSort(a, LENGTH);
	//ShellSort(a, LENGTH);
//	BubbleSort(a, LENGTH);
//	QuickSort(a, LENGTH);
	//SelectionSort(a, LENGTH);
//	HeapSort(a, LENGTH);
	MergeSort(a, LENGTH);
	showList(a, LENGTH);
	return 0;
}