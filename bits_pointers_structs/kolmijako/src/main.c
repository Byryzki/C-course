#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "kolmijako.h"
#include "pikalaj.h"

int main(void)  /*Segmentointivirhe jossain???*/
{
  int i;
  int t[8];
  srand(time(NULL));
  for(i = 0; i < 8; i++){t[i] = rand() % 101; printf("%d ", t[i]);} printf("\n"); /*Musn't be same numbers*/
  //int t[8] = {1, 2, 8, 5, 10, 7, 4, 9};
  int x = 0;  /* Will receive less1 via a pointer parameter. */
  int y = 0;  /* Will receive less2 via a pointer parameter. */
  /* IntPari object ip receives less1 and less2 from the return value. */
  //IntPari ip = kolmijako(8, t, 4, 1, &x, &y);

  pikalajittele(0, 7, t);

  i = 0;
  int ii = 0;
  for(ii=0; ii<8; ii++){printf("%d ", t[ii]);} printf("\n");

  for(i = 0; i < 7; ++i)
  { /* Verify that each value is in a legal position with respect to the pivots 2 and 7. */
    if(((i < x) && (t[i] >= 2)) || ((i < y) && (t[i] >= 7)))
    {
      printf("Alkioiden järjestys laiton\n"); /* A value was in an illegal position! */
      break;
    }
  }
  return 0;
}