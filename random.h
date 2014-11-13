#ifndef RANDOM_H
#define RANDOM_H
#include"random.h"
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
void initial(int*pageArr,int memSize);
int isEx(int*pageArr,int memSize,int page);
int Random(int*arr,int memSize,int pageSize);
int notFull(int*pageArr,int memSize);
#endif

