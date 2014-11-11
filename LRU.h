#ifndef LRU_H
#define LRU_H
#define MAX_INT 1000;
/**
 *  A struct used to represent the physical memory page.
 */
typedef struct{
	int status;
	int time;
	int num;
}Page;
int LRU(int*arr,int memSize,int pageSize);
/**
 *  A function used to test if the page needed is already is in the physical memory.
 */
int isExist(Page*pageArr,int memSize,int page);
/**
 * A function used to test if the physical memory is full.
 */
int isFree(Page*pageArr,int memSize);
/**
 * A function used to init the physical memory frame.
 */
void init(Page*pageArr,int pageSize);
/**
 * A function used to to get the frame which will be replaced(LRU frame) from the physical memory.
 */
int maxTime(Page*pageArr,int memSize);
/**
 * A function used to increase the time for all the frame.
 */
void increaseTime(Page*pageArr,int memSize,int page);

#endif
