#include <stdlib.h>
#include "boolean.h"
#include "./ADT/mesinkata/mesinkata.h"
#include "./ADT/array/array.h"

boolean isEqualStr(char *str1, char *str2)
{
    int i = 0;
    boolean checker = (StringLength(str1) == StringLength(str2));
    while (str1[i] != '\0' && str2[i] != '\0' && checker)
    {
        if (str1[i] != str2[i])
            checker = false;
        i++;
    }
    return checker;
}

void createGame(char *name, TabStr *games)
{
    printf("Masukkan nama game yang akan ditambahkan: ");
    STARTWORD("", "");
    int count = 0;
    Word tempWord = currentWord;
    while (!IsEOP() && GetCC() != NEWLINE)
    {
        ADVWORD();
        ConcatWords(&tempWord, ' ', currentWord);
        count++;
    }
    if (count > 0)
        currentWord = tempWord;
    int i = 0, j;
    char *temp;
    boolean isAvail = true;
    while (i < games->Neff && isAvail)
    {
        if (isEqualStr(games->TI[i], name))
            isAvail = false;
        i++;
    }
    if (isAvail)
    {
        temp = (char *)malloc(sizeof(char *) * (CAPACITY));
        j = 0;
        while (currentWord.TabWord[j] != '\0')
        {
            temp[j] = currentWord.TabWord[j];
            j++;
        }
        temp[j] = '\0';
        SetArray(games, games->Neff, temp);
        printf("Game berhasil ditambahkan.\n");
    }
    else
        printf("Sudah ada game dengan nama %s.\n", name);
}