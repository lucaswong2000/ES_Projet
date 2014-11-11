#include"LRU.h"
#include"linkLRU.h"
#include<time.h>
#define NUM_PAGES 20
int main()
{
	int memSize;
	int arr[NUM_PAGES]={1,2,3,4,2,1,5,6,2,1,2,3,7,6,3,2,1,2,3,6};
	int arr2[10000];
	srand(time(NULL));
	int i=0;
	for(i=0;i<10000;i++)
	{
		arr2[i]=rand()%100;
	}
	scanf("%d",&memSize);
	LRU(arr,memSize,NUM_PAGES);
	linkLRU(arr,memSize,NUM_PAGES);
	LRU(arr2,memSize,10000);
	linkLRU(arr2,memSize,10000);
	return 0;
	
}
