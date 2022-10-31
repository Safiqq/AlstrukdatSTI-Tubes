#include <stdio.h>
#include "mesinkarakter.h"

char currentChar;
boolean EOP;

static FILE *pita;

void START(boolean isConfig)
{
    pita = isConfig ? fopen("../data/config.txt", "r") : stdin;
    ADV();
}

void ADV()
{
    fscanf(pita, "%c", &currentChar);
    EOP = IsEOP();
    if (EOP)
        fclose(pita);
}

char GetCC()
{
    return currentChar;
}

boolean IsEOP()
{
    return currentChar == MARK;
}