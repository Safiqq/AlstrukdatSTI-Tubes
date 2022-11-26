#include "arrayChar.h"

void CreateAC(ArrayChar *T)
{
    T->Neff = 0;
}

int LengthAC(ArrayChar T)
{
    return T.Neff;
}

void SetAC(ArrayChar *T, int i, ElTypeAC v)
{
    T->TI[i] = v;
    if (i >= T->Neff)
        SetNeffAC(T, T->Neff + 1);
}

void SetNeffAC(ArrayChar *T, int N)
{
    T->Neff = N;
}

boolean IsEmptyAC(ArrayChar T)
{
    return T.Neff == 0;
}