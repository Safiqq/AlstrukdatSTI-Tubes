#include <stdio.h>
#include "../mesinkarakter/mesinkarakter.h"
#include "mesinkata.h"

char currentChar;
boolean EndWord;
Word currentWord;

void ConcatWords(Word *str1, char separator, Word str2)
{
    int i = str1->Length, j, temp = str1->Length;
    if (separator != '\0')
    {
        str1->TabWord[i] = separator;
        i++;
    }
    for (j = 0; j < str2.Length; j++)
    {
        str1->TabWord[i] = str2.TabWord[j];
        i++;
    }
    str1->TabWord[i] = '\0';
    str1->Length = i;
}

void IgnoreBlanks()
{
    while (GetCC() == BLANK)
    {
        ADV();
    }
}

void IgnoreLines()
{
    while (GetCC() == NEWLINE)
    {
        ADV();
    }
}

void STARTWORD()
{
    START();
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

void ADVLINE()
{
    IgnoreLines();
    int count = 0;
    ADVWORD();
    Word tempWord = currentWord;
    while (!IsEOP() && GetCC() != NEWLINE)
    {
        ADVWORD();
        ConcatWords(&tempWord, ' ', currentWord);
        count++;
    }
    if (count > 0)
        currentWord = tempWord;
    IgnoreLines();
}

void CopyWord()
{
    int i = 0;
    while (!IsEOP() && GetCC() != MARK && GetCC() != BLANK)
    {
        currentWord.TabWord[i] = GetCC();
        ADV();
        i++;
    }
    if (i < NMax)
        currentWord.Length = i;
    else
        currentWord.Length = NMax;
    currentWord.TabWord[i] = '\0';
}

boolean isEqual(Word str1, char *str2)
{
    int i = 0;
    boolean isDiffer = false;
    while (str1.TabWord[i] != '\0' && str2[i] != '\0' && !isDiffer)
    {
        if (str1.TabWord[i] != str2[i])
            isDiffer = true;
        i++;
    }
    return !isDiffer;
}