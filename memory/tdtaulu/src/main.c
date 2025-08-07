#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tdtaulu.h"

int main(void)
{
  const char *nimi = "ote.bin";
  const unsigned int lkm = 3;
  const unsigned int n = lkm*3; /*muokkaa takaisin 100*/
  unsigned int u = 0;
  double *dt = malloc(n*sizeof(double));
  char *dt_tavut = (char *) dt;
  double *dt2 = malloc(n*sizeof(double));
  char *dt2_tavut = (char *) dt2;
  int virhe = 0;
  TdTaulu *tdt = NULL;
  for(u = 0; u < n; ++u)
  { /* Arvotaan taulukkoon satunnaisia liukulukuja. */
    dt[u] = ((double) rand() / RAND_MAX)*rand();
  }
  tdt = luoTdTaulu(n, sizeof(double), nimi);
  for(u = 0; (u + lkm <= n) && (tdt != NULL) && (!virhe); u += lkm)
  { /* Kirjoitetaan dt:n arvot lkm alkiota kerrallaan tiedostotaulukkoon. */
    virhe = tdtKirj(tdt, u, lkm, &dt_tavut[u*sizeof(double)]);
  }
  vapautaTdTaulu(tdt); /* Suljetaan tiedostotaulukko. */
  tdt = avaaTdTaulu(nimi); /* Avataan olemassaoleva tiedostotaulukko. */
  for(u = 0; (u + lkm <= n) && (tdt != NULL) && (!virhe); u += lkm)
  { /* Luetaan tiedostotaulukon alkiot lkm alkiota kerrallaan taulukkoon dt2. */
    virhe = tdtLue(tdt, u, lkm, &dt2_tavut[u*sizeof(double)]);
  }
  if(memcmp(dt, dt2, n*sizeof(double)) == 0) /* Tuliko taulukkoon dt2 samat kuin dt:n arvot? */
  {
    printf("Tiedoston kirjoitus ja luku %d alkiota kerrallaan: ok!\n", lkm);
  }
  else
  {
    printf("Tiedoston kirjoitus ja luku %d alkiota kerrallaan: VIRHE!\n", lkm);
  }
  vapautaTdTaulu(tdt);
  remove(nimi);  /* Poistaa tiedoston. */
  free(dt);
  free(dt2);
  return 0;
}