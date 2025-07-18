#include <stdio.h>
#include <stdlib.h>
#include "utf8.h"


void utf8_koodaa(unsigned int c, unsigned char utf8[])
{
  int i;
  int k = 0;
  int bytes = 0;
  int bitit[32];
  int found = 0;

  unsigned int mask = 1 << 31;
  for(i = 0; i < 32; i++)  /*find MSB position*/
  {
    bitit[i] = (c & mask) ? 1 : 0;
    mask >>= 1;

    if(bitit[i] == 1 && !found)
    {
      k = 32-i;
      found = 1;
    }
  }
  if(!k){k = 1;}  /*value is 0*/

  if(k >= 0 && k <=7){bytes = 1;}
  else if(k > 7 && k <=11){bytes = 2;}
  else if(k > 11 && k <=16){bytes = 3;}
  else if(k > 16 && k <=21){bytes = 4;}
  else{printf("koodi liian pitkä!");}

  if(bytes == 1)
  {
    for(i=0; i<8; i++){utf8[0] |= (bitit[i] & 1) << (7-i);} /*construct char from bit array*/
  }
  else if(bytes == 2)
  {
    utf8[0] = 192; /*11000000*/
    utf8[1] = 128; /*10000000*/
    utf8[2] = '\0';

    for(i=0; i<5; i++){
      utf8[0] |= (bitit[32-11+i] & 1) << (4-i);}
    for(i=0; i<6; i++){
      utf8[1] |= (bitit[32-6+i] & 1) << (5-i);}
  }
  else if(bytes == 3)
  {
    utf8[0] = 224; /*11100000*/
    utf8[1] = 128; /*10000000*/
    utf8[2] = 128; /*10000000*/
    utf8[3] = '\0';

    for(i=0; i<5; i++){
      utf8[0] |= (bitit[32-20+i] & 1) << (4-i);}
    for(i=0; i<6; i++){
      utf8[1] |= (bitit[32-14+i] & 1) << (5-i);}
    for(i=0; i<6; i++){
      utf8[1] |= (bitit[32-6+i] & 1) << (5-i);}
  }
  else if(bytes == 4)
  {
    utf8[0] = 240; /*11110000*/
    utf8[1] = 128; /*10000000*/
    utf8[2] = 128; /*10000000*/
    utf8[3] = 128; /*10000000*/
    utf8[4] = '\0';

    for(i=0; i<5; i++){
      utf8[0] |= (bitit[32-27+i] & 1) << (4-i);}
    for(i=0; i<6; i++){
      utf8[1] |= (bitit[32-22+i] & 1) << (5-i);}
    for(i=0; i<6; i++){
      utf8[1] |= (bitit[32-14+i] & 1) << (5-i);}
    for(i=0; i<6; i++){
      utf8[1] |= (bitit[32-6+i] & 1) << (5-i);}
  }
  
}
