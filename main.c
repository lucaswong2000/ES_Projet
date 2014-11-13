<<<<<<< HEAD
#include "LRU.h"
#include "linkLRU.h"
#include "aging.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

=======
#include"LRU.h"
#include"linkLRU.h"
#include "random.h"
#include<time.h>
>>>>>>> random
#define NUM_PAGES 20
#define NUM_PAGES1 3000
#define NUM_PAGES2 5000
#define NUM_PAGES3 70000
#define NUM_PAGES4 9000
#define NUM_PAGES5 10000
#define NUM_PAGES6 12000
#define NUM_PAGES7 14000

#define MAX_VALUE1 10
#define MAX_VALUE2 50
#define MAX_VALUE3 50
#define MAX_VALUE4 200
#define MAX_VALUE5 500
#define MAX_VALUE6 1000

#define MEM_SIZE1 5
#define MEM_SIZE2 10
#define MEM_SIZE3 20
#define MEM_SIZE4 30
#define MEM_SIZE5 40
#define MEM_SIZE6 50
#define MEM_SIZE7 100
#define MEM_SIZE8 150
#define MEM_SIZE9 200

#define RAND(arr,size,max) {int i=0;for(i=0;i<size;++i){arr[i]=rand()%max;}}
int main()
{
	int memSize;
	int arr[NUM_PAGES]={1,2,3,4,2,1,5,6,2,1,2,3,7,6,3,2,1,2,3,6};
	int i=0;
	printf("Le suite est: ");
	for(i=0;i<NUM_PAGES;++i)
	{
		printf("%d  ",arr[i]);
	}
	printf("\n");
	int arr1[NUM_PAGES1];
	int arr2[NUM_PAGES2];
	int arr3[NUM_PAGES3];
	int arr4[NUM_PAGES4];
	int arr5[NUM_PAGES5];
	int arr6[NUM_PAGES6];
	int arr7[NUM_PAGES7];
	srand(time(NULL));
	RAND(arr1,NUM_PAGES1,MAX_VALUE3);
	RAND(arr2,NUM_PAGES2,MAX_VALUE3);
	RAND(arr3,NUM_PAGES3,MAX_VALUE3);
	RAND(arr4,NUM_PAGES4,MAX_VALUE3);
	RAND(arr5,NUM_PAGES5,MAX_VALUE3);
	RAND(arr6,NUM_PAGES6,MAX_VALUE3);
	RAND(arr7,NUM_PAGES7,MAX_VALUE3);

	memSize=33;
	//scanf("%d",&memSize);
	memSize=20;
	printf("-----------------------LRU--------------------------\n");
	LRU(arr,memSize,NUM_PAGES);
	printf("-----------------------FIFO--------------------------\n");
	
	printf("-----------------------Aging--------------------------\n");
        agingPageAlgo(arr3, memSize, NUM_PAGES	);
	printf("-----------------------RANDOM--------------------------\n");
	Random(arr,memSize,NUM_PAGES);	
	//linkLRU(arr,memSize,NUM_PAGES);
	LRU(arr7,memSize,NUM_PAGES7);
	Random(arr7,memSize,NUM_PAGES7);
	//linkLRU(arr2,memSize,10000);
	return 0;
	
}
