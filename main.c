#include "LRU.h"
#include "linkLRU.h"
#include "aging.h"
#include "fifo.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MEM 20
#define VSIZE 100
#define NUM_PAGES 20
#define FIXED_SIZE 10000
#define MAX_VSIZE 1000
#define RAND(arr,from,to,min,range) {int i=0;for(i=(from);i<(to);++i){arr[i]=rand()%(range)+(min);}}
int main()
{
	int arr_t[NUM_PAGES]={1,2,3,4,2,1,5,6,2,1,2,3,7,6,3,2,1,2,3,6};
	int memSize[17]={100,150,200,250,300,350,400,450,500,550,600,650,700,750,800,850,900};
	int Request[11]={200,400,800,1600,3200,6400,12800,25600,51200,102400,204800};
	int i=0;
	int j=0;
	srand(time(NULL));
	printf(" ");
	for(j=0;j<11;j++)
	{
		int total1=0;
		int total2=0;
		int total3=0;
		int total4=0;
		int arr[Request[j]];
		for(i=0;i<30;i++)
		{
			srand(time(NULL));
			RAND(arr,0,Request[j]/3,0,VSIZE/3);
			RAND(arr,Request[j]/3,2*Request[j]/3, 0 , 2*VSIZE/3);
			RAND(arr,2*Request[j]/3,Request[j], 0 , VSIZE);
			
			total1+=LRU(arr,MEM,memSize[j]);
			total2+=agingPageAlgo(arr,MEM,memSize[j]);
			total3+=fifo(arr,MEM,memSize[j]);	
			total4+=Random(arr,MEM,memSize[j]);
		}
		printf("LRU rate   :%f\t",(float)(total1/30)/Request[j]);
		printf("Aging rate :%f\t",(float)(total2/30)/Request[j]);
		printf("fifo rate  :%f\t",(float)(total3/30)/Request[j]);
		printf("Random rate:%f\n",(float)(total4/30)/Request[j]);
		
	}
	printf("\n");
	for(j=0;j<17;j++)
	{
		int total1=0;
		int total2=0;
		int total3=0;
		int total4=0;
		int arr[FIXED_SIZE];
		for(i=0;i<30;i++)
		{
			srand(time(NULL));
			RAND(arr,0,FIXED_SIZE/3,0,MAX_VSIZE/3);
			RAND(arr,FIXED_SIZE/3,2*FIXED_SIZE/3, 0 , 2*MAX_VSIZE/3);
			RAND(arr,2*FIXED_SIZE/3,FIXED_SIZE, 0 , MAX_VSIZE);
			
			total1+=LRU(arr,memSize[j],FIXED_SIZE);
			total2+=agingPageAlgo(arr,memSize[j],FIXED_SIZE);
			total3+=fifo(arr,memSize[j],FIXED_SIZE);	
			total4+=Random(arr,memSize[j],FIXED_SIZE);
		}
		printf("LRU rate   :%f\t",(float)(total1/30)/FIXED_SIZE);
		printf("Aging rate :%f\t",(float)(total2/30)/FIXED_SIZE);
		printf("fifo rate  :%f\t",(float)(total3/30)/FIXED_SIZE);
		printf("Random rate:%f\n",(float)(total4/30)/FIXED_SIZE);
	}
	return 0;
	
}
