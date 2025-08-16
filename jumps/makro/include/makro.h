#ifdef OTE_DEBUG
    #include <stdio.h>
#endif

double PII = 3.141592653589793;

#define MJ(x) (char str[64]\
     sprintf(str, "\"%f\"", x))

#ifndef DESIMAALIT
    #define DESIMAALIT 3
#endif

#ifndef TYYPPI
    typedef unsigned char TYYPPI;
#endif

#define MIN(a,b) ((a < b) ? a : b)

#define MAX(a,b) ((a > b) ? a : b)

#define MIN3(a,b,c) ((MIN(a,b) < c) ? MIN(a,b) : c)

#define MAX3(a,b,c) ((MAX(a,b) > c) ? MAX(a,b) : c)

#define MIN4(a,b,c,d) ((MIN3(a,b,c) < d) ? MIN3(a,b,c) : d)

#define MAX4(a,b,c,d) ((MAX3(a,b,c) > d) ? MAX3(a,b,c) : d)

#ifdef OTE_DEBUG
    #define debug(msg) (fprintf(stderr, msg))
#else
    #define debug(msg) ((void)0)
#endif