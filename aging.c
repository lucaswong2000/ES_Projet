#include "aging.h"
//return the first mem slot that is available if there is free memory availble, return -1
int findFirstAvailMem(int *physicalMem, int size)
{
  int i = 0;
  for (i = 0 ; i <size; i++)
  {
    if (physicalMem[i] == -1)
    {
      return i;
    }
  }
  return -1;
}


void updateAge(unsigned *agingTable, int size, int accessedIndex)
{
	int i = 0;
	for (i = 0 ; i< size; i++)
	{
		if (i == accessedIndex)
		{
		unsigned data = agingTable[accessedIndex];
		unsigned sign = 1;
		sign = sign<<(sizeof(unsigned)*8 - 1);	
		//printf("sign: %u\n", sign);
		//printf("data1: %u\n", data);

		data = data>>1;
		data = data|sign;
		//printf("data2: %u to be entered in %d \n", data, accessedIndex);
		agingTable[accessedIndex] = data;

		}
		else
		{
		unsigned data = agingTable[i];
		data = data>>1;
		agingTable[i] = data;
		}
	}

}

int findOldestPageIndex(unsigned *agingTable, int size)
{
  int index = 0;
  int min = 0;
  int i = 0;
  for ( i = 0; i<size; i++)
  {
    if (agingTable[i] <= min)
    {
	min = agingTable[i];
	index = i ;
    }
  }

  return index;
}


int existe(int *physicalMem, int size, int request)
{
  int i = 0;
  for (i = 0 ; i<size; i++)
  {
    if (request == physicalMem[i])
    {
      return i;
    }
  }
  return -1;
}


int agingPageAlgo(int *memRequest, int physicalMemSize, int numOfPages)
{

  int missedCount = 0;
  //On define un tableau pour record l'age de chaque page
  unsigned *agingTable = malloc(physicalMemSize*sizeof(unsigned));
  int *physicalMem =malloc(physicalMemSize*sizeof(int));

  //initialize the memory content to -1, which means not occupied
  int i = 0;
  for (i = 0; i< physicalMemSize; i++)
  {
    physicalMem[i] = -1;
  }


  //initialiser chaque age de page
  for (i = 0; i< physicalMemSize; i++)
  {
    agingTable[i] = 0;
  }

  if (debug)
  {
    printf("ini finished\n");
  }
  //Ici, on va lance la simlation l'acess de memoire/page
  //Sur chaque access(clock), l'age de page accede est augemente par 1, pour les autre pages, l'age augement rest la meme;
  //pour eviter le probleme qui se produis quand on access zone 1 de page tres frequentement dans la premier period, et puis on accede que zone 2 de VM frequent, on essayer de divider par 2 avant de augementer, c'est pour diminuit l'effect d'access tres anciens;

  //Ici on commance la simulation d'access
  for (i = 0; i<numOfPages; i++)
  {
    //premierement on va voir si la page demande existe deja dans le memoir physical
    int location = existe(physicalMem, physicalMemSize, memRequest[i]);
    if(location != -1)
    {
      //OK, la donne demander existe deja dans le memoir physique!
      if (debug)
      {
      printf("Cache Hit for memory access: %d!\n", memRequest[i]);
      }
      updateAge(agingTable, physicalMemSize, location);
    }
    else
    {
      //Page Fault, on a besion de "Page in"
      if (debug)
      {
        printf("Page fault for memory access: %d\n", memRequest[i]);
      }
      int freeMemIndex = findFirstAvailMem(physicalMem, physicalMemSize); 
      if (freeMemIndex != -1)
      {
        //On a encore de memoir physique
        if (debug)
        {
          printf("We still got free Memeory, loading %d\n", memRequest[i]);
        }
        physicalMem[freeMemIndex] = memRequest[i];
        updateAge(agingTable, physicalMemSize, freeMemIndex);
      }
      else
      {
        //there is no more pysical memory available....
        //1. let's find out the oldest page
        int oldestPage = findOldestPageIndex(agingTable, physicalMemSize);
        //2. Now let's PAGE OUT this page
        physicalMem[oldestPage] = -1;
        //3. Now paging in the new mem request
        physicalMem[oldestPage] = memRequest[i];
        updateAge(agingTable, physicalMemSize, oldestPage);
      }
      missedCount ++;
    }
  }
  ///printf("Miss rate: %.2f \n", (float)missedCount/numOfPages);
  //free(agingTable);
  //free(physicalMem);
  return missedCount;
}
