void agingPageAlgo(int *memRequest, int physicalMemSize, int virtMemSize)
{
  //On define un tableau pour record l'age de chaque page
  int agingTable[physicalMemSize] = {};
  //initialiser chaque age de page
  for (int i = 0; i< physicalMemSize; i++)
  {
    agingTable[i] = 0;
  }

  //Ici, on va lance la simlation l'acess de memoire/page
  //Sur chaque access(clock), l'age de page accede est augemente par 1, pour les autre pages, l'age augement rest la meme;
  //pour eviter le probleme qui se produis quand on access zone 1 de page tres frequentement dans la premier period, et puis on accede que zone 2 de VM frequent, on essayer de divider par 2 avant de augementer, c'est pour diminuit l'effect d'access tres anciens;

  //Ici on commance la simulation d'access
  for (int i = 0; i<virtMemSize, i++)
  {
    //premierement on va voir si la page demande existe deja dans le memoir physical
    if(existe(memRequest[i]))
    {
      //OK, la donne demander existe deja dans le memoir physique!
      printf("Cache Hit pour mem request: %d!\n", memRequest[i]);
      continue;
    }
    else
    {
      //Page Fault, on a besion de "Page in"
      //TODO pagein code
      //if there is still free phsical memroy available...
      //
      //if there is no physical memory available....
      //TODO page out
      //TODO page in
      //TODO return data accessed
      //
      //
      //Apres, on va mettre a jour le tableau de record pour l'age de page
      //TODO update record tableau code
      //
      //
}
