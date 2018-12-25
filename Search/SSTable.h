#pragma once
#define KeyType int
#define OtherType int
#define LIST_SIZE 20
typedef struct {
	KeyType key;
	OtherType other_data;
}ElemType;

typedef struct {
	ElemType *elem;//是从elem[1]开始存的
	int length = LIST_SIZE;
}SSTable;

void init_SSTable(SSTable &ST) {
	ST.elem = (ElemType*)malloc(sizeof(ElemType)*(LIST_SIZE + 1));
}

void showSSTable(SSTable ST) {
	for (int i = 1;i <= ST.length;i++) {
		printf("（%d）%d\n", i, ST.elem[i].key);
	}
}