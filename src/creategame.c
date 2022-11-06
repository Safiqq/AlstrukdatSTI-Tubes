#include "./ADT/mesinkata/mesinkata.h"
#include "./ADT/array/array.h"
#include "boolean.h"

boolean isEqualStr(char *str1, char *str2)
{
    int i = 0;
    boolean isDiffer = false;
    while (str1[i] != '\0' && str2[i] != '\0' && !isDiffer)
    {
        if (str1[i] != str2[i])
            isDiffer = true;
        i++;
    }
    return !isDiffer;
}

void createGame(char *name, TabStr *T)
{
    int i = 0, j = 0;
    boolean isAvail = true;
    while (i < T->Neff && isAvail)
    {
        if (isEqualStr(T->TI[i], name))
            isAvail = false;
        i++;
    }
    if (isAvail)
    {
        T->TI[T->Neff] = name;
        T->Neff++;
        printf("Game berhasil ditambahkan.\n");
    }
    else
        printf("Sudah ada game dengan nama %s.\n", name);
}
