#include <stdio.h>
#include "../mesinkarakter/mesinkarakter.h"
#include "mesinkata.h"

boolean EndWord;
Word currentWord;

void IgnoreBlanks()
{
    while (GetCC() == BLANK)
    {
        ADV();
    }
}

void STARTWORD(boolean isConfig)
{
    START(isConfig);
    IgnoreBlanks();
    if (GetCC() == MARK)
        EndWord = true;
    else
    {
        EndWord = false;
        CopyWord();
    }
}

void ADVWORD()
{
    IgnoreBlanks();
    if (GetCC() == MARK)
        EndWord = true;
    else
        CopyWord();
    IgnoreBlanks();
}

void CopyWord()
{
    int i = 0;
    while ((GetCC() != MARK) && (GetCC() != BLANK))
    {
        currentWord.TabWord[i] = GetCC();
        ADV();
        i++;
    }
    currentWord.Length = i;
    if (i < NMax)
        currentWord.Length = i;
    else
        currentWord.Length = NMax;
}

void CopyLine()
{

}
