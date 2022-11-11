#include "array.h"

void CreateArray(TabStr *T)
{
    T->Neff = 0;
}

int LengthArray(TabStr T)
{
    return T.Neff;
}


void SetArray(TabStr *T, IdxType i, ElTypeArray v)
{
    T->TI[i] = v;
    if (i >= T->Neff)
    {
        SetNeffArray(T, T->Neff + 1);
    }
}

void SetNeffArray(TabStr *T, IdxType N)
{
    T->Neff = N;
}

boolean IsEmptyArray(TabStr T)
{
    return T.Neff == 0;
}


void PrintArray(TabStr T)
{
    if (!IsEmptyArray(T))
    {
        int i;
        for (i = 0; i < LengthArray(T); i++)
        {
            printf("%d.%s\n", i + 1, T.TI[i]);
        }
    }
}