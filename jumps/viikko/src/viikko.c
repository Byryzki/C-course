#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <locale.h>
#include "viikko.h"

void viikko(int pv, int kk, int vuosi)
{
    int i;
    time_t aika;
    char buffer[50];
    struct tm *date;

    date = calloc(sizeof(struct tm), 1);

    date->tm_mday = pv;
    date->tm_mon = kk - 1;
    date->tm_year = vuosi - 1900;

    aika = mktime(date);
    if(date->tm_wday == 0){date->tm_mday = pv - date->tm_wday - 6;} /*week overflow*/
    else{date->tm_mday = pv - date->tm_wday + 1;} /*modify to start from monday*/
    aika = mktime(date);

    for(i=0; i<7; i++)
    {
        strftime(buffer, sizeof(buffer), "%A %d. %B %Y", date);
        printf("%s\n", buffer);

        date->tm_mday++;
        aika = mktime(date);
    }

    free(date);
}