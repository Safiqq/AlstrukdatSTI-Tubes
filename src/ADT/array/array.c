#include <stdio.h>
#include "array.h"

void CreateArray(TabStr *T)
{
    T->Neff = 0;
}

int LengthArray(TabStr T)
{
    return T.Neff;
}

ElTypeArray GetArray(TabStr T, IdxType i)
{
    return T.TI[i];
}

void CopyArray(TabStr Tin, TabStr *Tout)
{
    int i;
    for (i = 0; i < LengthArray(Tin); i++)
    {
        Tout->TI[i] = Tin.TI[i];
    }
    Tout->Neff = Tin.Neff;
}

void SetArray(TabStr *T, IdxType i, ElTypeArray v)
{
    T->TI[i] = v;
    if (i >= T->Neff)
        SetNeffArray(T, T->Neff + 1);
}

void SetNeffArray(TabStr *T, IdxType N)
{
    T->Neff = N;
}

boolean IsEmptyArray(TabStr T)
{
    return T.Neff == 0;
}

boolean IsFullArray(TabStr T)
{
    return T.Neff == CAPACITY;
}

void PrintArray(TabStr T)
{
    if (IsEmptyArray(T))
        printf("Tabel kosong\n");
    else
    {
        int i;
        for (i = 0; i < LengthArray(T); i++)
        {
            // printf("%d\n", i);
            printf("%s\n", T.TI[i]);
        }
    }
}