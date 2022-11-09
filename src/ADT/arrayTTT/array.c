#include "array.h"

void CreateArr(TabChr *T)
{
    T->Neff = 0;
}

int LengthArr(TabChr T)
{
    return T.Neff;
}

ElTypeArr GetArr(TabChr T, IdxType i)
{
    return T.TI[i];
}

void CopyArr(TabChr Tin, TabChr *Tout)
{
    int i;
    for (i = 0; i < LengthArr(Tin); i++)
    {
        Tout->TI[i] = Tin.TI[i];
    }
    Tout->Neff = Tin.Neff;
}

void SetArr(TabChr *T, IdxType i, ElTypeArr v)
{
    T->TI[i] = v;
    if (i >= T->Neff)
        SetNeffArr(T, T->Neff + 1);
}

void SetNeffArr(TabChr *T, IdxType N)
{
    T->Neff = N;
}

boolean IsEmptyArr(TabChr T)
{
    return T.Neff == 0;
}

boolean IsFullArr(TabChr T)
{
    return T.Neff == CAPACITY;
}

void PrintArr(TabChr T)
{
    if (IsEmptyArr(T))
        printf("Tabel kosong\n");
    else
    {
        int i;
        for (i = 0; i < LengthArr(T); i++)
        {
            // printf("%d\n", i);
            printf("%c\n", T.TI[i]);
        }
    }
}