#include "signaalit.h"
#include <stdio.h>
#include <signal.h>
#include <setjmp.h>

void hoidaSIGFPE(int s)
{
    printf("Aiheutui signaali SIGFPE");
    exit(s);
}

void hoidaSIGSEGV(int s)
{
    printf("Aiheutui signaali SIGSEGV");
    exit(s);
}