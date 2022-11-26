#include "arrayStr.h"

void CreateAS(ArrayStr *T)
{
    T->Neff = 0;
}

int LengthAS(ArrayStr T)
{
    return T.Neff;
}

void SetAS(ArrayStr *T, IdxType i, ElTypeAS v)
{
    T->TI[i] = v;
    if (i >= T->Neff)
    {
        SetNeffAS(T, T->Neff + 1);
    }
}

void SetNeffAS(ArrayStr *T, IdxType N)
{
    T->Neff = N;
}

boolean IsEmptyAS(ArrayStr T)
{
    return T.Neff == 0;
}

void PrintAS(ArrayStr T)
{
    if (!IsEmptyAS(T))
    {
        int i;
        for (i = 0; i < LengthAS(T); i++)
        {
            printf("%d.%s\n", i + 1, T.TI[i]);
        }
    }
}