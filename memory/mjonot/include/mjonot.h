#ifndef MOJONOT
#define MJONOT

#include <stddef.h>

char ** kopioi_mjt(char **strs, size_t n);

char ** jarjesta_mjt(char **strs, size_t n, int (*cmp)(const char*, const char *));


#endif