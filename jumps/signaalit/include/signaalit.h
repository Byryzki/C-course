#ifndef SIGNAALIT
#define SIGNAALIT
#include <stdio.h>
#include <setjmp.h>

extern jmp_buf paluuTila;

void hoidaSIGFPE(int s);
void hoidaSIGSEGV(int s);

#endif