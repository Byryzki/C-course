#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

DblSolmu * ds_luo(double data, DblSolmu *seur)
{
  DblSolmu *ds = malloc(sizeof(DblSolmu));
  ds->data = data;
  ds->seur = seur;
  return ds;
}

DblLista * dl_luo(void)
{
  DblLista *dl = malloc(sizeof(DblLista));
  dl->n = 0;
  dl->paa = NULL;
  return dl;
}

void dl_tuhoa(DblLista *dl)
{
  while(dl->n > 0)
  {
    dl_poistaEdesta(dl);
  }
  free(dl);
}

DblSolmu * dl_lisaaEteen(DblLista *dl, double arvo)
{
  dl->paa = ds_luo(arvo, dl->paa);
  dl->n += 1;
  return dl->paa;
}

double dl_poistaEdesta(DblLista *dl)
{
  double arvo = 0;
  if(dl->n > 0)
  {
    DblSolmu *vanhaPaa = dl->paa;
    arvo = dl->paa->data;
    dl->paa = dl->paa->seur;
    free(vanhaPaa);
    dl->n -= 1;
  }
  return arvo;
}

void dl_tulosta(const DblLista *lista)
{
  DblSolmu *s;
  printf("Lista:");
  for(s = lista->paa; s != NULL; s = s->seur)
  {
    printf(" %.1f", s->data);
  }
  printf("\n");
}

double dl_alkio(const DblLista *lista, size_t i)
{
    DblSolmu *s;
    double result;
    
    s = lista->paa;
    for(i; i>0; i--){s = s->seur;}

    result = s->data;

    return result;
}

DblSolmu * dl_lisaa(DblLista *lista, size_t i, double arvo)
{
    int j = 0;
    int no_s = 0;
    int no_e = 0;
    DblSolmu *u;
    DblSolmu *old;
    DblSolmu *old_pre;

    if(i >= lista->n)   /*illegal index*/
    {
        i = lista->n;
        no_s = 1;
    }

    u = malloc(sizeof(DblSolmu));   /*empty struct pointer*/
    old = malloc(sizeof(DblSolmu));   /*empty struct pointer*/
    old_pre = malloc(sizeof(DblSolmu));   /*empty struct pointer*/
    
    if(lista->n == 0)   /*empty list*/
    {
        u->data = arvo;
        u->seur = NULL;
        lista->paa = u;
        lista->n++;

        return u;
    }
    else if(lista->n == 1)  /*only one in list*/
    {
        if(i==0)
        {
            u->data = arvo;
            u->seur = lista->paa;
            lista->paa = u;
        }
        else
        {
            u->data = arvo;
            lista->paa->seur = u;
        }
        
        lista->n++;

        return u;
    }
    else
    {
        if(i==0)    /*append to paa*/
        {
            old = lista->paa;
            u->seur = old;
            lista->paa = u;
        }
        else if(i==lista->n)    /*new last element*/
        {
            for(old = lista->paa; old->seur != NULL; old->seur)
            {
                old = old->seur;
            }

            old->seur = u;
        }
        else    /*in between*/
        {
            old = lista->paa;
            for(j=0; j<i; j++)
            {
                if(j == i-1)
                {
                    old_pre = old;
                }

                old = old->seur;
            }

            old_pre->seur = u;
            u->seur = old;
        }

        u->data = arvo;
        lista->n++;
    }

    

    return u;
    
}

double dl_poista(DblLista *lista, size_t i)
{
    int j = 0;
    DblSolmu *u;
    DblSolmu *succ;
    DblSolmu *pre;
    double removed;

    if(i > lista->n || lista->n == 0){
        return 0;} /*illegal index or list empty*/

    if(lista->paa->seur == NULL)    /*listassa yksi alkio*/
    {
        removed = lista->paa->data;
        free(lista->paa);
        lista->n--;

        return removed;
    }
    else
    {
        j=0;
        for(u = lista->paa; u != NULL; u->seur)
        {
            if(j == i-1){pre = u;}
            else if(j == i)
            {
                if(u->seur == NULL){pre->seur = NULL;}  /*i on vika*/
                else if(i==0)   /*i on 0*/
                {
                    lista->paa = u->seur;
                }
                else
                {
                    succ = u->seur;
                    pre->seur = succ;
                }
            
                removed = u->data;
                free(u);
                lista->n--;

                break;
            }

            u = u->seur;
            j++;
        }
    }

    return removed;
}