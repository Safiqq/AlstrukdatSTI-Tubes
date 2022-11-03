#include <stdio.h>
#include "array.h"

void MakeEmpty(TabStr *T)
{
    T->Neff = 0;
}

int NbElmt(TabStr T)
{
    return T.Neff;
}

int MaxNbEl(TabStr T)
{
    return IdxMax - IdxMin + 1;
}

IdxType GetFirstIdx(TabStr T)
{
    return IdxMin;
}

IdxType GetLastIdx(TabStr T)
{
    return T.Neff;
}

ArrElType GetElmt(TabStr T, IdxType i)
{
    return T.TI[i];
}

void SetTab(TabStr Tin, TabStr *Tout)
{
    int i;
    for (i = 0; i < NbElmt(Tin); i++)
    {
        Tout->TI[i] = Tin.TI[i];
    }
    Tout->Neff = Tin.Neff;
}

void SetEl(TabStr *T, IdxType i, ArrElType v)
{
    T->TI[i] = v;
    if (i >= T->Neff)
        SetNeff(T, T->Neff + 1);
}

void SetNeff(TabStr *T, IdxType N)
{
    T->Neff = N;
}

boolean IsIdxValid(TabStr T, IdxType i)
{
    return i >= IdxMin && i <= IdxMax;
}

boolean IsIdxEff(TabStr T, IdxType i)
{
    return i >= GetFirstIdx(T) && i <= GetLastIdx(T);
}

boolean IsEmpty(TabStr T)
{
    return T.Neff == 0;
}

boolean IsFull(TabStr T)
{
    return T.Neff == IdxMax;
}

void TulisIsi(TabStr T)
{
    if (IsEmpty(T))
        printf("Tabel kosong\n");
    else
    {
        int i;
        for (i = IdxMin; i < NbElmt(T); i++)
        {
            // printf("%d\n", i);
            printf("%s\n", T.TI[i]);
        }
    }
}