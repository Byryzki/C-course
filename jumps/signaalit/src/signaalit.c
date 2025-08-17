#include "signaalit.h"
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <setjmp.h>

void hoidaSIGFPE(int s)
{
    longjmp(paluuTila, SIGFPE);
}

void hoidaSIGSEGV(int s)
{
    longjmp(paluuTila, SIGSEGV);
}