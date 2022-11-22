#include "map.h"

boolean stringEqual(char *a,char*b){
    boolean beda=false;
    if(StringLen(a)==StringLen(b)){
        while(*a!='\0' && !beda){
            if(*a!=*b){
                beda = true;
            }
            *a++;
            *b++;
        }
        return !beda;
    }
    else{
        return beda;
    }
}

void CreateMap(MapSB *M)
{
    M->Count = Nil;
}

boolean IsEmpty(MapSB M){
    return (M.Count == Nil);
}

boolean IsFullMap(MapSB M)
{
    return M.Count == MaxEl;
}

void InsertMap(MapSB *M, keytype k, valuetype v)
{
    if (!IsFullMap(*M))
    {
        {
            M->Elements[M->Count].Key = k;
            M->Elements[M->Count].Value = v;
            M->Count++;
        }
    }
}

void DeleteMap(MapSB *M, keytype k)
{
    if (M->Count == 1)
        M->Count = Nil;
    else
    {
        if (IsMemberMap(*M, k))
        {
            int i = 0;
            while (i < M->Count && !stringEqual(M->Elements[i].Key,k))
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

boolean IsMemberMap(MapSB M, keytype k)
{
    int i = 0;
    while (i < M.Count)
    {
        if (stringEqual(M.Elements[i].Key,k))
            return true;
        i++;
    }
    return false;
}

valuetype Value(MapSB M, keytype k){
    if(IsMemberMap(M,k)){
        int i = 0;
        boolean found=false;
        while(i<M.Count && !found){
            if(stringEqual(M.Elements[i].Key,k)){

                found = true;
            }
            else{
                i++;
            }
        }
        return M.Elements[i].Value;
    }
    else{
        return Undefined;
    }  
}