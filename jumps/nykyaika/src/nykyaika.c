#include <stdio.h>
#include <time.h>

int main()
{
    int day, month, year;
    int dayOfWeek;
    struct tm *date;
    time_t aika;
    char buffer[50];
    char pv[5];
    char *days[] = {"Sunnuntai", "Maanantai", "Tiistai", 
                    "Keskiviikko", "Torstai", "Perjantai", "Lauantai"};
    time(&aika);
    date = localtime(&aika);
    
    strftime(buffer, sizeof(buffer), "%d.%m.%Y klo %H:%M", date);
    strftime(pv, sizeof(pv), "%a", date);

    if(pv[0] == 'S' && pv[1] == 'u'){dayOfWeek = 0;}
    else if(pv[0] == 'M'){dayOfWeek = 1;}
    else if(pv[0] == 'T' && pv[1] == 'u'){dayOfWeek = 2;}
    else if(pv[0] == 'W'){dayOfWeek = 3;}
    else if(pv[0] == 'T' && pv[1] == 'h'){dayOfWeek = 4;}
    else if(pv[0] == 'F'){dayOfWeek = 5;}
    else if(pv[0] == 'S' && pv[1] == 'a'){dayOfWeek = 6;}

    printf("%s ", days[dayOfWeek]);
    printf("%s\n", buffer);


    
    return 0;
}