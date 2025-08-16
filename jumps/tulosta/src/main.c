#include <stdio.h>
#include <stdlib.h>

#include "tulosta.h"

int main(int arc, char **argv)
{
    size_t pit = tulosta(stdout, "%s%%\n", "Hello World");
    pit = tulosta(stdout, "Tulostui %d merkkiä\n", (int) pit);
    pit = tulosta(stdout, "%c%c sitten %d merkkiä\n", 'J', 'a', (int) pit);
    tulosta(stdout, "Tulostui %d merkkiä\n", (int) pit);

    return 0;
}