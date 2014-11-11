#include "LRU.h"
#include "aging.h"
#include <stdio.h>
#include <stdlib.h>
#define NUM_PAGES 20
int main()
{
	int memSize;
	int arr[NUM_PAGES]={1,2,3,4,2,1,5,6,2,1,2,3,7,6,3,2,1,2,3,6};
	scanf("%d",&memSize);
	LRU(arr,memSize,NUM_PAGES);
        agingPageAlgo(arr, memSize, NUM_PAGES);
	return 0;
	
}
