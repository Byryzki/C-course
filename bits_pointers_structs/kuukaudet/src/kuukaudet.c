#include "kuukaudet.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int karkausvuosi(int y)
{
    int kv = 0;
    if(y % 4 == 0)
    {
        if(y % 100 == 0)
        {
            if(y % 400 == 0)
            {
                kv = 1;
            }
        }
        else{kv = 1;}
    }

    return kv;
}

char kkPituus(const char *monthName, int y)
{
    int i;
    int ii;

    const char *KK_NIMET[KK_LKM] = {"tammikuu", "helmikuu", "maaliskuu", "huhtikuu", "toukokuu", "kesakuu", "heinakuu", "elokuu", "syyskuu", "lokakuu", "marraskuu", "joulukuu"};
    const char KK_PAIVAT[2][KK_LKM] = {{31,28,31,30,31,30,31,31,30,31,30,31},{31,29,31,30,31,30,31,31,30,31,30,31}};

    for(i=0; i<12; i++)
    {
        for(ii=0; i < strlen(monthName); ii++)
        {
            char a = tolower(monthName[ii]);
            char b = KK_NIMET[i][ii];
            
            if(!(a == b)){break;}
        }
        if(ii == strlen(monthName)+1)   /*match found!*/
        {
            return KK_PAIVAT[karkausvuosi(y)][i];
        }
    }

    return -1;
}