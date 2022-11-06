#include "mesinkarakter.h"

int countMark;
int limitMark;
int retval;
char currentChar;
boolean isFile;

FILE *pita;
FILE *pitaFile;

void START(char *path, char *type)
{
    countMark = 0;
    if (isFile)
        pitaFile = fopen(path, type);
    else
        pita = stdin;
    ADV();
}

void ADV()
{
    retval = fscanf(isFile ? pitaFile : pita, "%c", &currentChar);
    if (retval < 0)
        fclose(isFile ? pitaFile : pita);
}

char GetCC()
{
    return currentChar;
}

boolean IsEOP()
{
    if (currentChar == MARK)
        countMark++;
    return retval == EOF;
}