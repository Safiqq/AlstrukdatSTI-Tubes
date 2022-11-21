#include "map.h"

void CreateMap(Map *M)
{
    M->Count = Nil;
}

boolean IsFullMap(Map M)
{
    return M.Count == MaxEl;
}

void InsertMap(Map *M, keytype k, valuetype v)
{
    if (!IsFullMap(*M))
    {
        {
            M->Count++;
            M->Elements[M->Count - 1].Key = k;
            M->Elements[M->Count - 1].Value = v;
        }
    }
}

void DeleteMap(Map *M, keytype k)
{
    if (M->Count == 1)
        M->Count = Nil;
    else
    {
        if (IsMemberMap(*M, k))
        {
            int i = 0;
            while (i < M->Count && M->Elements[i].Key != k)
                i++;
            while (i < M->Count)
            {
                M->Elements[i].Key = M->Elements[i + 1].Key;
                M->Elements[i].Value = M->Elements[i + 1].Value;
                i++;
            }
            M->Count--;
        }
    }
}

boolean IsMemberMap(Map M, keytype k)
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
