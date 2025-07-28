#include <stdio.h>
#include <stdlib.h>
#include "kertotaulu.h"

int main(int argc, char *argv[])
{ /* argv[1]...argv[4] are assumed to give the parameters a, b, c ja d. */
  Kertotaulu *kt = luoKertotaulu(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4]));
  uint i = 0;
  uint j = 0;
  for(i = 0; i <= (kt->d - kt->c + 1); ++i)    /* Rows. */
  {
    for(j = 0; j <= (kt->b - kt->a + 1); ++j)  /* Columns. */
    {
      if((i > 0) || (j > 0)) /* Check that we are not at [0][0]. */
      {
         printf("%4u", kt->kertotaulu[i][j]); /* Print using 4-character width. */
      }
      else
      {
         printf("    "); /* The empty top left index [0][0] gets 4 spaces. */
      }
    }
    printf("\n");
  }
  tuhoaKertotaulu(kt);
  return 0;
}