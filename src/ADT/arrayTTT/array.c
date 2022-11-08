#include <stdio.h>
#include "array.h"

void CreateArray(Tab *T)
{
    T->Neff = 0;
}

int LengthArray(Tab T)
{
    return T.Neff;
}

ElType GetArray(Tab T, IdxType i)
{
    return T.TI[i];
}

void CopyArray(Tab Tin, Tab *Tout)
{
    int i;
    for (i = 0; i < LengthArray(Tin); i++)
    {
        Tout->TI[i] = Tin.TI[i];
    }
    Tout->Neff = Tin.Neff;
}

void SetArray(Tab *T, IdxType i, ElType v)
{
    T->TI[i] = v;
    if (i >= T->Neff)
        SetNeffArray(T, T->Neff + 1);
}

void SetNeffArray(Tab *T, IdxType N)
{
    T->Neff = N;
}

boolean IsEmptyArray(Tab T)
{
    return T.Neff == 0;
}

boolean IsFullArray(Tab T)
{
    return T.Neff == CAPACITY;
}

void PrintArray(Tab T)
{
    if (IsEmptyArray(T))
        printf("Tabel kosong\n");
    else
    {
        int i;
        for (i = 0; i < LengthArray(T); i++)
        {
            // printf("%d\n", i);
            printf("%c\n", T.TI[i]);
        }
    }
}