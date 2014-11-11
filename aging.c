#include "aging.h"
//return the first mem slot that is available if there is free memory availble, return -1
int findFirstAvailMem(int *physicalMem, int size)
{
  for (int i = 0 ; i <size; i++)
  {
    if (physicalMem[i] == -1)
    {
      return i;
    }
  }
  return -1;
}


void updateAge(int *agingTable, int size, int accessedIndex)
{
    agingTable[accessedIndex] = agingTable[accessedIndex]/2;
    agingTable[accessedIndex] = agingTable[accessedIndex] + 1;
}

int findOldestPageIndex(int *agingTable, int size)
{
  int index = 0;
  for (int i = 0; i<size; i++)
  {
    if (agingTable[i]< agingTable[index])
    {
      index = i;
    }
  }
  return index;
}


int existe(int *physicalMem, int size, int request)
{
  for (int i = 0 ; i<size; i++)
  {
    if (request == physicalMem[i])
    {
      return i;
    }
  }
  return 0;
}


void agingPageAlgo(int *memRequest, int physicalMemSize, int numOfPages)
{


  int missedCount = 0;
  //On define un tableau pour record l'age de chaque page
  int *agingTable = malloc(physicalMemSize*sizeof(int));
  int *physicalMem =malloc(physicalMemSize*sizeof(int));

  //initialize the memory content to -1, which means not occupied
  for (int i = 0; i< physicalMemSize; i++)
  {
    physicalMem[i] = -1;
  }


  //initialiser chaque age de page
  for (int i = 0; i< physicalMemSize; i++)
  {
    agingTable[i] = 0;
  }

  printf("ini finished\n");
  //Ici, on va lance la simlation l'acess de memoire/page
  //Sur chaque access(clock), l'age de page accede est augemente par 1, pour les autre pages, l'age augement rest la meme;
  //pour eviter le probleme qui se produis quand on access zone 1 de page tres frequentement dans la premier period, et puis on accede que zone 2 de VM frequent, on essayer de divider par 2 avant de augementer, c'est pour diminuit l'effect d'access tres anciens;

  //Ici on commance la simulation d'access
  for (int i = 0; i<numOfPages; i++)
  {
    //premierement on va voir si la page demande existe deja dans le memoir physical
    if(existe(physicalMem, physicalMemSize, memRequest[i]))
    {
      //OK, la donne demander existe deja dans le memoir physique!
      printf("Cache Hit for memory access: %d!\n", memRequest[i]);
      continue;
    }
    else
    {
      //Page Fault, on a besion de "Page in"
      printf("Page fault for memory access: %d\n", memRequest[i]);
      int freeMemIndex = findFirstAvailMem(physicalMem, physicalMemSize); 
      if (freeMemIndex != -1)
      {
        //On a encore de memoir physique
        printf("We still got free Memeory, loading %d\n", memRequest[i]);
        physicalMem[freeMemIndex] = memRequest[i];
        updateAge(agingTable, physicalMemSize, i);
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
  printf("Miss rate: %f", (float)missedCount/numOfPages);
}
