#pragma once
#include<stdlib.h>
#include<stdio.h>
#include"SSTable.h"
//Ë³Ğò²éÕÒ/ÉÚ±øËã·¨
//Sequential search table


int S_search(SSTable ST, KeyType K) {
	ST.elem[0].key = K;
	int i = 0;
	for ( i = ST.length;ST.elem[i].key!=K;i--) {
		if (ST.elem[i].key == K)
			return i;
	}
	return i;
}