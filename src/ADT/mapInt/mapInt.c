#include "mapInt.h"

void CreateMI(Map *M)
{
    M->Count = Nil;
}

boolean IsFullMI(Map M)
{
    return M.Count == MaxEl;
}

void InsertMI(Map *M, keytype k, valuetype v)
{
    if (!IsFullMI(*M))
    {
        {
            M->Count++;
            M->Elements[M->Count - 1].Key = k;
            M->Elements[M->Count - 1].ValueMS = v;
        }
    }
}

void DeleteMI(Map *M, keytype k)
{
    if (M->Count == 1)
        M->Count = Nil;
    else
    {
        if (IsMemberMI(*M, k))
        {
            int i = 0;
            while (i < M->Count && M->Elements[i].Key != k)
                i++;
            while (i < M->Count)
            {
                M->Elements[i].Key = M->Elements[i + 1].Key;
                M->Elements[i].ValueMS = M->Elements[i + 1].ValueMS;
                i++;
            }
            M->Count--;
        }
    }
}

boolean IsMemberMI(Map M, keytype k)
{
    int i = 0;
    while (i < M.Count)
    {
        if (M.Elements[i].Key == k)
            return true;
        i++;
    }
    return false;
}
