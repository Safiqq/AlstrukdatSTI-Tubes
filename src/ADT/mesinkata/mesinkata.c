#include "mesinkata.h"

char currentChar;
boolean EndWord;
Word currentWord;

int StringLength(char *str)
{
    int i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}

boolean isEqual(Word str1, char *str2)
{
    int i = 0;
    boolean checker = (str1.Length == StringLength(str2));
    while (str1.TabWord[i] != '\0' && str2[i] != '\0' && checker)
    {
        if (str1.TabWord[i] != str2[i])
            checker = false;
        i++;
    }
    return checker;
}

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
        ADV();
}

void IgnoreLines()
{
    while (GetCC() == NEWLINE)
        ADV();
}

void STARTWORD(char *path, char *type)
{
    START(path, type);
    ADVWORD();
}

void ADVWORD()
{
    IgnoreBlanks();
    if (GetCC() == BLANK || GetCC() == MARK)
        EndWord = true;
    else
    {
        EndWord = false;
        CopyWord();
    }
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
    while (!IsEOP() && !EndWord)
    {
        currentWord.TabWord[i] = GetCC();
        ADV();
        if (GetCC() == BLANK || GetCC() == MARK)
            EndWord = true;
        i++;
    }
    if (i < NMax)
        currentWord.Length = i;
    else
        currentWord.Length = NMax;
    currentWord.TabWord[i] = '\0';
}
