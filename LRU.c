#include"LRU.h"
#include<stdio.h>
#include<stdlib.h>
void init(Page*pageArr,int memSize)
{
	int i;
	for(i=0;i<memSize;i++)
	{
		pageArr[i].status=0;
		pageArr[i].time=MAX_INT;
		pageArr[i].num=-1;
	}	
}
int isExist(Page*pageArr,int memSize,int page)
{
	int i=0;
	for(i=0;i<memSize;i++)
	{
		if(pageArr[i].num==page)
			return i;
	}
	return -1;
}
int isFree(Page*pageArr,int memSize)
{
	int i=0;
	for(i=0;i<memSize;i++)
	{
		if(pageArr[i].status==0)
			return i;
	}
	return -1;
}
int maxTime(Page*pageArr,int memSize)
{
	int max=pageArr[0].time;
	int replaced=0;
	int i=0;
	for(i=1;i<memSize;i++)
	{
		if(max<pageArr[i].time)
		{
			max=pageArr[i].time;
			replaced=i;
		}
	}
	return replaced;
}
void increaseTime(Page*pageArr,int memSize,int memNum)
{
	int i=0;
	for(i=0;i<memSize;i++)
	{
		if((pageArr[i].status==1)&&(i!=memNum))
			pageArr[i].time++;
	}
}
int LRU(int*arr,int memSize,int pageSize)
{
	int nPageFault=0,i=0;
	int memNum;
	int replace;
	Page*pageArr=malloc(memSize*sizeof(Page));
	init(pageArr,memSize);
	printf("the sequence replaced : %d\t");
	for(i=0;i<pageSize;i++)
	{
		if((memNum=isExist(pageArr,memSize,arr[i]))>=0)
		{
		//	printf("aaaaa\n");
			pageArr[memNum].time=0;
			increaseTime(pageArr,memSize,memNum);
		}else if((memNum=isFree(pageArr,memSize))>=0){
			nPageFault++;	
			pageArr[memNum].status=1;
			pageArr[memNum].time=0;
			pageArr[memNum].num=arr[i];
			increaseTime(pageArr,memSize,memNum);
		}else{
			memNum=maxTime(pageArr,memSize);
			nPageFault++;
			printf("%d\t",pageArr[memNum].num);
			pageArr[memNum].status=1;
			pageArr[memNum].time=0;
			pageArr[memNum].num=arr[i];
			increaseTime(pageArr,memSize,memNum);
		}
	}
	printf("\n");
	printf("number of page faults:%d\n",nPageFault);
	return 0;
	
}
