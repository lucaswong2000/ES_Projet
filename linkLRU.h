#ifndef LINKLRU_H
#define LINKLRU_H
#include<stdio.h>
#include<stdlib.h>
typedef struct memPage{
	int pageNum;
	struct memPage*next;
}memPage;
int linkLRU(int*arr,int memSize,int pageSize );
#endif
