#include "../header/creategame.h"

void createGame(char *name, ArrayStr *games, ArrayMap *arrSB)
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
        SetAS(games, games->Neff, temp);
        InsertLastAM(arrSB);
        printf("Game berhasil ditambahkan.\n");
    }
    else
        printf("Sudah ada game dengan nama %s.\n", name);
}