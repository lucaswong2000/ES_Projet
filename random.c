#include"random.h"
void initial(int*pageArr,int memSize)
{
	int i;
	for(i=0;i<memSize;i++)
	{
		pageArr[i]=-1;
	}	
}
int isEx(int*pageArr,int memSize,int page)
{
	int i=0;
	for(i=0;i<memSize;i++)
	{
		if(pageArr[i]==page)
			return i;
	}
	return -1;
}
int notFull(int*pageArr,int memSize)
{
	int i=0;
	for(i=0;i<memSize;i++)
	{
		if(pageArr[i]==-1)
			return i;
	}
	return -1;
}
int Random(int*arr,int memSize,int pageSize)
{
	srand(time(NULL));
	int nPageFault=0,i=0;
	int memNum;
	int*pageArr=(int*)malloc(memSize*sizeof(int));
	initial(pageArr,memSize);
	//printf("Les victimes sont: ");
	for(i=0;i<pageSize;i++)
	{
		if((memNum=isEx(pageArr,memSize,arr[i]))<0)
		{
			if((memNum=notFull(pageArr,memSize))>=0){
				pageArr[memNum]=arr[i];
			}else{
				memNum=rand()%memSize;
	//			printf("%d  ",pageArr[memNum]);
				pageArr[memNum]=arr[i];
			}
			nPageFault++;
		}
	}
	//printf("\n");
	//printf("Numero de Page Faults:%d\n",nPageFault);
	free(pageArr);
	return nPageFault;
	
}
