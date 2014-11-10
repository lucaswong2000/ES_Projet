#ifndef LRU_H
#define LRU_H
#define MAX_INT 1000;
typedef struct{
	int status;
	int time;
	int num;
}Page;
int LRU(int*arr,int memSize,int pageSize);
int isExist(Page*pageArr,int memSize,int page);
int isFree(Page*pageArr,int memSize);
void init(Page*pageArr,int pageSize);
int maxTime(Page*pageArr,int memSize);
void increaseTime(Page*pageArr,int memSize,int page);

#endif
