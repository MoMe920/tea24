#include <stdio.h> // wird fuer putc benötigt
#include "greet.h" // Vorwaertsdeklaration von gruss

void gruss(void)
{
    putc('A', stdout);
    putc('\n', stdout);
}