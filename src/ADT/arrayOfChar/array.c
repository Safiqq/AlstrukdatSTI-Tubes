#include "array.h"

void CreateArr(TabChr *T)
{
    T->Neff = 0;
}

int LengthArr(TabChr T)
{
    return T.Neff;
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