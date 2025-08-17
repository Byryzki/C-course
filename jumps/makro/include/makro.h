#ifndef MAKRO
#define MAKRO

#ifdef OTE_DEBUG
    #include <stdio.h>
#endif

#define PII "3.141592653589793"

#define MJ(x) x

#ifndef DESIMAALIT
    #define DESIMAALIT 3
#endif

#ifndef TYYPPI
    #define TYYPPI unsigned char
#endif

#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))

#define MIN3(a,b,c) (MIN(MIN((a),(b)),(c)))
#define MAX3(a,b,c) (MAX(MAX((a),(b)),(c)))

#define MIN4(a,b,c,d) (MIN(MIN3((a),(b),(c)),(d)))
#define MAX4(a,b,c,d) (MAX(MAX3((a),(b),(c)),(d)))

#ifdef OTE_DEBUG
    #define debug(msg) fprintf(stderr, msg)
#else
    #define debug(msg)
#endif

#endif